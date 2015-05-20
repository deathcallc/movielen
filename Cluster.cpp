#include "Cluster.h"
#include <iostream>
#include <fstream>
#include "Model/Matrix/IMatrixOpt.h"
#include "Model/Matrix/MatrixOpt.h"
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(Pair p1, Pair p2)
{
	return (p1.val > p2.val)?true:false;
}

void Cluster::genTopkEigenVector(const string valpath, const string vecpath, const string output, const int row, const int col, const int k)
{
	MatrixOpt mat(row, k);
	ifstream fin;
	vector<Pair> vec;

	fin.open(valpath.c_str(), ios::in | ios::app | ios::binary);
	double val;
	string str;
	int i = 0;
	while(!fin.eof())
	{
		fin>>str;
		val = atof(str.c_str());
		Pair p;
		p.id = i;
		p.val = val;
		vec.push_back(p);
		i++;
	}
	fin.close();

	vector<int> result;
	getTopkValue(vec,k+1,result);

	MatrixOpt ori(row, col);
	MatrixOpt eigenvec(row , k);
	ori.readDateFromFile(vecpath);
	for(int i = 1; i < result.size(); i++)
	{
		VecX ev(row);
		ori.col(ev, result[i]);
		eigenvec.setCol(ev, i-1);
	}

	eigenvec.printToFile(output);
}

void Cluster::getTopkValue(vector<Pair>& vec, int k, vector<int>& re)
{
	sort(vec.begin(), vec.end(), cmp);
	int n = (vec.size() < k)?vec.size():k;
	for(int i = 0; i < n; i++)
	{
		cout<<vec[i].val<<" "<<vec[i].id<<endl;
		re.push_back(vec[i].id);
	}
}

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

VecX Cluster::genEigenValues(const string sem, int rows, int cols)
{
	MatrixOpt ma(rows,cols);
	MatrixOpt la(rows,cols);
	ma.readDateFromFile(sem);
	ma.genLaplacianMatrix(la);
	return la.eigenvalues();
}
