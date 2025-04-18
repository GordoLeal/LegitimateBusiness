#pragma once
class Settings
{
public:
	bool LightHouseAsDelivery;
	bool BeachAsDelivery;
	bool SimeonAsDelivery;
	bool PierAsDelivery;
	bool EnableTrailers;
	bool EnableFlyingVehicles;
	bool EnableWaterVehicles;
	bool DisplayMaxAmount;
	bool ShowHelpText;
	bool AntiParkingLotBeach;

	bool GetBoolFromSetting(char* setting);
	bool DoesSettingsFileExists();
	void ReadValuesFromSettingsFile();
	void CreateSettingsFile();
};

