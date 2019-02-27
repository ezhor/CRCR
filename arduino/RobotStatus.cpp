#include "RobotStatus.h"

RobotStatus::RobotStatus() {
}

RobotStatus::RobotStatus(std::string serializedStatus) {
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

std:string toString(){
	std::stringstream stringStream;
	stringStream
		<< "leftMotorPower=" << this->leftMotorPower
		<< ";rightMotorPower=" << this->rightMotorPower
		<< ";shoulderRotation=" << this->shoulderRotation
		<< ";elbowRotation=" << this->elbowRotation
		<< ";wristRotation=" << this->wristRotation
		<< ";handRotation=" << this->handRotation
}