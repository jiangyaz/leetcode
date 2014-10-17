/* Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

int toNumber(string s) {
    int out = 0, isPos = true, start = 0;
    if (s[0] == '-') {
        isPos = false;
        start++;
    }
    for (int i = start; i < s.length(); i++) 
	    out = out * 10 + s[i] - '0';
    return isPos ? out : -out;
}

int evalRPN(vector<string> &tokens) {
    stack<int> sta;
    int num1, num2;
    for (int i = 0; i < tokens.size(); i++) {
	    if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
		    num1 = sta.top(); sta.pop();
		    num2 = sta.top(); sta.pop();
		    if (tokens[i] == "+")
			    sta.push(num1+num2);
		    else if (tokens[i] == "-")
			    sta.push(num2-num1);
		    else if (tokens[i] == "*")
			    sta.push(num1*num2);
		    else if (tokens[i] == "/")
			    sta.push(num2/num1);
	    } else {
	        sta.push(toNumber(tokens[i]));
	    }
    }
    return sta.top();
} 