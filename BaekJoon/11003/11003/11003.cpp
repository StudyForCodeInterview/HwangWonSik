#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    long long N, L;
    cin >> N >> L;
    vector<long long> v(N + 1);
    for (long long i = 1; i < N+1; i++)
    {
        cin >> v[i];
    }
  
    deque<pair<long long, long long>> window;
    long long end = 1;
    while (end <= N)
    {   
        while (1)
        {
            if (window.empty())
            {
                break;
            }
            if (window.back().second <= v[end])
            {
                break;
            }
            else
            {
                window.pop_back();
            }
        }
        window.push_back(make_pair(end, v[end]));
        if (window.front().first == end - L)
        {
            window.pop_front();
        }
        cout << window.front().second << ' ';
        end++;
    }
}

    