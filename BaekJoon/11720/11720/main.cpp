#include <iostream>
#include <string>
using namespace std;
int main()
{
	int numCnt;
	cin >> numCnt;
	string numStr;
	cin >> numStr;
	int sum = 0;
	for (int i = 0; i < numCnt; i++)
	{
		sum += numStr[i]-'0';
	}
	cout << sum << endl;
	return 0;
}