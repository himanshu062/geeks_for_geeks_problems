//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
        void nullPoints(int n, double magnets[], double getAnswer[])
    {
        auto force = [&](double x) {
            double f = 0.0;
            for (int i = 0; i < n; i++)
                f += 1.0 / (x - magnets[i]);
            return f;
        };
        
        for (int i = 0; i < n - 1; i++) {
            double left = magnets[i], right = magnets[i + 1], mid;
            while (right - left > 1e-9) {
                mid = (left + right) / 2.0;
                if (force(mid) > 0) left = mid;
                else right = mid;
            }
            getAnswer[i] = mid;
        }
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends