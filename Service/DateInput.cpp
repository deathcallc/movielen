#include "DateInput.h"
#include <iostream>
#include <fstream>

using namespace std;

DateInput::DateInput(int x, int y):sp(x,y)
{
}

bool DateInput::readDate(ifstream& in)
{
	int from = 0, to = 0;
	in>>from>>to;
	cout<<from<<" "<<to<<endl;
	return true;
}


bool DateInput::readDate(string filePath)
{
	if(!access(filePath.c_str(), F_OK))
	{
		cout<<"file is not exist!"<<endl;
		return false;
	}
	ifstream in;
	in.open(filePath.c_str(),ios::out | ios::app | ios::binary);
	if(!in.is_open())
	{
		cout<<"fail to open file"<<endl;
	}

	readDate(in);
	in.close();
	return true;
}

SpMatrix& DateInput::getSpMatrix()
{
	return sp;
}
