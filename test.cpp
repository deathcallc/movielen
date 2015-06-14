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
#include "Preprocess.h"
#include "Cluster.h"

using namespace std;

int main()
{
	int col = 700;
	int row = 700;


	MatrixOpt sp(4, 6);
	MatrixOpt sem(6, 6);
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

	Cluster cl;
	cl.createSemMatrix(&sp,&sem);
	sem.print();

/*	MatrixOpt orimatrix(col, row);
	orimatrix.readDateFromFile("./dim20-18-15-12.txt");
	orimatrix.transpose();*/
/*	MatrixOpt sem(col,col);
	Cluster cl;
	cl.createSemMatrix(&orimatrix, &sem);
	sem.balance();

/*	sem.readDateFromFile("./normatrix");

	sem.printToFile("./matrix");


	MatrixOpt la(col, col);
	cout<<"Get Matrix!"<<endl;
	sem.genLaplacianMatrix(la);
	cout<<"Get Laplacian!"<<endl;
	MatrixOpt vec(col, col);
	la.eigenvectors(vec);
	
	vec.printToFile("./EigenVector");
	cout<<"Get eigenvectors!"<<endl;

	VecX xf = la.eigenvalues();
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
	cout<<"Get eigenvalues!"<<endl;
//	sp.transpose();
//	MatrixOpt sem(2000,2000);
//	sp.print(); 

	cl.genTopkEigenVector("./eigenvalues","./EigenVector","./submatrix",col,col,2);
	

	cout<<"Get Subeigenvectors!"<<endl;

	cout<<"Finish!"<<endl;
/*	
	
	MatrixOpt sp(2000, 30);
	sp.readDateFromFile(TEST_DATE_PATH);
	sp.print();

*/

	
	return 0;
}
