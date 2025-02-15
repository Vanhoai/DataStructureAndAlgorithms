#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

struct Node {
    int value;
    Node *L, *R;

    Node(int value) {
        this->value = value;
        L = R = nullptr;
    }
};

void makeNode(Node *root, int u, int v, char c) {
    if (c == 'L') {
        root->L = new Node(v);
    } else
        root->R = new Node(v);
}

void insertNode(Node *root, int u, int v, char c) {
    if (root == nullptr)
        return;

    if (root->value == u)
        makeNode(root, u, v, c);

    insertNode(root->R, u, v, c);
    insertNode(root->L, u, v, c);
}

void levelOrder(Node *node) {
    queue<Node *> q;
    q.push(node);

    while (!q.empty()) {
        Node *top = q.front();
        q.pop();

        cout << top->value << " ";
        if (top->L != nullptr)
            q.push(top->L);

        if (top->R != nullptr)
            q.push(top->R);
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        Node *root = nullptr;

        FOR(i, 0, n) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root == nullptr) {
                root = new Node(u);
                makeNode(root, u, v, c);
            } else {
                insertNode(root, u, v, c);
            }
        }

        levelOrder(root);
        cout << endl;
    }

    return 0;
}