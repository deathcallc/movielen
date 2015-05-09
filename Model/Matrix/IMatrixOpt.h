#ifndef IMATRIXOPT_H
#define IMATRIXOPT_H

#include "../../Eigen/Sparse"

class IMatrixOpt
{
public:
	virtual short get(int x, int y) = 0;
	virtual void set(int x, int y, short val) = 0;
	virtual int rows() = 0;
	virtual int cols() = 0;
	virtual void printToFile() = 0;
};
#endif
