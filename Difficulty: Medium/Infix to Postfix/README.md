<h2><a href="https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?page=2&difficulty=Easy,Medium,Hard&status=unsolved&sortBy=submissions">Infix to Postfix</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an infix expression in the form of string <strong>str</strong>. Convert this infix expression to postfix expression.</span></p>
<ul>
<li><span style="font-size: 18px;"><strong>Infix expression:</strong> The expression of the form a <strong>op</strong> b. When an operator is in-between every pair of operands.</span></li>
<li><span style="font-size: 18px;"><strong>Postfix expression:</strong> The expression of the form a b <strong>op</strong>. When an operator is followed for every pair of operands.</span><br><span style="font-size: 18px;"><strong>Note:</strong> The order of precedence is: ^ <strong>greater than</strong>&nbsp;* <strong>equals to</strong> / <strong>greater than</strong> + <strong>equals to</strong> -. Ignore the right associativity of <strong>^</strong>.</span></li>
</ul>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: str = "a+b*(c^d-e)^(f+g*h)-i"
<strong>Output</strong>: abcd^e-fgh*+^*+i-
<strong>Explanation</strong>:
After converting the infix expression 
into postfix expression, the resultant 
expression will be&nbsp;abcd^e-fgh*+^*+i-
</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: str = "A*(B+C)/D"
<strong>Output</strong>: ABC+*D/
<strong>Explanation</strong>:
After converting the infix expression 
into postfix expression, the resultant 
expression will be&nbsp;ABC+*D/
</span>&nbsp;</pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>This is a <strong>function </strong>problem. You only need to complete the function<strong> infixToPostfix()&nbsp;</strong>that takes a&nbsp;<strong>string</strong>(Infix Expression) as a&nbsp;<strong>parameter</strong> and <strong>returns </strong>a <strong>string(</strong>postfix expression<strong>)</strong>. The <strong>printing </strong>is done <strong>automatically </strong>by the <strong>driver code</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(|str|).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(|str|).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ |str| ≤ 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>VMWare</code>&nbsp;<code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Stack</code>&nbsp;<code>Data Structures</code>&nbsp;