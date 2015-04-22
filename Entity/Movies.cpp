#include <iostream>
#include <string.h>
#include "Movies.h"

using namespace std;

void Movies::setMovieId(const int id)
{
	Movies::movieId = id;
}

int Movies::getMovieId()
{
	return Movies::movieId;
}

void Movies::setTitle(const string t)
{
	Movies::title = t;
}

string Movies::getTitle()
{
	return Movies::title;
}

void Movies::setGenres(const MOVIES_FLAG flag)
{
	Movies::genres = flag;
}

void Movies::addGenresFlag(const MOVIES_FLAG flag)
{
	Movies::genres |= flag;
}

void Movies::removeGenresFlag(const MOVIES_FLAG flag)
{
	Movies::genres &= (~flag);
}

bool Movies::hasGenresFlag(const MOVIES_FLAG flag)
{
	if((flag & Movies::genres) != 0)
	{
		return true;
	}
	return false;
}

MOVIES_FLAG Movies::getGenres()
{
	return Movies::genres;
}

void Movies::clear()
{
	Movies::movieId = -1;
	Movies::title = "";
	Movies::genres = 0;
}

ostream& operator<<(ostream& out, Movies& l)
{
	out<<"movieId : "<<l.movieId<<endl;
	out<<"title : "<<l.title<<endl;
	out<<"genres : "<<l.genres<<endl;
	return out;
}
