#include <iostream>
#include <fstream>
#include "Model/SparseMatri/SparseMatriOpt.h"
#include "Service/DateInput.h"
#include "Cfg/Configuration.h"
#include "Service/RatingReader.h"
#include "Entity/Rating.h"
#include "Pretreatment.h"

using namespace std;

int main()
{
	SpMatrix sp(LATEST_MOVIE_NUM, LATEST_USER_NUM);
//	sp.set(10000,10000,100);
//	cout<<sp.get(10000,10000)<<endl;

	/*
	Rating r;
	RatingReader rd("/home/lxw/movielen/ml-latest/t_ratings.csv");
	while(rd.getNextRating(r))
	{
		cout<<r<<endl;
	}*/
	
	Pretreatment pre;
	pre.createRatingMatrix(sp,"/home/lxw/movielen/ml-latest/t_ratings.csv");
//	pre.authorDatePretreat("/home/lxw/network/Date/e_AMiner-Author.txt");
//	pre.authorDatePretreat(AUTHOR_FILE_PATH);
//	pre.paperDatePretreat("/home/lxw/network/Date/e_AMiner-Paper.txt");
//	pre.countPaper("/home/lxw/network/Date/e_AMiner-Paper.txt");
//	pre.countPaper(PAPER_FILE_PATH);
	
	return 0;
}
