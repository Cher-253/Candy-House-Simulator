#include<iostream>
#include<ctype.h>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<time.h>
#include<ctime>
#include<iomanip>
#include<map>
#include <chrono>
#include <mutex>
#include <thread>
#include <vector>
#include "House.h"
#include "TrickOrTreater.h"

int TrickOrTreater::ImDone = 0;

TrickOrTreater::TrickOrTreater(std::string Name, std::vector<House*>List)
	: name{Name}, ListOfHouses{List}
	{
	}

void TrickOrTreater::Walk(int speed) 
{
    for (int i = 0; i < 10; ++i) 
	{	
		path << '.';
		std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }
}

void TrickOrTreater::GoTrickOrTreating()
{
	int speed = 0;
	for(auto l: ListOfHouses)
	{	
		speed = rand()%500 + 1;
		Walk(speed);
		Bucket[l->ringDoorbell(path)]++;
	}
	ImDone++;
}

std::string TrickOrTreater::getName()
{
	return name;
}

void TrickOrTreater::startThread()
{
	TOTThreadPtr = new std::thread(&TrickOrTreater::GoTrickOrTreating, this);
}

void TrickOrTreater::joinThread()
{
	this->TOTThreadPtr->join();
	delete this->TOTThreadPtr;
}

std::string TrickOrTreater::getPath()
{
	return path.str();
}

std::ostream& operator<<(std::ostream& output, TrickOrTreater& TOT)
{
	output << TOT.name << "'s - ";
	for(auto g: TOT.Bucket)
	{
		output<<g.second<<" "<<g.first<<" , ";
	}
	output<<"\n";
	return output;
}