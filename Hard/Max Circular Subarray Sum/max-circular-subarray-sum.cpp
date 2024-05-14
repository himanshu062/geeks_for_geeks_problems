//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        if(num==1)
        return arr[0];
        int curr=arr[0];
        int best=arr[0];
        int sum=0;
        for(int i=1;i<num;i++)
        {
            
            curr=curr+arr[i];
            curr=max(curr,arr[i]);
           best=max(curr,best);
            
        }
        
        if(best<0)
        return best;
        int ans1=best;
        for(int i=0;i<num;i++)
        {
            sum=sum+arr[i];
            arr[i]=arr[i]*(-1);
        }
        
          int curr1=arr[0];
        int best1=arr[0];
        for(int i=1;i<num;i++)
        {
            curr1=curr1+arr[i];
            curr1=max(curr1,arr[i]);
           best1=max(curr1,best1);
            
        }
        
       return max(ans1,sum+best1); 
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends