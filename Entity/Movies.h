#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <string.h>

typedef int MOVIES_FLAG;

const MOVIES_FLAG MOVIES_FLAG_ACTION = 1<<1;
const MOVIES_FLAG MOVIES_FLAG_ADVENTURE = 1<<2;
const MOVIES_FLAG MOVIES_FLAG_ANIMATION = 1<<3;
const MOVIES_FLAG MOVIES_FLAG_CHILDRENS = 1<<4;
const MOVIES_FLAG MOVIES_FLAG_COMEDY = 1<<5;
const MOVIES_FLAG MOVIES_FLAG_CRIME = 1<<6;
const MOVIES_FLAG MOVIES_FLAG_DOCUMENTARY = 1<<7;
const MOVIES_FLAG MOVIES_FLAG_DRAMA = 1<<8;
const MOVIES_FLAG MOVIES_FLAG_FANTASY = 1<<9;
const MOVIES_FLAG MOVIES_FLAG_FILMNOIR = 1<<10;
const MOVIES_FLAG MOVIES_FLAG_HORROR = 1<<11;
const MOVIES_FLAG MOVIES_FLAG_MUSICAL = 1<<12;
const MOVIES_FLAG MOVIES_FLAG_MYSTERY = 1<<13;
const MOVIES_FLAG MOVIES_FLAG_ROMANCE = 1<<14;
const MOVIES_FLAG MOVIES_FLAG_SCIFI = 1<<15;
const MOVIES_FLAG MOVIES_FLAG_THRILLER = 1<<16;
const MOVIES_FLAG MOVIES_FLAG_WAR = 1<<17;
const MOVIES_FLAG MOVIES_FLAG_WESTERN = 1<<18;

const std::string MOVIES_ACTION = "Action";
const std::string MOVIES_ADVENTURE = "Adventure";
const std::string MOVIES_ANIMATION = "Animation";
const std::string MOVIES_CHILDRENS = "Children's";
const std::string MOVIES_COMEDY = "Comedy";
const std::string MOVIES_CRIME = "Crime";
const std::string MOVIES_DOCUMENTARY = "Documentary";
const std::string MOVIES_DRAMA = "Drama";
const std::string MOVIES_FANTASY = "Fantasy";
const std::string MOVIES_FILMNOIR = "Film-Noir";
const std::string MOVIES_HORROR = "Horror";
const std::string MOVIES_MUSICAL = "Musical";
const std::string MOVIES_MYSTERY = "Mystery";
const std::string MOVIES_ROMANCE = "Romance";
const std::string MOVIES_SCIFI = "Sci-Fi";
const std::string MOVIES_THRILLER = "Thriller";
const std::string MOVIES_WAR = "War";
const std::string MOVIES_WESTERN = "Western";

class Movies
{
private:
	int movieId;
	std::string title;
	MOVIES_FLAG genres;

	MOVIES_FLAG getFlag(const std::string flag);
public:
	Movies();
	void setMovieId(const int id);
	int getMovieId();
	void setTitle(const std::string t);
	std::string getTitle();
	void setGenres(const MOVIES_FLAG flag);
	void addGenresFlag(const MOVIES_FLAG flag);
	void addGenresFlag(const std::string flag);
	void removeGenresFlag(const MOVIES_FLAG flag);
	void removeGenresFlag(const std::string flag);
	bool hasGenresFlag(const MOVIES_FLAG flag);
	bool hasGenresFlag(const std::string flag);
	MOVIES_FLAG getGenres();

	void clear();
	friend std::ostream& operator<<(std::ostream& out, Movies& l);
	
};

#endif
