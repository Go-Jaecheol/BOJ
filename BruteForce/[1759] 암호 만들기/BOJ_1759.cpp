#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int l, c;
vector <char> alpha;

void print(int index, string s);
int check(string s);

int main(void)
{
	char temp;

	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		cin >> temp;
		alpha.push_back(temp);
	}
	sort(alpha.begin(), alpha.end());

	print(0, "");

	return 0;
}

void print(int index, string s)
{
	if (s.length() == l)
	{
		if (check(s) != -1)
			cout << s << endl;
		return;
	}
	else
	{
		if (index >= c)
			return;
		print(index + 1, s + alpha[index]);
		print(index + 1, s);
	}
}

int check(string s)
{
	int vowel = 0, cons = 0;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			vowel++;
		else
			cons++;
	}

	if (vowel < 1)
		return -1;
	if (cons < 2)
		return -1;
	else
		return 0;
}