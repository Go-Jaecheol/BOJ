#include <iostream>
#include <cmath>

using namespace std;

int n_Count(int n);
int Decomposition(int n, int temp);	// Recursion

int main(void)
{
	int n, answer, count;

	cin >> n;
	count = n_Count(n);
	answer = Decomposition(n, 1 * pow(10, count - 2));
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

int Decomposition(int n, int temp)
{
	int sum, num;
	sum = temp;
	num = temp;
	while (temp > 0)
	{
		sum += temp % 10;
		temp /= 10;
	}

	if (n == num)
		return 0;
	if (sum == n)
		return num;
	else
		Decomposition(n, num + 1);

}