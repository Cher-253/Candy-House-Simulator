#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<time.h>
#include<iomanip>
#include<map>
#include <chrono>
#include <mutex>
#include <thread>
#include <vector>
#include "House.h"
#include "TrickOrTreater.h"
#include "CandyHouse.h"
#include "ToothbrushHouse.h"

ToothbrushHouse::ToothbrushHouse(std::string ToothbrushHouseName, std::map<int,std::string>ToothbrushRanking) 
    :House(ToothbrushHouseName, ToothbrushRanking)
    {
    }

std::string ToothbrushHouse::ringDoorbell(std::ostringstream &path)
{
	door.lock();
	path << "-";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	int toothbrush = rand() % (CandyRankingMap.size()) + 1;
	door.unlock();
	return CandyRankingMap[toothbrush];
}