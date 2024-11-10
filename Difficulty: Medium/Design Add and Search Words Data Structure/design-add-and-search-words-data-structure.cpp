//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++
class WordDictionary {
    struct TrieNode {
        TrieNode *children[26] = {};
        bool isWord = false;
    };

    TrieNode *root;

    bool searchInNode(const string &word, TrieNode *node, int index) {
        if (!node) return false;
        if (index == word.size()) return node->isWord;
        char c = word[index];
        if (c == '.') {
            for (TrieNode *child : node->children) {
                if (searchInNode(word, child, index + 1)) return true;
            }
            return false;
        }
        int i = c - 'a';
        return searchInNode(word, node->children[i], index + 1);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode *node = root;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i]) node->children[i] = new TrieNode();
            node = node->children[i];
        }
        node->isWord = true;
    }

    bool search(string word) {
        return searchInNode(word, root, 0);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        // Read first array
        int n;
        cin >> n;
        cin.ignore();
        string fnc;
        getline(cin, fnc);
        stringstream ss(fnc);
        vector<string> function(n);
        for (int i = 0; i < n; i++) {
            ss >> function[i];
        }
        string wrds;
        getline(cin, wrds);
        stringstream ss1(wrds);
        // Read second array
        vector<string> words(n);
        words[0] = "init";
        for (int i = 1; i < n; i++) {
            ss1 >> words[i];
        }
        vector<string> res;
        WordDictionary wordDictionary;
        bool init = false;
        for (int i = 0; i < n; i++) {
            string fn = function[i];
            string word = words[i];
            if (fn == "WordDictionary") {
                res.push_back("null");
                init = true;
            }
            if (fn == "addWord" && init) {
                wordDictionary.addWord(word);
                res.push_back("null");
            }
            if (fn == "search" && init) {
                res.push_back(wordDictionary.search(word) ? "true" : "false");
            }
        }
        for (string s : res)
            cout << s << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends