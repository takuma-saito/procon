#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e6;
int N, L; int A[MAX_N];

int main()
{
    deque<int> dq;
    cin >> N >> L;
    rep(i, N) cin >> A[i];
    for(int i=0; i<N; i++) {
        while (dq.size()>0 && A[dq.back()] >= A[i]) dq.pop_back();
        dq.push_back(i);
        if (i>=L-1) printf("%d%s", A[dq.front()], i==N-1?"\n":" ");
        if (dq.front() == i-L+1) dq.pop_front();
    }
}