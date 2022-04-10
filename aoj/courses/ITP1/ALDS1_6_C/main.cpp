#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
struct Card {char c; int val;};
const int MAX_N=100000;
Card A[MAX_N];

// [l, r)
int partition(int l, int r) {
    int x = A[r-1].val;
    int k = l;
    for(int i=l; i<r-1; i++) {
        if (A[i].val<=x) {swap(A[i], A[k++]);}
    }
    swap(A[k], A[r-1]);
    return k;
}

void quicksort(int l, int r) {
    if (l+1>=r) return;
    int idx = partition(l, r);
    quicksort(l, idx);
    quicksort(idx, r);
}

int main()
{
    map<int, vector<char>> table;
    int n; cin >> n;
    rep(i, n) {
        char c; int j; cin >> c >> j;
        A[i] = Card({c, j});
        table[j].push_back(c);
    }
    quicksort(0, n);
    bool stable = true;
    for(int i=0; i<n; i++) {
        int k=0;
        while(i+k<n && A[i+k].val == A[i].val) {
            auto cs = table[A[i].val];
            if (A[i+k].c != cs.at(k)) {
                stable=false;
                break;
            }
            k++;
        }
        i += k-1;
        if(!stable) {break;}
    }
    printf("%s\n", stable?"Stable":"Not stable");
    rep(i, n) { printf("%c %d\n", A[i].c, A[i].val); }
}