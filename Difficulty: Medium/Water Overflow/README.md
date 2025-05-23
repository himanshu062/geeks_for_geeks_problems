<h2><a href="https://www.geeksforgeeks.org/problems/champagne-overflow2636/1?page=8&difficulty=Medium&status=unsolved&sortBy=submissions">Water Overflow</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">There is a stack of water glasses in the form of a Pascal triangle and a person wants to pour the water at the topmost glass, but the capacity of each glass is 1 unit. Overflow takes place in such a way that after 1 unit, 1/2 of the remaining unit gets into the bottom left glass and the other half in the bottom right glass. Now John pours <strong>K</strong> units of water in the topmost glass and wants to know how much water is there in the <strong>C</strong>th glass of the <strong>R</strong>th row.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong> Assume that there are enough glasses in the triangle till no glass overflows.</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;"><strong>K = </strong>3</span><strong>, </strong><span style="font-size: 18px;"><strong>R = </strong>2</span><strong>, </strong><span style="font-size: 18px;"><strong>C = </strong>1</span>
<span style="font-size: 18px;"><strong>Output:</strong></span>
<span style="font-size: 18px;">1.000000</span>
<span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">After the first glass, 2 units of water
will remain and they will spread equally
on the two glasses on the second row.
Therefore, the glass on the 2nd row and
1st column will have 1 unit of water.</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;"><strong>K = </strong>3</span><strong>, </strong><span style="font-size: 18px;"><strong>R = </strong>2</span><strong>, </strong><span style="font-size: 18px;"><strong>C = </strong>2</span>
<span style="font-size: 18px;"><strong>Output:</strong></span>
<span style="font-size: 18px;">1.000000</span>
<span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">After the first glass, 2 units of water
will remain and they will spread equally
on the two glasses on the second row.
Therefore, the glass on the 2nd row and
2nd column will have 1 unit of water.</span></pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>waterOverflow()</strong> which takes 3 Integers K, R, and C as input and returns the amount of water(<strong>6 digits of precision</strong>) in the Cth glass of Rth row.</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(K<sup>2</sup>)<br><strong>Expected Auxiliary Space:</strong> O(K<sup>2</sup>)</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong></span><br><span style="font-size: 18px;">1 &lt;= K &lt;= 500<br>1 &lt;= R,C &lt;= K</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>D-E-Shaw</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Matrix</code>&nbsp;