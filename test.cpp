#include <iostream>
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
/*	MatrixOpt sp(MOVIE_NUM, USER_NUM);
	MatrixOpt sem(USER_NUM, USER_NUM);
	Pretreatment pre;
	pre.createRatingMatrix(&sp,RATING_FILE_PATH);
	
	Cluster cl;
	cl.createSemMatrix(&sp, &sem);
	sem.balance();
	sem.printToFile();*/

	
	
	MatrixOpt sp(2000, 30);
	sp.readDateFromFile(TEST_DATE_PATH);
	sp.print();





//	pre.createRatingMatrix(im,"/home/lxw/movielen/ml-1m/t_ratings.dat");
//	im->printToFile();
//	pre.authorDatePretreat("/home/lxw/network/Date/e_AMiner-Author.txt");
//	pre.authorDatePretreat(AUTHOR_FILE_PATH);
//	pre.paperDatePretreat("/home/lxw/network/Date/e_AMiner-Paper.txt");
//	pre.countPaper("/home/lxw/network/Date/e_AMiner-Paper.txt");
//	pre.countPaper(PAPER_FILE_PATH);
	
	return 0;
}
