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

void MatrixOpt::initMatrix(int* num)
{
	int n = 0;
	for(int i = 0; i < mat.rows(); i++)
	{
		for(int j = 0; j < mat.cols(); j++)
		{
			set(i,j,num[n]);
			n++;
		}
	}
}

void MatrixOpt::eigenvectors(MatrixOpt& ev)
{
	Eigen::EigenSolver<MatrixSX> es(mat);
	ev.mat = es.eigenvectors().real();
}

void MatrixOpt::genLaplacianMatrix(MatrixOpt& la)
{
	for(int i = 0; i < mat.rows(); i++)
	{
		la.set(i,i,0);
		for(int j = 0; j < mat.cols(); j++)
		{
			la.set(i,i,la.get(i,i) + get(i,j));
		}
	}
	la.mat -= mat;
}

MatrixSX& MatrixOpt::getMatrix()
{
	return mat;
}

VecX MatrixOpt::eigenvalues()
{
	return mat.eigenvalues().real();
}

void MatrixOpt::transpose()
{
	MatrixSX tmp(mat.cols(), mat.rows());
	tmp = mat.transpose();
	mat.resize(tmp.rows(), tmp.cols());
	mat = tmp;
}

void MatrixOpt::readDateFromFile(string filePath)
{
	ifstream fin;
	fin.open(filePath.c_str(), ios::in | ios::app | ios::binary);
	double val;
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

double MatrixOpt::get(int x, int y)
{
	return mat(x,y);
}
void MatrixOpt::set(int x, int y, double val)
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

void MatrixOpt::printToFile(string path)
{
	FILE* fout = fopen(path.c_str(),"w+");
	int x = 0, y = 0;
	for(x = 0; x < rows(); x++)
	{
		for(y = 0; y < cols(); y++)
		{
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
