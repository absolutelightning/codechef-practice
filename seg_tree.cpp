#include<vector>

using namespace std;

class SegmentTreeNode {
public:
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    int l, r;
    int min;
};

class SegmentTree {
public:
    SegmentTreeNode * root = nullptr;
    void build(vector<int> &ar) {
        int size = ar.size();
        root = build_tree(0, size - 1, root, ar);
    }
    int query(int l, int r) {
        return query_tree(root, l, r);
    }
    int query_tree(SegmentTreeNode * node, int l, int r) {
        int minv = INT_MAX;
        if (node == nullptr) {
            return minv;
        }
        if (node->l >= l && node->r <= r) {
            return node->min;
        }
        if (l > node->r || r < node->l) {
            return minv;
        }
        return min(query_tree(node->left, l, r), query_tree(node->right, l, r));
    }
    SegmentTreeNode * build_tree(int l, int r, SegmentTreeNode *n, vector<int> & ar) {
        if (n == nullptr) {
            n = new SegmentTreeNode();
            n->l = l;
            n->r = r;
            n->min = INT_MAX;
            n->left = nullptr;
            n->right = nullptr;
        }
        if (l == r) {
            n->min = min(n -> min, ar[l]);
        }
        else if (l < r) {
            int mid = (l + r) >> 1;
            n->left = build_tree(l, mid, n->left, ar);
            n->right = build_tree(mid + 1, r, n->right, ar);
            n->min = min(n->left->min, n->right->min);
        }
        else {
            return nullptr;
        }
        return n;
    }
};
