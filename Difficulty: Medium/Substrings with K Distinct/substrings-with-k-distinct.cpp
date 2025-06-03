class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here.
        int l, r;
            vector<int> f(26, 0);
            int uni = 0;
            long long ans = 0;
            l = 0;
            r = 0;
            long long extra = 0;
            while(r < s.size()){
                if(f[s[r] - 'a'] == 0)
                  ++uni;
                ++f[s[r] - 'a'];
                while(uni > k){
                    --f[s[l] - 'a'];
                    if(f[s[l] - 'a'] == 0)
                    --uni;
                    ++l;
                    extra = 0;
                }
                if(uni == k){
                    while(f[s[l] - 'a'] > 1){
                      ++extra;
                      --f[s[l] - 'a'];
                      ++l;
                    }
                    ans += extra + 1;
                }
                ++r;
            }
            return ans;
    }
};