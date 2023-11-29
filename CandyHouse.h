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
#include "House.h"

#ifndef _CANDY_HOUSE_
#define _CANDY_HOUSE_

class CandyHouse : public House
{
    public :
        CandyHouse(std::string CandyHouseName,std::map<int,std::string> CandyRankingMap);
        std::string ringDoorbell(std::ostringstream &path);
        ~CandyHouse()
        {
            std::cout<<"CANDYHOUSE"<<"\n";
        }
};
#endif