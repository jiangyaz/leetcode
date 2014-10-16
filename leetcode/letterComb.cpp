/* Letter Combinations of a Phone Number
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

*/

vector<string> letterCombinations(string digits) {
	vector<string> res;
	string sol;
	getLetterComb(res, sol, digits, 0);   
	return res; 
}

void getLetterComb(vector<string> &res, string &sol, string digits, int index) {
	string table[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
	if (index == digits.length()) {
		res.push_back(sol);
		return;
	}
	int num = digits[index] - '0';
	for (int i = 0; i < table[num].size(); i++) {
		sol.push_back(table[num][i]);
		getLetterComb(res, sol, digits, index+1);
		sol.pop_back();
	}
}