#ifndef VECOPT_H
#define VECOPT_H

#include "../../Eigen/Dense"
#include "IVecOpt.h"

typedef Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> VecX;

class VecOpt:public IVecOpt
{
private:
	VecX vec;
public:
	VecX(int x);
	float get(int index);
	void set(int index, float val);
	int rows();
	float dot(IVecOpt& vec);
	float norm();
//	void printToFile();
};
#endif
