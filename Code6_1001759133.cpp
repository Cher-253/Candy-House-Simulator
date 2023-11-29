#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<cstring>
#include<map>
#include<chrono>
#include <mutex>
#include <thread>
#include<stdlib.h>
#include "House.h"
#include "TrickOrTreater.h"
#include "CandyHouse.h"
#include "ToothbrushHouse.h"

using namespace std;

void get_command_line_params(int argc, char *argv[], string& TOTfile, string& Housefile, string& Candyfile)
{
	if(argc==4)
	{
		TOTfile = argv[1];
		Housefile =  argv[2];
		Candyfile = argv[3];
	}
	else
	{
        throw invalid_argument("\nMissing command line parameters - Usage : TOTFILENAME HOUSEFILENAME CANDYFILENAME\n");
	}
}

int main(int argc, char *argv[])
{
	string TOTFilename, HouseFilename, CandyFilename;
	map<int,string>CandyRankingMap;
	string CandyLine;
	char CandyLineA[50] = {};
	string CandyName;
	int CandyRanking;
	char *CandyPtr = NULL;
	vector<House*>Houses;
	string HouseLine;
	vector<TrickOrTreater>TOTs;
	string TotLine;
	ostringstream HouseHeading;
	srand(time(NULL));
	try
    {
        get_command_line_params(argc,argv,TOTFilename,HouseFilename,CandyFilename);
    }
    catch (invalid_argument& ex)
    {
        cout<<"Missing command line parameters - Usage : TOTFILENAME HOUSEFILENAME CANDYFILENAME\n\n";
        exit(0);
    }
	ifstream TOTFH("TOT.txt", ios::in);
    ifstream HouseFH("HOUSES.txt", ios::in);
    ifstream CandyFH("CANDY.txt", ios::in);
	while (getline(CandyFH,CandyLine))
	{
		strcpy(CandyLineA, CandyLine.c_str());
		CandyPtr = strtok(CandyLineA, "|");
		CandyName = CandyPtr;
		CandyPtr = strtok(NULL, "|");
		CandyRanking = atoi(CandyPtr);
        CandyRankingMap.insert(make_pair(CandyRanking, CandyName));   
	}
	CandyFH.close();
	HouseHeading << "          ";
	while (getline(HouseFH,HouseLine))
	{
		House *NewHouse = new House{HouseLine,CandyRankingMap};
        int Randnum = rand()% 2;
        cout<<"Randnum is " << Randnum<<"\n";
        if(Randnum==0)
        {
            CandyHouse CanHouse{HouseLine,CandyRankingMap};
            Houses.push_back(CanHouse);
        }
        else
        {
            ToothbrushHouse ToothHouse{HouseLine,CandyRankingMap};
            Houses.push_back(ToothHouse);
        }
		HouseHeading << HouseLine;
		for (int i = 0; i < 11 - HouseLine.length(); i++)
			HouseHeading << " ";
	}
	HouseHeading << endl << endl;
	HouseFH.close();
	while (getline(TOTFH,TotLine))
	{
		TOTs.push_back(TrickOrTreater{TotLine,Houses});
	}
	TOTFH.close();
	for (auto &i: TOTs)
	{
		i.startThread();
	}
	while (TrickOrTreater::ImDone != TOTs.size() ) 
	{
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << HouseHeading.str();
        for (auto &b: TOTs) 
		{
			cout << b.getPath()<< b.getName()<< endl;
        }
		this_thread::sleep_for(chrono::milliseconds(5));
    }	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << HouseHeading.str();
	for (auto &y:TOTs) 
	{
		cout << y.getPath()<< y.getName()<< endl;
	}
	for (auto  &t: TOTs)
	{
		cout << t;
	}
	for (auto &k: TOTs)
	{
		k.joinThread();
	}
	for (auto &g: Houses)
	{
		delete(g);
	}
	return 0;
}