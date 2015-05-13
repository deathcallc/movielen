#include "Cluster.h"
#include <iostream>
#include "Model/Matrix/IMatrixOpt.h"
#include "Model/Matrix/MatrixOpt.h"
#include <cmath>

using namespace std;

void Cluster::MP(MatrixOpt* sp, int index, float norm, VecX& tar, VecX& coef)
{
//	cout<<"norm: "<<norm<<endl;
	float max = 0;
	float dot = 0;
	int patchIndex = 0;
	VecX d;
	for(int i = 0; i < sp->cols(); i++)
	{
		if(i == index)
		{
			continue;
		}

		sp->col(d,i);
//		d.normalize();
		dot = tar.dot(d);
		if(abs(dot) > max)
		{
			max = dot;
			patchIndex = i;
		}
	}
	coef(patchIndex, 0) += max;
	sp->col(d,patchIndex);
//	d.normalize();

	tar -= max*d;
//	cout<<"max: "<<max<<"  index: "<<patchIndex<<"  norm:"<<norm<<endl;
	float tNorm = tar.norm();
	if(abs(tNorm - norm) > OP_RESIDUAL)
	{
		MP(sp, index, tNorm, tar, coef);
	}
	else
	{
		return;
	}
}

void Cluster::createSemMatrix(MatrixOpt* doc, MatrixOpt* sem)
{
	VecX tar;
	MatrixOpt tmp(doc->rows(), doc->cols());
//	doc->print();
//	cout<<endl;
	clone(tmp, (*doc));
	tmp.normalize();
//	tmp.print();

	for(int i = 0; i < doc->cols(); i++)
	{
		cout<<"i= "<<i<<endl;
		VecX v(VecX::Zero(sem->cols()));
		doc->col(tar,i);
		MP(&tmp, i, 0, tar, v);
		sem->setCol(v,i);
	}
}

