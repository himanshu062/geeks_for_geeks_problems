//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class BrowserHistory {
public:
     // constructor to initialize object with homepage
    string ur[5000];
        int cur=0, end=0;
        
        BrowserHistory(string homepage) {
            ur[0] = homepage;
        }
        
        void visit(string url) {        
            cur++;
            ur[cur] = url;
            end = cur;
        }
        
        string back(int steps) {
            if(steps>cur) cur=0;
            else cur-=steps;
            return ur[cur];
        }
        
        string forward(int steps) {
            if(cur+steps>end) cur=end;
            else cur+=steps;
            return ur[cur];
        
    }
};

//{ Driver Code Starts.

int main()
{
    string homepage;
    cin >> homepage;
    
    BrowserHistory obj(homepage);
    
    int total_queries;
    cin >> total_queries;
    while(total_queries--)
    {
        int query;
        cin >> query;
        
        // if query = 1, visit()
        // if query = 2, back()
        // if query = 3, forward()
        
        if(query == 1) {
            string url;
            cin >> url;
            obj.visit(url);
        }
        else if(query == 2) {
            int steps;
            cin >> steps;
            cout << obj.back(steps) << endl;
        }
        else {
            int steps;
            cin >> steps;
            cout << obj.forward(steps) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends