---
# 프로젝트 주제
---

![header](https://capsule-render.vercel.app/api?type=venom&color=0:3ABEF9,100:b678c4&height=200&section=header&text=헬스_케어_시스템&fontSize=40)

---
## 작품 기간 : 24.04.15 ~ 24.04.22
---
## 주제 선정 배경
운동에 관심이 많다 보니 우리가 운동할 때 불편한 점이 무엇이 있을까 생각해 보았고, STM32 MCU로 구현 할 운동머신을 생각해 보았습니다.
<br>
헬스장에 대표 유산소 운동 기구로 런닝머신이 있고, 기존 런닝머신은 운동이 끝나 머신을 종료하게 되면 운동 기록을 더 이상 볼 수 없어 기록을 할 수 없습니다. 이러한 이유로 운동을 하며 몸의 성장이나 진행 상황을 알 수 없게 됩니다.
<br>
개인이나 서버에서 운동 기록을 저장하게 되면, 운동 계획과 목표를 세우게 되면서 건강 관리나 운동 루틴을 만들어 성장하는 자신을 보며 운동에 대한 재미를 더 느낄 수 있습니다.

## 기술 구현 목표
1. 가스 센서, 적외선 불꽃 감지 센서, 온/습도 센서로 산불 초기 감지 > wifi와 통신하는 센서 값과 GPS 위치를 DB에 데이터 전송
2. 산불과 연기를 학습한 카메라가 산불 인식 > DB에 센서 데이터 전송
3. 화재 인식과 동시에 Buzzer가 울리면서 LED 점멸(경고, 대피용), 소방당국이 DB를 통해 실시간 정보와 GPS로 위치를 확인할 수 있다.
4. 수막 설비 시스템 동작 > DB로 Actuator 데이터 전송
5. DB를 소방서와 공유 > 화재가 감지된 장소로 이동
6. 불이 진압 되면 수막 설비 시스템 종료

## 기대 효과
- 산불 발생 시 초기에 감지 및 진화하여 산불 확산을 사전에 방지한다.
- 사람 눈으로 산불 발견이 어려운 만큼 IoT 센서와 딥러닝으로 학습된 카메라를 통해 이중으로 감지한다.
- 자동화된 시스템을 통해 산불이 마을로 접근하는 경우 주민들의 대피 시간을 확보하며 물적 피해 또한 줄인다.

<br>

**위의 효과로 대피 시간 확보와 산불 번짐을 저지 및 둔화 시킬 수 있으며, 적은 인원으로 효율적인 시스템 관리와 소방산업 활성화의 기여할 것**

---
## 개발 환경
| Board | Arduino | Jetson Nono | Raspberry Pi|
| --- | --- | --- | --- |
| Language | C++ |Python|C, PhP|
| OS |Windows|NVIDIA JetPack|RaspberryPi, linux|
| Library |DHT, SerialSoftWare, WiFiEsp, TinyGps, I2C|OpenCV, Yolov5|sys/socket, type, stdio, pthread, netinet/in.sys/stat, arpa/inet|
| System | Arduino |VSCode|GCC, APACHE, MariaDB|

## 프로젝트 팀원
|  | 이  름 | 역할 분담 |
| --- | --- | --- |
| 팀원 | 구주헌 |~|
| 팀원 | 이병찬 |~|

## 개발 일정
![개발](https://github.com/BChanGod/BChanGod_Device.github.io/blob/main/%EC%82%B0%EB%B6%88%EA%B0%90%EC%A7%80_%EC%9D%B4%EB%AF%B8%EC%A7%80/%EA%B0%9C%EB%B0%9C%EC%9D%BC%EC%A0%95.jpg)

## 향후 목표
-준비-

## 참고 자료, 문헌
