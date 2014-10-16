/* Zig zag conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number 
of rows like this: (you may want to display this pattern in a fixed font for 
better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a 
number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

string convert(string s, int nRows) {
    string out;
    if (s.length() == 0) return out;
    if (nRows == 1) return s;
    int L = 2*nRows-2;

    for (int i = 0; i < nRows; i++) {
        int start = 0;
        while (start + i < s.length()) {
            out += s[start+i];
            if ((i > 0) && (i < nRows - 1) && (start+L-i < s.length())) {
                out += s[start+L-i];
            }
            start += L;
        }
    }
    return out;
}  