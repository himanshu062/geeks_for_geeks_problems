//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
  struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };
    // Function to merge K sorted linked list.
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        for (Node* list : arr) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        Node* dummy = new Node(0);
        Node* curr = dummy;
        while (!minHeap.empty()) {
            Node* smallest = minHeap.top();
            minHeap.pop();
            curr->next = smallest;
            curr = curr->next;
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        return dummy->next;
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<Node*> arr;
        vector<int> nums;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            nums.push_back(number);
        }
        int ind = 0;
        int N = nums.size();

        while (ind < N) {
            int n = nums[ind++];
            int x = nums[ind++];
            Node* head = new Node(x);
            Node* curr = head;
            n--;

            for (int i = 0; i < n; i++) {
                x = nums[ind++];
                Node* temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
            arr.push_back(head);
        }

        Solution obj;
        Node* res = obj.mergeKLists(arr);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends