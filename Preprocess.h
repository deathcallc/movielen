#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <string.h>
#include "Model/Matrix/IMatrixOpt.h"

class Preprocess
{
public:
	void createRatingMatrix(IMatrixOpt* sp, std::string path);
};


#endif
