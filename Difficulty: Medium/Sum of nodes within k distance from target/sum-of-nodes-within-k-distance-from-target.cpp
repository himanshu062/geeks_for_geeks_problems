//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends

/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
public:
    void markParents(Node* root, unordered_map<Node*, Node*>& parent, Node*& targetNode, int target) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->data == target) targetNode = curr;
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    int sum_at_distK(Node* root, int target, int k) {
        unordered_map<Node*, Node*> parent;
        Node* targetNode = NULL;
        markParents(root, parent, targetNode, target);

        unordered_set<Node*> visited;
        queue<pair<Node*, int>> q;
        q.push(make_pair(targetNode, 0));
        visited.insert(targetNode);
        int sum = 0;

        while (!q.empty()) {
            pair<Node*, int> p = q.front();
            q.pop();
            Node* node = p.first;
            int dist = p.second;

            if (dist > k) break;
            sum += node->data;

            if (node->left && !visited.count(node->left)) {
                visited.insert(node->left);
                q.push(make_pair(node->left, dist + 1));
            }
            if (node->right && !visited.count(node->right)) {
                visited.insert(node->right);
                q.push(make_pair(node->right, dist + 1));
            }
            if (parent.count(node) && !visited.count(parent[node])) {
                visited.insert(parent[node]);
                q.push(make_pair(parent[node], dist + 1));
            }
        }

        return sum;
        
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    
cout << "~" << "\n";
}
	return 0;
}


// } Driver Code Ends