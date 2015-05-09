#ifndef PRETREATMENT_H
#define PRETREATMENT_H

#include <string.h>
#include "Model/Matrix/IMatrixOpt.h"

class Pretreatment
{
public:
	void createRatingMatrix(IMatrixOpt* sp, std::string path);
};


#endif
