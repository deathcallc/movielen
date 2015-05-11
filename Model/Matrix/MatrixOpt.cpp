#include "MatrixOpt.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

MatrixOpt::MatrixOpt(int x, int y):mat(MatrixSX::Zero(x,y))
{
	
}

MatrixSX& MatrixOpt::getMatrix()
{
	return mat;
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
			fprintf(fout,"%-6.3f",get(x,y));
		}
		fprintf(fout,"\n");
	}
	fclose(fout);
}
