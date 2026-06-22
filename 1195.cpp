/*
 * Beecrowd 1195 — Binary Search Tree
 * Time limit: 1 s
 *
 * Build a binary search tree by sequentially inserting the input
 * values (left subtree holds strictly smaller keys, right subtree
 * holds keys greater-or-equal). For each of C test cases (C <= 1000,
 * 1 <= N <= 500), print:
 *     Case n:
 *     Pre.: <pre-order>
 *     In..: <in-order>
 *     Post: <post-order>
 *     <blank line>
 * Space-separated values per line; no trailing space; trailing blank
 * line is required even after the last test case.
 *
 * Approach:
 *   Standard iterative BST insertion, then recursive DFS to emit each
 *   traversal. Nodes are kept in flat arrays so memory is reused
 *   between test cases. C and N are small enough that performance is
 *   not a concern.
 */

#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 505;
static int key_[MAXN], leftC[MAXN], rightC[MAXN];
static int nodeCount;

// Returns the index of the new node (-1 if duplicate, which the
// problem promises will not happen).
static int makeNode(int v) {
    int id = nodeCount++;
    key_[id] = v;
    leftC[id] = rightC[id] = -1;
    return id;
}

static void insertBST(int root, int v) {
    int cur = root;
    while (true) {
        if (v < key_[cur]) {
            if (leftC[cur] == -1) { leftC[cur] = makeNode(v); return; }
            cur = leftC[cur];
        } else {
            // Statement says "greater than or equal to" goes right,
            // but values are guaranteed distinct so == never fires.
            if (rightC[cur] == -1) { rightC[cur] = makeNode(v); return; }
            cur = rightC[cur];
        }
    }
}

static void preorder(int u, vector<int>& out) {
    if (u == -1) return;
    out.push_back(key_[u]);
    preorder(leftC[u], out);
    preorder(rightC[u], out);
}
static void inorder(int u, vector<int>& out) {
    if (u == -1) return;
    inorder(leftC[u], out);
    out.push_back(key_[u]);
    inorder(rightC[u], out);
}
static void postorder(int u, vector<int>& out) {
    if (u == -1) return;
    postorder(leftC[u], out);
    postorder(rightC[u], out);
    out.push_back(key_[u]);
}

static void emit(const char* label, const vector<int>& v) {
    fputs(label, stdout);
    for (size_t i = 0; i < v.size(); i++) {
        putchar(' ');
        printf("%d", v[i]);
    }
    putchar('\n');
}

int main() {
    int C;
    scanf("%d", &C);
    for (int tc = 1; tc <= C; tc++) {
        int N;
        scanf("%d", &N);
        nodeCount = 0;

        int root = -1;
        for (int i = 0; i < N; i++) {
            int v;
            scanf("%d", &v);
            if (root == -1) root = makeNode(v);
            else insertBST(root, v);
        }

        vector<int> pre, in, post;
        preorder(root, pre);
        inorder(root, in);
        postorder(root, post);

        printf("Case %d:\n", tc);
        emit("Pre.:", pre);
        emit("In..:", in);
        emit("Post:", post);
        // Trailing blank line after every case (including the last).
        putchar('\n');
    }
    return 0;
}
