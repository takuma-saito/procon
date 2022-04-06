#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, A, B, ans =  0;
    cin >> N >> A >> B;
    for(int i = 1; i <= N; i++) {
        int j = i, sum = 0;
        while (j != 0) {
            sum += j % 10;
            j /= 10;
        }
        if (A <= sum && sum <= B) {
            ans += i;
        }
    }
    cout << ans << endl;
}