#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 10;
int N; int num=-1; int A[MAX_N];

bool perm(int depth, bool match, int& count, vector<int>& vec) {
    if (depth==N) {
        count++;
        if (num>=0) {
            for(int i=-1; i<=1; i+=1) {
                if (num+i==count) {
                    rep(i, N) printf("%d%s", vec[i], i==N-1?"\n":" ");
                    return i==1;
                }
            }
        }
        if (match) num=count;
        return match;
    }
    for(int i=1; i<=9; i++) {
        if (A[i]<0) continue;
        int tmp = A[i];
        A[i] = -1;
        vec.push_back(i);
        bool res = perm(depth+1, match&&(tmp==depth), count, vec);
        vec.pop_back();
        A[i] = tmp;
        if (res) return true;
    }
    return false;
}

int main()
{
    int count=0;
    vector<int> vec;
    fill(A, A+MAX_N, -1);
    cin >> N; rep(i, N) { int x; cin >> x; A[x] = i;}
    perm(0, true, count, vec);
    count=0;
    perm(0, false, count, vec);
}