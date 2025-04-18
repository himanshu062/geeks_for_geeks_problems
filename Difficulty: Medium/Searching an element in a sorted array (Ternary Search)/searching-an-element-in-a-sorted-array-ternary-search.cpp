//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int ternarySearch(int arr[], int N, int K) 
    { 
       // Your code here
       int low = 0, high = N - 1;
        while(low <= high){
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;
            if(arr[mid1] == K) return 1;
            if(arr[mid2] == K) return 1;
            if(K < arr[mid1]) high = mid1 - 1;
            else if(K > arr[mid2]) low = mid2 + 1;
            else{
                low = mid1 + 1;
                high = mid2 - 1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int N, K;
        cin >> N >> K;
        
        int arr[N];
        
        for(int i = 0;i<N;i++){
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.ternarySearch(arr, N, K) << endl;

    
cout << "~" << "\n";
}

	return 0; 
} 

// } Driver Code Ends