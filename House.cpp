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

House::House(std::string Name, std::map<int,std::string>CandyRanking)
		:houseName{Name}, CandyRankingMap{CandyRanking}
		{
		}