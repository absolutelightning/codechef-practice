#include<map>

using namespace std;

class TrieNode {
public:
    map<char, TrieNode *> ch;
    int val;
};

class Trie {
public:
    TrieNode *root;

    void insert(string key, int val) {
        root = insert_trie(root, key, val, 0);
    }

    int get(string key) {
        return get_trie(root, key, 0);
    }

    int get_trie(TrieNode *n, string k, int d) {
        if (n == nullptr) {
            return -1;
        }
        if (d == k.size()) {
            return n->val;
        }
        if (n->ch.find(k[d]) != n->ch.end()) {
            return get_trie(n->ch[k[d]], k, d + 1);
        }
        return -1;
    }

    TrieNode* insert_trie(TrieNode *node, string k, int v, int d) {
        if (node == nullptr) {
            node = new TrieNode();
        }
        TrieNode *n = node;
        while (d <= k.size()) {
            if (d >= k.size()) {
                n->val = v;
                break;
            }
            if (n->ch.find(k[d]) != n->ch.end()) {
                n = n->ch[k[d]];
                d++;
                continue;
            }
            auto tn = new TrieNode();
            n->ch[k[d]] = tn;
            n->ch[k[d]]->val = INT_MAX;
            n = n->ch[k[d]];
            d++;
        }
        return node;
    }

};