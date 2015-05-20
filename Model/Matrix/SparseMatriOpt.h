#ifndef SPARSEMATRIOPT_H
#define SPARSEMATRIOPT_H

#include "../../Eigen/Sparse"
#include "IMatrixOpt.h"

typedef Eigen::SparseMatrix<float> SpMat;

class SpMatrix
{
private:
	SpMat mat;
public:
	SpMatrix(int x, int y);
	float get(int x, int y);
	void set(int x, int y, float val);
	int rows();
	int cols();
	void print();
	void setCol(VecX& vec, int index);
	void col(VecX& vec, int index);
	void printToFile(std::string path);
	void normalize(int index);
	void balance();
	void readDateFromFile(std::string filePath);
};
#endif
