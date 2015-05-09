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

using namespace std;

int main()
{
//	SpMatrix sp(LATEST_MOVIE_NUM, LATEST_USER_NUM);
//	SpMatrix sp(7, ONEM_MOVIE_NUM);
	
	MatrixOpt sp(MOVIE_NUM, USER_NUM);
//	MatrixOpt sp(7, MOVIE_NUM);
	IMatrixOpt* im = &sp;
//	cout<<"rows: "<<im->rows()<<" col:"<<im->cols()<<endl;
//	im->set(1,1,50);
//	im->set(2,2,40);
//	im->set(4,5,60);
//	im.printToFile();
//	sp.set(10000,10000,100);
//	cout<<im->get(1,1)<<endl;
//	im->printToFile();
	
/*	Rating r;
	RatingReader rd("/home/lxw/movielen/ml-1m/t_ratings.dat");
	while(rd.getNextRating(r))
	{
//		cout<<r<<endl;
		if(r.getMovieId() == 1 || r.getMovieId() == 2 ||
			r.getMovieId() == 3 || r.getMovieId() == 4 ||
			r.getMovieId() == 5)
			{
				cout<<r<<endl;
			}
	}
*/
/*	Movie m;
	MovieReader mr("/home/lxw/movielen/ml-1m/t_movies.dat");
//	MovieReader mr(LATEST_MOVIES_FILE_PATH);
	while(mr.getNextMovie(m))
	{
		cout<<m<<endl;
	}
*/	
	Pretreatment pre;
	pre.createRatingMatrix(im,RATING_FILE_PATH);
//	pre.createRatingMatrix(im,"/home/lxw/movielen/ml-1m/t_ratings.dat");
	im->printToFile();
//	pre.authorDatePretreat("/home/lxw/network/Date/e_AMiner-Author.txt");
//	pre.authorDatePretreat(AUTHOR_FILE_PATH);
//	pre.paperDatePretreat("/home/lxw/network/Date/e_AMiner-Paper.txt");
//	pre.countPaper("/home/lxw/network/Date/e_AMiner-Paper.txt");
//	pre.countPaper(PAPER_FILE_PATH);
	
	return 0;
}
