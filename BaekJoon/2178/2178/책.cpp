// 2178.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


struct Node
{
	int x;
	int y;
	int moveLen;
	int remainLen;
};
int n, m;
vector<vector<int>> g_miro;
queue <Node*> g_queue;

void MakeNode(Node* pPrevNode, int x, int y)
{
	Node* pNewNode = new Node;
	pNewNode->moveLen = pPrevNode->moveLen + 1;
	pNewNode->x = x;
	pNewNode->y = y;
	pNewNode->remainLen = abs(n - pNewNode->y) + abs(m - pNewNode->x);
	g_miro[pNewNode->y][pNewNode->x] = 0;
	g_queue.push(pNewNode);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m;
	g_miro = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			g_miro[i + 1][j + 1] = str[j] - '0';
		}
	}
	int answer = 0;
	Node* pStartNode = new Node;
	pStartNode->moveLen = 0;
	pStartNode->remainLen = n + m;
	pStartNode->x = 1;
	pStartNode->y = 1;
	g_queue.push(pStartNode);

	while (g_queue.size() > 0)
	{
		Node* pCurNode = g_queue.front();
		g_queue.pop();
		if (pCurNode->x == m && pCurNode->y == n)
		{
			answer = pCurNode->moveLen;
			break;
		}

		if (g_miro[pCurNode->y - 1][pCurNode->x])
		{
			MakeNode(pCurNode, pCurNode->x, pCurNode->y - 1);
		}
		if (g_miro[pCurNode->y + 1][pCurNode->x])
		{
			MakeNode(pCurNode, pCurNode->x, pCurNode->y + 1);
		}
		if (g_miro[pCurNode->y][pCurNode->x - 1])
		{
			MakeNode(pCurNode, pCurNode->x - 1, pCurNode->y);
		}
		if (g_miro[pCurNode->y][pCurNode->x + 1])
		{
			MakeNode(pCurNode, pCurNode->x + 1, pCurNode->y);
		}
	}
	cout << answer + 1 << '\n';

}

// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.
