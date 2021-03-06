<h2>337. House Robber III</h2><h3>Medium</h3><hr><div><p>The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.</p>

<p>Determine the maximum amount of money the thief can rob tonight without alerting the police.</p>

<p><b>Example 1:</b></p>

<pre><strong>Input: </strong>[3,2,3,null,3,null,1]

     <font color="red" data-darkreader-inline-color="" style="--darkreader-inline-color:#ff0000;">3</font>
    / \
   2   3
    \   \ 
     <font color="red" data-darkreader-inline-color="" style="--darkreader-inline-color:#ff0000;">3   1
</font>
<strong>Output:</strong> 7 
<strong>Explanation:</strong>&nbsp;Maximum amount of money the thief can rob = <font color="red" style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;; --darkreader-inline-color:#ff0000;" data-darkreader-inline-color="">3</font><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;"> + </span><font color="red" style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;; --darkreader-inline-color:#ff0000;" data-darkreader-inline-color="">3</font><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;"> + </span><font color="red" style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;; --darkreader-inline-color:#ff0000;" data-darkreader-inline-color="">1</font><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;"> = </span><b style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">7</b><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">.</span></pre>

<p><b>Example 2:</b></p>

<pre><strong>Input: </strong>[3,4,5,1,3,null,1]

&nbsp;    3
    / \
   <font color="red" data-darkreader-inline-color="" style="--darkreader-inline-color:#ff0000;">4</font>   <font color="red" data-darkreader-inline-color="" style="--darkreader-inline-color:#ff0000;">5</font>
  / \   \ 
 1   3   1

<strong>Output:</strong> 9
<strong>Explanation:</strong>&nbsp;Maximum amount of money the thief can rob = <font color="red" data-darkreader-inline-color="" style="--darkreader-inline-color:#ff0000;">4</font> + <font color="red" data-darkreader-inline-color="" style="--darkreader-inline-color:#ff0000;">5</font> = <b>9</b>.
</pre></div>