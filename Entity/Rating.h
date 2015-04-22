#ifndef RATING_H
#define RATING_H

#include <iostream>

class Rating
{
private:
	int userId;
	int movieId;
	double rating;
	long long timestamp;
public:
	void setUserId(const int id);
	int getUserId();
	void setMovieId(const int id);
	int getMovieId();
	void setRating(const double r);
	double getRating();
	void setTimestamp(const long long t);
	int getTimestamp();

	void clear();
	friend std::ostream& operator<<(std::ostream& out, Rating& r);
	
};

#endif
