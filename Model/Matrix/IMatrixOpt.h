#ifndef IMATRIXOPT_H
#define IMATRIXOPT_H

#include "../../Eigen/Sparse"
#include <string.h>

typedef Eigen::Matrix<float, Eigen::Dynamic, 1> VecX;

class IMatrixOpt
{
public:
	virtual float get(int x, int y) = 0;
	virtual void set(int x, int y, float val) = 0;
	virtual int rows() = 0;
	virtual int cols() = 0;
	virtual void setCol(VecX& vec, int index) = 0;
	virtual void col(VecX& vec, int index) = 0;
	virtual void print() = 0;
	virtual void printToFile() = 0;
	virtual void normalize(int index) = 0;
};
#endif
