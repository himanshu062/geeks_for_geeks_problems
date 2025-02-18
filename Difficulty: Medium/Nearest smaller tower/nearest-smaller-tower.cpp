//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n = arr.size();
        vector<int> left(n, -1), right(n, -1), result(n, -1);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) 
                s.pop();
            if (!s.empty()) 
                left[i] = s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) 
                s.pop();
            if (!s.empty()) 
                right[i] = s.top();
            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            if (left[i] == -1 && right[i] == -1) continue;
            if (left[i] == -1) result[i] = right[i];
            else if (right[i] == -1) result[i] = left[i];
            else {
                int left_dist = i - left[i], right_dist = right[i] - i;
                if (left_dist < right_dist) result[i] = left[i];
                else if (right_dist < left_dist) result[i] = right[i];
                else result[i] = (arr[left[i]] <= arr[right[i]]) ? left[i] : right[i];
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends