#include "RobotStatus.h"

#define BAUD_RATE_SERIAL 9600
#define BAUD_RATE_SERIAL1 115200
#define RSR "RSR"
#define RS "RS"
#define LEFT_MOTOR_POWER_KEY "leftMotorPower"
#define RIGHT_MOTOR_POWER_KEY "rightMotorPower"
#define SHOULDER_ROTATION_KEY "shoulderRotationwer"
#define ELBOW_ROTATION_KEY "elbowRotation"
#define WRIST_ROTATION_KEY "wristRotation"
#define HAND_ROTATION_KEY "handRotation"
#define SOUND_EVENT_KEY "soundEventrPower"

RobotStatus* robotStatus = new RobotStatus();

void setup()  {
  Serial.begin(BAUD_RATE_SERIAL);
  Serial1.begin(BAUD_RATE_SERIAL1);
  pinMode(LED_BUILTIN, OUTPUT);
  startServer();
}
void loop()  {
  parseReceivedData();
  updateMotorsPower();
}

void mirrorSerial(){
  if (Serial1.available()) {
    Serial.write((char)Serial1.read());
    }
 
  if (Serial.available()) {
    Serial1.write((char)Serial.read());
  }
}

void parseReceivedData(){
  String receivedData;
  int robotStatusRequestIndex;
  int robotStatusIndex;
  String robotStatus;
  if (Serial1.available()) {
    receivedData = Serial1.readStringUntil('\n');
    robotStatusRequestIndex = receivedData.indexOf(RSR);
    robotStatusIndex = receivedData.indexOf(RS);
    if(robotStatusRequestIndex > 0){
      //TODO currentStatus
      }else if(robotStatusIndex > 0){
        robotStatus = receivedData.substring(robotStatusIndex+3);
        parseRobotStatus(robotStatus);
        }
    } 
}

void parseRobotStatus(String serializedRobotStatus){
  robotStatus->setLeftMotorPower(findValueOfKey(serializedRobotStatus, LEFT_MOTOR_POWER_KEY));
  robotStatus->setRightMotorPower(findValueOfKey(serializedRobotStatus, RIGHT_MOTOR_POWER_KEY));
  robotStatus->setShoulderRotation(findValueOfKey(serializedRobotStatus, SHOULDER_ROTATION_KEY));
  robotStatus->setElbowRotation(findValueOfKey(serializedRobotStatus, ELBOW_ROTATION_KEY));
  robotStatus->setWristRotation(findValueOfKey(serializedRobotStatus, WRIST_ROTATION_KEY));
  robotStatus->setHandRotation(findValueOfKey(serializedRobotStatus, HAND_ROTATION_KEY));
  robotStatus->setSoundEvent(findValueOfKey(serializedRobotStatus, SOUND_EVENT_KEY));
  }

int findValueOfKey(String serializedRobotStatus, String key){
  int startIndex = serializedRobotStatus.indexOf(key)+key.length()+1;
  String keySubstring = serializedRobotStatus.substring(startIndex);
  int endIndex = keySubstring.indexOf(';');
  return keySubstring.substring(0, endIndex).toInt();
  }

void updateMotorsPower(){
  analogWrite(LED_BUILTIN, robotStatus->getLeftMotorPower()*255/100);
  }

void startServer(){
  delay(1000);
  Serial1.println("AT+CIPMUX=1");
  delay(50);
  Serial1.println("AT+CIPSERVER=1,2727");
  }
