#include <iostream>
#include "Eigen/Sparse"

using namespace std;
using namespace Eigen;

#define NODES 34546

int main()
{
	SparseMatrix<int> mat(NODES,NODES);
	mat.insert(10000,10000) = 1;
	cout<<mat.coeffRef(10000,10000)<<endl;
	return 0;
}
