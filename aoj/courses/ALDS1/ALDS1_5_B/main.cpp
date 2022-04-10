#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int A[500000], ans=0;

void merge(int left, int mid, int right) {
    vector<int> vec;
    int s = left, t = mid;
    while(s<mid && t<right) {
        if (A[s] <= A[t]) {
            vec.push_back(A[s++]);
            ans++;
        } else {
            vec.push_back(A[t++]);
            ans++;
        }
    }
    if (s < mid) {
        while(s < mid)   {vec.push_back(A[s++]); ans++;}
    } else if (t < right) {
        while(t < right) {vec.push_back(A[t++]); ans++;}
    }
    for(int i=right-1; i>=left; i--) {
        A[i] = vec.back(); vec.pop_back();
    }
}

// [left, right)
void mergeSort(int left, int right) {
    if (left+1<right) {
        int mid = (left+right)/2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

int main()
{
    int n; cin >> n;
    rep(i, n) {cin >> A[i];}
    mergeSort(0, n);
    rep(i, n) {printf("%d%s", A[i], i==n-1?"":" ");}
    cout << endl << ans << endl;
}