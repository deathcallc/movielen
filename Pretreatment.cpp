#include <iostream>
#include <fstream>
#include <limits.h>
#include <float.h>
#include <set>
#include "Cfg/Configuration.h"
#include "Service/PaperReader.h"
#include "Service/AuthorReader.h"
#include "Entity/Paper.h"
#include "Entity/Author.h"
#include "Pretreatment.h"

using namespace std;

void Pretreatment::countPaper(std::string path)
{
	int num[100] = {0};
	PaperReader pr(path);

	Paper p;
	while(pr.getNextPaper(p))
	{
		cout<<p.getIndex()<<endl;
		if(p.getYear() != 0)
		{
			num[p.getYear()-1936]++;
		}
	}

	ofstream fout;
	fout.open("./paperCount", ios::out);
	
	for(int i = 0; i < 100; i++)
	{
		fout<<i+1936<<" "<<num[i]<<endl;
	}
	fout.close();
}

void Pretreatment::authorDatePretreat(string path)
{
	int maxPc = 0,  maxCn = 0;
	double maxHi = 0, maxPi = 0, maxUpi = 0;
	int minPc = INT_MAX, minCn = INT_MAX;
	double minHi = DBL_MAX, minPi = DBL_MAX, minUpi = DBL_MAX;
	
	AuthorReader ar(path);

	Author au;

	while(ar.getNextAuthor(au))
	{
		cout<<au.getIndex()<<endl;
		if(au.getPc() < minPc && au.getPc() >= 0)
		{
			minPc = au.getPc();
		}
		
		if(au.getCn() < minCn && au.getCn() >= 0)
		{
			minCn = au.getCn();
		}

		if(au.getHi() < minHi && au.getHi() >= 0)
		{
			minHi = au.getHi();
		}

		if(au.getPi() < minPc && au.getPi() >= 0)
		{
			minPi = au.getPi();
		}
		if(au.getUpi() < minUpi && au.getUpi() >= 0)
		{
			minUpi = au.getUpi();
		}

		if(au.getPc() > maxPc)
		{
			maxPc = au.getPc();
		}
		if(au.getCn() > maxCn)
		{
			maxCn = au.getCn();
		}
		if(au.getHi() > maxHi)
		{
			maxHi = au.getHi();
		}
		if(au.getPi() > maxPi)
		{
			maxPi = au.getPi();
		}
		if(au.getUpi() > maxUpi)
		{
			maxUpi = au.getUpi();
		}
	}
	ofstream fout;
	fout.open("./authorResult", ios::out);
	fout<<"minPc : "<<minPc<<" maxPc : "<<maxPc<<endl;
	fout<<"minCn : "<<minCn<<" maxCn : "<<maxCn<<endl;
	fout<<"minHi : "<<minHi<<" maxHi : "<<maxHi<<endl;
	fout<<"minPi : "<<minPi<<" maxPi : "<<maxPi<<endl;
	fout<<"minUpi : "<<minUpi<<" maxUpi : "<<maxUpi<<endl;
	fout.close();
}

void Pretreatment::paperDatePretreat(string path)
{

	int max = 0, min = INT_MAX;
	set<string> s;

	PaperReader pr(path);

	Paper p;
	
	while(pr.getNextPaper(p))
	{
		cout<<p.getIndex()<<endl;
		if(p.getYear() < min && p.getYear() != 0)
		{
			min = p.getYear();
		}

		if(p.getYear() > max)
		{
			max = p.getYear();
		}

		s.insert(p.getVenue());
	}

	ofstream fout;
	fout.open("./paperResult_2000", ios::out);
	fout<<"min : "<<min<<" max : "<<max<<endl;

	set<string>::iterator it;

	for(it=s.begin(); it != s.end(); it++)
	{
		fout<<*it<<endl;
	}
	fout.close();

}
