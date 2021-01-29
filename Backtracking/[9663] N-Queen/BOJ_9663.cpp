#include <iostream>

using namespace std;

int n;
int cnt = 0;
int board[14];			// 체스판 행을 나타내는 일차원 배열

void Queen(int row);
int Check(int row);

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		board[0] = i;
		Queen(0);
	}

	cout << cnt << endl;

	return 0;
}

void Queen(int row)
{
	if (Check(row) == -1)	// 아닌 경우
		return;	
	if (row == n - 1)		// 정답을 다 찾은 경우
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		board[row + 1] = i;		// 같은 행이면 안되니까 다음 행부터 시작, 열을 저장
		Queen(row + 1);
	}
}

int Check(int row)
{
	for (int i = 0; i < row; i++)
	{
		if (board[i] == board[row] || abs(board[i] - board[row]) == abs(i - row))	// 열이 같을 때와 대각선인 경우
			return -1;
	}
	return 0;
}