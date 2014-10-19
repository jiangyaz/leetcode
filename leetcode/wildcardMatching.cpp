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
	const char *ss = s, *pp = NULL;
	while (*s != '\0') {
		if (*s == *p || *p == '?') {
			s++; p++;
			continue;
		}
		if (*p == '*') {
			pp = ++p;
			ss = s+1;
			continue;
		}
		if (pp) {
			p = pp;
			s = ss++;
			continue; 
		}
		return false;
	}
	while (*p == '*') p++;
	return *p == '\0';
}