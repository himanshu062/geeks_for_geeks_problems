//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.Scanner;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            Solution sln = new Solution();
            System.out.println(sln.findMin(a, b));

            System.out.println("~");
        }
    }
}


// } Driver Code Ends

// User function Template for Java

class Solution {
    public int findMin(int a, int b) {
        // Your code here
        int add = a + b;
        int sub = a - b;
        int mul = a * b;
        int div;

        try {
            div = a / b;
        } catch (Exception e) {
            div = Integer.MAX_VALUE;
        }

        return Math.min(Math.min(add, sub), Math.min(mul, div));
    }
}


//{ Driver Code Starts.
// } Driver Code Ends