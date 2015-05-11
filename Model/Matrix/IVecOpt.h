#ifndef IVECOPT_H
#define IVECOPT_H

#include "../../Eigen/Sparse"

class IVecOpt
{
public:
	virtual float get(int index) = 0;
	virtual void set(int index, float val) = 0;
	virtual int rows() = 0;
	virtual float dot(IVecOpt* vec);
	virtual float norm();
//	virtual void printToFile() = 0;
};
#endif
