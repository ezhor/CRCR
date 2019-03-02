#ifndef ROBOTSTATUS_H_
#define ROBOTSTATUS_H_

#include "Arduino.h"

class RobotStatus {
private:
	int leftMotorPower;
	int rightMotorPower;
	int shoulderRotation;
	int elbowRotation;
	int wristRotation;
	int handRotation;
	int soundEvent;
public:
	RobotStatus();
	~RobotStatus();

	int getLeftMotorPower();
	void setLeftMotorPower(int leftMotorPower);
	
	int getRightMotorPower();
	void setRightMotorPower(int rightMotorPower);
	
	int getShoulderRotation();
	void setShoulderRotation(int shoulderRotation);
	
	int getElbowRotation();
	void setElbowRotation(int elbowRotation);
	
	int getWristRotation();
	void setWristRotation(int wristRotation);
	
	int getHandRotation();
	void setHandRotation(int handRotation);

	int getSoundEvent();
	void setSoundEvent(int soundEvent);

	String toString();
};

#endif /* ROBOTSTATUS_H__H_ */
