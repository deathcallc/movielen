#ifndef MATRIXOPT_H
#define MATRIXOPT_H

#include "../../Eigen/Dense"
#include "IMatrixOpt.h"

typedef Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> MatrixSX;

class MatrixOpt:public IMatrixOpt
{
private:
	MatrixSX mat;
public:
	MatrixOpt(int x, int y);
	MatrixSX& getMatrix();
	float get(int x, int y);
	void set(int x, int y, float val);
	int rows();
	int cols();
	void print();
	void setCol(VecX& vec, int index);
	void col(VecX& vec, int index);
	void printToFile();
};
#endif
