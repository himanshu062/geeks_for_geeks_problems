//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        if (words.size() == 1) {
            string uniqueChars = "";
            unordered_set<char> seen;
            for (char c : words[0]) {
                if (seen.find(c) == seen.end()) {
                    seen.insert(c);
                    uniqueChars += c;
                }
            }
            return uniqueChars;
        }
        unordered_set<char> chars;
        for (const string &word : words) {
            for (char c : word) {
                chars.insert(c);
            }
        }
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDegree;
        for (char c : chars) {
            graph[c] = vector<char>();
            inDegree[c] = 0;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int minLen = min(word1.length(), word2.length());
            bool foundDiff = false;
            for (int j = 0; j < minLen; j++) {
                if (word1[j] != word2[j]) {
                    graph[word1[j]].push_back(word2[j]);
                    inDegree[word2[j]]++;
                    foundDiff = true;
                    break;
                }
            }
            if (!foundDiff && word1.length() > word2.length()) {
                return ""; 
            }
        }
        queue<char> q;
        for (auto& pair : inDegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }
        
        string result = "";
        while (!q.empty()) {
            char current = q.front();
            q.pop();
            result += current;
            for (char neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if (result.length() != chars.size()) {
            return ""; 
        }
        
        return result;
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends