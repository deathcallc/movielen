#include <iostream>
#include "Rating.h"

using namespace std;

void Rating::setUserId(const int id)
{
	Rating::userId = id;
}

int Rating::getUserId()
{
	return Rating::userId;
}

void Rating::setMovieId(const int id)
{
	Rating::movieId = id;
}

int Rating::getMovieId()
{
	return Rating::movieId;
}

void Rating::setRating(const double r)
{
	Rating::rating = r;
}

double Rating::getRating()
{
	return Rating::rating;
}

void Rating::setTimestamp(const long long t)
{
	Rating::timestamp = t;
}

int Rating::getTimestamp()
{
	return Rating::timestamp;
}

void Rating::clear()
{
	Rating::userId = -1;
	Rating::movieId = -1;
	Rating::rating = -1;
	Rating::timestamp = -1;
}

ostream& operator<<(ostream& out, Rating& r)
{
	out<<"userId : "<<r.userId<<endl;
	out<<"movieId : "<<r.movieId<<endl;
	out<<"Rating : "<<r.rating<<endl;
	out<<"Timestamp : "<<r.timestamp<<endl;
	return out;
}

