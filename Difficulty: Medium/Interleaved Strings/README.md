<h2><a href="https://www.geeksforgeeks.org/problems/interleaved-strings/1?page=1&category=Strings&difficulty=Medium&status=unsolved&sortBy=submissions">Interleaved Strings</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given strings <strong>A</strong>, <strong>B</strong>, and <strong>C</strong>, find whether <strong>C</strong> is formed by an interleaving of <strong>A</strong>&nbsp;and <strong>B</strong>.</span></p>
<p><span style="font-size: 18px;">An interleaving of two strings S&nbsp;and T&nbsp;is a configuration such&nbsp;that it creates a new string Y from the concatenation substrings of A and B and |Y| = |A + B| = |C|</span></p>
<p><span style="font-size: 18px;">For example:</span></p>
<p><span style="font-size: 18px;">A = "XYZ"</span></p>
<p><span style="font-size: 18px;">B = "ABC"</span></p>
<p><span style="font-size: 18px;">so we can make multiple interleaving string Y like, XYZABC, XAYBCZ, AXBYZC, XYAZBC and many more so here your task is to check whether you can create a string Y which can be equal to C.</span></p>
<p><span style="font-size: 18px;">Specifically, you just need to create substrings of string A and create substrings&nbsp;B and concatenate&nbsp;them and check whether it is equal to C or not.</span></p>
<p><span style="font-size: 18px;">Note: </span><strong>a + b</strong><span style="font-size: 18px;"> is the concatenation of strings a and b.</span></p>
<p><span style="font-size: 18px;">Return <strong>true</strong>&nbsp;if <strong>C</strong></span>&nbsp;<span style="font-size: 18px;">is formed by an interleaving of <strong>A</strong>&nbsp;and <strong>B</strong>, else return <strong>false.</strong></span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>A = YX, B = X, C =&nbsp;XXY
<strong>Output: <br></strong>0<strong>
Explanation: <br></strong>XXY is not interleaving of YX and X.
</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>A = XY, B = X, C = XXY
<strong>Output: <br></strong>1<strong>
Explanation: <br></strong>XXY is interleaving of XY and X.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>Complete the function <strong>isInterleave() </strong>which takes three strings <strong>A</strong>, <strong>B</strong> and<strong> C</strong> as parameters and returns true if C is an interleaving of A and B else returns false. (1 is printed by the driver code if the returned value is true, otherwise 0.)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ length of A, B ≤ 300<br>1 ≤ length of C ≤ 600</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>FactSet</code>&nbsp;<code>Google</code>&nbsp;<code>Zillious</code>&nbsp;<code>Yahoo</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;