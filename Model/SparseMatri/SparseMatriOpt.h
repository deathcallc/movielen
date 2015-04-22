#ifndef SPARSEMATRIOPT_H
#define SPARSEMATRIOPT_H

#include "../../Eigen/Sparse"

typedef Eigen::SparseMatrix<int> SpMat;

class SpMatrix
{
private:
	SpMat mat;
public:
	SpMatrix(int x, int y);
	int get(int x, int y);
	void set(int x, int y, int val);
};
#endif
