#include "MatrixOpt.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <fstream>

using namespace std;

MatrixOpt::MatrixOpt(int x, int y):mat(MatrixSX::Zero(x,y))
{
	
}

MatrixSX& MatrixOpt::getMatrix()
{
	return mat;
}

void MatrixOpt::readDateFromFile(string filePath)
{
	ifstream fin;
	fin.open(filePath.c_str(), ios::in | ios::app | ios::binary);
	float val;
	string str;
	for(int i = 0; i < mat.rows(); i++)
	{
		for(int j = 0; j < mat.cols(); j++)
		{
			fin>>str;
			val = atof(str.c_str());
			set(i,j,val);
		}
	}
	fin.close();
}

void MatrixOpt::balance()
{
	float val = 0;
	for(int i = 0; i < mat.rows(); i++)
	{
		for(int j = i; j < mat.cols(); j++)
		{
			val = abs(get(i,j)) + abs(get(j,i));
			set(i,j,val);
			set(j,i,val);
		}
	}
}

float MatrixOpt::get(int x, int y)
{
	return mat(x,y);
}
void MatrixOpt::set(int x, int y, float val)
{
	mat(x,y) = val;
}

int MatrixOpt::rows()
{
	return MatrixOpt::mat.rows();
}

int MatrixOpt::cols()
{
	return MatrixOpt::mat.cols();
}

void MatrixOpt::col(VecX& vec, int index)
{
	vec = MatrixOpt::mat.col(index);
}

void MatrixOpt::setCol(VecX& vec, int index)
{
	mat.col(index) = vec;
}

void MatrixOpt::print()
{
	cout<<mat<<endl;
}

void MatrixOpt::normalize(int index)
{
	if(index >= 0 && index < mat.cols())
	{
		mat.col(index).normalize();
	}
	else if(index == -1)
	{
		for(int i = 0; i < mat.cols(); i++)
		{
			mat.col(i).normalize();
		}
	}
}

void MatrixOpt::printToFile()
{
	FILE* fout = fopen("./matrix","w+");
	int x = 0, y = 0;
	for(x = 0; x < rows(); x++)
	{
		cout<<x<<endl;
		for(y = 0; y < cols(); y++)
		{
//			cout<<"x:"<<x<<"  y:"<<y<<"  val:"<<get(x,y)<<endl;
			fprintf(fout,"%-11.5f",get(x,y));
		}
		fprintf(fout,"\n");
	}
	fclose(fout);
}

void clone(MatrixOpt& a, MatrixOpt& b)
{
	a.mat = b.mat;
}
