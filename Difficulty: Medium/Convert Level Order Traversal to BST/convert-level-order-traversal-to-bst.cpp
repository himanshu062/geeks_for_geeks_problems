//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    
cout << "~" << "\n";
}
	return 0; 
}
// } Driver Code Ends


//User function Template for C++


//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n)
{
    // Code here
    if (n == 0) return nullptr;

    Node* root = new Node(arr[0]);
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {INT_MIN, INT_MAX}});

    int index = 1;
    while (index < n) {
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();

        Node* node = temp.first;
        int minValue = temp.second.first;
        int maxValue = temp.second.second;

        if (index < n && arr[index] > minValue && arr[index] < node->data) {
            node->left = new Node(arr[index++]);
            q.push({node->left, {minValue, node->data}});
        }

        if (index < n && arr[index] > node->data && arr[index] < maxValue) {
            node->right = new Node(arr[index++]);
            q.push({node->right, {node->data, maxValue}});
        }
    }

    return root;
}
