#include <iostream>
#include "Link.h"

using namespace std;

void Link::setMovieId(const int id)
{
	Link::movieId = id;
}

int Link::getMovieId()
{
	return Link::movieId;
}

void Link::setImdbId(const int id)
{
	Link::imdbId = id;
}

int Link::getImdbId()
{
	return Link::imdbId;
}

void Link::setTmdbId(const int id)
{
	Link::tmdbId = id;
}

int Link::getTmdbId()
{
	return Link::tmdbId;
}

void Link::clear()
{
	Link::movieId = -1;
	Link::imdbId = -1;
	Link::tmdbId = -1;
}

ostream& operator<<(ostream& out, Link& l)
{
	out<<"movieId : "<<l.movieId<<endl;
	out<<"imdbId : "<<l.imdbId<<endl;
	out<<"tmdbId : "<<l.tmdbId<<endl;
	return out;
}
