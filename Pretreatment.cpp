#include <iostream>
#include <fstream>
#include <limits.h>
#include <float.h>
#include <set>
#include "Cfg/Configuration.h"
#include "Service/RatingReader.h"
#include "Entity/Rating.h"
#include "Model/Matrix/IMatrixOpt.h"
#include "Pretreatment.h"

using namespace std;

void Pretreatment::createRatingMatrix(IMatrixOpt* sp, string path)
{
	Rating r;
	RatingReader rd(path);
	while(rd.getNextRating(r))
	{
		short rat = (short)(r.getRating() * 10);
//		cout<<r<<endl;
		cout<<"pre:"<<r.getUserId()<<endl;
		sp->set(r.getMovieId()-1,r.getUserId()-1, rat);
//		sp->set(r.getUserId(),r.getMovieId(), rat);
	}
}
