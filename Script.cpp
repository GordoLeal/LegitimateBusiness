#pragma once
#include "Script.h"
#include "keyboard.h"
#include <cstring>
//taken from Gogsi vehicle spreedsheat.
// Note: Game works with all the model names in caps only for some reason, be carefull with that.
const char* VehiclesList[] =
{
"AIRBUS",
"ADDER"
"AIRTUG",
"AKUMA",
"ALPHA",
"AMBULANCE",
"ARMYTANKER",
"ARMYTRAILER",
"ARMYTRAILER2",
"ASEA",
"ASEA2",
"ASTEROPE",
"BAGGER",
"BALETRAILER",
"BALLER",
"BALLER2",
"BANSHEE",
"BARRACKS",
"BARRACKS2",
"BATI",
"BATI2",
"BENSON",
"BESRA",
"BFINJECTION",
"BIFF",
"BIFTA",
"BISON",
"BISON2",
"BISON3",
"BJXL",
"BLADE",
"BLAZER",
"BLAZER2",
"BLAZER3",
"BLIMP",
"BLIMP2",
"BLISTA",
"BLISTA2",
"BLISTA3",
"BMX",
"BOATTRAILER",
"BOBCATXL",
"BODHI2",
"BOXVILLE",
"BOXVILLE2",
"BOXVILLE3",
"BRAWLER",
"BTYPE",
"BUCCANEER",
"BUFFALO",
"BUFFALO2",
"BUFFALO3",
"BULLDOZER",
"BULLET",
"BURRITO",
"BURRITO2",
"BURRITO3",
"BURRITO4",
"BURRITO5",
"BUS",
"BUZZARD",
"BUZZARD2",
"CABLECAR",
"CADDY",
"CADDY2",
"CAMPER",
"CARBONIZZARE",
"CARBONRS",
"CARGOBOB",
"CARGOBOB2",
"CARGOBOB3",
"CARGOPLANE",
"CAVALCADE",
"CAVALCADE2",
"CHEETAH",
"CHINO",
"COACH",
"COGCABRIO",
"COMET2",
"COQUETTE",
"COQUETTE2",
"COQUETTE3",
"CRUISER",
"CRUSADER",
"CUBAN800",
"CUTTER",
"DAEMON",
"DILETTANTE",
"DILETTANTE2",
"DINGHY",
"DINGHY2",
"DLOADER",
"DOCKTRAILER",
"DOCKTUG",
"DODO",
"DOMINATOR",
"DOMINATOR2",
"DOUBLE",
"DUBSTA",
"DUBSTA2",
"DUBSTA3",
"DUKES",
"DUKES2",
"DUMP",
"DUNE",
"DUNE2",
"DUSTER",
"ELEGY2",
"EMPEROR",
"EMPEROR2",
"EMPEROR3",
"ENTITYXF",
"EXEMPLAR",
"F620",
"FAGGIO2",
"FBI",
"FBI2",
"FELON",
"FELON2",
"FELTZER2",
"FELTZER3",
"FIRETRUK",
"FIXTER",
"FLATBED",
"FORKLIFT",
"FQ2",
"FREIGHT",
"FREIGHTCAR",
"FREIGHTCONT1",
"FREIGHTCONT2",
"FREIGHTGRAIN",
"FREIGHTTRAILER",
"FROGGER",
"FROGGER2",
"FUGITIVE",
"FUROREGT",
"FUSILADE",
"FUTO",
"GAUNTLET",
"GAUNTLET2",
"GBURRITO",
"GLENDALE",
"GRAINTRAILER",
"GRANGER",
"GRESLEY",
"HABANERO",
"HAKUCHOU",
"HANDLER",
"HAULER",
"HEXER",
"HOTKNIFE",
"HUNTLEY",
"INFERNUS",
"INGOT",
"INNOVATION",
"INTRUDER",
"ISSI2",
"JACKAL",
"JB700",
"JESTER",
"JESTER2",
"JET",
"JETMAX",
"JOURNEY",
"KALAHARI",
"LANDSTALKER",
"LAZER",
"LGUARD",
"LUXOR",
"LUXOR2",
"MAMMATUS",
"MANANA",
"MARQUIS",
"MARSHALL",
"MASSACRO",
"MASSACRO2",
"MAVERICK",
"MESA",
"MESA2",
"MESA3",
"METROTRAIN",
"MILJET",
"MINIVAN",
"MIXER",
"MIXER2",
"MONROE",
"MONSTER",
"MOWER",
"MULE",
"MULE2",
"NEMESIS",
"NINEF",
"NINEF2",
"ORACLE",
"ORACLE2",
"OSIRIS",
"PACKER",
"PANTO",
"PARADISE",
"PATRIOT",
"PBUS",
"PCJ",
"PENUMBRA",
"PEYOTE",
"PHANTOM",
"PHOENIX",
"PICADOR",
"PIGALLE",
"POLICE",
"POLICE2",
"POLICE3",
"POLICE4",
"POLICEB",
"POLICEOLD1",
"POLICEOLD2",
"POLICET",
"POLMAV",
"PONY",
"PONY2",
"POUNDER",
"PRAIRIE",
"PRANGER",
"PREDATOR",
"PREMIER",
"PRIMO",
"PROPTRAILER",
"RADI",
"RAKETRAILER",
"RANCHERXL",
"RANCHERXL2",
"RAPIDGT",
"RAPIDGT2",
"RATLOADER",
"RATLOADER2",
"REBEL",
"REBEL2",
"REGINA",
"RENTALBUS",
"RHAPSODY",
"RHINO",
"RIOT",
"RIPLEY",
"ROCOTO",
"ROMERO",
"RUBBLE",
"RUFFIAN",
"RUINER",
"RUMPO",
"RUMPO2",
"SABREGT",
"SADLER",
"SADLER2",
"SANCHEZ",
"SANCHEZ2",
"SANDKING",
"SANDKING2",
"SCHAFTER2",
"SCHWARZER",
"SCORCHER",
"SCRAP",
"SEASHARK",
"SEASHARK2",
"SEMINOLE",
"SENTINEL",
"SENTINEL2",
"SERRANO",
"SHAMAL",
"SHERIFF",
"SHERIFF2",
"SKYLIFT",
"SLAMVAN",
"SOVEREIGN",
"SPEEDER",
"SPEEDO",
"SPEEDO2",
"SQUALO",
"STALION",
"STALION2",
"STANIER",
"STINGER",
"STOCKADE",
"STOCKADE3",
"STRATUM",
"STRETCH",
"STUNT",
"SUBMERSIBLE",
"SUBMERSIBLE2",
"SULTAN",
"SUNTRAP",
"SUPERD",
"SURANO",
"SURFER",
"SURFER2",
"SURGE",
"SWIFT",
"SWIFT2",
"T20",
"TACO",
"TAILGATER",
"TANKER",
"TANKERCAR",
"TAXI",
"THRUST",
"TIPTRUCK",
"TIPTRUCK2",
"TITAN",
"TORNADO",
"TORNADO2",
"TORNADO3",
"TORNADO4",
"TORO",
"TOURBUS",
"TOWTRUCK",
"TOWTRUCK2",
"TR2",
"TR3",
"TR4",
"TRACTOR",
"TRACTOR2",
"TRACTOR3",
"TRAILERLOGS",
"TRAILERS",
"TRAILERS2",
"TRAILERS3",
"TRAILERSMALL",
"TRASH",
"TRFLAT",
"TRIBIKE",
"TRIBIKE2",
"TRIBIKE3",
"TROPIC",
"TURISMOR",
"TVTRAILER",
"UTILLITRUCK",
"UTILLITRUCK2",
"UTILLITRUCK3",
"VACCA",
"VADER",
"VELUM",
"VESTRA",
"VIGERO",
"VINDICATOR",
"VIRGO",
"VOLTIC",
"VOODOO2",
"WARRENER",
"WASHINGTON",
"WINDSOR",
"YOUGA",
"ZENTORNO",
"ZION",
"ZION2",
"ZTYPE"
};
std::list<char*> deliveredVehicles;
//int deliveredVehiclesCount = 0;

static void CreateHelpText(char* text, bool doSound) {
	UI::_SET_TEXT_COMPONENT_FORMAT((char*)"STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DISPLAY_HELP_TEXT_FROM_STRING_LABEL(0, 0, doSound, -1);
}

enum ScriptStage {
	CheckCurrentVehicle,
	LookingForValidVehicle,
	Delivering, //The Truth - Kifflom
	VehicleAtDelivery,
	DeleteVehicle
};

ScriptStage currentStage = ScriptStage::CheckCurrentVehicle;
bool DidWeAlreadyCheckVehicle = false;

struct TestSave
{
	char* test;
};

void TestSaveErr(SaveSystem::ErrSave err) {
	switch (err) {
	case SaveSystem::SaveDone:
		CreateHelpText((char*)"it worked", true);
		break;
	case SaveSystem::FileDoesNotExist:
		CreateHelpText((char*)"file does not exist", true);
		break;
	case SaveSystem::FolderNotFound:
		CreateHelpText((char*)"folder not found", true);
		break;
	case SaveSystem::DocumentsFolderNotFound:
		CreateHelpText((char*)"DocumentsFolderNotFound", true);
		break;
	case SaveSystem::EnhancedFolderEmpty:
		CreateHelpText((char*)"EnhancedFolderEmpty", true);
		break;
	case SaveSystem::EnhancedFolderNotFound:
		CreateHelpText((char*)"EnhancedFolderEmpty", true);
		break;
	case SaveSystem::OldPatchFolderEmpty:
		CreateHelpText((char*)"oldpatch empty", true);
		break;
	case SaveSystem::OldPatchFolderNotFound:
		CreateHelpText((char*)"oldpatchnotfoundd", true);
		break;
	case SaveSystem::AddressToPaternNotFound:
		CreateHelpText((char*)"AddressToPaternNotFound", true);
		break;
	case SaveSystem::CouldNotGetGTAVModule:
		CreateHelpText((char*)"CouldNotGetGTAVModule", true);
		break;
	case SaveSystem::ModuleHandleWasNull:
		CreateHelpText((char*)"ModuleHandleWasNull", true);
		break;
	case SaveSystem::UNK:
		CreateHelpText((char*)"UNK", true);
		break;
	}
}

//Pattern Pointers
intptr_t pSavedSlotNumberPTR;
intptr_t pToBeLoadedSaveFilePTR;
// Return of the pointers
int LastLoadedSaveSlotNumber;
char* ToBeLoadedSaveFile;
//Misc
std::string lastLoadedSaveFile;
std::wstring pathToSaveFolder;
std::string lastValueOfToBeLoadedSaveFile;
//MissionReplay
bool missionReplayCalled;
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

void LoadCurrentSave() {

	// Script got reloaded into prologue, this is probably a new game.
	// Mission replay does not cause a script reload.
	if (SCRIPT::_GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT(GAMEPLAY::GET_HASH_KEY((char*)"Prologue1")) > 0)
	{
		OutputDebugString("New Mission started, cleaning delivered vehicles");
		// Player just loaded a new game.
		// clean everything.
		deliveredVehicles.clear();
	}
	else
	{

		if (missionReplayCalled)
		{
			std::string cmp(ToBeLoadedSaveFile);
			OutputDebugString((cmp + "Testando").c_str());
			if (cmp.find("MISREP000") != std::string::npos) {
				//absolutamente nada.
				OutputDebugString("Absolutamente nada");
			}
			else
			{
				deliveredVehicles.clear();
				SaveSystem::LoadProgress(pathToSaveFolder, LastLoadedSaveSlotNumber, deliveredVehicles);
			}
			// Player just got out of a mission replay and is loading everything back.
			OutputDebugString("Mission replay is over, loading MISREP");

		}
		else
		{

			if (LastLoadedSaveSlotNumber >= 0 && LastLoadedSaveSlotNumber < 15)
			{
				// Player Just loaded a save file.
				// Load user data from that save.
				OutputDebugString("Load Save File...");
				deliveredVehicles.clear();
				SaveSystem::LoadProgress(pathToSaveFolder, LastLoadedSaveSlotNumber, deliveredVehicles);

			}
			else
			{
				OutputDebugString("Load Save File for the first time...");
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
	for (char* v : deliveredVehicles)
	{
		if (_stricmp(v, veh) == 0)
		{
			return true;
		}
	}
	return false;
}
Blip simeonBlip;
Blip countrysideLightHouseBlip;
Blip lifeguardBeachBlip;

void EnableAllDeliveryBlips() {
	//simeonBlip = UI::ADD_BLIP_FOR_COORD(-55, -1112, 26);
	countrysideLightHouseBlip = UI::ADD_BLIP_FOR_COORD(3426, 5174, 7);
	lifeguardBeachBlip = UI::ADD_BLIP_FOR_COORD(-1174, -1773, 3);
	UI::SET_BLIP_FLASHES(countrysideLightHouseBlip, true);
	UI::SET_BLIP_FLASHES(lifeguardBeachBlip, true);
	UI::SET_BLIP_FLASH_TIMER(countrysideLightHouseBlip, 5000);
	UI::SET_BLIP_FLASH_TIMER(lifeguardBeachBlip, 5000);
	UI::SET_BLIP_COLOUR(countrysideLightHouseBlip, 53);
	UI::SET_BLIP_COLOUR(lifeguardBeachBlip, 41);

}

void DisableAllDeliveryBlips() {
	//if (UI::DOES_BLIP_EXIST(simeonBlip))
	//	UI::REMOVE_BLIP(&simeonBlip);
	if (UI::DOES_BLIP_EXIST(countrysideLightHouseBlip))
		UI::REMOVE_BLIP(&countrysideLightHouseBlip);
	if (UI::DOES_BLIP_EXIST(lifeguardBeachBlip))
		UI::REMOVE_BLIP(&lifeguardBeachBlip);
}

void CreateQuickDebugTextThisFrame(char* text) {
	//Draw basic text
	UI::SET_TEXT_FONT(0);
	UI::SET_TEXT_SCALE(0.5f, 0.5f);
	UI::SET_TEXT_WRAP(0.0, 1.0);
	UI::SET_TEXT_CENTRE(1);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::SET_TEXT_SCALE(0, 1);
	UI::_SET_TEXT_ENTRY((char*)"STRING");
	UI::SET_TEXT_COLOUR(255, 255, 255, 255);
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(0.5f, 0.5f);
}

void ShowCollectedAmount() {
	std::string output;
	output += std::to_string(deliveredVehicles.size());
	output += " | ";
	size_t sizeVL = sizeof(VehiclesList) / sizeof(VehiclesList[0]); // i may change the original vehicle list, so this line automate some of the process.
	output += std::to_string(sizeVL);
	//Draw basic text
	UI::SET_TEXT_FONT(0);
	UI::SET_TEXT_SCALE(0.1f, 0.1f);
	UI::SET_TEXT_WRAP(0.0, 1.0);
	UI::SET_TEXT_CENTRE(1);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::SET_TEXT_SCALE(0, 1);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY((char*)"STRING");
	UI::SET_TEXT_COLOUR(255, 255, 255, 255);
	UI::_ADD_TEXT_COMPONENT_STRING((char*)output.c_str());
	UI::_DRAW_TEXT(0.25f, 0.85f);
}

bool alreadySaving = false;
bool wasLoadingScreenActive;
Vector3 TestPos1;
Vector3 TestPos2;
void Update() {

	Ped pPedID = PLAYER::PLAYER_PED_ID();
	Player pID = PLAYER::PLAYER_ID();

	if (IsKeyDown(VK_NUMPAD0))
	{

	}
	if (IsKeyDown(VK_NUMPAD1))
	{

	}
	if (IsKeyDown(VK_NUMPAD2))
	{

	}

	// Detect if we started a Mission Replay.
	if (!missionReplayCalled)
		if (lastValueOfToBeLoadedSaveFile.find("MISREP") == std::string::npos && std::string(ToBeLoadedSaveFile).find("MISREP") != std::string::npos)
		{
			OutputDebugString("Mission Replay Started");
			missionReplayCalled = true;
			SaveSystem::SaveProgressForReplay(deliveredVehicles, false, pathToSaveFolder);
		}

	lastValueOfToBeLoadedSaveFile = ToBeLoadedSaveFile;

	// GTA and ScriptHookV don't have a option to directly check if the player just saved the game manually, only auto saves,
	// this require to investigate the globals and too lazy to do this now, so gonna do this check manually.
	// Did the player open the save menu or auto-save happened?
	// check if any file has been modified, and if it did trigger the save.
	// note for myself: i could also check if the hud element for the save icon is visible.
	if (SCRIPT::_GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT(GAMEPLAY::GET_HASH_KEY((char*)"save_anywhere")) > 0 || GAMEPLAY::IS_AUTO_SAVE_IN_PROGRESS())
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
			else
			{
				CreateHelpText((char*)"Not enough Collected Vehicles to save", true);
			}
		}
	}
	else
	{
		alreadySaving = false;
	}
	
	ShowCollectedAmount();

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
			for (const char* a : VehiclesList)
			{
				if (VEHICLE::IS_VEHICLE_MODEL(lastDrivenVehicle, GAMEPLAY::GET_HASH_KEY((char*)a)) == TRUE) {
					foundValidVehicle = true;
					// The vehicle we have is valid, check the delivered list.
					OutputDebugStringA("Player is in:");
					OutputDebugStringA(a);
					if (QuickCheckIfDelivered((char*)a)) {
						alreadyHave = true;
						CreateHelpText((char*)"Vehicle already delivered", false);
						break;
					}
					// This vehicle haven't been delivered, tell the player about it and start the script.
					currentStage = ScriptStage::Delivering;
					CreateHelpText((char*)"This vehicle can be delivered to the drop point", true);
					EnableAllDeliveryBlips();
					break;
				}
			}

			if (alreadyHave || !foundValidVehicle) {
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
			//if (ENTITY::IS_ENTITY_IN_AREA(pPedID, -59, -1104, 25, -39, -1120, 28, false, false, 0)) // Simeon Dealership
			// Countryside Lighthouse | Lifeguard tower
			// Countryside Lighthouse: xyz | Pos 1: 3407, 5193, -1 | Pos 2: 3451, 5150, 45
			//LifeguardTower: xyz |Pos 1: -1165, -1807, 25 | Pos 2: -1217,-1766 , -1
			if (ENTITY::IS_ENTITY_IN_AREA(pPedID, 3407, 5193, -1, 3451, 5150, 45, false, false, -1) || ENTITY::IS_ENTITY_IN_AREA(pPedID, -1165, -1807, 25, -1217, -1766, -1, false, false, 0))
			{

				currentStage = VehicleAtDelivery;
			}
		}
		else
		{
			// Player got out of vehicle, stop everything.
			if (simeonBlip != NULL) {
				UI::REMOVE_BLIP(&simeonBlip);
			}
			currentStage = ScriptStage::CheckCurrentVehicle;
		}
		break;

	case VehicleAtDelivery:
	{ // C2360
		Vehicle lastDriven = PLAYER::GET_PLAYERS_LAST_VEHICLE();
		//VEHICLE::GET_PED_IN_VEHICLE_SEAT(eVehicleSeat::VehicleSeatAny);
		AI::TASK_EVERYONE_LEAVE_VEHICLE(lastDriven);
		//char* vehiclename = VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(ENTITY::GET_ENTITY_MODEL(lastDriven));
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(lastDriven, true, true); // set current vehicle as a mission entity, so we can delete after.
		// GTA missions scripts = const float DEFAULT_VEH_STOPPING_DISTANCE = 10.5
		//vehicle id / stopping distance / time to stop the vehicle for / bool: no idea what it does
		VEHICLE::_TASK_BRING_VEHICLE_TO_HALT(lastDriven, 1, 10, true); // Stop vehicle
		//PED::KNOCK_PED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID()); // kick player from vehicle
		//AI::TASK_LEAVE_VEHICLE(PLAYER::PLAYER_PED_ID(), lastDriven, 0);

		currentStage = ScriptStage::DeleteVehicle;
		break;
	}
	case DeleteVehicle:
		// BUG: If SET_PLAYER_MAY_NOT_ENTER_ANY_VEHICLE is after GET_PLAYER_LAST_VEHICLE you can't delete the vehicle
		PLAYER::SET_PLAYER_MAY_NOT_ENTER_ANY_VEHICLE(pID);
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
			//Someone still is in the car, test next frame.
			break;
		}
		OutputDebugString("Testing PLayer is in vehicle");
		// Car is probably free to delete;
		if (!PED::IS_PED_IN_ANY_VEHICLE(pPedID, true)) {
			Entity attachedVehicle = VEHICLE::GET_ENTITY_ATTACHED_TO_TOW_TRUCK(lastDriven);
			if (attachedVehicle != -1) {
				VEHICLE::DETACH_VEHICLE_FROM_TOW_TRUCK(lastDriven, attachedVehicle);
			}
			VEHICLE::DETACH_VEHICLE_FROM_ANY_TOW_TRUCK(lastDriven);
			char* vehiclename = VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(ENTITY::GET_ENTITY_MODEL(lastDriven));
			QuickAddToDelivered(vehiclename);
			// BUG: if player is in a hangout, for some random reason the script sets the last driven to null but the vehicle never gets deleted.
			//VEHICLE::EXPLODE_VEHICLE(lastDriven, false, true);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(lastDriven, 0, 0, 0, true, true, true);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&lastDriven);
			//VEHICLE::DELETE_VEHICLE(&lastDriven);
			//Just in case the car still somewhere...
			lastDriven = PLAYER::GET_PLAYERS_LAST_VEHICLE();
			if (lastDriven != 0)
			{
				OutputDebugString("not null");
			}
			else
			{
				OutputDebugString("is null");
			}
			CreateHelpText((char*)"Vehicle delivered!", true);


			currentStage = ScriptStage::CheckCurrentVehicle;
		}

		break;
	}

	//Random Ideas - Delete later
	// 			//ENUM VEHICLE_SEAT
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
	//Vector3 a = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	//std::string textcomplet = "X: " + std::to_string(a.x) + " | Y: " + std::to_string(a.y) + " | Z: " + std::to_string(a.z);
	//CreateQuickDebugTextThisFrame((char*)textcomplet.c_str());
	//Vehicle lastdrivenvehicle = PLAYER::GET_PLAYERS_LAST_VEHICLE();
	////float vehiclehealth = VEHICLE::GET_VEHICLE_BODY_HEALTH(lastdrivenvehicle);
	////int vehicleClass = VEHICLE::GET_VEHICLE_LAYOUT_HASH(lastdrivenvehicle);
	//Hash h = GAMEPLAY::GET_HASH_KEY((char*)"taxi");
	//textcomplet = textcomplet + "\nlast driven vehicle: " + std::to_string(lastdrivenvehicle) + "\n TAXI HASH NAME:" + std::to_string(h);
	//if (VEHICLE::IS_VEHICLE_MODEL(lastdrivenvehicle, h) == TRUE) {

	//	UI::_SET_TEXT_COMPONENT_FORMAT((char*)"STRING");
	//	UI::_ADD_TEXT_COMPONENT_STRING((char*)textcomplet.c_str());
	//	UI::_DISPLAY_HELP_TEXT_FROM_STRING_LABEL(0, 0, 0, -1);
	//}
	//VEHICLE::IS_VEHICLE_MODEL();
	//STREAMING::IS_MODEL_A_VEHICLE();
	//ENTITY::GET_ENTITY_MODEL(); // Hash model of a entity. now how to get a entity from a vehicle
	//draw help text
}

// Reminder to myself: variables set outside of functions are reserved as globals
// they keep their value between transitions and loading screens IF a default value have not been set.
// the code inside the script is reloaded after transitions and loading screens.
void ScriptMain() {
	//Just to make sure everything is correctly loaded.
	LoadHookPointers();
	// Script got reloaded, try read the save files and see if we should do something.
	LoadCurrentSave();
	WAIT(1000);
	currentStage = ScriptStage::CheckCurrentVehicle;
	while (true) {
		Update();
		WAIT(0);
	}
}