//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntMatrix
{
    public static int[][] input(BufferedReader br, int n, int m) throws IOException
    {
        int[][] mat = new int[n][];
        
        for(int i = 0; i < n; i++)
        {
            String[] s = br.readLine().trim().split(" ");
            mat[i] = new int[s.length];
            for(int j = 0; j < s.length; j++)
                mat[i][j] = Integer.parseInt(s[j]);
        }
        
        return mat;
    }
    
    public static void print(int[][] m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
    
    public static void print(ArrayList<ArrayList<Integer>> m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
}


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);
        
        return a;
    }
    
    public static void print(int[] a)
    {
        for(int e : a){
            if(e==Integer.MIN_VALUE)
              System.out.print("INF ");
            else
              System.out.print(e+" ");
        }
        System.out.println();
    }
    
    public static void print(ArrayList<Integer> a)
    {
        for(int e : a){
            if(e==Integer.MIN_VALUE)
              System.out.print("INF ");
            else
              System.out.print(e+" ");
        }
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int v; 
            v = Integer.parseInt(br.readLine());
            
            
            int e; 
            e = Integer.parseInt(br.readLine());
            
            
            int src; 
            src = Integer.parseInt(br.readLine());
            
            
            int[][] edges = IntMatrix.input(br, e, 3);
            
            Solution obj = new Solution();
            int [] res = obj.maximumDistance(v, e, src, edges);
            
            IntArray.print(res);
            
        
System.out.println("~");
}
    }
}

// } Driver Code Ends


class Solution {
    public static int [] maximumDistance(int v, int e, int src, int[][] edges) {
        // code here
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < v; i++) graph.add(new ArrayList<>());
        for (int[] edge : edges) {
            graph.get(edge[0]).add(new int[]{edge[1], edge[2]});
        }

        Stack<Integer> stack = new Stack<>();
        boolean[] visited = new boolean[v];
        for (int i = 0; i < v; i++) {
            if (!visited[i]) topologicalSort(i, visited, graph, stack);
        }

        int[] dist = new int[v];
        Arrays.fill(dist, Integer.MIN_VALUE);
        dist[src] = 0;

        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (dist[node] != Integer.MIN_VALUE) {
                for (int[] neighbor : graph.get(node)) {
                    if (dist[node] + neighbor[1] > dist[neighbor[0]]) {
                        dist[neighbor[0]] = dist[node] + neighbor[1];
                    }
                }
            }
        }
        return dist;
    }

    private static void topologicalSort(int node, boolean[] visited, List<List<int[]>> graph, Stack<Integer> stack) {
        visited[node] = true;
        for (int[] neighbor : graph.get(node)) {
            if (!visited[neighbor[0]]) topologicalSort(neighbor[0], visited, graph, stack);
        }
        stack.push(node);
    }
}
        
