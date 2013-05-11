#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <list>
#include <climits>

using namespace std;

int C;
int n, p;

struct Matrix
{
	vector<vector<int> > matrix;

	Matrix(vector<vector<int> > init)
	{
		int size = init.size();
		matrix.resize(size);
		for(int i = 0; i < size; i++)
		{
			matrix[i].resize(size);
			for(int j = 0; j < size; j++)
			{
				matrix[i][j] = init[i][j];
			}
		}
	}

	Matrix product(Matrix rhs) const
	{
		int size = matrix.size();
		vector<vector<int> > result;

		result.resize(size);
		for(int i = 0; i < size; i++)
		{
			result[i].resize(size);
			for(int j = 0; j < size; j++)
			{
				result[i][j] = 0;
				for(int k = 0; k < size; k++)
				{
					result[i][j] += matrix[i][k]*rhs.matrix[k][j];
					result[i][j] %= 10007;
				}
			}
		}
		return Matrix(result);
	}
};

Matrix getResult(Matrix m, int p)
{
	if(p == 1) return m;
	if(p % 2 == 1) return m.product(getResult(m, p-1));

	Matrix h = getResult(m, p/2);

	return h.product(h);
}

int main()
{       
	scanf("%d", &C);

	while(C --> 0)
	{       
		vector<vector<int> > matrix;
		scanf("%d %d", &n, &p);
		matrix.resize(n);
		for(int i = 0; i < n; i++)
		{
			matrix[i].resize(n);
			for(int j = 0; j < n; j++)
			{
				scanf("%d", &matrix[i][j]);
			}
		}

		Matrix result = getResult(Matrix(matrix), p);

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				printf("%d%c", result.matrix[i][j], j < n-1 ? ' ' : '\n');
			}
		}
	}

	return 0;
}
