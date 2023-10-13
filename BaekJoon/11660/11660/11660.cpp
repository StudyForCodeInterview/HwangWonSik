
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int** Map= new int*[n+1];
	for (int i = 0; i < n + 1; i++)
	{
		Map[i] = new int[n + 1];
		Map[i][0] = 0;
		Map[0][i] = 0;
	}

	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < n+1; j++)
		{
			int num;
			cin >> num;
			Map[i][j] = Map[i][j - 1]+ Map[i-1][j]- Map[i - 1][j-1] + num;
		}
	}

	for (int i = 0; i < m; i++)
	{
		
		int startX, startY, endX, endY;
		int answer = 0;
		cin >> startX >> startY >> endX >> endY;
	
			
		answer= Map[endX][endY] - Map[startX-1][endY]-Map[endX][startY-1]+Map[startX-1][startY-1];
		cout << answer << '\n';

	
	}
}

