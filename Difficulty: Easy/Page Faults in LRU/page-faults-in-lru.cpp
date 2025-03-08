//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        unordered_set<int> cache;
        unordered_map<int, list<int>::iterator> pos;
        list<int> lru;
        int faults = 0;
        
        for (int i = 0; i < N; i++) {
            if (cache.find(pages[i]) == cache.end()) {
                if (cache.size() == C) {
                    int lruPage = lru.back();
                    lru.pop_back();
                    cache.erase(lruPage);
                    pos.erase(lruPage);
                }
                faults++;
            } else {
                lru.erase(pos[pages[i]]);
            }
            lru.push_front(pages[i]);
            cache.insert(pages[i]);
            pos[pages[i]] = lru.begin();
        }
        return faults;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends