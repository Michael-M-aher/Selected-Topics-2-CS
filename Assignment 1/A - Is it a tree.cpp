#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define sz(x) (int)x.size()

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct Node {
    int id = -1;
    bool vis=false;
    vector<Node*> adj={};
    Node(int _id) : id(_id) {}
};

int n, m;
vector<Node*> nodes;

void inp() {
    cin >> n >> m;
    nodes.resize(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = new Node(i);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        nodes[u]->adj.push_back(nodes[v]);
        nodes[v]->adj.push_back(nodes[u]);
    }
}

void dfs(Node* node) {
    node->vis = true;
    for (Node* child : node->adj) {
        if (!child->vis) {
            dfs(child);
        }
    }
}

bool isTree(vector<Node*>& nodes,int e) {
    if (e != sz(nodes) - 1) {
        return false;
    }
    dfs(nodes[0]);
    for (Node* node : nodes) {
        if (!node->vis) {
            return false;
        }
    }
    return true;
}


int main() {
    fast();
    inp();
    cout << (isTree(nodes, m) ? "YES" : "NO") << endl;
    return 0;
}