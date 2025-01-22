//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    struct Node * reverse(struct Node* first){
        Node *curr=first,*prev=NULL,*np;
        while(curr!=NULL){
            np=curr->next;
            curr->next=prev;
            prev=curr;
            curr=np;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {   Node *dumb=new Node(0);Node *dummy=dumb;
        // code here
        Node *n1=reverse(first);
        Node *n2=reverse(second);
        int c=0;
        while(n1!=NULL || n2 !=NULL || c){
            int sum=0;
            if(n1!=NULL){
                sum+=n1->data;n1=n1->next;
            }
             if(n2!=NULL){
                sum+=n2->data;n2=n2->next;
            }
             sum+=c;
             c=sum/10;
            // int base=sum%10;
            Node *node=new Node(sum%10);
            dummy->next=node;
            dummy=node;
            
        }
        Node *ans= reverse(dumb->next);
        if(ans->data==0){
            Node *jk=ans;
            while(jk->data == 0 && jk->next!=NULL){
                jk=jk->next;
            }
           
            return jk;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends