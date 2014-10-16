/* Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/

char lowCase(char ch) {
    if (ch >= 'A' && ch <= 'Z') 
        return ch - 'A' + 'a';
    else 
        return ch;
}

bool isAlphaNumeric(char ch) {
    if (ch >= '0' && ch <= '9') 
        return true;
    else if (ch >= 'a' && ch <= 'z') 
        return true;
    else if (ch >= 'A' && ch <= 'Z') 
        return true;
    else 
        return false; 
}

bool isPalindrome(string s) {
    int start = 0, end = s.length()-1;
    while (start < end) {
	    while (start < end && !isAlphaNumeric(s[start])) {start++;}
	    while (start < end && !isAlphaNumeric(s[end])) {end--;}
	    if (lowCase(s[start++]) != lowCase(s[end--])) return false;
    }
    return true;
}