//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        int maxElement = INT_MIN;
        for (int i = 0; i < k; i++) {
            minHeap.push({KSortedArray[i][0], {i, 0}});
            maxElement = max(maxElement, KSortedArray[i][0]);
        }
        int rangeStart = 0, rangeEnd = INT_MAX;
        while (true) {
            auto current = minHeap.top();
            minHeap.pop();
            int minElement = current.first;
            int listIndex = current.second.first;
            int elementIndex = current.second.second;
            if (maxElement - minElement < rangeEnd - rangeStart) {
                rangeStart = minElement;
                rangeEnd = maxElement;
            }
            if (elementIndex + 1 < n) {
                int nextElement = KSortedArray[listIndex][elementIndex + 1];
                minHeap.push({nextElement, {listIndex, elementIndex + 1}});
                maxElement = max(maxElement, nextElement);
            } 
            else break;
            
        }
        
        return {rangeStart, rangeEnd};
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
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends