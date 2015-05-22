#ifndef CLUSTER_H
#define CLUSTER_H

#include <iostream>
#include "Model/Matrix/IMatrixOpt.h"
#include "Model/Matrix/MatrixOpt.h"
#include <vector>
#include <string.h>

const float MIN_RESIDUAL = 1;
const float OP_RESIDUAL = 0.005;
const int sparsity = 10;

typedef struct pair
{
	int id;
	double val;
}Pair;

class Cluster
{
private:
	void MP(MatrixOpt* sp, int index, float norm, VecX& tar, VecX& coef);
//	bool cmp(Pair p1, Pair p2);
	void getTopkValue(std::vector<Pair>& vec, int k, std::vector<int>& re);	
public:
	void createSemMatrix(MatrixOpt* doc, MatrixOpt* sem);
	VecX genEigenValues(const std::string sem, int rows, int cols);
	void genTopkEigenVector(const std::string valpath, const std::string vecpath, const std::string output, const int row, const int col, const int k);
};


#endif
