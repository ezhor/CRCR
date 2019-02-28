#include "./RobotStatus.h"

RobotStatus::RobotStatus() {
}

RobotStatus::RobotStatus(String serializedStatus) {
}

RobotStatus::~RobotStatus() {
}

unsigned int RobotStatus::getLeftMotorPower(){
	return this->leftMotorPower;
}

void RobotStatus::setLeftMotorPower(unsigned int leftMotorPower){
	this->leftMotorPower = leftMotorPower;
}

unsigned int RobotStatus::getRightMotorPower(){
	return this->rightMotorPower;
}

void RobotStatus::setRightMotorPower(unsigned int rightMotorPower) {
	this->rightMotorPower = rightMotorPower;
}

unsigned int RobotStatus::getShoulderRotation() {
	return this->shoulderRotation;
}

void RobotStatus::setShoulderRotation(unsigned int shoulderRotation) {
	this->shoulderRotation = shoulderRotation;
}

unsigned int RobotStatus::getElbowRotation() {
	return this->elbowRotation;
}

void RobotStatus::setElbowRotation(unsigned int elbowRotation) {
	this->elbowRotation = elbowRotation;
}

unsigned int RobotStatus::getWristRotation() {
	return this->wristRotation;
}

void RobotStatus::setWristRotation(unsigned int wristRotation) {
	this->wristRotation = wristRotation;
}

unsigned int RobotStatus::getHandRotation() {
	return this->handRotation;
}

void RobotStatus::setHandRotation(unsigned int handRotation) {
	this->handRotation = handRotation;
}

unsigned short int RobotStatus::getSoundEvent() {
	return this->soundEvent;
}

void RobotStatus::setSoundEvent(unsigned short int soundEvent) {
	this->soundEvent = soundEvent;
}



String RobotStatus::toString(){
	String status = String();
	
	status = "leftMotorPower=" + this->leftMotorPower;
	status += ";rightMotorPower=" + this->rightMotorPower;
	status += ";shoulderRotation=" + this->shoulderRotation;
	status += ";elbowRotation=" + this->elbowRotation;
	status += ";wristRotation=" + this->wristRotation;
	status += ";handRotation=" + this->handRotation;

	return status;
}
