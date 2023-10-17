#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	list<pair<int,int>> stack;
	int n;
	cin >> n;
	vector<int> answers(n,-1);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		while (!stack.empty()&& stack.back().second<num)
		{
			answers[stack.back().first] = num;
			stack.pop_back();
		}
		stack.push_back(make_pair(i, num));
	}
	for (int answer : answers)
	{
		cout << answer << ' ';
	}
}
