/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int n) {
        // code here
        int ans = INT_MIN;
        while(root){
            if(root->data==n)return n;
            else if(root->data<n){
                ans=max(ans,root->data);
                root=root->right;
            }
            else root=root->left;
        }
        return ans==INT_MIN?-1:ans;
    }
};