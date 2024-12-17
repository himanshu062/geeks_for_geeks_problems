//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    int n = num.size();
        int digitsToKeep = n - k; 
        string result = "";

        for (char digit : num) {
            while (!result.empty() && result.back() > digit && k > 0) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }
        result.resize(digitsToKeep);
        while (result.size() > 1 && result[0] == '0') {
            result.erase(result.begin());
        }

        return result.empty() ? "0" : result;
}