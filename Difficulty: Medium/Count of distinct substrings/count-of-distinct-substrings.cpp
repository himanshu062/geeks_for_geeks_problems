//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 
cout << "~" << "\n";
}
}


// } Driver Code Ends


/*You are required to complete this method */
class SuffixAutomaton {
public:
    struct State {
        int len, link;
        unordered_map<char, int> next;
    };

    vector<State> states;
    int last;

    SuffixAutomaton(int maxLen) {
        states.reserve(2 * maxLen);
        states.push_back({0, -1});
        last = 0;
    }

    void extend(char c) {
        int cur = states.size();
        states.push_back({states[last].len + 1, 0});
        int p = last;
        while (p != -1 && !states[p].next.count(c)) {
            states[p].next[c] = cur;
            p = states[p].link;
        }
        if (p == -1) {
            states[cur].link = 0;
        } else {
            int q = states[p].next[c];
            if (states[p].len + 1 == states[q].len) {
                states[cur].link = q;
            } else {
                int clone = states.size();
                states.push_back(states[q]);
                states[clone].len = states[p].len + 1;
                while (p != -1 && states[p].next[c] == q) {
                    states[p].next[c] = clone;
                    p = states[p].link;
                }
                states[q].link = states[cur].link = clone;
            }
        }
        last = cur;
    }

    int countDistinctSubstrings() {
        int total = 0;
        for (size_t i = 1; i < states.size(); i++) {
            total += states[i].len - states[states[i].link].len;
        }
        return total + 1; 
    }
};

int countDistinctSubstring(string s) {
    SuffixAutomaton automaton(s.size());
    for (char c : s) {
        automaton.extend(c);
    }
    return automaton.countDistinctSubstrings();
}