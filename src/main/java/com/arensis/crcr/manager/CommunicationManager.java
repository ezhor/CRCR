package com.arensis.crcr.manager;

import com.arensis.crcr.model.RobotStatus;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class CommunicationManager {
	private static final int CRCR_PORT = 2727;
	private static final String ROBOT_STATUS_REQUEST_HEADER = "RSR";
	private static final String ROBOT_STATUS_HEADER = "RS";
	private OutputStream outputStream;
	private InputStream inputStream;

	public void connect(String ip) {
		try {
			Socket socket = new Socket(ip, CRCR_PORT);
			this.outputStream = socket.getOutputStream();
			this.inputStream = socket.getInputStream();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void update(RobotStatus robotStatus) {
		send(robotStatus.toString(), ROBOT_STATUS_HEADER);
	}

	//TODO
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

	private void send(String string, String header){
		try {
			outputStream.write(header.concat("@").concat(string).concat("\n").getBytes());
			System.out.println(string);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
