package com.arensis.crcr.manager;

import com.arensis.crcr.model.RobotStatus;

public class InputManager {
	private RobotStatus robotStatus;

	public RobotStatus getRobotStatus() {
		return robotStatus;
	}

	public void setRobotStatus(RobotStatus robotStatus) {
		this.robotStatus = robotStatus;
	}

	public RobotStatus fetchInputs() {
		this.robotStatus.setLeftMotorPower(27);
		this.robotStatus.setRightMotorPower(72);
		this.robotStatus.setShoulderRotation(90);
		this.robotStatus.setElbowRotation(34);
		this.robotStatus.setWristRotation(76);
		this.robotStatus.setHandRotation(12);
		return robotStatus;
	}

}
