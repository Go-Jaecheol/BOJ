#include <iostream>

using namespace std;

int n;
int cnt = 0;
int board[14];			// ü���� ���� ��Ÿ���� ������ �迭

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
	if (Check(row) == -1)	// �ƴ� ���
		return;	
	if (row == n - 1)		// ������ �� ã�� ���
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		board[row + 1] = i;		// ���� ���̸� �ȵǴϱ� ���� ����� ����, ���� ����
		Queen(row + 1);
	}
}

int Check(int row)
{
	for (int i = 0; i < row; i++)
	{
		if (board[i] == board[row] || abs(board[i] - board[row]) == abs(i - row))	// ���� ���� ���� �밢���� ���
			return -1;
	}
	return 0;
}