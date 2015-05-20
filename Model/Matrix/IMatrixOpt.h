#ifndef IMATRIXOPT_H
#define IMATRIXOPT_H

#include "../../Eigen/Sparse"
#include <string.h>
typedef double MATRIX_TYPE;
typedef Eigen::Matrix<double, Eigen::Dynamic, 1> VecX;

class IMatrixOpt
{
public:
	virtual double get(int x, int y) = 0;
	virtual void set(int x, int y, double val) = 0;
	virtual int rows() = 0;
	virtual int cols() = 0;
	virtual void setCol(VecX& vec, int index) = 0;
	virtual void col(VecX& vec, int index) = 0;
	virtual void print() = 0;
	virtual void printToFile(std::string path) = 0;
	virtual void normalize(int index = -1) = 0;
	virtual void balance() = 0;
	virtual void readDateFromFile(std::string filePath) = 0;
};
#endif
