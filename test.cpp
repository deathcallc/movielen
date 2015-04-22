#include <iostream>
#include <fstream>
#include "Model/SparseMatri/SparseMatriOpt.h"
#include "Service/DateInput.h"
#include "Cfg/Configuration.h"
#include "Service/RatingReader.h"
#include "Entity/Rating.h"

using namespace std;

int main()
{
/*	SpMatrix sp(NODE_NUM, NODE_NUM);
	sp.set(10000,10000,100);
//	cout<<sp.get(10000,10000)<<endl;

	DateInput input(NODE_NUM, NODE_NUM);
	if(!access(FILE_PATH,F_OK))
	{
//		cout<<"abccccc"<<endl;
	}i
	
	ifstream in;
	in.open(FILE_PATH,ios::out | ios::app | ios::binary);
	input.readDate(in);
	in.close();

	PaperReader pr("/home/lxw/network/Date/e_AMiner-Paper.txt");

	
	Paper p;
	
	while(pr.getNextPaper(p))
	{
		cout<<p;
		cout<<endl;
	}


	AuthorReader ar("/home/lxw/network/Date/e_AMiner-Author.txt");
	
	Author p;
	while(ar.getNextAuthor(p))
	{
		cout<<p;
		cout<<endl;
	}*/

	Rating r;
	RatingReader rd("/home/lxw/movielen/ml-latest/t_ratings.csv");
	while(rd.getNextRating(r))
	{
		cout<<r<<endl;
	}
	
//	Pretreatment pre;
//	pre.paperDatePretreat(PAPER_FILE_PATH);
//	pre.authorDatePretreat("/home/lxw/network/Date/e_AMiner-Author.txt");
//	pre.authorDatePretreat(AUTHOR_FILE_PATH);
//	pre.paperDatePretreat("/home/lxw/network/Date/e_AMiner-Paper.txt");
//	pre.countPaper("/home/lxw/network/Date/e_AMiner-Paper.txt");
//	pre.countPaper(PAPER_FILE_PATH);
	
	return 0;
}
