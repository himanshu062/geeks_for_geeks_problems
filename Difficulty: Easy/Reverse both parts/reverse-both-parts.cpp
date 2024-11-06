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
    cout << endl;
}


// } Driver Code Ends
// User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  Node* reverseSegment(Node* head, int count) {

    Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        int i = 0;
        
        while (curr && i < count) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        
        head->next = curr; 
        return prev; 
    }
    
    Node* reverse(Node* head, int k) {
        if (!head || k <= 0) return head;
        Node* firstSegmentHead = reverseSegment(head, k);
        Node* current = firstSegmentHead;
        for (int i = 1; i < k && current; i++) {
            current = current->next;
        }
        
        if (!current || !current->next) return firstSegmentHead; 
        Node* secondSegmentHead = reverseSegment(current->next, INT_MAX);
        current->next = secondSegmentHead;
        
        return firstSegmentHead;
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
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
        cout << "~" << endl;
    }
}
// } Driver Code Ends