#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string.h>

const std::string LATEST_LINKS_FILE_PATH = "/home/lxw/movielen/ml-latest/links.csv";
const std::string LATEST_MOVIES_FILE_PATH = "/home/lxw/movielen/ml-latest/movies.csv";
const std::string LATEST_RATING_FILE_PATH = "/home/lxw/movielen/ml-latest/ratings.csv";
const std::string LATEST_TAGS_FILE_PATH = "/home/lxw/movielen/ml-latest/tags.csv";

const int LATEST_MOVIE_NUM = 27000;
const int LATEST_USER_NUM = 230000;

const std::string ONEM_USERS_FILE_PATH = "/home/lxw/movielen/ml-1m/users.dat";
const std::string ONEM_MOVIES_FILE_PATH = "/home/lxw/movielen/ml-1m/movies.dat";
const std::string ONEM_RATING_FILE_PATH = "/home/lxw/movielen/ml-1m/ratings.dat";

const int ONEM_MOVIE_NUM = 4000;
const int ONEM_USER_NUM = 6000;

#ifdef ONEM_DATE

const std::string USERS_FILE_PATH = ONEM_USERS_FILE_PATH;
const std::string MOVIES_FILE_PATH = ONEM_MOVIES_FILE_PATH;
const std::string RATING_FILE_PATH = ONEM_RATING_FILE_PATH;

const int MOVIE_NUM = ONEM_MOVIE_NUM;
const int USER_NUM = ONEM_USER_NUM;

#endif

#ifdef LATEST_DATE

const std::string LINKS_FILE_PATH = LATEST_LINKS_FILE_PATH;
const std::string MOVIES_FILE_PATH = LATEST_MOVIES_FILE_PATH;
const std::string RATING_FILE_PATH = LATEST_RATING_FILE_PATH;
const std::string TAGS_FILE_PATH = LATEST_TAGS_FILE_PATH;

const int MOVIE_NUM = LATEST_MOVIE_NUM;
const int USER_NUM = LATEST_USER_NUM;

#endif

#endif
