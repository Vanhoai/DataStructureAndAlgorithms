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

int height(Node *root) {
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->L), height(root->R));
}

bool check2(Node *root) {
    if (root == nullptr)
        return true;

    if ((root->R == nullptr && root->L != nullptr) ||
        (root->R != nullptr && root->L == nullptr))
        return false;

    return check2(root->L) && check2(root->R);
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

        if (check2(root))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}