//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minEle;
    stack<pair<int, int>> s;
    Solution() {}
    void push(int x) {
        if(s.size()==0)
            s.push({x, x});
        else
            s.push({x, min(x, s.top().second)});
    }
    void pop() {
        if(s.empty()) return;
        pair<int, int> p = s.top();
        s.pop();
    }
    int peek() {
        if(s.empty()) return -1;
        return s.top().first;
    }
    int getMin() {
        if(s.empty()) return -1;
        return s.top().second;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends