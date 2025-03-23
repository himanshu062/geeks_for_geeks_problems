<h2><a href="https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1?page=2&difficulty=Medium&status=unsolved&sortBy=accuracy">Find rectangle with corners as 1</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a&nbsp;NxM binary matrix consisting of 0s and 1s. Find if there exists a rectangle/ square within the matrix whose all four corners are 1.&nbsp;</span></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N = 4, M = 5
matrix[][] = 
{
{1 0 0 1 0},
{0 0 <span style="color: #ff0000;">1</span> 0 <span style="color: #ff0000;">1</span>},
{0 0 0 1 0}, 
{1 0 <span style="color: #ff0000;">1</span> 0 <span style="color: #ff0000;">1</span>}
} </span>

<span style="font-size: 18px;"><strong>Output</strong>: Yes
<strong>Explanation:</strong>
Valid corners are at index (1,2), (1,4), (3,2), (3,4) </span></pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N = 3, M = 3
matrix[][] = 
{{0 0 0},
{0 0 0},
{0 0 0}}
<strong>Output:</strong> No</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to take input or print anything. Complete the function <strong>ValidCorners()</strong>&nbsp;that takes the given matrix as input parameter and returns a boolean value.</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= R, C &lt;= 200<br>0 &lt;= A[i] &lt;= 1</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Matrix</code>&nbsp;<code>Data Structures</code>&nbsp;