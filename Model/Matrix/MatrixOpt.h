#ifndef MATRIXOPT_H
#define MATRIXOPT_H

#include "../../Eigen/Dense"
#include "IMatrixOpt.h"

typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MatrixSX;

class MatrixOpt:public IMatrixOpt
{
private:
	MatrixSX mat;
public:
	MatrixOpt(int x, int y);
	MatrixSX& getMatrix();
	void transpose();
	double get(int x, int y);
	void set(int x, int y, double val);
	int rows();
	int cols();
	void print();
	void setCol(VecX& vec, int index);
	void col(VecX& vec, int index);
	void printToFile(std::string path);
	void normalize(int index = -1);
	void balance();
	void readDateFromFile(std::string filePath);
	void genLaplacianMatrix(MatrixOpt& la);
	void initMatrix(int* num);

	VecX eigenvalues();
	void eigenvectors(MatrixOpt& ev);
	friend void clone(MatrixOpt& a, MatrixOpt& b);
};
#endif
