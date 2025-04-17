#pragma once
#include "SaveSystem.h"
#include <Psapi.h>
#include <filesystem>
#include <ShlObj.h>
#include <Shlwapi.h>
//#include <stdexcept>
//#include <exception>
#include <iostream>
#include <list>

const std::string Identifier = "GORDOLEAL?";
//outputdebugstringA()

SaveSystem::ErrSave SaveSystem::SaveProgress(std::list<char*> vehicles, bool isEnhanced, std::wstring saveFolderPath)
{
	// Find the newest modified save.
	std::wstring testingFilesPath = saveFolderPath + L"\\*";
	// start the check files loop operation
	WIN32_FIND_DATAW folderData;
	HANDLE hFind = FindFirstFileW(testingFilesPath.c_str(), &folderData);
	if (hFind == INVALID_HANDLE_VALUE) //For debug
	{
		return ErrSave::FolderNotFound;
	}

	FILETIME mostRecentModifiedTime = { 0, 0 };
	std::wstring mostRecentFile;
	do {
		//ignore folders.
		if (!(folderData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			//the fastest way to compare wchar* is to just abuse the wstring powers.
			//Uses a bit more of memory and cpu cycles, but is the easier solution.
			std::wstring tobetested = folderData.cFileName;
			//Check only the save files and ignore the backup files.
			//settings and snapmatic are saved in the same folder so we need to ignore them.
			if (!tobetested.empty())
				if (tobetested.find(L"SGTA") != std::wstring::npos && tobetested.find(L".bak") == std::wstring::npos) {
					//We only want to modify the save file that JUST happened. if nothing happened just ignore the rest.
					// for optimization this test could be made at the folders, WAY before we get to this part but too lazy to change now...

					FILETIME currentSystemTime;
					GetSystemTimeAsFileTime(&currentSystemTime);
					FILETIME bufferForCurrentFileCheck = folderData.ftLastWriteTime;
					//Only way i found to increment the FILETIME for comparisson with another FILETIME is converting into ULARGE_INTEGER
					ULARGE_INTEGER uli;
					uli.LowPart = bufferForCurrentFileCheck.dwLowDateTime;
					uli.HighPart = bufferForCurrentFileCheck.dwHighDateTime;
					uli.QuadPart += 5ULL * 10000000ULL; // + 50 000 000 , Adds 5 seconds to current system time. FILETIME works in 100 microseconds.
					bufferForCurrentFileCheck.dwHighDateTime = uli.HighPart;
					bufferForCurrentFileCheck.dwLowDateTime = uli.LowPart;

					//if the file we are currently looking is inside the 5 seconds buffer.
					//if FILETIME + 5 seconds is ahead of current time then is a file that have been written in the last 5 seconds.
					if (CompareFileTime(&bufferForCurrentFileCheck, &currentSystemTime) > 0) {
						//just in case we have 2 or more files with less than 5 seconds.
						if (CompareFileTime(&folderData.ftLastWriteTime, &mostRecentModifiedTime) > 0)
						{
							mostRecentModifiedTime = folderData.ftLastWriteTime;
							mostRecentFile = folderData.cFileName;
						}
					}
				}
		}
	} while (FindNextFileW(hFind, &folderData));
	FindClose(hFind);

	if (mostRecentFile.empty())
	{
		// We didn't find a save file or is all the saves are bellow the 5 seconds buffer, meaning a save didn't happen.
		return ErrSave::FileDoesNotExistOrNotBellowBuffer;
	}
	else
	{
		// We have the save file now, try write information into it.
		std::wstring lastUsedSaveFilePath = saveFolderPath + L"\\" + mostRecentFile;
		std::fstream saveStream;
		// ios::ate: will write to the very end of the file. i don't want to break the save file.
		saveStream.open(lastUsedSaveFilePath.c_str(), std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
		saveStream << Identifier.c_str(); //identifier to know from now on is only the data we have written, need to be something unique.
		//don't need fancy json/xml stuff for now, just write the data and recover later.
		OutputDebugString("saving Loop");
		for (char* v : vehicles) {
			saveStream << ',';
			OutputDebugString(v);
			saveStream << v;
			saveStream << '#';
		}
		saveStream << '!';// identifier to know we are over with the data.
		saveStream.close();

	}
	return ErrSave::SaveDone;
}

SaveSystem::ErrSave SaveSystem::SaveProgressForReplay(std::list<char*> vehicles, bool isEnhanced, std::wstring saveFolderPath) {
	// Find the newest modified save.
	std::wstring testingFilesPath = saveFolderPath + L"\\*";
	// start the check files loop operation
	WIN32_FIND_DATAW folderData;
	HANDLE hFind = FindFirstFileW(testingFilesPath.c_str(), &folderData);
	if (hFind == INVALID_HANDLE_VALUE) //For debug
	{
		return ErrSave::FolderNotFound;
	}

	std::wstring mostRecentFile;
	do {
		//ignore folders.
		if (!(folderData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			//the fastest way to compare wchar* is to just abuse the wstring powers.
			//Uses a bit more of memory and cpu cycles, but is the easier solution.
			std::wstring tobetested = folderData.cFileName;
			//Check only the replay save file and ignore the backup files.
			if (!tobetested.empty())
				if (tobetested.find(L"MISREP0000") != std::wstring::npos && tobetested.find(L".bak") == std::wstring::npos)
				{
					// GTAV only generates 1 MISREP file (except the .bak) so don't need to do any more checks.
					mostRecentFile = folderData.cFileName;
					break;
				}
		}
	} while (FindNextFileW(hFind, &folderData));
	FindClose(hFind);

	if (mostRecentFile.empty())
	{
		return ErrSave::FileDoesNotExistOrNotBellowBuffer;
	}
	else
	{
		// We have the save file now, try write information into it.
		std::wstring lastUsedSaveFilePath = saveFolderPath + L"\\" + mostRecentFile;
		std::fstream saveStream;
		// ios::ate: will write to the very end of the file. i don't want to break the save file.
		saveStream.open(lastUsedSaveFilePath.c_str(), std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
		saveStream << Identifier.c_str(); //identifier to know from that point and forward is only the data we have written, need to be something unique.
		//don't need fancy json/xml stuff for now, just write the data and recover later.
		OutputDebugString("saving Loop");
		for (char* v : vehicles) {
			saveStream << ',';
			OutputDebugString(v);
			saveStream << v;
			saveStream << '#';
		}
		saveStream << '!';// identifier to know we are over with the data.
		saveStream.close();

	}
	return ErrSave::SaveDone;
}

static uintptr_t GetAddressFromPattern(uintptr_t baseAddress, size_t processRegionSize, const unsigned char* pattern, const char* mask)
{
	size_t patternLength = strlen(mask);
	for (size_t x = 0; x <= processRegionSize - patternLength; x++) {
		bool found = true;
		for (size_t z = 0; z < patternLength; z++) {
			if (mask[z] == 'x')
			{
				if (pattern[z] != *reinterpret_cast<unsigned char*>(baseAddress + x + z)) {
					found = false;
					break;
				}
			}
		}
		if (found)
			return baseAddress + x;
	}
	return 0x0;
}

/// <summary>
/// Just a quick helper.
/// </summary>
/// <param name="lastSavedSlotBuffer">Where the value is gonna be inserted to</param>
/// <param name="pointerToLastSavedSlotNumber">pointer to the address of the global</param>
/// <returns></returns>
SaveSystem::ErrSave SaveSystem::GetLastReadSlotNumber(int* lastSavedSlotBuffer, intptr_t* pointerToLastSavedSlotNumber)
{
	//get the value from the address
	*lastSavedSlotBuffer = *reinterpret_cast<int*>(*pointerToLastSavedSlotNumber);
	return SaveSystem::SaveDone;

}

/// <summary>
/// Just a quick helper.
/// </summary>
/// <param name="lastSavedSlotBuffer">Where the value is gonna be inserted to</param>
/// <param name="pointerToLastSavedSlotNumber">pointer to the address of the global</param>
/// <returns></returns>
SaveSystem::ErrSave SaveSystem::GetToBeReadSaveFile(char** ToBeReadSaveFile, intptr_t* pointerToBeReadSaveFile)
{
	//get the value from the address
	*ToBeReadSaveFile = reinterpret_cast<char*>(*pointerToBeReadSaveFile);
	return SaveSystem::SaveDone;

}

SaveSystem::ErrSave SaveSystem::GetPointerToLastLoadedSlotNumber(intptr_t* pointerBuffer)
{
	//GTA Handle
	HANDLE gtaProcess = GetCurrentProcess();
	HMODULE hModule = GetModuleHandleA(NULL);
	if (hModule == NULL) {
		return ErrSave::ModuleHandleWasNull;
	}

	uint8_t* BaseAddress = (uint8_t*)hModule;   //Unlock RGSC bonus for Elegy RH8 only on patch 1.27

	if (*(UINT64*)(BaseAddress + 0x1624174) == 0x1416CAE828EC8348)
	{
		*(UINT64*)(BaseAddress + 0xF18908) = 0x3390909090C301B0;
	}
	
	MODULEINFO modInfo = { 0 };
	if (!K32GetModuleInformation(gtaProcess, hModule, &modInfo, sizeof(MODULEINFO)))
	{
		return ErrSave::CouldNotGetGTAVModule;
	}

	uintptr_t baseAddress = reinterpret_cast<uintptr_t>(modInfo.lpBaseOfDll);
	size_t moduleSize = modInfo.SizeOfImage;

	// GTAV seems to have 2 globals for the selected slot,
	// one that gets set when asking the player if he is sure that wants to load the save.
	// the other gets set when the player press confirm.
	// We are going to use the one that gets set after the player hit the confirmation button, since it seems more stable.
	// if the player just loaded the game that variable is gonna be -1, in this case i need to check the last modified Save file.

	//                         \/(??) address to RIP offset.
	// 89 1D ?? ?? ?? ?? 89 05 ?? ?? ?? ?? 83
	//                                     /\ (83) address to next instruction (not required to be part of the pattern just coincidence)
	const unsigned char MemorySlotPattern[] = "\x89\x1D\x00\x00\x00\x00\x89\x05\x00\x00\x00\x00\x83";
	const char MemorySlotMask[] = "xx????xx????x";

	uintptr_t addressToPatern = GetAddressFromPattern(baseAddress, moduleSize, MemorySlotPattern, MemorySlotMask);
	if (addressToPatern == 0x0) {
		return SaveSystem::ErrSave::AddressToPaternNotFound;
	}
	//GTAV is x64, RIP-relative address, so i need to do a bit extra math for the correct address.
	int ripOffset = *reinterpret_cast<int*>(addressToPatern + 8);
	uintptr_t addressNextCall = addressToPatern + 12;
	*pointerBuffer = addressNextCall + ripOffset;
	return SaveSystem::SaveDone;
}

SaveSystem::ErrSave SaveSystem::GetPointerToBeLoadedSaveFile(intptr_t* pointerBuffer)
{
	//GTA Handle
	HANDLE gtaProcess = GetCurrentProcess();
	HMODULE hModule = GetModuleHandleA(NULL);
	if (hModule == NULL) {
		return ErrSave::ModuleHandleWasNull;
	}
	MODULEINFO modInfo = { 0 };
	if (!K32GetModuleInformation(gtaProcess, hModule, &modInfo, sizeof(MODULEINFO)))
	{
		return ErrSave::CouldNotGetGTAVModule;
	}

	uintptr_t baseAddress = reinterpret_cast<uintptr_t>(modInfo.lpBaseOfDll);
	size_t moduleSize = modInfo.SizeOfImage;

	// GTAV saves a string of the save file that needs to be read on the next load.
	// For mission replays it sets to MSRP0000 right at the start of the mission replay.
	// the value stays until a save file load is called or another mission replay starts.
	// we already know when a mission replay starts, can use this to know if it ended.

	//                               \/(??) address to RIP offset.
	// 48 8D 15 ?? ?? ?? ?? 48 8D 0D ?? ?? ?? ?? E8 ?? ?? ?? ?? F7 D8
	//                                           /\ (E8) address to next instruction (not required to be part of the pattern just coincidence)
	const unsigned char MemorySlotPattern[] = "\x48\x8D\x15\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xF7\xD8";
	const char MemorySlotMask[] = "xxx????xxx????x????xx";

	uintptr_t addressToPatern = GetAddressFromPattern(baseAddress, moduleSize, MemorySlotPattern, MemorySlotMask);
	if (addressToPatern == 0x0) {
		return SaveSystem::ErrSave::AddressToPaternNotFound;
	}
	//GTAV is x64, RIP-relative address, so i need to do a bit extra math for the correct address.
	int ripOffset = *reinterpret_cast<int*>(addressToPatern + 10);
	uintptr_t addressNextCall = addressToPatern + 14;
	*pointerBuffer = addressNextCall + ripOffset;
	return SaveSystem::SaveDone;
}


SaveSystem::ErrSave FillArrayWithSaveFileData(std::wstring saveFolderPath, std::wstring saveFileName, std::list<char*>& deliveredVehiclesFromSave)
{
	//Save File found, time to take the values from inside.
	std::fstream streamRecentFile;
	streamRecentFile.open((saveFolderPath + L"\\" + saveFileName), std::ios::in | std::ios::out | std::ios::binary);
	// found this simple "file to string" iterator while looking on other stuff, it seems to work, not a clue how it works... magic...
	// good enough for me.
	std::string savefilecontent{ std::istreambuf_iterator<char>(streamRecentFile), std::istreambuf_iterator<char>() };
	OutputDebugString(savefilecontent.c_str());
	size_t posOurContent = savefilecontent.find(Identifier);
	if (posOurContent == std::string::npos) {
		//Identifier not found, save don't have any data.
		OutputDebugString("Save File don't have data");
		return SaveSystem::ErrSave::SaveFileDontHaveData;
	}
	// i don't care for the content that comes before the identifier, also remove the identifier.
	savefilecontent.erase(0, posOurContent + Identifier.size());
	deliveredVehiclesFromSave.clear();
	//just a basic loop.
	OutputDebugStringA("Start of basic load loop");
	int x = 0;
	std::string content;
	bool hitEnd = false;
	do {
		switch (savefilecontent.at(x))
		{
		case '?':
			OutputDebugStringA("IDENTIFIER IS WHERE IT SHOULD NEVER BE");
			content.clear();
			break;
		case ','://start of value
			OutputDebugStringA("Start of value");
			content.clear();
			break;
		case '#'://end of value{
		{
			OutputDebugStringA("End of Value");
			char* memoryIssues = new char[content.size() + 1];
			strcpy_s(memoryIssues, content.size() + 1, content.c_str());
			deliveredVehiclesFromSave.push_back(memoryIssues);
			break;
		}
		case '!'://end of data we care.
			OutputDebugStringA("End of loop");
			hitEnd = true;
			break;
		default:
			content += savefilecontent.at(x);
			OutputDebugStringA(("returning at " + std::to_string(x) + " =" + content).c_str());
			break;
		}
		x++;
	} while (!hitEnd);
	streamRecentFile.close();
	return SaveSystem::ErrSave::SaveDone;
}

/// <summary>
/// On first time load the game sets the slot to -1 and stays this way until a save is loaded.
/// the game loads the last written save file, so we do the same after the script is loaded for
/// the first time.
/// This function should be called at the script start because of that.
/// </summary>
SaveSystem::ErrSave SaveSystem::LoadProgressForFirstTime(std::wstring saveFolderPath, std::list<char*>& deliveredVehiclesFromSave)
{
	// Find the newest modified save.
	std::wstring testingFilesPath = saveFolderPath + L"\\*";
	// start the check files loop operation
	WIN32_FIND_DATAW folderData;
	HANDLE hFind = FindFirstFileW(testingFilesPath.c_str(), &folderData);
	if (hFind == INVALID_HANDLE_VALUE) //For debug
	{
		return ErrSave::FolderNotFound;
	}

	FILETIME mostRecentModifiedTime = { 0, 0 };
	std::wstring mostRecentFile;
	do {
		//ignore folders.
		if (!(folderData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			//the fastest way to compare wchar* is to just abuse the wstring powers.
			//Uses a bit more of memory and cpu cycles, but is the easier solution.
			std::wstring tobetested = folderData.cFileName;
			//Check only the save files and ignore the backup files.
			//settings and snapmatic are saved in the same folder so we need to ignore them.
			if (!tobetested.empty())
				if (tobetested.find(L"SGTA") != std::wstring::npos && tobetested.find(L".bak") == std::wstring::npos) {
					if (CompareFileTime(&folderData.ftLastWriteTime, &mostRecentModifiedTime) > 0)
					{
						mostRecentModifiedTime = folderData.ftLastWriteTime;
						mostRecentFile = folderData.cFileName;
					}
				}
		}
	} while (FindNextFileW(hFind, &folderData));
	FindClose(hFind);

	if (mostRecentFile.empty())
	{
		return ErrSave::FileDoesNotExist;
	}

	return FillArrayWithSaveFileData(saveFolderPath, mostRecentFile, deliveredVehiclesFromSave);
}

/// <summary>
/// Try Load the last read file.
/// </summary>
/// <param name="saveFolderPath"></param>
/// <returns></returns>
SaveSystem::ErrSave SaveSystem::LoadProgress(std::wstring saveFolderPath, int saveSlotNumber, std::list<char*>& deliveredVehiclesFromSave)
{
	//Find the save file that matches the name
	std::wstring testingFilesPath = saveFolderPath + L"\\*";
	// start the check files loop operation
	WIN32_FIND_DATAW folderData;
	HANDLE hFind = FindFirstFileW(testingFilesPath.c_str(), &folderData);
	if (hFind == INVALID_HANDLE_VALUE) //For debug
	{
		return ErrSave::FolderNotFound;
	}

	std::wstring saveFileName(L"SGTA5");
	if (saveSlotNumber < 10) {
		//SGTA50001
		saveFileName += L"000";
	}
	else
	{
		//SGTA50014
		saveFileName += L"00";
	}
	saveFileName += std::to_wstring(saveSlotNumber);
	std::wstring testingA(L"result:");
	testingA += saveFileName;
	OutputDebugStringW(testingA.c_str());
	bool foundSaveFile = false;
	do {
		//ignore folders.
		if (!(folderData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			std::wstring tobetested = folderData.cFileName;
			if (!tobetested.empty()) {
				if (tobetested.compare(saveFileName) == 0) {
					foundSaveFile = true;
					break;
				}
			}
		}
	} while (FindNextFileW(hFind, &folderData));
	FindClose(hFind);

	if (!foundSaveFile)
	{
		OutputDebugString("File does not exist");
		return ErrSave::FileDoesNotExist;
	}
	
	return FillArrayWithSaveFileData(saveFolderPath, saveFileName, deliveredVehiclesFromSave);
}

SaveSystem::ErrSave SaveSystem::LoadProgressFromReplay(std::wstring saveFolderPath, std::list<char*>& deliveredVehiclesFromSave)
{
	std::wstring testingFilesPath = saveFolderPath + L"\\*";
	// start the check files loop operation
	WIN32_FIND_DATAW folderData;
	HANDLE hFind = FindFirstFileW(testingFilesPath.c_str(), &folderData);
	if (hFind == INVALID_HANDLE_VALUE) //For debug
	{
		return ErrSave::FolderNotFound;
	}

	std::wstring mostRecentFile;
	do {
		//ignore folders.
		if (!(folderData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			std::wstring tobetested = folderData.cFileName;
			if (!tobetested.empty())
				if (tobetested.find(L"MISREP0000") != std::wstring::npos && tobetested.find(L".bak") == std::wstring::npos) {
						mostRecentFile = folderData.cFileName;
						break;
				}
		}
	} while (FindNextFileW(hFind, &folderData));
	FindClose(hFind);

	if (mostRecentFile.empty())
	{
		return ErrSave::FileDoesNotExist;
	}

	return FillArrayWithSaveFileData(saveFolderPath, mostRecentFile, deliveredVehiclesFromSave);
}

SaveSystem::ErrSave SaveSystem::GetSaveFilePath(bool isCurrentPatch, std::wstring* saveFolderPathBuffer)
{
	// I was going to make a better way of dealing with errors but i got lazy. - GordoLeal.

	//To get the full path for the game files i need to find where it is.
	// - To find it i need to find the documents folder. Microsoft likes to move this shit everwhere.
	// - i need to find if the game is using Project127 (custom path) or is Enhanced (default path).
	// - Find the player ID so we can get the correct folder.

	//First get the documents folder, because of microsoft reasons the path for this fucking thing point to everwhere.
	PWSTR testPathDoc = nullptr;
	HRESULT findDocFoldResult = SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &testPathDoc);
	switch (findDocFoldResult)
	{
	case S_OK:
		break;
	case E_FAIL:
	case E_INVALIDARG:
		// need to manualy free memory. (By MSDC: https://learn.microsoft.com/en-us/windows/win32/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath )
		CoTaskMemFree(testPathDoc);
		return SaveSystem::ErrSave::DocumentsFolderNotFound;
		break;
	}

	std::wstring finalpath = L"";
	if (isCurrentPatch)
	{
		// Instead of getting the first available folder, i test for the last modified folder, 
		// this way in the rare case is a multi profile user the mod can support it

		// L"\\Rockstar Games\\GTA V\\Profiles\\GTA V"
		std::wstring enhancedSavePath = testPathDoc + (std::wstring)L"\\Rockstar Games\\GTA V\\Profiles\\GTA V";
		WIN32_FIND_DATAW folderDataEnhanced;
		HANDLE hFind = FindFirstFileW((enhancedSavePath + L"\\*").c_str(), &folderDataEnhanced);
		if (hFind == INVALID_HANDLE_VALUE)
		{
			return ErrSave::EnhancedFolderNotFound;
		}
		// Get the most recent modified folder, this way we know this is correct folder we want to use.
		FILETIME mostRecentTimeFolder_Enhanced = { 0, 0 };
		std::wstring mostRecentFolder_Enhanced;
		do {
			//ONLY FOLDERS.
			if ((folderDataEnhanced.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				if (CompareFileTime(&folderDataEnhanced.ftLastWriteTime, &mostRecentTimeFolder_Enhanced) > 0)
				{
					mostRecentTimeFolder_Enhanced = folderDataEnhanced.ftLastWriteTime;
					mostRecentFolder_Enhanced = folderDataEnhanced.cFileName;
				}
			}
		} while (FindNextFileW(hFind, &folderDataEnhanced));
		FindClose(hFind);

		if (mostRecentFolder_Enhanced.empty())
		{
			return ErrSave::EnhancedFolderEmpty;
		}
		finalpath = enhancedSavePath + L"\\" + mostRecentFolder_Enhanced;
		// L"\\Rockstar Games\\GTA V\\Profiles\\GTA V\\XXXXXXXX"
	}
	else
	{
		// TODO: Test Project127 folder last written time agains default path, this way i can make sure the player is not using a save from the default path.
		// For now: Just assume the player is using Project127, who is dumb enough to not use it for patch 1.27?

		// Instead of getting the first available folder, i test for the last modified folder, 
		// this way in the rare case is a multi profile user the mod can support it

		// L"\\Rockstar Games\\GTA V\\Profiles\\GTA V\\"
		std::wstring OldPatchSavePath = testPathDoc + (std::wstring)L"\\Rockstar Games\\GTA V\\Profiles\\Project127\\GTA V";
		WIN32_FIND_DATAW folderData_OldPatch;
		HANDLE hFind = FindFirstFileW((OldPatchSavePath + L"\\*").c_str(), &folderData_OldPatch);
		if (hFind == INVALID_HANDLE_VALUE)  //For Debug
		{
			return ErrSave::OldPatchFolderNotFound;
		}
		// Get the most recent modified folder, only way we know this is correct folder we want to use.
		FILETIME mostRecentTimeFolder_OldPatch = { 0, 0 };
		std::wstring mostRecentFolder_OldPatch;
		do {
			//ONLY FOLDERS.
			if ((folderData_OldPatch.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				if (CompareFileTime(&folderData_OldPatch.ftLastWriteTime, &mostRecentTimeFolder_OldPatch) > 0)
				{
					mostRecentTimeFolder_OldPatch = folderData_OldPatch.ftLastWriteTime;
					mostRecentFolder_OldPatch = folderData_OldPatch.cFileName;
				}
			}
		} while (FindNextFileW(hFind, &folderData_OldPatch));
		FindClose(hFind);

		if (mostRecentFolder_OldPatch.empty())
		{//For Debug
			return ErrSave::OldPatchFolderEmpty;
		}
		finalpath = OldPatchSavePath + L"\\" + mostRecentFolder_OldPatch;
		// L"\\Rockstar Games\\GTA V\\Profiles\\Project127\\GTA V\\XXXXXXXX"
	}

	*saveFolderPathBuffer = finalpath;
	CoTaskMemFree(testPathDoc);
	return ErrSave::SaveDone;
}
