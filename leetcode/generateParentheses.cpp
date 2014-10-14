/* Generate Parentheses 

Given n pairs of parentheses, write a function to generate all combinations 
of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

vector<string> generateParenthesis(int n) {
	vector<string> res;
	string sol;     
	getParenthesis(res, sol, 0, 0, n);   
	return res;
}

void getParenthesis(vector<string> &res, string &sol, int left, int right, int n) {
	if (left == n && right == n) {
		res.push_back(sol);
		return;
	}
	
	if (left < n) {
		sol.push_back('(');
		getParenthesis(res, sol, left+1, right, n);
		sol.pop_back();
	}
	
	if (left > right) {
		sol.push_back(')');
		getParenthesis(res, sol, left, right+1, n);
		sol.pop_back();
	}
}