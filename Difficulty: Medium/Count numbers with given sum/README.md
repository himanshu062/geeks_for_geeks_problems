<h2><a href="https://www.geeksforgeeks.org/problems/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum0733/1?page=6&difficulty=Medium&status=unsolved&sortBy=submissions">Count numbers with given sum</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two integers <strong>‘n’</strong> and <strong>‘sum’</strong>, find the count of all n digit numbers whose sum of digits is&nbsp;‘sum’. Leading 0’s are not counted as digits.&nbsp;</span></p>
<p><span style="font-size: 18px;">Since the answer can be large, output it modulo 10<sup>9</sup>+7.</span></p>
<p><br><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 2, sum = 2
<strong>Output:</strong> 2
<strong>Explaination:</strong> 
The 2 digit numbers are 11 and 20.</span></pre>
<p><br><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 1, sum = 10
<strong>Output:</strong> -1
<strong>Explaination:</strong> 
We cannot get sum as 10 from a single digit.</span></pre>
<p><br><span style="font-size: 18px;"><strong>Your Task:</strong><br>You do not need to read input or print anything. Your task is to complete the function <strong>countWays()</strong> which takes the value <strong>n</strong> and <strong>sum</strong> as input parameters and returns the number of possible ways modulo 10<sup>9</sup>+7. If there is no possible way then it returns -1.</span></p>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n*sum)<br><strong>Expected Auxiliary Space:</strong> O(n*sum)</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 10<sup>3</sup><br>1 ≤ sum ≤ 10<sup>3</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Mathematical</code>&nbsp;