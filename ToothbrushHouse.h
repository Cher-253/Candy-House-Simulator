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

#ifndef _TOOTHBRUSH_HOUSE_
#define _TOOTHBRUSH_HOUSE_

class ToothbrushHouse : public House
{
    public :
        ToothbrushHouse(std::string ToothbrushHouseName,std::map<int,std::string> CandyRankingMap);
        std::string ringDoorbell(std::ostringstream &path);
        ~ToothbrushHouse()
        {
            std::cout<<"TOOTHBRUSHHOUSE"<<"\n";
        }
};

#endif