#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int nodes[25][4];

int height(int n) {
    auto &node = nodes[n];
    if (node[3] != -1) return node[3];
    int h = -1;
    if (node[0] != -1) h = max(h, height(node[0]));
    if (node[1] != -1) h = max(h, height(node[1]));
    return node[3] = h+1;
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
    rep(i, n) {
        auto node = nodes[i];
        int h = height(i);
        int sibling = node[2] == -1 ? -1 : (i ^ nodes[node[2]][0] ^ nodes[node[2]][1]);
        int deg = 0, depth = 0;
        string type;
        if (node[0] != -1) deg++;
        if (node[1] != -1) deg++;
        if (node[2] == -1) type = "root";
        else if (node[0] == -1 && node[1] == -1) type = "leaf";
        else type = "internal node";
        for(auto it = node; it[2] != -1; it = nodes[it[2]], depth++);
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
            i, node[2], sibling, deg, depth, h, type.c_str());
    }
}