//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(struct Node* head) {
    while (head != nullptr) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        int len1 = 0, len2 = 0;
        Node* temp1 = head1;
        Node* temp2 = head2;

        while (temp1) {
            len1++;
            temp1 = temp1->next;
        }

        while (temp2) {
            len2++;
            temp2 = temp2->next;
        }
        temp1 = head1;
        temp2 = head2;

        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i++) {
                temp1 = temp1->next;
            }
        } else {
            for (int i = 0; i < len2 - len1; i++) {
                temp2 = temp2->next;
            }
        }
        while (temp1 && temp2) {
            if (temp1 == temp2) {
                return temp1; 
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return nullptr;
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        Node *head3 = nullptr, *tail3 = nullptr;
        int tmp;
        string input1, input2, input3;

        getline(cin, input1); // Read the entire line for LinkedList1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node* new_node = new Node(tmp);
            if (!head1) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for LinkedList2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node* new_node = new Node(tmp);
            if (!head2) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        getline(cin, input3); // Read the entire line for common LinkedList elements
        stringstream ss3(input3);
        while (ss3 >> tmp) {
            Node* new_node = new Node(tmp);
            if (!head3) {
                head3 = new_node;
                tail3 = new_node;
            } else {
                tail3->next = new_node;
                tail3 = new_node;
            }
        }

        Node* common = head3;

        if (tail1)
            tail1->next = common; // Connecting LinkedList1 to the common list
        if (tail2)
            tail2->next = common; // Connecting LinkedList2 to the common list

        Solution ob;
        Node* intersection = ob.intersectPoint(head1, head2);
        if (intersection) {
            cout << intersection->data << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}

// } Driver Code Ends