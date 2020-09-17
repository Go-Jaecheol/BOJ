#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>	//To use pair Class

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b); //pair�� second�������� ��������

// ó�� �����Ҷ� ����ð��� �������� �������� �����ϰ� (������ ���۽ð� ���� ��������)
// ���� ù��°�� �� �� �ִ� �� == ���� ù��° ��
// �״��� �� �� �ִ� �� == ���۽ð��� <�� �� ���� ����ð�> �̻��� �� �� ���� ���� ���� ��
// ����ð��� �������� ������ ��Ȳ��

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
	// ���� �� �������� ��⸸ �ߴ� �ڵ�

	cout << cnt << endl;

	return 0;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;	// ������ first�������� ��������
	return a.second < b.second;
}