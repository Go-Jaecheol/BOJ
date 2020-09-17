#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(vector<int> &v, int n);
int getSum(vector<int> v, int n);

int main()
{
	int n;
	vector<int> time;

	cin >> n;
	input(time, n);
	sort(time.begin(), time.end());
	
	cout << getSum(time, n) << endl;

	return 0;
}

void input(vector<int> &v, int n)
{
	int item;

	for (int i = 0; i < n; i++)
	{
		cin >> item;
		v.push_back(item);
	}
}

int getSum(vector<int> v, int n)
{
	int sum;

	sum = v[0];
	for (int i = 1; i < n; i++)
	{
		v[i] += v[i - 1];
		sum += v[i];
	}

	return sum;
}