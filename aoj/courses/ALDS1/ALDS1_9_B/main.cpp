#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_A = 1<<31;
const int MAX_N = 1<<22;
int n, A[MAX_N];

void maxHeapify(int x) {
    int l = 2*x, r = 2*x+1, largest;
    if (l <= n && A[x] < A[l]) largest = l;
    else largest = x;
    if (r <= n && A[largest] < A[r]) largest = r;
    if (x == largest) return;
    swap(A[x], A[largest]);
    maxHeapify(largest);
}

void buildMaxHeap(int n) {
    for(int i=n/2; i>0; i--) maxHeapify(i);
}

int main()
{
    cin >> n; rep(i, n) {cin >> A[i+1];}
    buildMaxHeap(n);
    for(int i=1; i<=n; i++) printf(" %d", A[i]);
    cout << endl;
}
