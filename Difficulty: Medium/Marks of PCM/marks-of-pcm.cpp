//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution{
    public:
    void customSort (int phy[], int chem[], int math[], int N)
    {
        // your code here
        vector<tuple<int, int, int>> students;
        for (int i = 0; i < N; i++) 
            students.emplace_back(phy[i], -chem[i], math[i]);

        sort(students.begin(), students.end());

        for (int i = 0; i < N; i++) {
            tie(phy[i], chem[i], math[i]) = students[i];
            chem[i] = -chem[i];
        }
    } 
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int phy[n];
		int chem[n];
		int math[n];
		for (int i = 0; i < n; ++i)
			cin >> phy[i] >> chem[i] >> math[i];
        Solution ob;
		ob.customSort (phy, chem, math, n);
		for (int i = 0; i < n; ++i)
			cout << phy[i] << " " << chem[i] << " " << math[i] << endl; 
	
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends