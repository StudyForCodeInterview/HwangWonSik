
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool changed = false;
    int N;
    cin >> N;
    int* A;
    A = new int[N+1];
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= N + 1; i++) {
        changed = false;
        for (int j = 1; j <= N - i; j++) {
            if (A[j] > A[j + 1]) {
                changed = true;
                swap(A[j], A[j + 1]);
            }
        }
        if (changed == false) {
            cout << i << '\n';
            break;
        }
    }
}