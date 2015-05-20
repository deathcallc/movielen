#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Model/Matrix/SparseMatriOpt.h"
#include "Model/Matrix/IMatrixOpt.h"
#include "Model/Matrix/MatrixOpt.h"
#include "Service/DateInput.h"
#include "Cfg/Configuration.h"
#include "Service/RatingReader.h"
#include "Service/MovieReader.h"
#include "Entity/Rating.h"
#include "Entity/Rating.h"
#include "Pretreatment.h"
#include "Cluster.h"

using namespace std;

int main()
{
/*	MatrixOpt sp(4, 6);
	int num[24] = {1,2,1,4,5,9,
		2,2,10,8,1,6,
		1,8,1,4,2,6,
		2,2,2,3,10,15};

	IMatrixOpt* im = &sp;
	int n = 0;
	for(int i = 0; i < im->rows(); i++)
	{
		for(int j = 0; j < im->cols(); j++)
		{
			im->set(i,j,num[n]);
			n++;
		}
	}

	MatrixOpt sem(6,6);
	Cluster cl;
	cl.createSemMatrix(&sp, &sem);
	cout<<"result:"<<endl;
	sem.balance();
	sem.print();*/
//	cout<<"rows: "<<im->rows()<<" col:"<<im->cols()<<endl;
/*	VecX vec(7);
	vec<<1,2,3,4,5,6,7;
	im->setCol(vec, 2);
	VecX re(7);
	im->col(re,2);
	cout<<re<<endl;*/
	
/*	Movie m;
	MovieReader mr("/home/lxw/movielen/ml-1m/t_movies.dat");
//	MovieReader mr(LATEST_MOVIES_FILE_PATH);
	while(mr.getNextMovie(m))
	{
		cout<<m<<endl;
	}
*/	
/*	MatrixOpt sp(2000, 2000);
	sp.readDateFromFile("/home/zergling/movielen/program/movielen/matrixtest");
	Eigen::VectorXf xf = sp.eigenvalues();
	FILE* fout = fopen("./eigenvalues","w+");
	for(int i = 0; i < xf.rows(); i++)
	{
		fprintf(fout,"%f ",xf[i]);
	}
	fclose(fout);*/
	
/*	int num[9] = {1,1,0,4,3,0,1,0,2};
	MatrixOpt la(3,3);
	MatrixOpt ma(3,3);
	ma.initMatrix(num);
//	ma.print();
	MatrixOpt vc(3,3);
	ma.eigenvectors(vc);
	vc.printToFile("./EigenVector.txt");
	cout<<endl;
*/
/*	MatrixOpt ma(USER_NUM, USER_NUM);
	MatrixOpt la(USER_NUM, USER_NUM);
	ma.readDateFromFile("/home/zergling/movielen/program/matrix");
	cout<<"Get Matrix!"<<endl;
	ma.genLaplacianMatrix(la);
	cout<<"Get Laplacian!"<<endl;
	MatrixOpt vec(USER_NUM, USER_NUM);
	la.eigenvectors(vec);
	
	vec.printToFile("./EigenVector.txt");
//	VecX xf = la.eigenvalues();
	cout<<"Get eigenvectors!"<<endl;*/

	

	/*
	FILE* fout = fopen("./eigenvalues","w+");
	for(int i = 0; i < xf.rows(); i++)
	{
		if(xf[i] < 0.0000001)
		{
			xf[i] = 0;
		}
		fprintf(fout,"%f ",xf[i]);
	}
	fclose(fout);
	cout<<"Finish!"<<endl;*/
//	sp.transpose();
//	MatrixOpt sem(2000,2000);
//	sp.print(); 
/*	MatrixOpt sp(MOVIE_NUM, USER_NUM);
	MatrixOpt sem(USER_NUM, USER_NUM);
	Pretreatment pre
	pre.createRatingMatrix(&sp,RATING_FILE_PATH);*/
	
/*	Cluster cl;
	cl.createSemMatrix(&sp, &sem);
	sem.balance();
	sem.printToFile();*/


	Cluster cl;
	cl.genTopkEigenVector("./eigenvalues","./EigenVector.txt","./submatrix",USER_NUM,USER_NUM,10);
/*	
	
	MatrixOpt sp(2000, 30);
	sp.readDateFromFile(TEST_DATE_PATH);
	sp.print();

*/

	
	return 0;
}
