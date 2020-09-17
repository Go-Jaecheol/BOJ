#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>	//To use pair Class

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b); //pair의 second기준으로 오름차순

// 처음 시작할때 종료시간을 기준으로 오름차순 정렬하고 (같으면 시작시간 기준 오름차순)
// 제일 첫번째로 올 수 있는 값 == 정렬 첫번째 값
// 그다음 올 수 있는 값 == 시작시간이 <그 전 값의 종료시간> 이상인 값 중 제일 정렬 빠른 값
// 종료시간이 빠를수록 최적의 상황임

int main()
{
	int n, start, finish, cnt = 0, current;
	vector<pair<int, int>> time;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> start >> finish;
		time.push_back({ start, finish });
	}
	sort(time.begin(), time.end(), compare);

	current = time[0].second;
	cnt++;

	for (int i = 1; i < n; i++)
	{
		if (time[i].first < current)
			continue;
		cnt++;
		current = time[i].second;
	}

	/*
	while (1)
	{
		prev_cnt = cnt;
		for (int i = index + 1; i < n; i++)
		{
			if (current <= time[i].first)
			{
				current = time[i].second;
				index = i;
				cnt++;
				break;
			}
		}
		if (prev_cnt == cnt)
			break;
	}
	*/
	// 수정 전 쓸데없이 길기만 했던 코드

	cout << cnt << endl;

	return 0;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;	// 같으면 first기준으로 오름차순
	return a.second < b.second;
}