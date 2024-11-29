//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    struct Box {
        int height, width, length;
    };

    static bool compare(Box a, Box b) {
        return (a.length * a.width) > (b.length * b.width);
    }

    int maxHeight(int height[], int width[], int length[], int n) {
        vector<Box> boxes;

        for (int i = 0; i < n; i++) {
            boxes.push_back({height[i], max(width[i], length[i]), min(width[i], length[i])});
            boxes.push_back({width[i], max(height[i], length[i]), min(height[i], length[i])});
            boxes.push_back({length[i], max(height[i], width[i]), min(height[i], width[i])});
        }

        sort(boxes.begin(), boxes.end(), compare);

        int m = boxes.size();
        vector<int> dp(m);

        for (int i = 0; i < m; i++) {
            dp[i] = boxes[i].height;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (boxes[i].width < boxes[j].width && boxes[i].length < boxes[j].length) {
                    dp[i] = max(dp[i], dp[j] + boxes[i].height);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    
cout << "~" << "\n";
}
	
	return 0;
}
	
// } Driver Code Ends