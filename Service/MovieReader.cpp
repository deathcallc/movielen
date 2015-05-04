#include "MovieReader.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

MovieReader::MovieReader(string p):Reader(p)
{
}

MovieReader::~MovieReader()
{
}

bool MovieReader::getNextMovie(Movie& m)
{
	m.clear();
	string::size_type pos;
	string str, strHead, content;
	vector<string> vec;
	vector<string> gen;
	if(!fin.eof())
	{
		vec.clear();

		getline(fin,str);
		str = str.substr(0,str.length() - 1);
		
		split(str, ",", vec);
		/*
		while(s!= null)
		{
			vec.push_back(s);
			s = strtok(str.c_str(), ',');
		}*/

		if(vec.size() < 3)
		{
			return false;
		}

		

		if(vec.size() > 3)
		{
			string id = vec[0];
			string gen = vec[vec.size()-1];
			string title = vec[1];
			for(int i = 2; i < vec.size() - 1; i++)
			{
				title += ","+vec[i];
			}
			vec.clear();
			vec.push_back(id);
			vec.push_back(title);
			vec.push_back(gen);
		}

		cout<<vec[0]<<endl;
		
		m.setMovieId(atoi(vec[0].c_str()));
		m.setTitle(vec[1]);
			
		split(vec[2], "|", gen);

		for(int i = 0; i < gen.size(); i++)
		{
			m.addGenresFlag(gen[i]);
		}

		return true;
	}
	return false;
}
