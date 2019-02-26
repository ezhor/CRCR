package com.arensis.crcr.gui;

import java.util.Timer;
import java.util.TimerTask;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.BarChart;
import javafx.scene.chart.CategoryAxis;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.chart.XYChart.Data;
import javafx.scene.chart.XYChart.Series;
import javafx.stage.Stage;

public class Main extends Application {
	Data<String, Number> leftMotorData;
	Data<String, Number> rightMotorData;

	public static void main(String[] args) {
		launch(args);
	}

	@Override
	public void start(Stage primaryStage) throws Exception {
		final CategoryAxis xAxis = new CategoryAxis();
		final NumberAxis yAxis = new NumberAxis(0, 100, 10);
		final BarChart<String, Number> motorBarChart = new BarChart<>(xAxis, yAxis);
		final XYChart.Series<String, Number> series = new Series<>();
		final Scene scene;
		
		primaryStage.setTitle("CRCR: Cool Remote Controlled Robot");
		leftMotorData = new Data<>("Left Motor", 0);
		rightMotorData = new Data<>("Right Motor", 0);
		series.setName("Motors");		
		series.getData().addAll(leftMotorData, rightMotorData);
		yAxis.setAnimated(false);
		xAxis.setAnimated(false);
		scene = new Scene(motorBarChart, 300, 300);
		motorBarChart.getData().addAll(series);
		primaryStage.setScene(scene);
		primaryStage.show();
		//bc.setAnimated(false);
		
		startSynchro();
	}

	private void startSynchro() {
		final Timer timer = new Timer();
		timer.schedule(new TimerTask() {
		int increment = 0;

			@Override
			public void run() {
				
				double value = (double) leftMotorData.getYValue();
				
				if(value == 0) {
					increment = 10;
				}else if(value == 100) {
					increment = -10;
				}
				leftMotorData.setYValue(value + increment);
				
			}
		}, 0, 500);
	}
}