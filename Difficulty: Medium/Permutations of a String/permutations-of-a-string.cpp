//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> findPermutation(string &S) {
        // Code here there
        set<string>ans;
		    int n=S.size();
		    vector<bool> a(n,0);
		    function<void(int,string)> traverse =[&](int p, string curr)
		    {
		        if(p==n){
		            ans.insert(curr);
		            return;
		        }
		        for(int i=0;i<n;i++){
		            if(!a[i]){
		                a[i]=1;
		                curr+=S[i];
		                traverse(p+1,curr);
		                curr.pop_back();
		                a[i]=0;
		            }
		        }
		        
		    };
		    traverse(0, "");
		    vector<string>b;
		    for(auto i:ans)
		    b.push_back(i);
		    return b;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends