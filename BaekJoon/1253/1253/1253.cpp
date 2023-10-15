#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	long long N;
	long long small, big;
	cin >> N;

	vector<long long> nums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	long long answer = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		small = 0;
		big = nums.size()-1;
		while (small < big)
		{
			if (nums[small] + nums[big] == nums[i])
			{
				if (small != i && big != i)
				{
					answer++;
					break;
				}
				else if (small == i)
				{
					small++;
				}
				else 
				{
					big--;
				}
			}
			else if (nums[small] + nums[big] < nums[i])
			{
				small++;
			}
			else
			{
				big--;
			}
		}
	}
	cout << answer;
}