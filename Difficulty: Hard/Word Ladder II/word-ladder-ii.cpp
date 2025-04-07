//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) return {};
        
        queue<vector<string>> q;
        unordered_map<string, int> level;
        vector<vector<string>> result;
        
        q.push({beginWord});
        level[beginWord] = 1;
        words.erase(beginWord);
        
        while (!q.empty()) {
            vector<string> currPath = q.front();
            q.pop();
            string currWord = currPath.back();
            int currLevel = currPath.size();
            
            if (currWord == endWord) {
                result.push_back(currPath);
                continue;
            }
            
            string temp = currWord;
            for (int i = 0; i < currWord.length(); i++) {
                char original = currWord[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) continue;
                    currWord[i] = c;
                    
                    if (words.find(currWord) != words.end()) {
                        int nextLevel = level[currWord];
                        if (nextLevel == 0 || nextLevel == currLevel + 1) {
                            vector<string> newPath = currPath;
                            newPath.push_back(currWord);
                            q.push(newPath);
                            level[currWord] = currLevel + 1;
                        }
                    }
                }
                currWord[i] = original;
            }
            
            words.erase(currWord);
        }
        
        return result;
    }
};


//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends