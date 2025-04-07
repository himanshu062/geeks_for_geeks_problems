//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            long num = Long.parseLong(br.readLine().trim());
            Solution obj = new Solution();
            long ans = obj.closestPalindrome(num);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public long closestPalindrome(long num) {
        // Code here
        if (num < 10) return num;
        
        String s = String.valueOf(num);
        int len = s.length();
        long left = Long.parseLong(s.substring(0, (len + 1) / 2));
        
        long[] candidates = new long[5];
        candidates[0] = getPalindrome(left, len);
        candidates[1] = getPalindrome(left - 1, len);
        candidates[2] = getPalindrome(left + 1, len);
        candidates[3] = (long)Math.pow(10, len - 1) - 1;
        candidates[4] = (long)Math.pow(10, len) + 1;
        
        long closest = candidates[0];
        long minDiff = Math.abs(num - closest);
        
        for (int i = 1; i < 5; i++) {
            long diff = Math.abs(num - candidates[i]);
            if (diff < minDiff || (diff == minDiff && candidates[i] < closest)) {
                minDiff = diff;
                closest = candidates[i];
            }
        }
        
        return closest;
    }
    
    private long getPalindrome(long left, int len) {
        String leftStr = String.valueOf(left);
        StringBuilder sb = new StringBuilder(leftStr);
        if (len % 2 == 1) {
            sb.deleteCharAt(sb.length() - 1);
        }
        return Long.parseLong(leftStr + sb.reverse().toString());
    }
}