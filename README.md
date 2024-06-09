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
헬스장에 대표 유산소 운동 기구로 런닝머신이 있고, 기존 런닝머신은 운동이 끝나 머신을 종료하게 되면 운동 기록을 더 이상 볼 수 없어 기록을 할 수 없습니다. 이러한 이유로 운동을 하며 몸의 성장이나 운동 계획의 진행 상황을 알 수 없게 됩니다.
<br>
개인이나 서버에서 운동 기록을 저장하게 되면, 운동 계획과 목표를 세우게 되면서 건강 관리나 운동 루틴을 만들어 성장하는 자신을 보며 운동에 대한 재미를 더 느낄 수 있습니다.

## 기술 구현 목표
< STM32 MCU KIT 활용 >
1. DC Motor로 런닝머신 구현
2. Push Button으로 런닝머신 기능을 추가(1번 Start/Stop, 2번 속도 감소(--), 3번 속도 증가(++)PWM제어)
3. LCD에 km, kcal 출력
4. Array FND, 4자리 FND에 UpCount를 구현하고 Motor가 동작할 때만 Count 되는 기능을 추가
5. BlueTooth로 결과를 DB에 전송
<br>

< Arduino Board 활용 >
1. DHT 센서로 온/습도를 측정해 불쾌지수를 나타낸다.
2. Servo Motor로 A/C을 구현할 것이고 불쾌지수가 75이상이면 A/C 작동
3. WIFI 로 센서 데이터를 DB에 전송

---
## 개발 환경
| Board | Arduino | STM32 MCU KIT | Raspberry Pi|
| --- | --- | --- | --- |
| Language | C++ |C/C++|C, PHP|
| OS | Windows | Window | RaspberryPi, linux|
| System | Arduino IDE |VSCode|Android, APACHE, MariaDB|

## 프로젝트 팀원
|  | 이  름 | 역할 분담 |
| --- | --- | --- |
| 팀원 | 구주헌 |STM32CubeIDE 런닝머신 전체 구현, DB 생성, data 시각화, Android|
| 팀원 | 이병찬 |STM32CubeIDE Motor, PushButton 구현, Arduino DHT, Servo Motor, WIFI 구현|

## 문제점
블루투스 모듈 이용해서 메시지를 보낼 때 제대로 처리가 되지 않는 문제 발생
![개발]()

## 해결 방안
Delay를 주어 해결
![개발]()

## 향후 목표
1. 웨어러블을 접목해 심박수 측정 기능 추가
2. 운동 App으로 운동기구 제어 기능 추가
3. 무산소 운동 기록 측정

## 참고 자료, 문헌
불쾌지수 > 생활기상지수 > 도움말 (weather.go.kr)
![image](https://github.com/BChanGod/HealthCareSystem/assets/159971128/0f53c483-f3a0-47d7-b963-3881681d64bf)
