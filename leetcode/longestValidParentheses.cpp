/* Longest Valid Parentheses

Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", 
which has length = 4.

*/

int longestValidParentheses(string s) {
    if (s.length() == 0) return 0;
    stack<int> sta;
    int minIndex = 0, maxLen = 0;
    for (int i = 0; i < s.length(); i++) {
	    if (s[i] == '(') {
		    sta.push(i);
    	} else {    // receives ')'
		    if (sta.empty()) {
			    minIndex = i + 1;
		    } else {
		        sta.pop();
		        if (sta.empty()) 
		            maxLen = max(maxLen, i - minIndex + 1);
		        else 
		            maxLen = max(maxLen, i - sta.top()); // trick!
		    }
	    }
    }
    return maxLen;
}