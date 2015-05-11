#include "SparseMatriOpt.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

SpMatrix::SpMatrix(int x, int y):mat(x,y)
{
	
}

float SpMatrix::get(int x, int y)
{
	return SpMatrix::mat.coeffRef(x,y);
}

void SpMatrix::set(int x, int y, float val)
{
	SpMatrix::mat.insert(x,y) = val;
}

int SpMatrix::rows()
{
	return SpMatrix::mat.rows();
}

int SpMatrix::cols()
{
	return SpMatrix::mat.cols();
}

void SpMatrix::col(VecX& vec, int index)
{
}

void SpMatrix::setCol(VecX& vec, int index)
{
}

void SpMatrix::print()
{
}

void SpMatrix::normalize(int index = -1)
{
}

void SpMatrix::printToFile()
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
	}
	fclose(fout);
}
