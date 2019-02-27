package com.arensis.crcr.manager;

import com.arensis.crcr.model.RobotStatus;

public class CommunicationManager {

	public void update(RobotStatus robotStatus) {
	}

	public RobotStatus fetchCurrentStatus() {
		final RobotStatus robotStatus = new RobotStatus();
		robotStatus.setLeftMotorPower(72);
		robotStatus.setRightMotorPower(27);
		robotStatus.setShoulderRotation(90);
		robotStatus.setElbowRotation(34);
		robotStatus.setWristRotation(76);
		robotStatus.setHandRotation(12);
		return robotStatus;
	}

}
