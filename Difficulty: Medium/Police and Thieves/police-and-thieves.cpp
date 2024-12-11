//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
         deque<int> police, thieves;
        int caught = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') police.push_back(i);
            else if (arr[i] == 'T') thieves.push_back(i);

            while (!police.empty() && !thieves.empty()) {
                if (abs(police.front() - thieves.front()) <= k) {
                    caught++;
                    police.pop_front();
                    thieves.pop_front();
                } 
                else if (police.front() < thieves.front()) 
                    police.pop_front();
                else 
                    thieves.pop_front();
            }
        }

        return caught;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	
cout << "~" << "\n";
}
	return 0; 
} 


// } Driver Code Ends