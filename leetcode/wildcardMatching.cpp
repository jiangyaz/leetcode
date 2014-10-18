/* wildcard matching

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

bool isMatch(const char *s, const char *p) {
	if (*p == '\0') return *s =='\0';
	const char *ss;
	const char *mark;
	while (*s != '\0') {
		if (*s == *p || *p == '?') {
			s++; p++;
			continue;
		}
		if (*p == '*') {
			mark = p+1;
			ss = s;
			continue;
		}
		if (mark) {
			p = mark;
			s = ++ss;
			continue; 
		}
		return false;
	}
	return true;
}