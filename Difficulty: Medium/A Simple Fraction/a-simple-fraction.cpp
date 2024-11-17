//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator % denominator == 0)
            return to_string(numerator / denominator);
        
        string result;
        if ((numerator < 0) ^ (denominator < 0))
            result += '-';
        
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        
        result += to_string(num / den);
        result += '.';
        
        num %= den;
        unordered_map<long long, int> remainderMap;
        while (num != 0) {
            if (remainderMap.find(num) != remainderMap.end()) {
                result.insert(remainderMap[num], "(");
                result += ')';
                break;
            }
            remainderMap[num] = result.size();
            num *= 10;
            result += to_string(num / den);
            num %= den;
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends