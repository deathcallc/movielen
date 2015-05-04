#ifndef MOVIEREADER_H
#define MOVIEREADER_H

#include "../Entity/Movie.h"
#include "Reader.h"
#include <string.h>
#include <fstream>
#include <vector>

class MovieReader:public Reader
{
private:
public:
	MovieReader(std::string p);
	~MovieReader();
	bool getNextMovie(Movie& m);
};

#endif
