#ifndef PRETREATMENT_H
#define PRETREATMENT_H

#include <string.h>
#include "Model/SparseMatri/SparseMatriOpt.h"

class Pretreatment
{
public:
	void createRatingMatrix(SpMatrix &sp, std::string path);
};


#endif
