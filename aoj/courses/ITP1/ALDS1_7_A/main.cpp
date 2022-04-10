#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
struct Tree {
    int id;
    int parent;
    int depth;
    vector<int> children;
};

void dfs(vector<Tree>&trees, Tree &tree, int depth) {
    tree.depth = depth;
    if (tree.children.empty()) {return;}
    for(auto &child: tree.children) {dfs(trees, trees[child], depth+1);}
}

int main()
{
    int n; cin >> n;
    vector<Tree> trees(n);
    rep(i, n) {
        int id, k; cin >> id >> k;
        vector<int> children;
        rep(i, k) {int x; cin >> x; children.push_back(x);}
        trees[id] = Tree({id, -1, 0, children});
    }
    rep(i, n) {
        for(int child: trees[i].children) {
            trees[child].parent = i;
        }
    }
    Tree root;
    for(auto &tree: trees) {if (tree.parent == -1) {root = tree;}}
    dfs(trees, root, 0);
    rep(i, n) {
        auto node = trees[i];
        int children_size = node.children.size();
        string node_type;
        if (node.parent == -1 ) {node_type = "root";}
        else if (node.children.empty()) {node_type = "leaf";}
        else {node_type = "internal node";}
        printf("node %d: parent = %d, depth = %d, ", node.id, node.parent, node.depth);
        cout << node_type << ", [";
        rep(i, children_size) {printf("%d%s", node.children[i], i==children_size-1?"":", ");}
        printf("]\n");
    }
}