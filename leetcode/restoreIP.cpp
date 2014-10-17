/* Restore IP Addresses
Given a string containing only digits, restore it by returning all 
possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

bool isValidNumber(string s) {
    int num = 0;
    if (s.length() > 1 && s[0] == '0') return false;
    
	for (int i = 0; i < s.length(); i++) {
	    if (s[i] < '0' || s[i] > '9') 
	        return false;
	    num = num * 10 + (s[i] - '0');
    }
    
    if (num >= 0 && num <= 255)  
        return true;
    else  
        return false;
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string sol;
    getIP(res, sol, s, 0, 0);
    return res;
}

void getIP(vector<string> &res, string &sol, string s, int start, int level) {
    if (level == 4) {
	    if (start == s.length()) {
		    sol.pop_back();
		    res.push_back(sol);
	    }
	    return;
    }
    if (start == s.length()) return;
    
    // push 1 number
    int len = sol.length();
    if (isValidNumber(s.substr(start, 1))) {
	    sol += s.substr(start, 1) + ".";
	    getIP(res, sol, s, start+1, level+1);
	    sol.resize(len);
    }
    // push 2 numbers
    if (start+2 <= s.length() && isValidNumber(s.substr(start, 2))) {
	    sol += s.substr(start, 2) + ".";
	    getIP(res, sol, s, start+2, level+1);
	    sol.resize(len);
    }
    // push 3 numbers
    if (start+3 <= s.length() && isValidNumber(s.substr(start, 3))) {
	    sol += s.substr(start, 3) + ".";
	    getIP(res, sol, s, start+3, level+1);
	    sol.resize(len);
    }
}