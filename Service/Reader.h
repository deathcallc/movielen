#ifndef READER_H
#define READER_H

#include <string.h>
#include <fstream>
#include <vector>

class Reader
{
protected:
	std::string path;
	std::ifstream fin;
	void split(std::string str, std::string p, std::vector<std::string>& vec);
public:
	Reader(std::string p);
	~Reader();

};

#endif
