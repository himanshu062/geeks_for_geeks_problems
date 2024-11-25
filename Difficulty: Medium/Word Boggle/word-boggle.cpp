//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord = false;
    };

    TrieNode* root;

    void insertTrie(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    void searchWord(vector<vector<char>>& board, int x, int y, TrieNode* node, string currentWord, unordered_set<string>& result, vector<vector<bool>>& visited, vector<int>& dx, vector<int>& dy) {
        if (node->isEndOfWord) result.insert(currentWord);
        
        visited[x][y] = true;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() && !visited[nx][ny] && node->children.count(board[nx][ny])) {
                searchWord(board, nx, ny, node->children[board[nx][ny]], currentWord + board[nx][ny], result, visited, dx, dy);
            }
        }

        visited[x][y] = false;
    }

public:
    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        root = new TrieNode();
        for (const string& word : dictionary) {
            insertTrie(word);
        }

        unordered_set<string> result;
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (root->children.count(board[i][j])) {
                    searchWord(board, i, j, root->children[board[i][j]], string(1, board[i][j]), result, visited, dx, dy);
                }
            }
        }

        vector<string> resultVec(result.begin(), result.end());
        sort(resultVec.begin(), resultVec.end());
        return resultVec;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends