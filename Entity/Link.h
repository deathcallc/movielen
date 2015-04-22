#ifndef LINK_H
#define LINK_H

#include <iostream>

class Link
{
private:
	int movieId;
	int imdbId;
	int tmdbId;
public:
	void setMovieId(const int id);
	int getMovieId();
	void setImdbId(const int id);
	int getImdbId();
	void setTmdbId(const int id);
	int getTmdbId();

	void clear();
	friend std::ostream& operator<<(std::ostream& out, Link& l);
	
};

#endif
