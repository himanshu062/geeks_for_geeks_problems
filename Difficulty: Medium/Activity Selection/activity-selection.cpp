//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int activitySelection(vector<int> start, vector<int> end) {
        // Your code here
        vector<pair<int, int>> activities;
        for (int i = 0; i < start.size(); i++) {
            activities.push_back({end[i], start[i]});
        }
        sort(activities.begin(), activities.end());

        int count = 0, lastEndTime = 0;
        for (auto& activity : activities) {
            if (activity.second > lastEndTime) {
                count++;
                lastEndTime = activity.first;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> end;
        ss.str(input);
        while (ss >> num)
            end.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, end) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends