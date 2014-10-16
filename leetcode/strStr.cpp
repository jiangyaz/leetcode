/* Implement strStr()
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, 
or null if needle is not part of haystack.
*/

char *strStr(char *haystack, char *needle) {
	if (strlen(needle) == 0) return haystack;

	while (*haystack != '\0') {
		if (*haystack == *needle) {
			char *p1 = haystack;
			char *p2 = needle;
			while (*p2 != '\0') {
				if (*p1 != *p2 || *p1 == '\0') 
					break;
				p1++; p2++;
			}
			if (p2 == '\0') return haystack;
		} 
		haystack++;
	} 
	return NULL;       
}