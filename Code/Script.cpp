#pragma once
#include "Script.h"
#include "keyboard.h"
#include "Vehicles.h"

std::list<char*> deliveredVehicles;
std::list<const char*> fullVehicleList;
Vehicle LastStolenVehicle;
BOOLEAN ParkingAbuseDuringMission;

enum ScriptStage {
	CheckCurrentVehicle,
	LookingForValidVehicle,
	Delivering, //The Truth - Kifflom
	VehicleAtDelivery,
	DeleteVehicle
};

// Pattern Pointers
intptr_t pSavedSlotNumberPTR;
intptr_t pToBeLoadedSaveFilePTR;
// Return of the pointers
int LastLoadedSaveSlotNumber;
char* ToBeLoadedSaveFile;
// Misc
std::string lastLoadedSaveFile;
std::wstring pathToSaveFolder;
std::string lastValueOfToBeLoadedSaveFile;
bool alreadySaving = false;
bool wasLoadingScreenActive;
char* lastValidVehicle;
Settings gSettings;
ScriptStage currentStage = ScriptStage::CheckCurrentVehicle;
bool OrtegaTrailerDelivered;
// Mission specific
bool IsInArmenian = false;
bool IsInDLG = false;
// MissionReplay
bool missionReplayCalled;
// Generate Remaining Cars List.
const DWORD genMaxPressingTime = 5000;
DWORD genStartPressingTime;
bool genStartTimer = false;
bool genAlreadyCreatingFile = false;
//Quick Help generate missing vehicles
const DWORD hmvMaxTimer = 1800000; //30 minutes
//DWORD hmvMaxTimer = 30000; //30 seconds for testing
DWORD hmvStartTime;

static void CreateHelpText(char* text, bool doSound) {
	UI::_SET_TEXT_COMPONENT_FORMAT((char*)"STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DISPLAY_HELP_TEXT_FROM_STRING_LABEL(0, 0, doSound, -1);
}
void LoadHookPointers() {
	//Save Files
	SaveSystem::GetSaveFilePath(false, &pathToSaveFolder);

	//Pattern Finding
	// Number of last Loaded Save slot
	if (SaveSystem::GetPointerToLastLoadedSlotNumber(&pSavedSlotNumberPTR) == SaveSystem::ErrSave::SaveDone)
	{
		if (SaveSystem::GetLastReadSlotNumber(&LastLoadedSaveSlotNumber, &pSavedSlotNumberPTR) != SaveSystem::ErrSave::SaveDone)
		{
			OutputDebugString("something happened address could not be loaded...");
			CreateHelpText((char*)"something happened address could not be loaded...", true);
			return;
		}
	}
	else
	{
		OutputDebugString("something happened and pointers could not be loaded...");
		CreateHelpText((char*)"something happened and pointers could not be loaded...", true);
		return;
	}
	//char* of to be loaded Save File.
	if (SaveSystem::GetPointerToBeLoadedSaveFile(&pToBeLoadedSaveFilePTR) == SaveSystem::ErrSave::SaveDone) {
		if (SaveSystem::GetToBeReadSaveFile(&ToBeLoadedSaveFile, &pToBeLoadedSaveFilePTR) != SaveSystem::ErrSave::SaveDone) {
			OutputDebugString("something happened address could not be loaded...");
			CreateHelpText((char*)"something happened address could not be loaded...", true);
			return;
		}
	}
	else
	{
		OutputDebugString("something happened and pointers could not be loaded...");
		CreateHelpText((char*)"something happened and pointers could not be loaded...", true);
		return;
	}
}

void FillFullVehicleList()
{
	fullVehicleList.clear();
	for (const char* a : VehiclesList)
	{
		fullVehicleList.push_back(a);
	}

	if (gSettings.EnableFlyingVehicles)
	{
		for (const char* b : FlyingVehicles)
		{
			fullVehicleList.push_back(b);
		}
	}
	if (gSettings.EnableWaterVehicles)
	{
		for (const char* c : WaterVehicles)
		{
			fullVehicleList.push_back(c);
		}
	}
	if (gSettings.EnableTrailers)
	{
		for (const char* c : TrailerVehicles)
		{
			fullVehicleList.push_back(c);
		}
	}
}

void LoadCurrentSave() {

	// Script got reloaded into prologue, this is probably a new game.
	// Mission replay does not cause a script reload.
	if (SCRIPT::_GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT(GAMEPLAY::GET_HASH_KEY((char*)"Prologue1")) > 0)
	{
		// Player just loaded a new game.
		// clean everything.
		deliveredVehicles.clear();
	}
	else
	{

		if (missionReplayCalled)
		{
			std::string cmp(ToBeLoadedSaveFile);
			if (cmp.find("MISREP000") != std::string::npos) {
				//Nothing is needed
			}
			else
			{
				deliveredVehicles.clear();
				SaveSystem::LoadProgress(pathToSaveFolder, LastLoadedSaveSlotNumber, deliveredVehicles);
			}
			// Player just got out of a mission replay and is loading everything back.

		}
		else
		{

			if (LastLoadedSaveSlotNumber >= 0 && LastLoadedSaveSlotNumber < 15)
			{
				// Player Just loaded a save file.
				// Load user data from that save.
				deliveredVehicles.clear();
				SaveSystem::LoadProgress(pathToSaveFolder, LastLoadedSaveSlotNumber, deliveredVehicles);

			}
			else
			{
				SaveSystem::LoadProgressForFirstTime(pathToSaveFolder, deliveredVehicles);
				// Player Just oppened the game, check the latest saved files.
			}
		}
	}
	missionReplayCalled = false;
}

void QuickAddToDelivered(char* veh)
{
	deliveredVehicles.push_back(veh);
}

bool QuickCheckIfDelivered(char* veh)
{
	std::string a(veh);
	for (char* v : deliveredVehicles)
	{
		if (a.compare(v) == 0) {
			return true;
		}
	}
	return false;
}

// BLIPS
Blip simeonBlip;
Blip countrysideLightHouseBlip;
Blip lifeguardBeachBlip;
Blip PierBlip;

void EnableAllDeliveryBlips()
{

	if (gSettings.BeachAsDelivery) {
		lifeguardBeachBlip = UI::ADD_BLIP_FOR_COORD(-1174, -1773, 3);
		UI::SET_BLIP_FLASHES(lifeguardBeachBlip, true);
		UI::SET_BLIP_FLASH_TIMER(lifeguardBeachBlip, 5000);
		UI::SET_BLIP_COLOUR(lifeguardBeachBlip, BlipColorWhite);
	}

	if (gSettings.LightHouseAsDelivery)
	{
		countrysideLightHouseBlip = UI::ADD_BLIP_FOR_COORD(3426, 5174, 7);
		UI::SET_BLIP_FLASHES(countrysideLightHouseBlip, true);
		UI::SET_BLIP_FLASH_TIMER(countrysideLightHouseBlip, 5000);
		UI::SET_BLIP_COLOUR(countrysideLightHouseBlip, 41);
	}

	if (gSettings.SimeonAsDelivery && !(!gSettings.SimeonStateDuringArmenian && IsInArmenian))
	{
		simeonBlip = UI::ADD_BLIP_FOR_COORD(-55, -1112, 26);
		UI::SET_BLIP_FLASHES(simeonBlip, true);
		UI::SET_BLIP_FLASH_TIMER(simeonBlip, 5000);
		UI::SET_BLIP_COLOUR(simeonBlip, BlipColorGreen);

	}
	if (gSettings.PierAsDelivery && !(!gSettings.SimeonStateDuringArmenian && IsInDLG)) {
		PierBlip = UI::ADD_BLIP_FOR_COORD(-1813, -1200, 13);
		UI::SET_BLIP_FLASHES(PierBlip, true);
		UI::SET_BLIP_FLASH_TIMER(PierBlip, 5000);
		UI::SET_BLIP_COLOUR(PierBlip, 53);
	}

}

void DisableAllDeliveryBlips() {
	if (UI::DOES_BLIP_EXIST(simeonBlip))
		UI::REMOVE_BLIP(&simeonBlip);
	if (UI::DOES_BLIP_EXIST(countrysideLightHouseBlip))
		UI::REMOVE_BLIP(&countrysideLightHouseBlip);
	if (UI::DOES_BLIP_EXIST(lifeguardBeachBlip))
		UI::REMOVE_BLIP(&lifeguardBeachBlip);
	if (UI::DOES_BLIP_EXIST(PierBlip))
		UI::REMOVE_BLIP(&PierBlip);
}

// =-=-=-=-=-=-=-=-=-=-=-=-=- UI =-=-=-=-=-=-=-=-=-=-

void ShowCollectedAmount() {
	std::string outputAmount;
	int totalDeliveredVehicles = deliveredVehicles.size();
	int totalFullVehicles = fullVehicleList.size();
	if (OrtegaTrailerDelivered)
	{
		totalFullVehicles++;
	}
	outputAmount += std::to_string(totalDeliveredVehicles);
	if (gSettings.DisplayMaxAmount) {
		outputAmount += " | ";
		outputAmount += std::to_string(totalFullVehicles);
	}
	//Draw collect amount
	UI::SET_TEXT_FONT(0);
	UI::SET_TEXT_WRAP(0.0, 1.0);
	UI::SET_TEXT_CENTRE(1);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::SET_TEXT_SCALE(0, 0.8f);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY((char*)"STRING");
	UI::SET_TEXT_COLOUR(255, 255, 255, 255);
	UI::_ADD_TEXT_COMPONENT_STRING((char*)outputAmount.c_str());
	UI::_DRAW_TEXT(0.25f, 0.85f);

	if (gSettings.ShowHelpText)
	{
		if (GetTickCount() >= hmvStartTime + hmvMaxTimer)
		{
			hmvStartTime = GetTickCount();
			//quick help text
			const char* outputHelp = "Need help?\nHold ~INPUT_RELOAD~ and ~INPUT_COVER~ for 5 seconds to create a missing cars list.";
			CreateHelpText((char*)outputHelp, true);
		}
	}
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-  Testing player in Area =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
typedef struct {
	float x1;
	float y1;
	float z1;
	float x2;
	float y2;
	float z2;
}DeliveryArea;

enum StatusEntityInArea {
	none,
	Simeon,
	Beach,
	Lighthouse,
	Pier
};

const DeliveryArea SimeonArea = { -38, -1102, -1, -60, -1120, 35 };
const DeliveryArea LighthouseArea = { 3459, 5148, 45, 3369, 5197, -1 };
const DeliveryArea BeachArea = { -1165, -1807, 25, -1223, -1761, -1 };
const DeliveryArea PierArea = { -1787, -1180, 50, -1859, -1260, -1 };

StatusEntityInArea IsEntityInDeliveryArea(Entity entity) {

	if (ENTITY::IS_ENTITY_IN_AREA(entity, LighthouseArea.x1, LighthouseArea.y1, LighthouseArea.z1, LighthouseArea.x2, LighthouseArea.y2, LighthouseArea.z2, true, true, 0)
		&& gSettings.LightHouseAsDelivery)
	{
		return Lighthouse;
	}
	if (ENTITY::IS_ENTITY_IN_ANGLED_AREA(entity, BeachArea.x1, BeachArea.y1, BeachArea.z1, BeachArea.x2, BeachArea.y2, BeachArea.z2, 45, false, false, 0)
		&& gSettings.BeachAsDelivery)
	{
		return Beach;
	}
	if (ENTITY::IS_ENTITY_IN_AREA(entity, SimeonArea.x1, SimeonArea.y1, SimeonArea.z1, SimeonArea.x2, SimeonArea.y2, SimeonArea.z2, false, false, 0)
		&& gSettings.SimeonAsDelivery)
	{
		if (!gSettings.SimeonStateDuringArmenian && IsInArmenian)
		{
			return none;
		}

		return Simeon;
	}
	if (ENTITY::IS_ENTITY_IN_ANGLED_AREA(entity, PierArea.x1, PierArea.y1, PierArea.z1, PierArea.x2, PierArea.y2, PierArea.z2, 45, false, false, 0)
		&& gSettings.PierAsDelivery)
	{
		if (!gSettings.PierStateDuringDLG && IsInDLG)
		{
			return none;
		}
		return Pier;
	}
	return none;
}




//DEBUG =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- DEBUG =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void DrawBoxArea(DeliveryArea area) {
	GRAPHICS::DRAW_BOX(area.x1, area.y1, area.z1, area.x2, area.y2, area.z2, 2, 120, 120, 100);
}


// =0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0= ORTEGA TRAILER =0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=0=

// First check after load to know if ortega was already delivered in this save.
void SetOrtegaTrailerWasDelivered() {
	const std::string modelName = "PROPTRAILER";
	for (char* a : deliveredVehicles) {
		//"PROPTRAILER"
		if (modelName == a)
		{
			OrtegaTrailerDelivered = true;
			return;
		}
	}
	OrtegaTrailerDelivered = false;
}

Vector3 pos1;
Vector3 pos2;
bool show = false;

void CreateMissingCarsTXTFile()
{
	std::fstream genFileStream;
	genFileStream.open("SSA_MissingVehicles.txt", std::ios::in | std::ios::out | std::ios::trunc);
	if (genFileStream.is_open()) {
		std::list<const char*> genMissingVehicles;
		for (const char* x : fullVehicleList)
		{
			bool found = false;
			for (const char* z : deliveredVehicles)
			{
				if (x == z)
				{
					found = true;
				}
			}
			if (!found)
			{
				genMissingVehicles.push_back(x);
			}

		}

		genFileStream << "Missing Vehicles:\n";
		for (const char* a : genMissingVehicles)
		{
			genFileStream << a;
			genFileStream << '\n';
		}

		genFileStream << '\n';
		genFileStream << "Delivered Vehicles:\n";

		for (const char* b : deliveredVehicles)
		{
			genFileStream << b;
			genFileStream << '\n';
		}
		genFileStream.close();
	}
}

void Update() {

	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- CONSTANTLY USED VARIABLES =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	Ped pPedID = PLAYER::PLAYER_PED_ID();
	Player pID = PLAYER::PLAYER_ID();

	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- MISSION REPLAY TEST =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	// Detect if we started a Mission Replay.
	if (!missionReplayCalled)
		if (lastValueOfToBeLoadedSaveFile.find("MISREP") == std::string::npos && std::string(ToBeLoadedSaveFile).find("MISREP") != std::string::npos)
		{
			OutputDebugString("Mission Replay Started");
			missionReplayCalled = true;
			SaveSystem::SaveProgressForReplay(deliveredVehicles, false, pathToSaveFolder);
		}

	lastValueOfToBeLoadedSaveFile = ToBeLoadedSaveFile;
	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- SAVE LOADING TEST=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	// GTA and ScriptHookV don't have a option to directly check if the player just saved the game manually, only auto saves,
	// this require to investigate the globals and too lazy to do this now, so gonna do this check manually.
	// Did the player open the save menu or auto-save happened?
	// check if any file has been modified, and if it did trigger the save.
	// note for myself: i could also check if the hud element for the save icon is visible.
	if (SCRIPT::_GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT(GAMEPLAY::GET_HASH_KEY((char*)"save_anywhere")) > 0
		|| GAMEPLAY::IS_AUTO_SAVE_IN_PROGRESS())
	{
		// if save was been called or the save menu has been open, test if we can save and try to save into it.
		if (!alreadySaving) {
			alreadySaving = true;
			std::wstring savepath;
			WAIT(200);//GTA needs to finish messing with the file before we do anything.
			SaveSystem::GetSaveFilePath(false, &savepath);
			if (deliveredVehicles.size() > 0) {
				for (char* dah : deliveredVehicles) {
					OutputDebugString(dah);
				}
				SaveSystem::ErrSave err = SaveSystem::SaveProgress(deliveredVehicles, false, savepath);
				if (err == SaveSystem::ErrSave::FileDoesNotExistOrNotBellowBuffer) {
					CreateHelpText((char*)"FileDoesNotExistOrNotBellowBuffer", true);
				}
				else if (err == SaveSystem::ErrSave::SaveDone) {
					CreateHelpText((char*)"Collected Vehicles saved with success...", true);
				}
				else {
					// TODO: if saving error happens make a global backup save.
					CreateHelpText((char*)"Saving error...", true);
				}
			}
			//else
			//{
			//	//CreateHelpText((char*)"Not enough Collected Vehicles to save", true);
			//}
		}
	}
	else
	{
		alreadySaving = false;
	}
	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- USER INTERFACE =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	ShowCollectedAmount();

	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- GENERATE LIST OF MISSING CARS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	bool genList1 = CONTROLS::IS_CONTROL_PRESSED(0, eControl::ControlCover);
	bool genList2 = CONTROLS::IS_CONTROL_PRESSED(0, eControl::ControlReload);

	if (genList1 && genList2) {

		if (genStartTimer)
		{
			if ((GetTickCount() >= genStartPressingTime + genMaxPressingTime) && !genAlreadyCreatingFile)
			{
				genAlreadyCreatingFile = true;
				CreateMissingCarsTXTFile();
			}
		}
		else
		{
			genStartTimer = true;
			genStartPressingTime = GetTickCount();
		}

	}
	else
	{
		genStartTimer = false;
		genAlreadyCreatingFile = false;
	}

	//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-  MISSION SPECIFIC STUFF  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- 

	// i don't like this code, find a better way later...
	IsInArmenian = false;
	IsInDLG = false;

	if (!gSettings.SimeonStateDuringArmenian
		&& (SCRIPT::_GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT(GAMEPLAY::GET_HASH_KEY((char*)"Armenian1")) > 0
			|| SCRIPT::_GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT(GAMEPLAY::GET_HASH_KEY((char*)"Armenian3")) > 0)
		)
	{
		IsInArmenian = true;
	}

	if (!gSettings.PierStateDuringDLG && SCRIPT::_GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT(GAMEPLAY::GET_HASH_KEY((char*)"Family2")) > 0)
	{
		IsInDLG = true;
	}



	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- TRAILERS AND ORTEGA TEST =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	// We want to only call this only once per frame, so have it in a way that can be reused for other parts of the script.
	const int ARR_SIZE = 255;
	Vehicle vehInWorld[ARR_SIZE];
	int vehInWorldCount = worldGetAllVehicles(vehInWorld, ARR_SIZE);
	for (int b = 0; b < vehInWorldCount; b++)
	{
		Vehicle vehTrailerTest = vehInWorld[b];
		if (IsEntityInDeliveryArea(vehTrailerTest) != none)
		{
			if (gSettings.EnableTrailers) {

				for (const char* a : TrailerVehicles)
				{
					if (VEHICLE::IS_VEHICLE_MODEL(vehTrailerTest, GAMEPLAY::GET_HASH_KEY((char*)a)) == TRUE)
					{

						if (!QuickCheckIfDelivered((char*)a))
						{
							ENTITY::SET_ENTITY_AS_MISSION_ENTITY(vehTrailerTest, TRUE, TRUE);
							VEHICLE::DETACH_VEHICLE_FROM_TRAILER(PLAYER::GET_PLAYERS_LAST_VEHICLE());
							VEHICLE::DETACH_VEHICLE_FROM_ANY_TOW_TRUCK(vehTrailerTest);
							QuickAddToDelivered((char*)a);
							VEHICLE::DELETE_VEHICLE(&vehTrailerTest);

							std::string trHelper;
							trHelper += "Trailer Delivered!\n";
							trHelper += "(";
							trHelper += a;
							trHelper += ")";

							CreateHelpText((char*)trHelper.c_str(), true);
						}
						break;
					}
				}
			}

			// Using the trailer loop just so we don't have to create a second loop, is a small optmization.
			if (!OrtegaTrailerDelivered) {
				if (VEHICLE::IS_VEHICLE_MODEL(vehTrailerTest, GAMEPLAY::GET_HASH_KEY((char*)"PROPTRAILER")) == TRUE)
				{
					if (!QuickCheckIfDelivered((char*)"PROPTRAILER"))
					{
						VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(GAMEPLAY::GET_HASH_KEY((char*)"PROPTRAILER"));
						VEHICLE::DETACH_VEHICLE_FROM_TRAILER(PLAYER::GET_PLAYERS_LAST_VEHICLE());
						ENTITY::SET_ENTITY_AS_MISSION_ENTITY(vehTrailerTest, TRUE, TRUE);
						VEHICLE::DETACH_VEHICLE_FROM_ANY_TOW_TRUCK(vehTrailerTest);
						QuickAddToDelivered((char*)"PROPTRAILER");
						VEHICLE::DELETE_VEHICLE(&vehTrailerTest);
						std::string trHelper;
						trHelper += "Ortega Delivered???\n";
						trHelper += "(";
						trHelper += "PROPTRAILER";
						trHelper += ")";
						CreateHelpText((char*)trHelper.c_str(), true);
						UI::_SET_NOTIFICATION_TEXT_ENTRY((char*)"STRING");
						UI::_ADD_TEXT_COMPONENT_STRING((char*)"WHY DID YOU BRING A ENTIRE TRAILER? AND WHY THERE'S A GUY INSIDE IT?");
						UI::_SET_NOTIFICATION_MESSAGE((char*)"CHAR_SIMEON", (char*)"CHAR_SIMEON", false, 4, (char*)"SIMEON", (char*)"What is this?");
						UI::_DRAW_NOTIFICATION(0, 1);
						OrtegaTrailerDelivered = true;
					}
					break;
				}

			}
		}

	}

	//  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- SCRIPT STAGES =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	switch (currentStage)
	{
	case CheckCurrentVehicle:
		// Wait for player to get into a vehicle and check if is valid.
		if (PED::IS_PED_IN_ANY_VEHICLE(pPedID, false))
		{
			// Entering another vehicle after delivering causes the lookingForValidVehicle to be set
			// even if we are inside a valid vehicle.
			// adding this small delay fixes it.
			WAIT(100);

			Vehicle lastDrivenVehicle = PLAYER::GET_PLAYERS_LAST_VEHICLE();
			bool foundValidVehicle = false;
			bool alreadyHave = false;

			// ANTI PARKING LOT ABUSE
			if (gSettings.AntiParkingLotBeach && gSettings.BeachAsDelivery)
			{
				if (LastStolenVehicle != lastDrivenVehicle)
				{
					if (!VEHICLE::_IS_VEHICLE_ENGINE_ON(lastDrivenVehicle))
					{
						Vector3 CurrentCoords = ENTITY::GET_ENTITY_COORDS(pPedID, 0x1);

						float CheatDistance = SYSTEM::VDIST(CurrentCoords.x, CurrentCoords.y, CurrentCoords.z, -1195, -1788, 0);

						if (CheatDistance < 600.0f)
						{
							if (!GAMEPLAY::GET_MISSION_FLAG())
							{
								ParkingAbuseDuringMission = 0x0;
								ENTITY::SET_ENTITY_COORDS(pPedID, CurrentCoords.x, CurrentCoords.y, CurrentCoords.z + 1, 0x0, 0x0, 0x0, 0x0);
								WAIT(1000);
								VEHICLE::EXPLODE_VEHICLE(lastDrivenVehicle, false, true);
								CreateHelpText((char*)"Parking lot abuse detected!", true);
								break;
							}

							else
							{
								ParkingAbuseDuringMission = 0x1;
							}
						}

						else
						{
							ParkingAbuseDuringMission = 0x0;
							LastStolenVehicle = lastDrivenVehicle;
						}

					}

					else
					{
						ParkingAbuseDuringMission = 0x0;
						LastStolenVehicle = lastDrivenVehicle;
					}
				}
			}

			Hash lastDriveModelHash = ENTITY::GET_ENTITY_MODEL(lastDrivenVehicle);

			for (const char* a : fullVehicleList)
			{

				if (VEHICLE::IS_VEHICLE_MODEL(lastDrivenVehicle, GAMEPLAY::GET_HASH_KEY((char*)a)) == TRUE)
				{
					foundValidVehicle = true;
					// The vehicle we have is valid, check the delivered list.
					if (QuickCheckIfDelivered((char*)a))
					{
						alreadyHave = true;
						CreateHelpText((char*)"This vehicle has already been delivered!", false);
						break;
					}

					// This vehicle haven't been delivered, tell the player about it and start the script.
					currentStage = ScriptStage::Delivering;
					CreateHelpText((char*)"This vehicle can be delivered!", true);
					EnableAllDeliveryBlips();
					lastValidVehicle = (char*)a;
					break;
				}
			}

			if (alreadyHave || !foundValidVehicle)
			{
				//Player is in already delivered or vehicle is not in the list, start looking for valid vehicle procedure.
				currentStage = ScriptStage::LookingForValidVehicle;
			}
		}
		else
		{
			// Player is out of vehicle, stop everything.
			DisableAllDeliveryBlips();
		}
		break;

	case LookingForValidVehicle:
		//Player is in invalid vehicle just cycle until he gets out.
		if (!PED::IS_PED_IN_ANY_VEHICLE(pPedID, false)) {
			//Player is not in vehicle, start looking for the next one.
			currentStage = ScriptStage::CheckCurrentVehicle;
		}
		break;

	case Delivering:
		// Player is in a valid vehicle, wait for player to get at the delivery point and do the removing process.
		if (PED::IS_PED_IN_ANY_VEHICLE(pPedID, false))
		{
			// test if player is in delivery area.
			switch (IsEntityInDeliveryArea(pPedID))
			{
			case none:
				break;
			default:
				currentStage = VehicleAtDelivery;
				break;

			}
		}
		else
		{
			// Player got out of vehicle, stop everything.
			DisableAllDeliveryBlips();
			currentStage = ScriptStage::CheckCurrentVehicle;
			lastValidVehicle = (char*)"";
		}
		break;

	case VehicleAtDelivery:
	{ // C2360

		Vehicle lastDriven = PLAYER::GET_PLAYERS_LAST_VEHICLE();
		//vehicle id / stopping distance / time to stop the vehicle for / bool: no idea what it does
		//VEHICLE::_TASK_BRING_VEHICLE_TO_HALT(lastDriven, 5, 5, true); // Stop vehicle
		switch (IsEntityInDeliveryArea(pPedID))
		{
		case none:
			//wut?
			break;
		case Simeon:
			VEHICLE::_TASK_BRING_VEHICLE_TO_HALT(lastDriven, 1, 5, true); // Stop vehicle
			break;
		case Lighthouse:
			WAIT(1000);
			ENTITY::SET_ENTITY_COORDS(pPedID, 3351, 5152, 20, false, false, false, false); // warp to safe zone.
			break;
		case Beach:

			if (gSettings.AntiParkingLotBeach && ParkingAbuseDuringMission)
			{
				Vector3 CurrentCoords = ENTITY::GET_ENTITY_COORDS(pPedID, 0x1);
				ENTITY::SET_ENTITY_COORDS(pPedID, CurrentCoords.x, CurrentCoords.y, CurrentCoords.z + 1, 0x0, 0x0, 0x0, 0x0);

				WAIT(1000);
				VEHICLE::EXPLODE_VEHICLE(lastDriven, false, true);
				CreateHelpText((char*)"Parking lot abuse detected!", true);

				DisableAllDeliveryBlips();
				currentStage = ScriptStage::CheckCurrentVehicle;
				lastValidVehicle = (char*)"";
				return;
			}

			VEHICLE::_TASK_BRING_VEHICLE_TO_HALT(lastDriven, 1, 5, true); // Stop vehicle
			break;
		case Pier:
			VEHICLE::_TASK_BRING_VEHICLE_TO_HALT(lastDriven, 1, 5, true); // Stop vehicle
			break;
		}

		// PLAYER IS IN DELIVERY AREA
		AI::TASK_EVERYONE_LEAVE_VEHICLE(lastDriven);
		//ENTITY::SET_ENTITY_AS_MISSION_ENTITY(lastDriven, true, true); // set current vehicle as a mission entity, so we can delete after.
		currentStage = ScriptStage::DeleteVehicle;
		WAIT(500);
		break;
	}
	case DeleteVehicle:
		// BUG: If SET_PLAYER_MAY_NOT_ENTER_ANY_VEHICLE is after GET_PLAYER_LAST_VEHICLE you can't delete the vehicle
		PLAYER::SET_PLAYER_MAY_NOT_ENTER_ANY_VEHICLE(pID);
		VEHICLE::DETACH_VEHICLE_FROM_TRAILER(PLAYER::GET_PLAYERS_LAST_VEHICLE());
		Vehicle lastDriven = PLAYER::GET_PLAYERS_LAST_VEHICLE();
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(lastDriven, true, true);
		//VS_ANY_PASSENGER = -2,				 //Any passenger seat
		//	VS_DRIVER = -1,						 // Drivers seat
		//	VS_FRONT_RIGHT = 0,					// Front Right seat
		//	VS_BACK_LEFT,						//Back left 	
		//	VS_BACK_RIGHT,						//Back right
		//	VS_EXTRA_LEFT_1,
		//	VS_EXTRA_RIGHT_1,
		//	VS_EXTRA_LEFT_2,
		//	VS_EXTRA_RIGHT_2,
		//	VS_EXTRA_LEFT_3,
		//	VS_EXTRA_RIGHT_3
		bool someoneStillInCar = false;
		for (int x = -2; x < 9; x++)
		{
			//	if (!VEHICLE::IS_VEHICLE_SEAT_FREE(lastDriven, x)) //this function don't work.
			Ped pedinSeat = VEHICLE::GET_PED_IN_VEHICLE_SEAT(lastDriven, x); // returns null/0 if seat don't have anyone.
			if (pedinSeat != NULL) {
				if (pedinSeat == pPedID)
				{
					someoneStillInCar = true;
					continue;
				}

				//flags: WARP PED | DONT CLOSE DOOR | DONT WAIT FOR VEHICLE TO STOP
				AI::TASK_LEAVE_VEHICLE(pedinSeat, lastDriven, 16 | 256 | 64);
				someoneStillInCar = true;
				break;
			}
		}

		if (someoneStillInCar) {
			//Someone still is in the car, emergency remove.
			for (int x = -2; x < 9; x++)
			{
				//	if (!VEHICLE::IS_VEHICLE_SEAT_FREE(lastDriven, x)) //this function don't work.
				Ped pedinSeat = VEHICLE::GET_PED_IN_VEHICLE_SEAT(lastDriven, x); // returns null/0 if seat don't have anyone.
				if (pedinSeat != NULL) {
					if (pedinSeat == pPedID)
					{
						continue;
					}


					Vector3 pedCoords = ENTITY::GET_ENTITY_COORDS(pedinSeat, false);
					ENTITY::SET_ENTITY_COORDS(pedinSeat, pedCoords.x, pedCoords.y, pedCoords.z, true, true, true, true);
					break;
				}
			}
			break;
		}

		// Car is probably free to delete;
		if (!PED::IS_PED_IN_ANY_VEHICLE(pPedID, true)) {
			std::string deliMsg;
			deliMsg += "Vehicle Delivered!";
			deliMsg += "\n(";
			deliMsg += VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(ENTITY::GET_ENTITY_MODEL(lastDriven));
			deliMsg += ")";
			VEHICLE::DETACH_VEHICLE_FROM_ANY_TOW_TRUCK(lastDriven);
			QuickAddToDelivered(lastValidVehicle);
			// BUG: if player is in a hangout, for some random reason the script sets the last driven to null but the vehicle never gets deleted.
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(lastDriven, 0, 0, 0, true, true, true);
			VEHICLE::EXPLODE_VEHICLE(lastDriven, false, true);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&lastDriven);
			//VEHICLE::DELETE_VEHICLE(&lastDriven);
			CreateHelpText((char*)deliMsg.c_str(), true);
			CreateMissingCarsTXTFile();
			currentStage = ScriptStage::CheckCurrentVehicle;
		}

		break;
	}
}

// Reminder to myself: variables set outside of functions are reserved as globals
// they keep their value between transitions and loading screens IF a default value have not been set.
// the code inside the script is reloaded after transitions and loading screens.
void ScriptMain() {
	//Just to make sure everything is correctly loaded.
	LoadHookPointers();
	//Settings
	gSettings.ReadValuesFromSettingsFile();
	FillFullVehicleList();
	// Script got reloaded, try read the save files and see if we should do something.
	LoadCurrentSave();
	WAIT(1000);
	//Check if it was possible to create the file.
	if (!gSettings.DoesSettingsFileExists())
	{
		UI::_SET_NOTIFICATION_TEXT_ENTRY((char*)"STRING");
		UI::_ADD_TEXT_COMPONENT_STRING((char*)"SSASettings.txt file couldn't be created.\nPlease start GTAV as ADMINISTRATOR.");
		UI::_SET_NOTIFICATION_MESSAGE((char*)"CHAR_SIMEON", (char*)"CHAR_SIMEON", false, 4, (char*)"WARNING!", (char*)"");
		UI::_DRAW_NOTIFICATION(0, 1);
	}
	//Check if ortega trailer was delivered
	SetOrtegaTrailerWasDelivered();
	currentStage = ScriptStage::CheckCurrentVehicle;
	while (true) {
		Update();
		WAIT(0);
	}
}
