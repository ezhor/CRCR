package com.arensis.crcr.main;

import java.util.Timer;
import java.util.TimerTask;

import com.arensis.crcr.manager.CommunicationManager;
import com.arensis.crcr.manager.GuiManager;
import com.arensis.crcr.manager.InputManager;
import com.arensis.crcr.model.RobotStatus;

import javafx.application.Application;
import javafx.stage.Stage;

@SuppressWarnings("restriction")
public class Main extends Application {
	private static final int UPDATE_TIME = 50;
	private final GuiManager guiManager = new GuiManager();
	private final InputManager inputManager = new InputManager();
	private final CommunicationManager communicationManager = new CommunicationManager();
	private final Timer timer = new Timer();

	public static void main(String[] args) {
		launch(args);
	}

	@Override
	public void start(Stage primaryStage) throws Exception {
		RobotStatus currentStatus = communicationManager.fetchCurrentStatus();
		guiManager.start(primaryStage);
		guiManager.update(currentStatus);
		inputManager.setRobotStatus(currentStatus);
		startUpdateThread();
	}

	private void startUpdateThread() {
		timer.schedule(new RobotStatusUpdater(), 0, UPDATE_TIME);
	}
	
	@Override
	public void stop() throws Exception {
		timer.cancel();
	}
	
	private class RobotStatusUpdater extends TimerTask{

		@Override
		public void run() {
			final RobotStatus robotStatus = inputManager.fetchInputs();
			guiManager.update(robotStatus);
			communicationManager.update(robotStatus);
		}
		
	}
}