// 1874.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <list>
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	list<int> stack;
	int n;
	cin >> n;

	int pushNum = 1;
	list<char> answers;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		while (stack.empty() || stack.back() < num)
		{
			stack.push_back(pushNum);
			answers.push_back('+');
			pushNum++;
		}
		if (stack.back() > num)
		{
			answers.clear();
			answers.push_back('*');
			break;
		}
		else if (stack.back() == num)
		{
			stack.pop_back();
			answers.push_back('-');
		}
	}
	for (char ch : answers)
	{
		if (ch == '*')
		{
			cout << "NO" << '\n';
		}
		else
		{
			cout << ch << '\n';
		}
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
