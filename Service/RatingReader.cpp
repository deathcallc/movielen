#include "RatingReader.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

RatingReader::RatingReader(string p):Reader(p)
{
}

RatingReader::~RatingReader()
{
}

bool RatingReader::getNextRating(Rating& p)
{
	p.clear();
	string::size_type pos;
	string str, strHead, content;
	vector<string> vec;
	if(!fin.eof())
	{
		vec.clear();
		getline(fin,str);
		
		split(str, ",", vec);

		if(vec.size() < 4)
		{
			return false;
		}

		p.setUserId(atoi(vec[0].c_str()));
		p.setMovieId(atoi(vec[1].c_str()));
		p.setRating(atof(vec[2].c_str()));
		p.setTimestamp(atoll(vec[3].c_str()));

		return true;
	}
	return false;
}
