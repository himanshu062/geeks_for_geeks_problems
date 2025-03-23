//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends


/* The functions which 
builds the segment tree */
int buildST(int arr[], int segTree[], int start, int end, int node) {
    if (start == end) {
        segTree[node] = arr[start];
        return arr[start];
    }
    int mid = (start + end) / 2;
    segTree[node] = min(buildST(arr, segTree, start, mid, 2 * node + 1),
                        buildST(arr, segTree, mid + 1, end, 2 * node + 2));
    return segTree[node];
}

int *constructST(int arr[], int n) {
    int size = 4 * n;
    int *segTree = new int[size];
    buildST(arr, segTree, 0, n - 1, 0);
    return segTree;
}

int queryST(int segTree[], int start, int end, int l, int r, int node) {
    if (l <= start && r >= end) return segTree[node];
    if (end < l || start > r) return INT_MAX;
    
    int mid = (start + end) / 2;
    return min(queryST(segTree, start, mid, l, r, 2 * node + 1),
               queryST(segTree, mid + 1, end, l, r, 2 * node + 2));
}

int RMQ(int st[], int n, int a, int b) {
    return queryST(st, 0, n - 1, a, b, 0);
}