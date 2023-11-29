#include<iostream>
#include<ctype.h>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<time.h>
#include<iomanip>
#include<map>
#include<chrono>
#include<mutex>
#include<thread>
#include<vector>

#ifndef _HOUSE_
#define _HOUSE_
class House
{
	public :
		House(std::string Name, std::map<int,std::string>CandyRanking);
		virtual std::string ringDoorbell(std::ostringstream &path);
		virtual ~House()
        {
            std::cout<<"HOUSE"<<"\n";
        }
	protected :
		std::string houseName;
		std::mutex door;
		std::map<int,std::string> CandyRankingMap;
};

#endif