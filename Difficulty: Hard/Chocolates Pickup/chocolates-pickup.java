//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int N = sc.nextInt();
            int M = sc.nextInt();

            int[][] grid = new int[N][M];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    grid[i][j] = sc.nextInt();
                }
            }

            Solution obj = new Solution();
            long res = obj.solve(N, M, grid);
            System.out.println(res);
        
System.out.println("~");
}
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
   int m = 0;
    int n = 0;
    public int solve(int n, int m, int grid[][]){
        // Code here
        this.m = m;
        this.n = n;
        int[][][] dp = new int[n][m][m];
        for(int[][] rows : dp) {
            for(int[] row: rows) {
                Arrays.fill(row, -1);
            }
        }
        
        return solve(grid, 0, 0, m-1, dp);
    }
    public int solve(int[][] grid, int row, int col1, int col2, int[][][] dp) {
        
        if( col1 < 0 || col1 >= m || col2 < 0 || col2 >= m ) {
            return Integer.MIN_VALUE;
        }
        
        if( row == n-1 ) {
            if( col1 == col2 ) return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }
        
        if( dp[row][col1][col2] != -1 ) return dp[row][col1][col2];
        
        int max = Integer.MIN_VALUE;
        
        for(int i=-1; i<2; i++) {
            for(int j=-1; j<2; j++) {
                if( col1 != col2 ) {
                    max = Math.max( max, grid[row][col1] + grid[row][col2] + solve(grid, row+1, col1+i, col2+j, dp));
                } else {
                    max = Math.max( max, grid[row][col1] + solve(grid, row+1, col1+i, col2+j, dp));
                }
            }
        }
        
        
        return dp[row][col1][col2] = max;
    }
}