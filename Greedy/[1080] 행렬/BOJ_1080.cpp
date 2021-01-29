#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Input_Matrix(vector< vector<int> > &v, int n, int m);
void Clear_Matrix(vector< vector<int> > &v, int n);
void Reverse(vector< vector<int> > &v, int a, int b);
int Check(vector< vector<int> > v1, vector< vector<int> > v2, int n, int m);

int main(void)
{
	int n, m, count = 0, check = 0;
	vector< vector<int> > matrix_A;
	vector< vector<int> > matrix_B;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		vector<int> element_A(m);
		matrix_A.push_back(element_A);
	}
	Input_Matrix(matrix_A, n, m);
	for (int i = 0; i < n; i++)
	{
		vector<int> element_B(m);
		matrix_B.push_back(element_B);
	}
	Input_Matrix(matrix_B, n, m);

	for (int i = 0; i + 2 < n; i++)
	{
		for (int j = 0; j + 2 < m; j++)
		{
			if (matrix_A[i][j] != matrix_B[i][j])
			{
				Reverse(matrix_A, i, j);
				count++;
			}
		}
	}
	check = Check(matrix_A, matrix_B, n, m);
	if (check == -1)
		count = -1;

	cout << count << endl;

	Clear_Matrix(matrix_A, n);
	Clear_Matrix(matrix_B, n);

	return 0;
}

void Input_Matrix(vector< vector<int> > &v, int n, int m)
{
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == '0')
				v[i][j] = 0;
			else
				v[i][j] = 1;
		}
	}
}

void Clear_Matrix(vector< vector<int> > &v, int n)
{
	for (int i = 0; i < n; i++)
	{
		v[i].clear();
	}
	v.clear();
}

void Reverse(vector< vector<int> > &v, int a, int b)
{
	for (int i = a; i <= a + 2; i++)
	{
		for (int j = b; j <= b + 2; j++)
		{
			if (v[i][j] == 0)
				v[i][j] = 1;
			else
				v[i][j] = 0;
		}
	}
}

int Check(vector< vector<int> > v1, vector< vector<int> > v2, int n, int m)
{
	int check = 0, count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v1[i][j] != v2[i][j])
			{
				check++;
				break;
			}
		}
	}
	if (check != 0)
		return -1;
	return 0;
}