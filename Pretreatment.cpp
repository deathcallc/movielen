#include <iostream>
#include <fstream>
#include <limits.h>
#include <float.h>
#include <set>
#include "Cfg/Configuration.h"
#include "Service/RatingReader.h"
#include "Entity/Rating.h"
#include "Model/SparseMatri/SparseMatriOpt.h"
#include "Pretreatment.h"

using namespace std;

void Pretreatment::createRatingMatrix(SpMatrix &sp, string path)
{
	Rating r;
	RatingReader rd(path);
	while(rd.getNextRating(r))
	{
		short rat = (short)(r.getRating() * 10);
		cout<<r<<endl;
		sp.set(r.getMovieId(),r.getUserId(), rat);
	}
}
