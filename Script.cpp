#pragma once
#include "Script.h"
#include "keyboard.h"
//#include <cstring>
//taken from Gogsi vehicle spreedsheat.
// Note: Game works with all the model names in caps only for some reason, be carefull with that.
const char* VehiclesList[] =
{
"ADDER",
"AIRBUS",
"AIRTUG",
"AKUMA",
"ALPHA",
"AMBULANCE",
//"ARMYTANKER",  //Trailer
//"ARMYTRAILER", //Trailer
//"ARMYTRAILER2", //Trailer
"ASEA",
//"ASEA2", // North Yankton
"ASTEROPE",
"BAGGER",
//"BALETRAILER", //Trailer - Cut from the game
"BALLER",
"BALLER2",
"BANSHEE",
"BARRACKS",
"BARRACKS2",
"BATI",
"BATI2",
"BENSON",
//"BESRA", // plane
"BFINJECTION",
"BIFF",
"BIFTA",
"BISON",
"BISON2", // Bison with another texture
"BISON3", // Bison with another color
"BJXL",
"BLADE",
"BLAZER",
"BLAZER2",
"BLAZER3",
//"BLIMP", // FLYING if returning player bonus is active: you can't spawn it, unless you take it from the air.
//"BLIMP2", // FLYING returning player bonus
"BLISTA",
"BLISTA2",
"BLISTA3",
"BMX",
//"BOATTRAILER", //Trailer
"BOBCATXL",
"BODHI2",
"BOXVILLE",
"BOXVILLE2",
"BOXVILLE3", // One time mission
//"BRAWLER", //not available in 1.27
"BTYPE",
"BUCCANEER",
"BUFFALO",
"BUFFALO2",
"BUFFALO3", //returnig player bonus
"BULLDOZER",
"BULLET",
"BURRITO",
"BURRITO2",
"BURRITO3",
//"BURRITO4", // Cut from the game in the enhanced version, only used in online
//"BURRITO5", // North Yankton
"BUS",
//"BUZZARD", //FLYING
//"BUZZARD2", //FLYING
//"CABLECAR", // you can't drive it
"CADDY",
"CADDY2",
"CAMPER",
"CARBONIZZARE",
"CARBONRS",
//"CARGOBOB", //FLYING
//"CARGOBOB2", //FLYING //just a reskin but you can buy
//"CARGOBOB3", //FLYING // cargobob (TPI) just a reskin
//"CARGOPLANE", //FLYING
"CAVALCADE",
"CAVALCADE2",
"CHEETAH",
//"CHINO", //Not available in 1.27
"COACH",
"COGCABRIO",
"COMET2",
"COQUETTE",
"COQUETTE2",
//"COQUETTE3", //Not available in 1.27
"CRUISER",
"CRUSADER",
//"CUBAN800", //FLYING
"CUTTER", //Only available in the big score
"DAEMON",
"DILETTANTE",
"DILETTANTE2", //spawns in Davis Quartz zone at night.
"DINGHY",
"DINGHY2",
"DLOADER",
//"DOCKTRAILER",
"DOCKTUG",
//"DODO", //FLYING // Returning Player
"DOMINATOR",
"DOMINATOR2", //Returning Player
"DOUBLE",
"DUBSTA",
//"DUBSTA2", //just a recolor
"DUBSTA3",
"DUKES",
"DUKES2",
"DUMP",
"DUNE",
"DUNE2",
//"DUSTER", //FLYING
//"ELEGY2", //could not find in 1.27. only reference i could find is Rockstar club exclusive?
"EMPEROR",
"EMPEROR2",
//"EMPEROR3", // North Yankton
"ENTITYXF",
"EXEMPLAR",
"F620",
"FAGGIO2",
//"FBI", // Impossible to obtain: https://www.reddit.com/r/GrandTheftAutoV/comments/gj250w/fib_buffalo_unmarked_cruiser_are_no_longer/
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
//"FREIGHT", //Train
//"FREIGHTCAR", //Train
//"FREIGHTCONT1", //Train
//"FREIGHTCONT2", //Train
//"FREIGHTGRAIN", //Train
//"FREIGHTTRAILER", //TRAILER
//"FROGGER", //FLYING
//"FROGGER2", //FLYING
"FUGITIVE",
"FUROREGT",
"FUSILADE",
"FUTO",
"GAUNTLET",
"GAUNTLET2", //Returning Player
"GBURRITO",
"GLENDALE",
//"GRAINTRAILER", //Trailer
"GRANGER",
"GRESLEY",
"HABANERO",
"HAKUCHOU",
//"HANDLER", //Not Possible to reach delivery point
"HAULER",
"HEXER",
"HOTKNIFE", //Returning Player
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
//"JET", //FLYING
//"JETMAX", //WATER
"JOURNEY",
"KALAHARI",
"LANDSTALKER",
//"LAZER", //FLYING
"LGUARD",
//"LUXOR", //FLYING
//"LUXOR2", //FLYING
//"MAMMATUS", //FLYING
"MANANA",
//"MARQUIS", //WATER
"MARSHALL",
"MASSACRO",
"MASSACRO2", //Returning Player Bonus
//"MAVERICK", //FLYING
"MESA",
//"MESA2", // North Yankton
"MESA3",
//"METROTRAIN", //Train
//"MILJET", //FLYING
"MINIVAN",
"MIXER",
"MIXER2",
"MONROE",
"MONSTER",
"MOWER",
"MULE",
//"MULE2", // ONLINE ONLY
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
//"POLICEOLD1", //North Yankton
//"POLICEOLD2", //North Yankton
"POLICET",
"POLMAV",
"PONY",
//"PONY2", //Just a different texture
"POUNDER",
"PRAIRIE",
"PRANGER",
//"PREDATOR", //WATER
"PREMIER",
"PRIMO",
//"PROPTRAILER", //Good luck trying to deliver Ortega's trailer.
"RADI",
//"RAKETRAILER", //can't drive
"RANCHERXL",
//"RANCHERXL2", //North Yankton
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
//"SADLER2", //North Yankton
"SANCHEZ",
"SANCHEZ2",
"SANDKING",
"SANDKING2",
"SCHAFTER2",
"SCHWARZER",
"SCORCHER",
"SCRAP",
//"SEASHARK",// WATER
//"SEASHARK2", //Lifeguard seashark - Just a different texture
"SEMINOLE",
"SENTINEL",
"SENTINEL2",
"SERRANO",
//"SHAMAL", //FLYING
"SHERIFF",
"SHERIFF2",
//"SKYLIFT", //FLYING - Can't obtain outside of a setup for big score
"SLAMVAN",
"SOVEREIGN",
//"SPEEDER", //WATER
"SPEEDO",
"SPEEDO2",
//"SQUALO", //WATER
"STALION",
"STALION2",
"STANIER",
"STINGER",
"STOCKADE",
//"STOCKADE3", //Cut from the game
"STRATUM",
"STRETCH",
//"STUNT", //FLYING
//"SUBMERSIBLE", //WATER
//"SUBMERSIBLE2", //WATER
"SULTAN",
//"SUNTRAP", //WATER
"SUPERD",
"SURANO",
"SURFER",
"SURFER2",
"SURGE",
//"SWIFT", //FLYING
//"SWIFT2", //FLYING
"T20",
"TACO",
"TAILGATER",
//"TANKER", //Trailer
//"TANKERCAR", //TRAILER
"TAXI",
"THRUST",
"TIPTRUCK",
"TIPTRUCK2",
//"TITAN", //FLYING
"TORNADO",
"TORNADO2",
"TORNADO3",
"TORNADO4",
//"TORO", //WATER
"TOURBUS",
"TOWTRUCK",
"TOWTRUCK2",
//"TR2", //Trailer
//"TR3", //Trailer
//"TR4", //Trailer
"TRACTOR",
"TRACTOR2",
//"TRACTOR3", //North Yankton
//"TRAILERLOGS", //Trailer
//"TRAILERS", //Trailer
//"TRAILERS2", //Trailer
//"TRAILERS3", //Trailer
//"TRAILERSMALL", //Trailer
"TRASH",
//"TRFLAT", //Trailer
"TRIBIKE",
"TRIBIKE2", //Just another Texture
"TRIBIKE3", // Just Another Texture
//"TROPIC", //WATER
"TURISMOR",
//"TVTRAILER", //Trailer
"UTILLITRUCK",
"UTILLITRUCK2",
"UTILLITRUCK3",
"VACCA",
"VADER",
//"VELUM", //FLYING
//"VESTRA", //FLYING
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

const char* TrailerVehicles[] =
{
"ARMYTANKER",  //Trailer
"ARMYTRAILER", //Trailer
//"ARMYTRAILER2", //Trailer - Exclusive to mission setup big score
//"BALETRAILER", // Does not exist
"BOATTRAILER", //Trailer
"DOCKTRAILER",
"GRAINTRAILER", //Trailer
"TANKER", //Trailer
//"TANKERCAR", //TRAIN
"TR2", //Trailer
"TR3", //Trailer
"TR4", //Trailer
"TRAILERLOGS", //Trailer
"TRAILERS", //Trailer
"TRAILERS2", //Trailer
"TRAILERS3", //Trailer
"TRAILERSMALL", //Trailer
"TRFLAT", //Trailer
//"TVTRAILER", //Trailer - Need glitch to leave mission area
"FREIGHTTRAILER" //TRAILER
};

const char* FlyingVehicles[] =
{
"BESRA",
"BLIMP", // if returning player bonus is active: you can't spawn it, unless you take it from the air.
"BLIMP2", //returning player bonus
"BUZZARD",
"BUZZARD2",
"CARGOBOB",
"CARGOBOB2", //just a reskin but you can buy
"CARGOBOB3", // cargobob (TPI) just a reskin
"CARGOPLANE",
"CUBAN800",
"DODO", // Returning Player
"DUSTER", //FLYING
"FROGGER", //FLYING
"FROGGER2", //FLYING - Reskin
"JET", //FLYING
"LAZER", //FLYING
"LUXOR", //FLYING
"LUXOR2", //FLYING
"MAMMATUS", //FLYING
"MAVERICK", //FLYING
"MILJET", //FLYING
"SHAMAL", //FLYING
//"SKYLIFT", //FLYING - Can't obtain outside of a setup for big score
"STUNT", //FLYING
"SWIFT", //FLYING
"SWIFT2", //FLYING
"TITAN", //FLYING
"VELUM", //FLYING
"VESTRA" //FLYING
};

const char* WaterVehicles[] =
{
	"JETMAX", //WATER
	"MARQUIS", //WATER
	"PREDATOR", //WATER
"SEASHARK",// WATER
//"SEASHARK2", //Lifeguard seashark - Just a different texture
"SPEEDER", //WATER
"SQUALO", //WATER
"SUBMERSIBLE", //WATER
"SUBMERSIBLE2", //WATER
"SUNTRAP", //WATER
"TORO", //WATER
"TROPIC" //WATER
};

std::list<char*> deliveredVehicles;
std::list<const char*> fullVehicleList;
//int deliveredVehiclesCount = 0;
enum ScriptStage {
	CheckCurrentVehicle,
	LookingForValidVehicle,
	Delivering, //The Truth - Kifflom
	VehicleAtDelivery,
	DeleteVehicle
};

ScriptStage currentStage = ScriptStage::CheckCurrentVehicle;
//bool DidWeAlreadyCheckVehicle = false;

static void CreateHelpText(char* text, bool doSound) {
	UI::_SET_TEXT_COMPONENT_FORMAT((char*)"STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DISPLAY_HELP_TEXT_FROM_STRING_LABEL(0, 0, doSound, -1);
}
//void TestSaveErr(SaveSystem::ErrSave err) {
//	switch (err) {
//	case SaveSystem::SaveDone:
//		CreateHelpText((char*)"it worked", true);
//		break;
//	case SaveSystem::FileDoesNotExist:
//		CreateHelpText((char*)"file does not exist", true);
//		break;
//	case SaveSystem::FolderNotFound:
//		CreateHelpText((char*)"folder not found", true);
//		break;
//	case SaveSystem::DocumentsFolderNotFound:
//		CreateHelpText((char*)"DocumentsFolderNotFound", true);
//		break;
//	case SaveSystem::EnhancedFolderEmpty:
//		CreateHelpText((char*)"EnhancedFolderEmpty", true);
//		break;
//	case SaveSystem::EnhancedFolderNotFound:
//		CreateHelpText((char*)"EnhancedFolderEmpty", true);
//		break;
//	case SaveSystem::OldPatchFolderEmpty:
//		CreateHelpText((char*)"oldpatch empty", true);
//		break;
//	case SaveSystem::OldPatchFolderNotFound:
//		CreateHelpText((char*)"oldpatchnotfoundd", true);
//		break;
//	case SaveSystem::AddressToPaternNotFound:
//		CreateHelpText((char*)"AddressToPaternNotFound", true);
//		break;
//	case SaveSystem::CouldNotGetGTAVModule:
//		CreateHelpText((char*)"CouldNotGetGTAVModule", true);
//		break;
//	case SaveSystem::ModuleHandleWasNull:
//		CreateHelpText((char*)"ModuleHandleWasNull", true);
//		break;
//	case SaveSystem::UNK:
//		CreateHelpText((char*)"UNK", true);
//		break;
//	}
//}

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
Settings gSettings;
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

void FillFullVehicleList()
{
	fullVehicleList.clear();
	for (const char* a : VehiclesList) {
		fullVehicleList.push_back(a);
	}
	if (gSettings.EnableFlyingVehicles) {
		for (const char* b : FlyingVehicles) {
			fullVehicleList.push_back(b);
		}
	}
	if (gSettings.EnableWaterVehicles) {
		for (const char* c : WaterVehicles) {
			fullVehicleList.push_back(c);
		}
	}
	if (gSettings.EnableTrailers) {
		for (const char* c : WaterVehicles) {
			fullVehicleList.push_back(c);
		}
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
				//Nothing is needed
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
	std::string a(veh);
	for (char* v : deliveredVehicles)
	{
		if (a.compare(v) == 0) {
			return true;
		}
	}
	return false;
}

Blip simeonBlip;
Blip countrysideLightHouseBlip;
Blip lifeguardBeachBlip;

void EnableAllDeliveryBlips()
{

	if (gSettings.BeachAsDelivery) {
		lifeguardBeachBlip = UI::ADD_BLIP_FOR_COORD(-1174, -1773, 3);
		UI::SET_BLIP_FLASHES(lifeguardBeachBlip, true);
		UI::SET_BLIP_FLASH_TIMER(lifeguardBeachBlip, 5000);
		UI::SET_BLIP_COLOUR(lifeguardBeachBlip, 41);
	}

	if (gSettings.LightHouseAsDelivery)
	{
		countrysideLightHouseBlip = UI::ADD_BLIP_FOR_COORD(3426, 5174, 7);
		UI::SET_BLIP_FLASHES(countrysideLightHouseBlip, true);
		UI::SET_BLIP_FLASH_TIMER(countrysideLightHouseBlip, 5000);
		UI::SET_BLIP_COLOUR(countrysideLightHouseBlip, 53);
	}
	if (gSettings.SimeonAsDelivery)
	{
		simeonBlip = UI::ADD_BLIP_FOR_COORD(-55, -1112, 26);
		UI::SET_BLIP_FLASHES(simeonBlip, true);
		UI::SET_BLIP_FLASH_TIMER(simeonBlip, 5000);
		UI::SET_BLIP_COLOUR(simeonBlip, BlipColorGreen);
	}

}

void DisableAllDeliveryBlips() {
	if (UI::DOES_BLIP_EXIST(simeonBlip))
		UI::REMOVE_BLIP(&simeonBlip);
	if (UI::DOES_BLIP_EXIST(countrysideLightHouseBlip))
		UI::REMOVE_BLIP(&countrysideLightHouseBlip);
	if (UI::DOES_BLIP_EXIST(lifeguardBeachBlip))
		UI::REMOVE_BLIP(&lifeguardBeachBlip);
}

//bool TestIfVehicleIsValid(Hash veh) {
//	bool valid = false;
//	if ((VEHICLE::IS_THIS_MODEL_A_HELI(veh) && gSettings.EnableFlyingVehicles) || (VEHICLE::IS_THIS_MODEL_A_PLANE(veh) && gSettings.EnableFlyingVehicles))
//	{
//		valid = true;
//	}
//	else if (VEHICLE::IS_THIS_MODEL_A_BOAT(veh) && gSettings.EnableWaterVehicles) {
//		valid = true;
//	}
//	return valid;
//}

//void CreateQuickDebugTextThisFrame(char* text) {
//	//Draw basic text
//	UI::SET_TEXT_FONT(0);
//	UI::SET_TEXT_SCALE(0.5f, 0.5f);
//	UI::SET_TEXT_WRAP(0.0, 1.0);
//	UI::SET_TEXT_CENTRE(1);
//	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
//	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
//	UI::SET_TEXT_SCALE(0, 1);
//	UI::_SET_TEXT_ENTRY((char*)"STRING");
//	UI::SET_TEXT_COLOUR(255, 255, 255, 255);
//	UI::_ADD_TEXT_COMPONENT_STRING(text);
//	UI::_DRAW_TEXT(0.5f, 0.5f);
//}

void ShowCollectedAmount() {
	std::string output;
	output += std::to_string(deliveredVehicles.size());
	output += " | ";
	output += std::to_string(fullVehicleList.size());
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
std::string lastValidVehicle = std::string("");

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
	Lighthouse
};

const DeliveryArea SimeonArea = { -38, -1102, -1, -60, -1120, 35 };
const DeliveryArea LighthouseArea = { 3459, 5148, 45, 3369, 5197, -1 };
const DeliveryArea BeachArea = { -1165, -1807, 25, -1223, -1761, -1 };

StatusEntityInArea IsEntityInDeliveryArea(Entity entity) {

	if (ENTITY::IS_ENTITY_IN_ANGLED_AREA(entity, LighthouseArea.x1, LighthouseArea.y1, LighthouseArea.z1, LighthouseArea.x2, LighthouseArea.y2, LighthouseArea.z2, 0, true, true, 0)
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
		return Simeon;
	}
	return none;
}

//DEBUG =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- DEBUG =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//void DrawBoxArea(DeliveryArea area) {
//	GRAPHICS::DRAW_BOX(area.x1, area.y1, area.z1, area.x2, area.y2, area.z2, 2, 120, 120, 100);
//}


void Update() {
	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- CONSTANTLY USED VARIABLES =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	Ped pPedID = PLAYER::PLAYER_PED_ID();
	Player pID = PLAYER::PLAYER_ID();

	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- DEBUG =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	//if (IsKeyDown(VK_NUMPAD0))
	//{
	//	DrawBoxArea(SimeonArea);
	//	DrawBoxArea(LighthouseArea);
	//	DrawBoxArea(BeachArea);
	//}
	//if (IsKeyJustUp(VK_NUMPAD1))
	//{
	//	//Taken from the nativetrainer
	//	// get entity to teleport
	//	Entity e = PLAYER::PLAYER_PED_ID();
	//	if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
	//		e = PED::GET_VEHICLE_PED_IS_USING(e);

	//	// get coords
	//	Vector3 coords;
	//	bool success = false;
	//	bool blipFound = false;
	//	// search for marker blip
	//	int blipIterator = UI::_GET_BLIP_INFO_ID_ITERATOR();
	//	for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator); UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator))
	//	{
	//		if (UI::GET_BLIP_INFO_ID_TYPE(i) == 4)
	//		{
	//			coords = UI::GET_BLIP_INFO_ID_COORD(i);
	//			blipFound = true;
	//			break;
	//		}
	//	}
	//	if (blipFound)
	//	{
	//		// load needed map region and check height levels for ground existence
	//		bool groundFound = false;
	//		static float groundCheckHeight[] = {
	//			100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0,
	//			450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0
	//		};
	//		for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	//		{
	//			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
	//			WAIT(100);
	//			if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, FALSE))
	//			{
	//				groundFound = true;
	//				coords.z += 3.0;
	//				break;
	//			}
	//		}
	//		// if ground not found then set Z in air and give player a parachute
	//		if (!groundFound)
	//		{
	//			coords.z = 100.0;
	//			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY((char*)"GADGET_PARACHUTE"), 1, 0);
	//		}
	//		success = true;
	//	}
	//}

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
	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- USER INTERFACE =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

	ShowCollectedAmount();

	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- TRAILERS TEST =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
	//Test if we have trailers inside the zone.

	if (gSettings.EnableTrailers)
	{
		const int ARR_SIZE = 255;
		Vehicle vehInWorld[ARR_SIZE];
		int vehInWorldCount = worldGetAllVehicles(vehInWorld, ARR_SIZE);
		for (int b = 0; b < vehInWorldCount; b++)
		{
			Vehicle vehTrailerTest = vehInWorld[b];
			/*if ((ENTITY::IS_ENTITY_IN_ANGLED_AREA(vehTrailerTest, LighthouseArea.x1, LighthouseArea.y1, LighthouseArea.z1, LighthouseArea.x2, LighthouseArea.y2, LighthouseArea.z2,0, true, true, 0)
				&& gSettings.LightHouseAsDelivery)
				|| (ENTITY::IS_ENTITY_IN_ANGLED_AREA(vehTrailerTest, BeachArea.x1, BeachArea.y1, BeachArea.z1, BeachArea.x2, BeachArea.y2, BeachArea.z2,45, false, false, 0)
					&& gSettings.BeachAsDelivery)
				|| (ENTITY::IS_ENTITY_IN_AREA(vehTrailerTest, SimeonArea.x1, SimeonArea.y1, SimeonArea.z1, SimeonArea.x2, SimeonArea.y2, SimeonArea.z2, false, false, 0)
					&& gSettings.SimeonAsDelivery)
				)*/
			if (IsEntityInDeliveryArea(vehTrailerTest) != none)
			{
				for (const char* a : TrailerVehicles)
				{
					if (VEHICLE::IS_VEHICLE_MODEL(vehTrailerTest, GAMEPLAY::GET_HASH_KEY((char*)a)) == TRUE)
					{

						if (!QuickCheckIfDelivered((char*)a))
						{
							VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(GAMEPLAY::GET_HASH_KEY((char*)a));
							VEHICLE::DETACH_VEHICLE_FROM_TRAILER(PLAYER::GET_PLAYERS_LAST_VEHICLE());
							ENTITY::SET_ENTITY_AS_MISSION_ENTITY(vehTrailerTest, TRUE, TRUE);
							VEHICLE::DETACH_VEHICLE_FROM_ANY_TOW_TRUCK(vehTrailerTest);
							QuickAddToDelivered((char*)a);
							VEHICLE::DELETE_VEHICLE(&vehTrailerTest);
							std::string trHelper;
							trHelper += "Trailer Delivered to Simeon!";
							trHelper += "(";
							trHelper += a;
							trHelper += ")";
							CreateHelpText((char*)trHelper.c_str(), true);
						}
						break;
					}
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

			Hash lastDriveModelHash = ENTITY::GET_ENTITY_MODEL(lastDrivenVehicle);
			VEHICLE::GET_VEHICLE_CLASS_FROM_NAME(lastDriveModelHash);
			OutputDebugString("player last drive model hash:");
			OutputDebugString(std::to_string(lastDriveModelHash).c_str());

			for (const char* a : fullVehicleList)
			{

				if (VEHICLE::IS_VEHICLE_MODEL(lastDrivenVehicle, GAMEPLAY::GET_HASH_KEY((char*)a)) == TRUE)
				{
					foundValidVehicle = true;
					// The vehicle we have is valid, check the delivered list.
					if (QuickCheckIfDelivered((char*)a)) {
						alreadyHave = true;
						CreateHelpText((char*)"Simeon already has this vehicle!", false);
						break;
					}

					// This vehicle haven't been delivered, tell the player about it and start the script.
					currentStage = ScriptStage::Delivering;
					CreateHelpText((char*)"This vehicle can be delivered to Simeon!", true);
					EnableAllDeliveryBlips();
					lastValidVehicle = a;
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
			/*if (
				(ENTITY::IS_ENTITY_IN_AREA(pPedID, LighthouseArea.x1, LighthouseArea.y1, LighthouseArea.z1, LighthouseArea.x2, LighthouseArea.y2, LighthouseArea.z2, false, true, 0)
					&& gSettings.LightHouseAsDelivery)
				|| (ENTITY::IS_ENTITY_IN_ANGLED_AREA(pPedID, BeachArea.x1, BeachArea.y1, BeachArea.z1, BeachArea.x2, BeachArea.y2, BeachArea.z2,45, false, true, 0)
					&& gSettings.BeachAsDelivery)
				|| (ENTITY::IS_ENTITY_IN_AREA(pPedID, SimeonArea.x1, SimeonArea.y1, SimeonArea.z1, SimeonArea.x2, SimeonArea.y2, SimeonArea.z2, false, true, 0)
					&& gSettings.SimeonAsDelivery)
				)
			{
				currentStage = VehicleAtDelivery;
			}*/
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
		}
		break;

	case VehicleAtDelivery:
	{ // C2360
		Vehicle lastDriven = PLAYER::GET_PLAYERS_LAST_VEHICLE();
		//vehicle id / stopping distance / time to stop the vehicle for / bool: no idea what it does
		//VEHICLE::_TASK_BRING_VEHICLE_TO_HALT(lastDriven, 5, 5, true); // Stop vehicle
		switch (IsEntityInDeliveryArea(lastDriven))
		{
		case none:
			//wut?
			break;
		case Simeon:
			VEHICLE::_TASK_BRING_VEHICLE_TO_HALT(lastDriven, 1, 5, true); // Stop vehicle
			break;
		case Lighthouse:
			WAIT(1000);
			ENTITY::SET_ENTITY_COORDS(pPedID, 3351, 5152, 20, false, false, false, false);
			break;
		case Beach:
			VEHICLE::_TASK_BRING_VEHICLE_TO_HALT(lastDriven, 1, 5, true); // Stop vehicle
			break;
		}

		AI::TASK_EVERYONE_LEAVE_VEHICLE(lastDriven);
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(lastDriven, true, true); // set current vehicle as a mission entity, so we can delete after.
		// GTA missions scripts = const float DEFAULT_VEH_STOPPING_DISTANCE = 10.5

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
			//Someone still is in the car, test next frame.
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
			deliMsg += "Vehicle Delivered to Simeon!";
			deliMsg += "\n(";
			deliMsg += VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(ENTITY::GET_ENTITY_MODEL(lastDriven));
			deliMsg += ")";
			VEHICLE::DETACH_VEHICLE_FROM_ANY_TOW_TRUCK(lastDriven);
			QuickAddToDelivered((char*)lastValidVehicle.c_str());
			// BUG: if player is in a hangout, for some random reason the script sets the last driven to null but the vehicle never gets deleted.
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(lastDriven, 0, 0, 0, true, true, true);
			VEHICLE::EXPLODE_VEHICLE(lastDriven, false, true);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&lastDriven);
			//VEHICLE::DELETE_VEHICLE(&lastDriven);
			CreateHelpText((char*)deliMsg.c_str(), true);
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
	//Settings
	gSettings.ReadValuesFromSettingsFile();
	FillFullVehicleList();
	// Script got reloaded, try read the save files and see if we should do something.
	LoadCurrentSave();
	WAIT(1000);
	currentStage = ScriptStage::CheckCurrentVehicle;
	while (true) {
		Update();
		WAIT(0);
	}
}