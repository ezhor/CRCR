#ifndef ROBOTSTATUS_H_
#define ROBOTSTATUS_H_

#include "Arduino.h"

class RobotStatus {
private:
	signed int leftMotorPower;
	signed int rightMotorPower;
	unsigned int shoulderRotation;
	unsigned int elbowRotation;
	unsigned int wristRotation;
	unsigned int handRotation;
	unsigned short int soundEvent;
public:
	RobotStatus();
	RobotStatus(String serializedStatus);
	~RobotStatus();

	unsigned int getLeftMotorPower();
	void setLeftMotorPower(unsigned int leftMotorPower);
	
	unsigned int getRightMotorPower();
	void setRightMotorPower(unsigned int rightMotorPower);
	
	unsigned int getShoulderRotation();
	void setShoulderRotation(unsigned int shoulderRotation);
	
	unsigned int getElbowRotation();
	void setElbowRotation(unsigned int elbowRotation);
	
	unsigned int getWristRotation();
	void setWristRotation(unsigned int wristRotation);
	
	unsigned int getHandRotation();
	void setHandRotation(unsigned int handRotation);

	unsigned short int getSoundEvent();
	void setSoundEvent(unsigned short int soundEvent);

	String toString();
};

#endif /* ROBOTSTATUS_H__H_ */
