//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> sortRecords(vector<string>& employee, vector<int>& salary) {
        // Your code goes here
        vector<pair<int, string>> records;
        for (int i = 0; i < employee.size(); ++i) {
            records.push_back({salary[i], employee[i]});
        }
        sort(records.begin(), records.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        vector<string> sortedEmployees;
        for (const auto& record : records) {
            sortedEmployees.push_back(record.second);
        }
        return sortedEmployees;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        vector<string> employee;
        vector<int> salary;

        string input;
        getline(cin, input); // Read the entire line for employee names
        stringstream ss(input);
        string name;
        while (ss >> name) {
            employee.push_back(name);
        }

        getline(cin, input); // Read the entire line for salaries
        stringstream ss2(input);
        int salaryValue;
        while (ss2 >> salaryValue) {
            salary.push_back(salaryValue);
        }

        Solution ob;
        vector<string> result = ob.sortRecords(employee, salary);
        for (const string& name : result) {
            cout << name << " ";
        }
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends