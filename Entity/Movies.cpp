#include <iostream>
#include <string.h>
#include "Movies.h"

using namespace std;

Movies::Movies()
{
	clear();
}

MOVIES_FLAG Movies::getFlag(const std::string flag)
{
	if(MOVIES_ACTION == flag)
	{
		return MOVIES_FLAG_ACTION;
	}	
	if(MOVIES_ADVENTURE == flag)
	{
		return MOVIES_FLAG_ADVENTURE;	
	}
	if(MOVIES_ANIMATION == flag)
	{
		return MOVIES_FLAG_ANIMATION;
	}
	if(MOVIES_CHILDRENS == flag)
	{
		return MOVIES_FLAG_CHILDRENS;
	}
	if(MOVIES_COMEDY == flag)
	{
		return MOVIES_FLAG_COMEDY;
	}
	if(MOVIES_CRIME == flag)
	{
		return MOVIES_FLAG_CRIME;
	}
	if(MOVIES_DOCUMENTARY == flag)
	{
		return MOVIES_FLAG_DOCUMENTARY;
	}
	if(MOVIES_DRAMA == flag)
	{
		return MOVIES_FLAG_DRAMA;
	}
	if(MOVIES_FANTASY == flag)
	{
		return MOVIES_FLAG_FANTASY;
	}
	if(MOVIES_FILMNOIR == flag)
	{
		return MOVIES_FLAG_FILMNOIR;
	}
	if(MOVIES_HORROR == flag)
	{
		return MOVIES_FLAG_HORROR;
	}
	if(MOVIES_MUSICAL == flag)
	{
		return MOVIES_FLAG_MUSICAL;
	}
	if(MOVIES_MYSTERY == flag)
	{
		return MOVIES_FLAG_MYSTERY;
	}
	if(MOVIES_ROMANCE == flag)
	{
		return MOVIES_FLAG_ROMANCE;
	}
	if(MOVIES_SCIFI == flag)
	{
		return MOVIES_FLAG_SCIFI;
	}
	if(MOVIES_THRILLER == flag)
	{
		return MOVIES_FLAG_THRILLER;
	}
	if(MOVIES_WAR == flag)
	{
		return MOVIES_FLAG_WAR;
	}
	if(MOVIES_WESTERN == flag)
	{
		return MOVIES_FLAG_WESTERN;
	}
	return 0;
	
}

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

void Movies::addGenresFlag(const string flag)
{
	return addGenresFlag(getFlag(flag));
}

void Movies::removeGenresFlag(const MOVIES_FLAG flag)
{
	Movies::genres &= (~flag);
}

void Movies::removeGenresFlag(const string flag)
{
	return removeGenresFlag(getFlag(flag));
}

bool Movies::hasGenresFlag(const MOVIES_FLAG flag)
{
	if((flag & Movies::genres) != 0)
	{
		return true;
	}
	return false;
}

bool Movies::hasGenresFlag(const string flag)
{
	return hasGenresFlag(getFlag(flag));
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
