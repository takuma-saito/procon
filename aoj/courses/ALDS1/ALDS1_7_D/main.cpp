#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int pre[40], in[40];
struct Node {int id, l, r;};
vector<Node> nodes;

void rdfs(int i) {
    Node &n = nodes[i];
    if (n.l!=-1) rdfs(n.l);
    if (n.r!=-1) rdfs(n.r);
    printf(" %d", i);
}

int main()
{
    int n; cin >> n;
    rep(i, n) {cin >> pre[i];} rep(i, n) {cin >> in[i];}
    for(int i=0, j=0; i<n; i++) {
        if (pre[i] == in[j] || i == n-1) {
            Node node = {-1, -1, -1};
            while (!nodes.empty() && j<n && nodes.back().id == in[++j]) {
                node = nodes.back();
                cout << node.id << endl;
                nodes.pop_back();
            }
            if (node.id>=0) node.r = in[j];
        }  else if (pre[i] != in[j]) {
            if (!nodes.empty()) nodes.back().l = pre[i];
            nodes.push_back(Node {pre[i], -1, -1});
        }
    }
    cout << nodes.size() << endl;
    rdfs(nodes[n-1].id);
}