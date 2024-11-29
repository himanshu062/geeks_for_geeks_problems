//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    int maxSubsetXOR(int arr[], int N)
    {
        //Your code here
        int index = 0;

        for (int bit = 31; bit >= 0; bit--) {
            int maxIdx = index;
            int maxNum = INT_MIN;

            for (int i = index; i < N; i++) {
                if ((arr[i] & (1 << bit)) != 0 && arr[i] > maxNum) {
                    maxNum = arr[i];
                    maxIdx = i;
                }
            }

            if (maxNum == INT_MIN) continue;

            swap(arr[index], arr[maxIdx]);

            for (int i = 0; i < N; i++) {
                if (i != index && (arr[i] & (1 << bit))) {
                    arr[i] ^= arr[index];
                }
            }

            index++;
        }

        int maxXOR = 0;
        for (int i = 0; i < N; i++) {
            maxXOR ^= arr[i];
        }

        return maxXOR;
    }
};

//{ Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubsetXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends