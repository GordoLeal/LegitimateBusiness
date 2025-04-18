#pragma once
#include "Settings.h"
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <Windows.h>

const char* SettingsFileName = "SSASettings.txt";
//DoesSettingsFileExists should be run before this command.
bool Settings::GetBoolFromSetting(char* setting)
{
	std::ifstream inFile;
	inFile.open(SettingsFileName);
	if (inFile.is_open()) {

	}
	return false;
}

void Settings::CreateSettingsFile()
{
	std::fstream settingsStream;
	settingsStream.open(SettingsFileName, std::ios::in | std::ios::out | std::ios::trunc);
	OutputDebugStringA("caralho cria a pasta caralho");
	if (settingsStream.is_open()) {
		OutputDebugStringA("ta open");
		std::string fileout;
		fileout += "# SETTINGS FILE FOR SUPER SIMEON AUTOS\n";
		fileout += "# 0 = false/disabled | 1 = true/enabled\n\n";
		fileout += "# Enable lighthouse as a delivery point\n";
		fileout += "LightHouseAsDelivery=1\n\n";
		fileout += "# Enable the lifeguard tower as a delivery point\n";
		fileout += "BeachAsDelivery=1\n\n";
		fileout += "# Enable Simeon as a delivery point\n";
		fileout += "SimeonAsDelivery=1\n\n";
		fileout += "# Enable Trailers as vehicles that can be delivered\n";
		fileout += "EnableTrailers=1\n\n";
		fileout += "# Enable Heli/Planes to be delivered\n";
		fileout += "EnableFlyingVehicles=1\n\n";
		fileout += "# Enable boats to be delivered\n";
		fileout += "EnableWaterVehicles=1\n\n";
		fileout += "# Display Max Amount of vehicles to be collected\n";
		fileout += "DisplayMaxAmount=1\n\n";
		fileout += "# Mod Made by GordoLeal\n";
		fileout += "# Twitch.tv/GordoLeal";
		settingsStream << fileout;
	}

	settingsStream.close();
}

bool Settings::DoesSettingsFileExists()
{
	std::ifstream settingsStream;
	settingsStream.open(SettingsFileName);
	bool exists = false;
	if (settingsStream.is_open())
	{
		exists = true;
	}
	settingsStream.close();
	return exists;
}

bool stringToBool(std::string inS) {
	if (inS.at(0) == '0') {
		return false;
	}
	else if (inS.at(0) == '1') {
		return true;
	}
	else
	{
		return false;
	}
}
void Settings::ReadValuesFromSettingsFile()
{
	if (!DoesSettingsFileExists()) {
		
		CreateSettingsFile();
		LightHouseAsDelivery = true;
		BeachAsDelivery = true;
		SimeonAsDelivery = true;
		EnableTrailers = true;
		EnableFlyingVehicles = true;
		EnableWaterVehicles = true;
		DisplayMaxAmount = true;
		return;
	}
	std::fstream settFileStream;
	settFileStream.open(SettingsFileName, std::ios::out | std::ios::in);
	std::string line;
	while (std::getline(settFileStream, line))
	{
		bool End = false;
		bool readingCmd = true;
		bool foundCmd = false;
		std::string command;
		std::string value;

		for (int x = 0; x < line.size(); x++)
		{
			if (line.at(0) == '#' && line.at(0) == '\n')
			{
				break;
			}

			switch (line.at(x))
			{
			case '\n':
				End = true;
				break;
			case '=':
				readingCmd = false;
				foundCmd = true;
				break;
			default:
			{
				if (readingCmd) {
					command += line.at(x);
				}
				else
				{
					value += line.at(x);
					End = true;
				}
				break;
			}
			}

			if (End)
				break;
		}

		if (foundCmd) 
		{
			bool found = false;
			if(!found && command.find("LightHouseAsDelivery") == 0)
			{
				LightHouseAsDelivery = stringToBool(value);
				found = true;
			}
			if (!found && command.find("BeachAsDelivery") == 0)
			{
				BeachAsDelivery= stringToBool(value);
				found = true;
			}
			if (!found && command.find("SimeonAsDelivery") == 0)
			{
				SimeonAsDelivery= stringToBool(value);
				found = true;
			}
			if (!found && command.find("EnableTrailers") == 0)
			{
				EnableTrailers= stringToBool(value);
				found = true;
			}
			if (!found && command.find("EnableFlyingVehicles") == 0)
			{
				EnableFlyingVehicles= stringToBool(value);
				found = true;
			}
			if (!found && command.find("EnableWaterVehicles") == 0)
			{
				EnableWaterVehicles= stringToBool(value);
				found = true;
			}
			if (!found && command.find("DisplayMaxAmount") == 0)
			{
				DisplayMaxAmount = stringToBool(value);
				found = true;
			}
		}
	}
}


