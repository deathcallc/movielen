#include "SparseMatriOpt.h"
#include <iostream>

using namespace std;

SpMatrix::SpMatrix(int x, int y):mat(x,y)
{
	
}

int SpMatrix::get(int x, int y)
{
	return SpMatrix::mat.coeffRef(x,y);
}
void SpMatrix::set(int x, int y, int val)
{
	SpMatrix::mat.insert(x,y) = val;
}

