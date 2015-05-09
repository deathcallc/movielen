#ifndef MATRIXOPT_H
#define MATRIXOPT_H

#include "../../Eigen/Dense"
#include "IMatrixOpt.h"

typedef Eigen::Matrix<short, Eigen::Dynamic, Eigen::Dynamic> MatrixSX;

class MatrixOpt:public IMatrixOpt
{
private:
	MatrixSX mat;
public:
	MatrixOpt(int x, int y);
	short get(int x, int y);
	void set(int x, int y, short val);
	int rows();
	int cols();
	void printToFile();
};
#endif
