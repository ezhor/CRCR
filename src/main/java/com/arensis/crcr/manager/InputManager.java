package com.arensis.crcr.manager;

import com.arensis.crcr.model.RobotStatus;
import com.github.strikerx3.jxinput.XInputAxes;
import com.github.strikerx3.jxinput.XInputDevice;
import com.github.strikerx3.jxinput.exceptions.XInputNotLoadedException;

public class InputManager {
    private static final int LX_DEAD_ZONE = 20;
	private RobotStatus robotStatus;

	public void setRobotStatus(RobotStatus robotStatus) {
		this.robotStatus = robotStatus;
	}

	public RobotStatus fetchInputs() {
		XInputDevice device;
		if (XInputDevice.isAvailable()) {
			try {
				device = XInputDevice.getDeviceFor(0);
				if(device.poll()){
					calculateMotorsPower(device.getComponents().getAxes());
				}
			} catch (XInputNotLoadedException e) {
				e.printStackTrace();
			}
		}
		return robotStatus;
	}

	private void calculateMotorsPower(XInputAxes axes) {
        int rtNormalized = Math.round(axes.rt*100);
        int ltNormalized = Math.round(axes.lt*100);
        int lxNormalized = Math.round(axes.lx*100);

        if(lxNormalized < LX_DEAD_ZONE && lxNormalized > -LX_DEAD_ZONE){
            lxNormalized = 0;
        }

		if(rtNormalized != 0){
			calculateForwardMovement(rtNormalized, lxNormalized);
		}else if(ltNormalized != 0){
			calculateBackwardMovement(ltNormalized, lxNormalized);
		}else{
            calculateInPlaceRotation(lxNormalized);
		}
	}

	private void calculateForwardMovement(int rtNormalized, int lxNormalized) {
		int motorReduction;
		int leftMotorPower;
		int rightMotorPower;

		motorReduction = Math.round((rtNormalized/2f) * lxNormalized/100f);
		leftMotorPower = Math.round(rtNormalized+motorReduction);
		leftMotorPower = leftMotorPower > 100 ? 100 : leftMotorPower;
		rightMotorPower = Math.round(rtNormalized-motorReduction);
		rightMotorPower = rightMotorPower > 100 ? 100 : rightMotorPower;

		robotStatus.setLeftMotorPower(leftMotorPower);
		robotStatus.setRightMotorPower(rightMotorPower);
	}

	private void calculateBackwardMovement(int ltNormalized, int lxNormalized) {
		int motorReduction;
		int leftMotorPower;
		int rightMotorPower;

		motorReduction = Math.round((ltNormalized/2f) * lxNormalized/100f);
		leftMotorPower = -Math.round(ltNormalized+motorReduction);
		leftMotorPower = leftMotorPower < -100 ? -100 : leftMotorPower;
		rightMotorPower = -Math.round(ltNormalized-motorReduction);
		rightMotorPower = rightMotorPower < -100 ? -100 : rightMotorPower;

		robotStatus.setLeftMotorPower(leftMotorPower);
		robotStatus.setRightMotorPower(rightMotorPower);
	}

	private void calculateInPlaceRotation(int lxNormalized) {
		robotStatus.setLeftMotorPower(lxNormalized);
		robotStatus.setRightMotorPower(-lxNormalized);
	}

}
