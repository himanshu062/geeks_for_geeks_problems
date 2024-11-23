//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void generateSubsets(int index, vector<int>& arr, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1]) continue;
            current.push_back(arr[i]);
            generateSubsets(i + 1, arr, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> AllSubsets(vector<int> arr, int n) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        vector<int> current;
        generateSubsets(0, arr, current, result);
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    
cout << "~" << "\n";
}
}   



// } Driver Code Ends