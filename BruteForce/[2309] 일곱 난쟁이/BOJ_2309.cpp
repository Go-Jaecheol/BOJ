#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int input(vector<int>& v);
void makeNew(vector<int> v1, vector<int>& v2, int f1, int f2);
void print(vector<int> v);

int main(void)
{
	vector<int> dwarf(9);
	vector<int> realDwarf(7);
	int sum, fake_sum, fake1, fake2;

	sum = input(dwarf);
	fake_sum = sum - 100;

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (dwarf[i] + dwarf[j] == fake_sum)
			{
				fake1 = i;
				fake2 = j;
				break;
			}
		}
	}
	makeNew(dwarf, realDwarf, fake1, fake2);
	print(realDwarf);

	return 0;
}

int input(vector<int>& v)
{
	int sum = 0;
	for (int &item : v)
	{
		cin >> item;
		sum += item;
	}
	return sum;
}

void makeNew(vector<int> v1, vector<int>& v2, int f1, int f2)
{
	int j = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i == f1 || i == f2)
			continue;
		v2[j] = v1[i];
		j++;
	}
}

void print(vector<int> v)
{
	sort(v.begin(), v.end());

	for (int i = 0; i < 7; i++)
	{
		cout << v[i] << endl;
	}
}