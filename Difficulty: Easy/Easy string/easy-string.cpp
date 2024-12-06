//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    
cout << "~" << "\n";
}
return 0;
}


// } Driver Code Ends


string transform(string S){
    //complete the function here
    string result = "";
    int count = 1;
    for (int i = 1; i <= S.size(); i++) {
        if (i < S.size() && tolower(S[i]) == tolower(S[i - 1])) {
            count++;
        } else {
            result += to_string(count) + string(1, tolower(S[i - 1]));
            count = 1;
        }
    }
    return result;
}

