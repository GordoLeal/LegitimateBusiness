#pragma once
class Settings
{
public:
	bool LightHouseAsDelivery;
	bool BeachAsDelivery;
	bool SimeonAsDelivery;
	bool EnableTrailers;
	bool EnableFlyingVehicles;
	bool EnableWaterVehicles;

	bool GetBoolFromSetting(char* setting);
	bool DoesSettingsFileExists();
	void ReadValuesFromSettingsFile();
	void CreateSettingsFile();
};

