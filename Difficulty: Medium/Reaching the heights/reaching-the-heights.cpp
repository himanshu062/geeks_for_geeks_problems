//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    sort(a, a + n, greater<int>());
    
    if (n == 1) return {a[0]};
    if (a[0] == a[n - 1]) return {-1};

    vector<int> result(n);
    int left = 0, right = n - 1;
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) result[i] = a[left++];
        else result[i] = a[right--];
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) sum += result[i];
        else sum -= result[i];
        if (sum <= 0) return {-1};
    }
    
    return result;
}
