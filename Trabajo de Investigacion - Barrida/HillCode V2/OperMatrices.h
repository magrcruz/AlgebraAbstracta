#pragma once

#include <vector>
using namespace std;

class OperMatrices
{
public:
	OperMatrices();
	template<class T>
	vector<vector<T>> mult(vector<vector<T>>, vector<vector<T>>);
	
};

template<class T>
inline vector<vector<T>> OperMatrices::mult(vector<vector<T>>mat1, vector<vector<T>>mat2)
{
	if (mat1[0].size() == mat2.size()) {
		vector<vector<T>> result;
		for (int i = 0; i < mat1.size(); i++) {
			result.push_back(vector<T>());
			for (int j = 0; j < mat2[0].size(); j++) {
				
				result[i].push_back(0);
				for (int k = 0; k < mat1[1].size(); ++k)
				{
					result[i][j] += mat1[i][k] * mat2[k][j];
				}

			}
		}
		return result;
	}
	else {
		return vector<vector<T>>();
	}

}



