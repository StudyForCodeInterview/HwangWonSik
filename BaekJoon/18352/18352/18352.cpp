// 18352.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;
vector<bool> g_visited;
unordered_map<int, vector<int>> g_graph;
vector<int> g_answers;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int nodeN, edgeN, distance, startN;
	cin >> nodeN >> edgeN >> distance >> startN;
	for (int i = 0; i < edgeN; i++)
	{
		int start, end;
		cin >> start >> end;
		g_graph[start].push_back(end);
	}
	g_visited = vector <bool>(nodeN+1,false);
	list<pair<int,int>> queue;
	g_visited[startN] = true;
	queue.push_back(make_pair(startN,0));
	
	while (queue.size() > 0)
	{
		auto curN_moveLen = queue.front();
		queue.pop_front();
		if (curN_moveLen.second == distance)
		{
			g_answers.push_back(curN_moveLen.first);
		}
		for (int neighbor : g_graph[curN_moveLen.first])
		{
			if (g_visited[neighbor] == false)
			{
				g_visited[neighbor] = true;
				queue.push_back(make_pair(neighbor,curN_moveLen.second+1));
			}
		}
	}
	if (g_answers.size() > 0)
	{
		sort(g_answers.begin(), g_answers.end());
		for (int answer : g_answers)
		{
			cout << answer << '\n';
		}
	}
	else
	{
		cout << -1 << '\n';
	}
	


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
