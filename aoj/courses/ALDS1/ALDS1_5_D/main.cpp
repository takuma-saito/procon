#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int A[200000];
long int ans=0;

void merge(int l, int mid, int r) {
    vector<int> vec;
    int s=l, t=mid;
    while(s<mid && t<r) {
        if (A[s] < A[t])      { vec.push_back(A[s++]); }
        else if (A[s] > A[t]) { vec.push_back(A[t++]); ans += mid-s; }
        else {runtime_error("Same value found");}
    }
    if (s<mid)      {while(s<mid) {vec.push_back(A[s++]);}}
    else if (t<r)   {while(t<r)   {vec.push_back(A[t++]);}}
    for(int i=r-1; i>=l; i--) {
        A[i] = vec.back(); vec.pop_back();
    }
}

// [l, r)
void countRev(int l, int r) {
    if (l+1<r) {
        int mid = (l+r)/2;
        countRev(l, mid);
        countRev(mid, r);
        merge(l, mid, r);
    }
}

int main()
{
    int n; cin >> n;
    rep(i, n) {cin >> A[i];}
    countRev(0, n);
    printf("%ld\n", ans);
}