//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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

class Solution {

  public:
    void mapParent(Node* root, unordered_map<Node*, Node*>& parentMap, Node*& target, int src) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            if (current->data == src) target = current;
            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }
    }

    int ladoos(Node* root, int src, int k) {
        if (!root) return 0;

        unordered_map<Node*, Node*> parentMap;
        unordered_set<Node*> visited;
        Node* target = nullptr;

        mapParent(root, parentMap, target, src);

        queue<pair<Node*, int>> q;
        q.push({target, 0});
        visited.insert(target);

        int sum = 0;

        while (!q.empty()) {
            Node* node = q.front().first;
            int distance = q.front().second;
            q.pop();

            if (distance > k) break;
            sum += node->data;

            if (node->left && visited.find(node->left) == visited.end()) {
                visited.insert(node->left);
                q.push({node->left, distance + 1});
            }

            if (node->right && visited.find(node->right) == visited.end()) {
                visited.insert(node->right);
                q.push({node->right, distance + 1});
            }

            if (parentMap.find(node) != parentMap.end() && visited.find(parentMap[node]) == visited.end()) {
                visited.insert(parentMap[node]);
                q.push({parentMap[node], distance + 1});
            }
        }

        return sum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        int home, k;
        cin >> home >> k;
        getchar();
        Solution obj;
        cout << obj.ladoos(root, home, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends