<h2><a href="https://www.geeksforgeeks.org/problems/combination-sum-1587115620/1?page=1&company=Amazon&difficulty=Medium&status=unsolved&sortBy=submissions">Combination Sum</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array&nbsp;any number of times to make B.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong><br>&nbsp;&nbsp;&nbsp; &nbsp; &nbsp; <strong>1.</strong> All numbers will be positive integers.<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<strong> 2.</strong> Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <strong>3.</strong> The combinations themselves must be sorted in ascending order.</span></p>
<p><br><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><strong><span style="font-size: 18px;">Input:
</span></strong><span style="font-size: 18px;">N = 4
arr[] = {7,2,6,5}
B = 16
<strong>Output:
</strong>(2 2 2 2 2 2 2 2)
(2 2 2 2 2 6)
(2 2 2 5 5)
(2 2 5 7)
(2 2 6 6)
(2 7 7)
(5 5 6)</span>
</pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><strong><span style="font-size: 18px;">Input:
</span></strong><span style="font-size: 18px;">N = 11
arr[] = {6,5,7,1,8,2,9,9,7,7,9}
B = 6
<strong>Output:
</strong>(1 1 1 1 1 1)
(1 1 1 1 2)
(1 1 2 2)
(1 5)
(2 2 2)
(6)
</span></pre>
<p><br><span style="font-size: 18px;"><strong>Your Task:</strong><br>Your task is to complete the function <strong>combinationSum()&nbsp;</strong>which takes the array <strong>A</strong> and a sum <strong>B </strong>as parameters and returns a list of list denoting the required combinations in the order specified in the problem description. <strong>The printing is handled by the driver's code</strong>. If no set can be formed with the given set, then&nbsp; "Empty" (without quotes) is printed.</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 30<br>1 &lt;= A[i] &lt;= 20<br>1 &lt;= B &lt;= 100</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Adobe</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Recursion</code>&nbsp;<code>Backtracking</code>&nbsp;<code>Algorithms</code>&nbsp;