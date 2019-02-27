#ifndef ROBOTSTATUS_H_
#define ROBOTSTATUS_H_

class RobotStatus {
private:
	unsigned int leftMotorPower;
	unsigned int rightMotorPower;
	unsigned int shoulderRotation;
	unsigned int elbowRotation;
	unsigned int wristRotation;
	unsigned int handRotation;
public:
	RobotStatus();
	RobotStatus(std::string serializedStatus);

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
};

#endif /* ROBOTSTATUS_H__H_ */