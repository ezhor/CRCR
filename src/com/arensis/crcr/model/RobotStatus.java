package com.arensis.crcr.model;

public class RobotStatus {
	private int leftMotorPower;
	private int rightMotorPower;
	private int shoulderRotation;
	private int elbowRotation;
	private int wristRotation;
	private int handRotation;
	private boolean soundEvent;

	public int getLeftMotorPower() {
		return leftMotorPower;
	}

	public void setLeftMotorPower(int leftMotorPower) {
		this.leftMotorPower = leftMotorPower;
	}

	public int getRightMotorPower() {
		return rightMotorPower;
	}

	public void setRightMotorPower(int rightMotorPower) {
		this.rightMotorPower = rightMotorPower;
	}

	public int getShoulderRotation() {
		return shoulderRotation;
	}

	public void setShoulderRotation(int shoulderRotation) {
		this.shoulderRotation = shoulderRotation;
	}

	public int getElbowRotation() {
		return elbowRotation;
	}

	public void setElbowRotation(int elbowRotation) {
		this.elbowRotation = elbowRotation;
	}

	public int getWristRotation() {
		return wristRotation;
	}

	public void setWristRotation(int wristRotation) {
		this.wristRotation = wristRotation;
	}

	public int getHandRotation() {
		return handRotation;
	}

	public void setHandRotation(int handRotation) {
		this.handRotation = handRotation;
	}

	public boolean isSoundEvent() {
		return soundEvent;
	}

	public void setSoundEvent(boolean soundEvent) {
		this.soundEvent = soundEvent;
	}

}
