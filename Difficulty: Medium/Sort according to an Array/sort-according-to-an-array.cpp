//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        //Your code here
        unordered_map<int, int> count_map;
        vector<int> not_in_A2, result;
        
        for (int i = 0; i < N; ++i) count_map[A1[i]]++;
        
        for (int i = 0; i < M; ++i) {
            if (count_map.find(A2[i]) != count_map.end()) {
                while (count_map[A2[i]]--) result.push_back(A2[i]);
                count_map.erase(A2[i]);
            }
        }
        
        for (auto it = count_map.begin(); it != count_map.end(); ++it)
            for (int i = 0; i < it->second; ++i) not_in_A2.push_back(it->first);
        
        sort(not_in_A2.begin(), not_in_A2.end());
        
        result.insert(result.end(), not_in_A2.begin(), not_in_A2.end());
        return result;

    } 
};

//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	
cout << "~" << "\n";
}
	return 0; 
} 

// } Driver Code Ends