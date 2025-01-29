//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class AutoCompleteSystem {
    unordered_map<string, int> freq;
    string current;
    
public:
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); i++) {
            freq[sentences[i]] += times[i];
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            freq[current]++;
            current = "";
            return {};
        }

        current += c;
        vector<pair<int, string>> suggestions;
        
        for (auto& it : freq) {
            if (it.first.find(current) == 0) {
                suggestions.push_back({-it.second, it.first});
            }
        }

        sort(suggestions.begin(), suggestions.end());

        vector<string> result;
        for (int i = 0; i < min(3, (int)suggestions.size()); i++) {
            result.push_back(suggestions[i].second);
        }

        return result;
    }
};
/**
 * Your AutoCompleteSystem object will be instantiated and called as such:
 * AutoCompleteSystem* obj = new AutoCompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        vector<string> sentences(n);
        vector<int> times(n);
        for (int i = 0; i < n; ++i) {

            getline(cin, sentences[i]);
            cin >> times[i];
            cin.ignore();
        }
        AutoCompleteSystem *obj = new AutoCompleteSystem(sentences, times);
        int q;
        cin >> q;
        cin.ignore();

        for (int i = 0; i < q; ++i) {
            string query;
            getline(cin, query);
            string qq = "";
            for (auto &x : query) {
                qq += x;
                vector<string> suggestions = obj->input(x);
                if (x == '#')
                    continue;
                cout << "Typed : \"" << qq << "\" , Suggestions: \n";
                for (auto &y : suggestions) {
                    cout << y << "\n";
                }
            }
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends