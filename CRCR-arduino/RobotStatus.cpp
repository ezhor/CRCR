#include "./RobotStatus.h"

RobotStatus::RobotStatus() {
  this->leftMotorPower = 0;
  this->rightMotorPower = 0;
  this->shoulderRotation = 0;
  this->elbowRotation = 0;
  this->wristRotation = 0;
  this->handRotation = 0;
  this->soundEvent = 0;
}

RobotStatus::~RobotStatus() {
}

int RobotStatus::getLeftMotorPower(){
	return this->leftMotorPower;
}

void RobotStatus::setLeftMotorPower(int leftMotorPower){
	this->leftMotorPower = leftMotorPower;
}

int RobotStatus::getRightMotorPower(){
	return this->rightMotorPower;
}

void RobotStatus::setRightMotorPower(int rightMotorPower) {
	this->rightMotorPower = rightMotorPower;
}

int RobotStatus::getShoulderRotation() {
	return this->shoulderRotation;
}

void RobotStatus::setShoulderRotation(int shoulderRotation) {
	this->shoulderRotation = shoulderRotation;
}

int RobotStatus::getElbowRotation() {
	return this->elbowRotation;
}

void RobotStatus::setElbowRotation(int elbowRotation) {
	this->elbowRotation = elbowRotation;
}

int RobotStatus::getWristRotation() {
	return this->wristRotation;
}

void RobotStatus::setWristRotation(int wristRotation) {
	this->wristRotation = wristRotation;
}

int RobotStatus::getHandRotation() {
	return this->handRotation;
}

void RobotStatus::setHandRotation(int handRotation) {
	this->handRotation = handRotation;
}

int RobotStatus::getSoundEvent() {
	return this->soundEvent;
}

void RobotStatus::setSoundEvent(int soundEvent) {
	this->soundEvent = soundEvent;
}



String RobotStatus::toString(){
	String status;
	
	status = String("leftMotorPower=") + this->leftMotorPower;
	status += String(";rightMotorPower=") + this->rightMotorPower;
	status += String(";shoulderRotation=") + this->shoulderRotation;
	status += String(";elbowRotation=") + this->elbowRotation;
	status += String(";wristRotation=") + this->wristRotation;
	status += String(";handRotation=") + this->handRotation;

	return status;
}
