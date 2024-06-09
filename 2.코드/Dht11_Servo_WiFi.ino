/*
프로젝트 : 헬스케어
코드 : 아두이노 센서
*/
#include <WiFiEsp.h>
#include <SoftwareSerial.h>
#include <MsTimer2.h>
#include <DHT.h>
#include <Servo.h>
#include <Adafruit_Sensor.h>

// 서버 접속용 MACRO
#define AP_SSID "embB"
#define AP_PASS "embB1234"
#define SERVER_NAME "10.10.14.63"
#define SERVER_PORT 5000
#define LOGID "KJH_ARD"//"LBC_ARD"
#define PASSWD "PASSWD"

#define CMD_SIZE 50
#define ARR_CNT 5
#define DHTTYPE DHT11
#define DHTPIN 4
#define SERVO_PIN 8

#define WIFIRX 6 //6:RX-->ESP8266 TX
#define WIFITX 7

// flag 변수 생성
bool timerIsrFlag = false;
bool sensorOnFlag = false;
bool sensorSet = false;

char sendBuf[CMD_SIZE];

unsigned int secCount;

char getSensorId[10];
volatile int sensorTime;

// 센서값 받아올 변수
float temp = 0.0;
float humi = 0.0;
DHT dht(DHTPIN, DHTTYPE);
Servo servo;

// 와이파이 설정
SoftwareSerial wifiSerial(WIFIRX, WIFITX);
WiFiEspClient client;

void setup() {
  wifi_Setup();
  Serial.begin(38400);

  MsTimer2::set(1000, timerIsr); // 1000ms period
  MsTimer2::start();

  dht.begin();
  servo.attach(SERVO_PIN);
}

void loop()
{
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  float x = 0.81 * temp;
  float y = 0.01 * humi;
  int dcf_index = x + y * (0.99 * temp - 14.3) + 46.3;

  if (isnan(temp) || isnan(humi))
  {
    Serial.println("...");
    return;
  }
  Serial.print("온도 : ");
  Serial.print(temp);
  Serial.print("°C, 습도 : ");
  Serial.print(humi);
  Serial.print("%, 불쾌지수 : ");
  Serial.println(dcf_index);

  if (dcf_index >= 75) // 불쾌지수가 75 이상이면 A/C 동작
    servo.write(0);
  else
    servo.write(90);
  delay(2000);

  // if (client.available())
  // {
  //   socketEvent();
  // }
  if (timerIsrFlag)
  {
    timerIsrFlag = false;

    humi = dht.readHumidity();
    temp = dht.readTemperature();

      // 센서 데이터를 지정된 시간에 따라 DB로 보냄
    if (!(secCount % 10))
    {
      sprintf(sendBuf, "[%s]CLEAN@%d@%d@%d\n", "KJH_GYM", (int)temp, (int)humi, dcf_index);
      client.write(sendBuf, strlen(sendBuf));
      client.flush();
      delay(500);
      sprintf(sendBuf, "[%s]CLEAN@%d@%d@%d\n", "KJH_AND", (int)temp, (int)humi, dcf_index);
      client.write(sendBuf, strlen(sendBuf));
      client.flush();
    }
  }
}

// // 명령어 파싱 후 확인
// void socketEvent()
// {
//   int i = 0;
//   char * pToken;
//   char * pArray[ARR_CNT] = {0};
//   char recvBuf[CMD_SIZE] = {0};
//   int len;

//   sendBuf[0] = '\0';
//   len = client.readBytesUntil('\n', recvBuf, CMD_SIZE);
//   client.flush();

//   // 서버에서 들어온 명령어를 []와 @를 구분자로 사용해서 분리한다.
//   pToken = strtok(recvBuf, "[@]");
//   while (pToken != NULL)
//   {
//     pArray[i] =  pToken;
//     if (++i >= ARR_CNT)
//       break;
//     pToken = strtok(NULL, "[@]");
//   }
  
//   if ((strlen(pArray[1]) + strlen(pArray[2])) < 16)
//   {
//     // 들어온 명령어를 LCD에 출력한다.
//   }
//   if (!strncmp(pArray[1], " New", 4)) // New Connected
//   {
//     return ;
//   }
//   else if (!strncmp(pArray[1], " Alr", 4)) //Already logged
//   {
//     client.stop();
//     server_Connect();
//     return ;
//   }
//   else if (!strncmp(pArray[1], "SET", 3)) // [???_ARD]SET@SENSOR@10 OR [???_ARD]SET
//   {
//     if(!strncmp(pArray[2], "SENSOR", 6))
//     {
//       sensorSet = true;
//       if (pArray[3] != NULL)
//         sensorTime = atoi(pArray[3]);
//       else
//         sensorTime = 10;
//     }
//     else
//       return;

//     sprintf(sendBuf, "[%s]%s@%s\n", pArray[0], pArray[1], pArray[2]);
//   }
//   else if (!strncmp(pArray[1], "GET", 3)) // [???_ARD]GET@SENSOR@10 OR [???_ARD]GET
//   {
//     if(!strncmp(pArray[2], "SENSOR", 6)) // 센서 데이터 전송
//     {
//       if (pArray[3] != NULL)
//       {
//         sensorTime = atoi(pArray[3]);
//         strcpy(getSensorId, pArray[0]);
//         return;
//       }
//       else
//       {
//         sensorTime = 0;
//         sprintf(sendBuf, "[%s]%s@%d@%d\r\n", pArray[0], pArray[2], (int)temp, (int)humi);
//       }
//     }
//     else
//       return;
//   }
//   else if (!strncmp(pArray[1], "SENSOR", 6))  // [SEN_ARD]SENSOR@ON OR [SEN_ARD]SENSOR@OFF
//   {  
//     if(!strncmp(pArray[2], "ON", 2))
//       sensorOnFlag = true;
//     else if(!strncmp(pArray[2], "OFF", 3))
//       sensorOnFlag = false;

//     sprintf(sendBuf, "[%s]%s@%s\n", pArray[0], pArray[1], pArray[2]);
//   }
//   else
//     return;

//   client.write(sendBuf, strlen(sendBuf));
//   client.flush();
// }

// 타이머 설정
void timerIsr()
{
  timerIsrFlag = true;
  secCount++;
}

// 와이파이 설정
void wifi_Setup() {
  wifiSerial.begin(38400);
  wifi_Init();
  server_Connect();
}
void wifi_Init()
{
  do {
    WiFi.init(&wifiSerial);
    if (WiFi.status() == WL_NO_SHIELD){
    }
    else
      break;
  } while (1);

  while (WiFi.begin(AP_SSID, AP_PASS) != WL_CONNECTED){
  }
}
int server_Connect()
{
  if (client.connect(SERVER_NAME, SERVER_PORT))
  {
    client.print("["LOGID":"PASSWD"]");
  }
}