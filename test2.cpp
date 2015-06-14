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
	int col = USER_NUM;
	int row = MOVIE_NUM;

	MatrixOpt orimatrix(row, col);

	Preprocess p;
	p.createRatingMatrix(&orimatrix,RATING_FILE_PATH);
	orimatrix.printToFile("./orimatrix");
	MatrixOpt sem(col,col);
	Cluster cl;
	cl.createSemMatrix(&orimatrix, &sem);
	sem.balance();
	sem.printToFile("./matrix");
	cout<<"Get SemMatrix!"<<endl;


/*	MatrixOpt la(col, col);
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
