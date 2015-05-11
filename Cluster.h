#ifndef CLUSTER_H
#define CLUSTER_H

#include <iostream>
#include "Model/Matrix/IMatrixOpt.h"
#include "Model/Matrix/MatrixOpt.h"

const float MIN_RESIDUAL = 1;
const float OP_RESIDUAL = 0.3;
const int sparsity = 10;

class Cluster
{
private:
	void MP(IMatrixOpt* sp, int index, float norm, VecX& tar, VecX& coef);
public:
	void createSemMatrix(IMatrixOpt* doc, IMatrixOpt* sem);
};


#endif
