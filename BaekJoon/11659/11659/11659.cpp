#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nCnt;
	int answerCnt;

	cin >> nCnt;
	cin >> answerCnt;


	int sumArr[100001];

	sumArr[0] = 0;
	int num;
	for (int i = 1; i < nCnt + 1; i++)
	{
		cin >> num;
		sumArr[i] = num + sumArr[i - 1];
	}
	int startArr[100001];
	int endArr[100001];
	for (int i = 0; i < answerCnt; i++)
	{
		cin >> startArr[i] >> endArr[i];
	}
	for (int i = 0; i < answerCnt; i++)
	{
		cout << sumArr[endArr[i]] - sumArr[startArr[i] - 1] << '\n';
	}

}
