//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node** tail_ref, int new_data) {
    struct Node* new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


// } Driver Code Ends
/* The Node is defined
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    /*The function below returns an int denoting
    the length of the longest palindrome list. */
    int countPalindrome(Node* left, Node* right) {
        int count = 0;
        while (left && right && left->data == right->data) {
            count++;
            left = left->next;
            right = right->next;
        }
        return count;
    }
    
    int maxPalindrome(Node* head) {
        if (!head) return 0;

        int maxLen = 0;
        Node* curr = head;
        Node* prev = nullptr;

        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            
            maxLen = max(maxLen, 2 * countPalindrome(prev, next) + 1); 
            maxLen = max(maxLen, 2 * countPalindrome(curr, next)); 

            prev = curr;
            curr = next;
        }

        return maxLen;
    }
};

//{ Driver Code Starts.

/* Driver program to test above function*/
int main() {
    int T, n, l;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        if (arr2.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr2[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr2.size(); ++i) {
            data = arr2[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        cout << ob.maxPalindrome(head) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends