#include <bits/stdc++.h>
using namespace std; 
using lli = long long int;

struct vertex {
    char key; 
    vector <int> child; 
    bool last; 
};

class Trie {
    vector <vertex> trie;  
public:
    Trie() {
        trie.push_back({' ', {}, true}); 
    }
    
    void insert(string w) {
        int cur = 0;
        int t = 0; 
        while (t<=w.size()-1) {
            bool ok = false;
            for(int c : trie[cur].child) {
                if (w[t] == trie[c].key) {
                    cur = c;
                    ok = true;
                    break; 
                }
            }
            if (!ok) {
                trie.push_back({w[t], {}}); 
                trie[cur].child.push_back(trie.size()-1); 
                cur = trie.size()-1; 
            }
            t++; 
        }
        trie[cur].last = true; 
    }

    int general(string w) {
        int cur = 0;
        int t = 0; 
        while (t<=w.size()-1) {
            bool ok = false;
            for(int c : trie[cur].child) {
                if (w[t] == trie[c].key) {
                    cur = c;
                    ok = true;
                    break; 
                }
            }
            if (!ok) return -1; 
            t++; 
        }
        return cur; 
    }
    
    bool search(string w) {
        int cur = general(w);
        if (cur == -1) return false; 
        return trie[cur].last; 
    }
    
    bool startsWith(string pr) {
        int cur = general(pr);
        return cur != -1; 
    }
};
