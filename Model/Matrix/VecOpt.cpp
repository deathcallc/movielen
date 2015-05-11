#include "VecOpt.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

VecOpt::VecOpt(int x):vec(x)
{
	
}

float VecOpt::get(int index)
{
	return vec(index,0);
}
void VecOpt::set(int index, float val)
{
	vec(index,0) = val;
}

int VecOpt::rows()
{
	return VecOpt::vec.rows();
}

/*
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
}*/
