package com.arensis.crcr.manager;

import com.arensis.crcr.model.RobotStatus;

import javafx.scene.Scene;
import javafx.scene.chart.BarChart;
import javafx.scene.chart.CategoryAxis;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.chart.XYChart.Data;
import javafx.scene.chart.XYChart.Series;
import javafx.stage.Stage;

public class GuiManager {
	private Data<String, Number> leftMotorData;
	private Data<String, Number> rightMotorData;
	
	public void start(Stage primaryStage) {
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
		scene = new Scene(motorBarChart, 350, 300);
		motorBarChart.getData().addAll(series);
		primaryStage.setScene(scene);
		primaryStage.show();
		//bc.setAnimated(false);
	}

	public void update(RobotStatus robotStatus) {
		this.leftMotorData.setYValue(robotStatus.getLeftMotorPower());
		this.rightMotorData.setYValue(robotStatus.getRightMotorPower());
	}
}
