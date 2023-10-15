// 12891.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
    long long dnaLen, passwordLen;
    string strDna;
    long long aMin, cMin, gMin, tMin;
    cin >> dnaLen >> passwordLen >> strDna >> aMin >> cMin >> gMin >> tMin;
    long long beginIndex;
    beginIndex = 0;
    long long aCnt=0, cCnt=0, gCnt=0, tCnt=0;
    for (int i = 0; i < passwordLen; i++)
    {
        if (strDna[i] == 'A')
        {
            aCnt++;
        }
        else if (strDna[i] == 'C')
        {
            cCnt++;
        }
        else if (strDna[i] == 'G')
        {
            gCnt++;
        }
        else if (strDna[i] == 'T')
        {
            tCnt++;
        }
    }
    long long answer = 0;

    if (aCnt >= aMin && cCnt >= cMin && gCnt >= gMin && tCnt >= tMin)
    {
        answer++;
    }
    beginIndex++;


    while (beginIndex+passwordLen-1 < strDna.size())
    {
        if (strDna[beginIndex-1] == 'A')
        {
            aCnt--;
        }
        else if (strDna[beginIndex-1] == 'C')
        {
            cCnt--;
        }
        else if (strDna[beginIndex-1] == 'G')
        {
            gCnt--;
        }
        else if (strDna[beginIndex-1] == 'T')
        {
            tCnt--;
        }
        
        if (strDna[beginIndex + passwordLen-1] == 'A')
        {
            aCnt++;
        }
        else if (strDna[beginIndex + passwordLen-1] == 'C')
        {
            cCnt++;
        }
        else if (strDna[beginIndex + passwordLen-1] == 'G')
        {
            gCnt++;
        }
        else if (strDna[beginIndex + passwordLen-1] == 'T')
        {
            tCnt++;
        }
        if (aCnt >= aMin && cCnt >= cMin && gCnt >= gMin && tCnt >= tMin)
        {
            answer++;
        }
        beginIndex++;
    }
    cout << answer;
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
