#include "MatrixOpt.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

MatrixOpt::MatrixOpt(int x, int y):mat(x,y)
{
	
}

short MatrixOpt::get(int x, int y)
{
	return mat(x,y);
}
void MatrixOpt::set(int x, int y, short val)
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
			fprintf(fout,"%-4d",get(x,y));
		}
		fprintf(fout,"\n");
	}
	fclose(fout);
}
