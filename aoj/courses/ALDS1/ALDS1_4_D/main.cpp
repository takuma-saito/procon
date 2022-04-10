#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int w[100000];
int k, n;

bool check(int p) {
    int weight=0, count=1, i=0;
    while(i<n) {
        if (w[i] > p) {
            return false;
        } else if (weight+w[i] <= p) {
            weight += w[i++];
        } else {
            weight = 0;
            if (++count > k) {return false;}
        }
    }
    return true;
}

int main()
{
    cin >> n >> k;
    int lb=0, ub=0;
    rep(i, n) {cin >> w[i]; ub+=w[i];}
    while (ub-lb>1) {
        int mid = (ub+lb)/2;
        if (check(mid)) {ub=mid;}
        else {lb=mid;}
    }
    printf("%d\n", ub);
}