#include <iostream>
#include <cmath>

using namespace std;

int n_Count(int n);

int main(void)
{
	int n, answer, count, sum, check = 0, temp;

	cin >> n;
	count = n_Count(n);
	for (int i = 1 * pow(10, count - 2); i < n; i++)
	{
		temp = i;
		sum = temp;
		while (temp > 0)
		{
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == n)
		{
			answer = i;
			check = 1;
			break;
		}
	}
	if (check == 0)
		answer = 0;

	cout << answer << endl;

	return 0;
}

int n_Count(int n)
{
	int count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return count;
}