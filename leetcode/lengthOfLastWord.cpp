/* Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

int lengthOfLastWord(const char *s) {
	int index = strlen(s)-1, count = 0;
	while (s[index] == ' ' && index >= 0) index--;

	while (s[index] != ' ' && index >= 0) {
		count++;
		index--;
	}
	return count;
}
