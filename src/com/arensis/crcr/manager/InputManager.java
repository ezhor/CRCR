package com.arensis.crcr.manager;

import com.arensis.crcr.model.RobotStatus;

public class InputManager {

	public RobotStatus fetchInputs() {
		final RobotStatus robotStatus = new RobotStatus();
		robotStatus.setLeftMotorPower(72);
		robotStatus.setRightMotorPower(27);
		return robotStatus;
	}

}
