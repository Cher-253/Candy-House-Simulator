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

CandyHouse::CandyHouse(std::string Name, std::map<int,std::string>CandyRanking) 
    :House(Name, CandyRanking)
    {
    }

std::string CandyHouse::CandyHouse::ringDoorbell(std::ostringstream &path)
{
	door.lock();
	path << "+";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	int candy = rand() % (CandyRankingMap.size()) + 1;
	door.unlock();
	return CandyRankingMap[candy];
}