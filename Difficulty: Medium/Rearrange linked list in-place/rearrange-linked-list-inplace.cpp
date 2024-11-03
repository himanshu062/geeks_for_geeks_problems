//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

The structure of linked list is the following

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
    Node *inPlace(Node *root) {
        // Code here
        if (!root || !root->next) return root;
        Node *slow = root, *fast = root;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *prev = nullptr, *curr = slow, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Node *first = root, *second = prev, *temp1, *temp2;
        while (second->next) {
            temp1 = first->next;
            temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
        return root;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        Solution ob;
        Node *ans = ob.inPlace(head);
        printList(ans);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends