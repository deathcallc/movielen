#ifndef SPARSEMATRIOPT_H
#define SPARSEMATRIOPT_H

#include "../../Eigen/Sparse"
#include "IMatrixOpt.h"

typedef Eigen::SparseMatrix<short> SpMat;

class SpMatrix:public IMatrixOpt
{
private:
	SpMat mat;
public:
	SpMatrix(int x, int y);
	short get(int x, int y);
	void set(int x, int y, short val);
	int rows();
	int cols();
	void printToFile();
};
#endif
