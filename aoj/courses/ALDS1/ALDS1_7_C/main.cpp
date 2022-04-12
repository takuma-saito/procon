#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int nodes[25][3];

void dfs(int i, int k) {
    if(k == 0) printf(" %d", i);
    if(nodes[i][0] != -1) dfs(nodes[i][0], k);
    if(k == 1) printf(" %d", i);
    if(nodes[i][1] != -1) dfs(nodes[i][1], k);
    if(k == 2) printf(" %d", i);
}

int main()
{
    fill((int *)nodes, (int *)nodes+4*25, -1);
    int n; cin >> n;
    rep(i, n) {
        int x, l, r;
        cin >> x >> l >> r;
        nodes[x][0] = l;
        nodes[x][1] = r;
        nodes[l][2] = x;
        nodes[r][2] = x;
    }
    int root=-1; rep(i, n) {if(nodes[i][2] == -1) root=i; }
    printf("Preorder\n"); dfs(root, 0);
    printf("\nInorder\n"); dfs(root, 1);
    printf("\nPostorder\n"); dfs(root, 2);
    cout << endl;
}