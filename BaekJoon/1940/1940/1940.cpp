#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	long long N, M;
	long long small, big;
	cin >> N >> M;

	vector<long long> nums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	small = 0;
	big = nums.size() - 1;
	sort(nums.begin(), nums.end());
	long long answer = 0;
	while (small < big)
	{
		if (nums[small] + nums[big] == M)
		{
			answer++;
			small++;
			big--;
		}
		else if (nums[small] + nums[big] < M)
		{
			small++;
		}
		else
		{
			big--;
		}
	}
	cout << answer;
}