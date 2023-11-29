#include<iostream>
#include<ctype.h>
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

#ifndef _TOT_H
#define _TOT_H

class TrickOrTreater
{
	friend std::ostream& operator<<(std::ostream& output, TrickOrTreater& TOT);
	public :
		TrickOrTreater(std::string Name, std::vector<House*>List);
		std::string getName();
		void startThread();
		void joinThread();
		void GoTrickOrTreating();
		void Walk(int); 
		std::string getPath();
		static int ImDone;
	private :
		std::string name;
		std::ostringstream path;
		std::thread *TOTThreadPtr = nullptr;
		std::map<std::string,int> Bucket;
		std::vector<House*>ListOfHouses;
};
#endif