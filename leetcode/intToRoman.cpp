/* Integer to Roman */


string intToRoman(int num) {
	string symb[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};      
	string out;
	for (int i = 0; i < 13; i++) {
		while (num >= val[i]) {
			num -= val[i];
			out += symb[i];
		}
	}
	return out;
}


