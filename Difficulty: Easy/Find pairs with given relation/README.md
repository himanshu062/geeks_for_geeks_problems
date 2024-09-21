<h2><a href="https://www.geeksforgeeks.org/problems/find-pairs-with-given-relation1540/1?page=1&difficulty=Easy&status=unsolved&sortBy=latest">Find pairs with given relation</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array <strong>arr[]</strong> of distinct integers, write a program to determine if there are two distinct pairs of elements (a, b) and (c, d) in the array such that the product of the first pair a * b is equal to the product of the second pair c * d. All four elements a, b, c, and d are distinct. If such pairs exist, return 1, otherwise, return -1.</span></p>
<p><strong style="font-size: 18px;">Examples:</strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [3, 4, 7, 1, 2, 9, 8]
<strong>Output:</strong> 1
<strong>Explanation</strong>: Product of 4 and 2 is 8 and also,the product of 1 and 8 is 8.  </span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [1, 6, 3, 9, 2, 10] 
<strong>Output:</strong> 1<br></span><span style="font-size: 18px;"><strong style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Explanation</strong><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">: Product of 1 and 6 is 6 and also,the product of 2 and 3 is 6.</span></span>
</pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n<sup>2</sup>).<br><strong>Expected Auxiliary Space:</strong> O(n<sup>2</sup>).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>4 ≤ arr.size() ≤ 10<sup>3<br></sup></span><span style="font-size: 18px;">1 ≤ arr[i] ≤ 10<sup>4</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Hash</code>&nbsp;<code>Data Structures</code>&nbsp;