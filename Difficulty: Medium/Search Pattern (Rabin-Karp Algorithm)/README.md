<h2><a href="https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1">Search Pattern (Rabin-Karp Algorithm)</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p data-start="374" data-end="392"><span style="font-size: 14pt;">Given two strings:</span></p>
<ul data-start="394" data-end="505">
<li data-start="394" data-end="440">
<p data-start="396" data-end="440"><span style="font-size: 14pt;">A&nbsp;<strong><code data-start="398" data-end="404">text</code></strong>&nbsp;string in which you want to search.</span></p>
</li>
<li data-start="441" data-end="505">
<p data-start="443" data-end="505"><span style="font-size: 14pt;">A&nbsp;<code data-start="445" data-end="454"><strong>pattern</strong></code>&nbsp;string that you are looking for within the&nbsp;<strong><code data-start="498" data-end="504">text</code></strong>.</span></p>
</li>
</ul>
<p data-start="507" data-end="656"><span style="font-size: 14pt;">Return all <strong>positions </strong>(1-based indexing) where the&nbsp;<code data-start="557" data-end="566"><strong>pattern</strong></code>&nbsp;occurs as a substring in the&nbsp;<strong><code data-start="596" data-end="602">text</code></strong>. </span></p>
<p data-start="507" data-end="656"><span style="font-size: 14pt;"><strong>Note:</strong> If the pattern does not occur in text, return an empty list.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: text = "birthdayboy", pattern = "birth"<br><strong>Output:</strong> [1]
<strong>Explanation</strong>: The string "birth" occurs at index 1 in text.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>text = "geeksforgeeks", pattern = "geek"
<strong>Output:</strong> [1, 9]
<strong>Explanation</strong>: The string "geek" occurs twice in text, one starts at index 1 and the other at index 9.</span></pre>
<p><span style="font-size: 18px;"><strong style="font-size: 18px;">Constraints:</strong><br><span style="font-size: 18px;">1 ≤ text.size() ≤ 10<sup>6</sup></span><br><span style="font-size: 18px;">1 ≤ pattern.size() ≤ text.size()</span><br><span style="font-size: 18px;">Both the strings consist of lowercase english alphabets.</span></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Pattern Searching</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;