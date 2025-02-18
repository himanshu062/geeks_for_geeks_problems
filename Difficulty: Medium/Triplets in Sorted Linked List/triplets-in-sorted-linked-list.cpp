//{ Driver Code Starts
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
// User function Template for C++
class Solution {
  public:
    int countTriplets(struct Node* head, int x) {
        // code here.
        vector<int> arr;
        while (head) {
            arr.push_back(head->data);
            head = head->next;
        }
        
        int n = arr.size(), count = 0;
        
        reverse(arr.begin(), arr.end());

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum == x) {
                    count++;
                    left++;
                    right--;
                } else if (sum < x) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return count;

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
        int k;
        cin >> k;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        int res = ob.countTriplets(head, k);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends