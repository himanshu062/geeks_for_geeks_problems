//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

public class LRUDesign {

    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {

            int capacity = Integer.parseInt(read.readLine());
            int queries = Integer.parseInt(read.readLine());
            LRUCache cache = new LRUCache(capacity);
            String str[] = read.readLine().trim().split(" ");
            int len = str.length;
            int itr = 0;

            for (int i = 0; (i < queries) && (itr < len); i++) {
                String queryType = str[itr++];
                if (queryType.equals("SET")) {
                    int key = Integer.parseInt(str[itr++]);
                    int value = Integer.parseInt(str[itr++]);
                    cache.set(key, value);
                }
                if (queryType.equals("GET")) {
                    int key = Integer.parseInt(str[itr++]);
                    System.out.print(cache.get(key) + " ");
                }
            }
            System.out.println();

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// design the class in the most optimal way

class LRUCache {
    // Constructor for initializing the cache capacity with the given value.
    TreeMap<Integer, int[]> entries = new TreeMap();
    HashMap<Integer, int[]> map = new HashMap();
    int size;
    int count = 0;
    LRUCache(int capacity) {
        // code here
        size = capacity;
    }

    // Function to return value corresponding to the key.
    public int get(int key) {
        // your code here
        if (map.containsKey(key)) 
        {
            int c = map.get(key)[1];
            entries.remove(c);
            count++;
            int val = map.get(key)[0];
            entries.put(count, new int[] { key, val });
            map.put(key, new int[] { val, count });
            return val;
        }
        return -1;
    }

    // Function for storing key-value pair.
    public void set(int key, int value) {
        // your code here
        if (map.containsKey(key)) 
        {
            int c = map.get(key)[1];
            entries.remove(c);
            count++;
            entries.put(count, new int[] { key, value });
            map.put(key, new int[] { value, count });
            return;
        }
        if (entries.size() == size) 
        {
            int lcount = entries.firstKey();
            int[] lkey = entries.get(lcount);
  
            map.remove(lkey[0]);
            entries.remove(lcount);
        }
        count++;
        entries.put(count, new int[] { key, value });
        map.put(key, new int[] { value, count });
    
    }
}
