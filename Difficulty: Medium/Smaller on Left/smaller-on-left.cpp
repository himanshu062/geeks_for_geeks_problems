//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> Smallestonleft(int arr[], int n);

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        int arr[n + 1];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> b;
        b = Smallestonleft(arr, n);
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";

        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n) {
    // Complete the function
    set<int> s;
    vector<int> result;
    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound(arr[i]);
        if (it == s.begin()) result.push_back(-1);
        else result.push_back(*prev(it));
        s.insert(arr[i]);
    }
    return result;
}