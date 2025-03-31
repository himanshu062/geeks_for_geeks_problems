//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends


class Solution
{
    
public:
    int getSpecialNumber(int N)
    {
        //code here.
        N--;
        int result = 0, place = 1;
        while (N > 0) {
            result += (N % 6) * place;
            N /= 6;
            place *= 10;
        }
        return result;
    }

};




//{ Driver Code Starts.

int main() 
{
	int t;
	cin>>t;
	while(t-->0)
	{
	    int N;
	    cin>> N;
	     Solution ob;
	    cout<<ob.getSpecialNumber(N)<<endl;
	
cout << "~" << "\n";
}
	
	return 0;
}
// } Driver Code Ends