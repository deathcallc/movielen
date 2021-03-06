#include "Reader.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

Reader::Reader(string p)
{
	Reader::fin.open(p.c_str(), ios::in | ios::app | ios::binary);
	Reader::path = p;
}

Reader::~Reader()
{
	if(Reader::fin.is_open())
	{
		Reader::fin.close();
	}
}

void Reader::split(string str, string p, vector<string>& vec)
{
	string b;
	string::size_type pos;
	while((pos = str.find(p.c_str())) != string::npos)
	{
		b = str.substr(0, pos);
		str = str.substr(pos + p.size(), string::npos);
		vec.push_back(b);
	}
	vec.push_back(str);
}
