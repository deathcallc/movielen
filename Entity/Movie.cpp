#include <iostream>
#include <string.h>
#include "Movie.h"

using namespace std;

Movie::Movie()
{
	clear();
}

MOVIES_FLAG Movie::getFlag(const string flag)
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

void Movie::setMovieId(const int id)
{
	Movie::movieId = id;
}

int Movie::getMovieId()
{
	return Movie::movieId;
}

void Movie::setTitle(const string t)
{
	Movie::title = t;
}

string Movie::getTitle()
{
	return Movie::title;
}

void Movie::setGenres(const MOVIES_FLAG flag)
{
	Movie::genres = flag;
}

void Movie::addGenresFlag(const MOVIES_FLAG f)
{
	Movie::genres |= f;
}

void Movie::addGenresFlag(const string &f)
{
	return addGenresFlag(getFlag(f));
}

void Movie::removeGenresFlag(const MOVIES_FLAG flag)
{
	Movie::genres &= (~flag);
}

void Movie::removeGenresFlag(const string flag)
{
	return removeGenresFlag(getFlag(flag));
}

bool Movie::hasGenresFlag(const MOVIES_FLAG flag)
{
	if((flag & Movie::genres) != 0)
	{
		return true;
	}
	return false;
}

bool Movie::hasGenresFlag(const string flag)
{
	return hasGenresFlag(getFlag(flag));
}

MOVIES_FLAG Movie::getGenres()
{
	return Movie::genres;
}

void Movie::clear()
{
	Movie::movieId = -1;
	Movie::title = "";
	Movie::genres = 0;
}

ostream& operator<<(ostream& out, Movie& l)
{
	out<<"movieId : "<<l.movieId<<endl;
	out<<"title : "<<l.title<<endl;
	out<<"genres : "<<l.genres<<endl;
	return out;
}
