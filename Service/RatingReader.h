#ifndef RATINGREADER_H
#define RATINGREADER_H

#include "../Entity/Rating.h"
#include "Reader.h"
#include <string.h>
#include <fstream>
#include <vector>

class RatingReader:public Reader
{
private:
public:
	RatingReader(std::string p);
	~RatingReader();
	bool getNextRating(Rating& p);
};

#endif
