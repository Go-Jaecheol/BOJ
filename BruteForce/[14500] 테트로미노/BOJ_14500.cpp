#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void Input_paper(vector< vector<int> > &v, int n, int m);
void Clear_paper(vector< vector<int> > &v, int n); 
void DFS(int x, int y, int count, int sum);
void Exception(int x, int y);							// ㅗ 모양인 경우

int n, m;
int visit[500][500];
int offset[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int max_sum = 0;
vector < vector<int> > paper;							// paper[500][500]으로도 가능

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		vector<int> element(m);
		paper.push_back(element);
	}
	Input_paper(paper, n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visit[i][j] = 1;
			DFS(i, j, 1, paper[i][j]);
			Exception(i, j);
			visit[i][j] = 0;
		}
	}
	cout << max_sum << endl;

	Clear_paper(paper, n);
	return 0;
}

void Input_paper(vector< vector<int> > &v, int n, int m)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			v[i][j] = temp;
		}
	}
}

void Clear_paper(vector< vector<int> > &v, int n)
{
	for (int i = 0; i < n; i++)
		v[i].clear();
	v.clear();
}

void DFS(int x, int y, int count, int sum)	// 시작점 x,y를 기준으로 offset만큼 이동해서 만든 모든 테트로미노에 대한 경우의 수를 DFS로 탐색
{
	int next_x, next_y;
	if (count == 4)						// base case
	{
		max_sum = max(sum, max_sum);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		next_x = x + offset[i][0];		// x를 offset만큼 이동
		next_y = y + offset[i][1];		// y를 offset만큼 이동
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && visit[next_x][next_y] != 1)	// 범위안에 있고 방문한적 없을때
		{
			visit[next_x][next_y] = 1;
			DFS(next_x, next_y, count + 1, sum + paper[next_x][next_y]);	// Recursion
			visit[next_x][next_y] = 0;
		}
	}
}

void Exception(int x, int y)		// ㅗ 모양에서 제일 중앙이 기준 x,y
{
	int sum, next_x, next_y, check;
	
	for (int cnt = 0; cnt < 4; cnt++)
	{
		sum = paper[x][y];
		check = 0;
		for (int i = 0; i < 4; i++)
		{
			if (i == cnt)			// 중앙을 기준으로 상하좌우 중 3가지만 추가하므로 하나는 제외 (4개중에 3개 뽑음)
				continue;
			next_x = x + offset[i][0];
			next_y = y + offset[i][1];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m)	// 범위안에 있는 경우에만
			{
				sum += paper[next_x][next_y];
				check++;
			}
		}
		if (check == 3)				// 3가지 다 범위안에 있는 경우 == check가 3
			max_sum = max(sum, max_sum);
	}
}