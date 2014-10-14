/* Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid 
but "(]" and "([)]" are not.
*/

bool isValid(string s) {
    stack<char> sta;
    int index = 0;
    while (index < s.length()) {
	    if (s[index] == '(' || s[index] == '{' || s[index] == '[') {
		    sta.push(s[index++]);
		    continue;
	    } else if (s[index] == ')') {
		    if (sta.empty() || sta.top() != '(')  // don't forget the sta.empty() condition
		        return false;
	    } else if (s[index] == '}') {
		    if (sta.empty() || sta.top() != '{') 
		        return false;    			
	    } else if (s[index] == ']') {
		    if (sta.empty() || sta.top() != '[') 
		        return false;
	    }
	    sta.pop();
	    index++;
    }
	    if (!sta.empty()) 
		    return false;
	    else 
		    return true; 
}