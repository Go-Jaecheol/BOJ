#include <iostream>
#include <vector>

using namespace std;
void inputCard(vector<int>& v, int n);
int chooseCard(vector<int> card, int n, int m);

int main()
{
	vector<int> card;
	int n, m, max;

	cin >> n >> m;
	inputCard(card, n);

	max = chooseCard(card, n, m);

	cout << max;

	return 0;
}

void inputCard(vector<int>& v, int n)
{
	int item;
	for (int i = 0; i < n; i++)
	{
		cin >> item;
		v.push_back(item);
	}
}

int chooseCard(vector<int> card, int n, int m)
{
	int sum, max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = card[i] + card[j] + card[k];
				if (sum > m)
					continue;
				if (sum > max)
					max = sum;
			}
		}
	}
	return max;
}