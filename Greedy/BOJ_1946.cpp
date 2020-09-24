#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n, start, finish, count, rank;
	vector<pair<int, int>> applicant;

	cin >> t;
	for (int k = 0; k < t; k++)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> start >> finish;
			applicant.push_back({ start, finish });
		}
		sort(applicant.begin(), applicant.end(),compare);

		count = 1;
		rank = applicant[0].second;

		for (int i = 1; i < n; i++)
		{
			if (applicant[i].second < rank)
			{
				count++;
				rank = applicant[i].second;
			}
		}

		cout << count << '\n';
		applicant.clear();
	}
	return 0;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}