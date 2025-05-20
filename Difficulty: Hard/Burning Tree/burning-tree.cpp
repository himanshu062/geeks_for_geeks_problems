//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* mapParentNodes(Node* root, unordered_map<Node*, Node*>& parentMap, int target) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = nullptr;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->data == target) {
                targetNode = curr;
            }
            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return targetNode;
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = mapParentNodes(root, parentMap, target);
        unordered_set<Node*> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited.insert(targetNode);

        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            bool fireSpread = false;

            for (int i = 0; i < size; i++) {
                Node* currentNode = q.front();
                q.pop();
                if (currentNode->left && visited.find(currentNode->left) == visited.end()) {
                    q.push(currentNode->left);
                    visited.insert(currentNode->left);
                    fireSpread = true;
                }
                if (currentNode->right && visited.find(currentNode->right) == visited.end()) {
                    q.push(currentNode->right);
                    visited.insert(currentNode->right);
                    fireSpread = true;
                }
                if (parentMap.find(currentNode) != parentMap.end() && visited.find(parentMap[currentNode]) == visited.end()) {
                    q.push(parentMap[currentNode]);
                    visited.insert(parentMap[currentNode]);
                    fireSpread = true;
                }
            }
            if (fireSpread) {
                time++;
            }
        }

        return time;
    }
};
