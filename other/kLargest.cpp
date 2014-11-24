#include <iostream>
#include <vector>
using namespace std;

vector<int> getKLargest1(vector<int> &num, int k) {
	vector<int> res;
	for (int i = 0; i < k; i++) {
		int max = num[i];
		int index = i;
		for (int j = i; j < num.size(); j++) {
			if (num[j] > max) {
				max = num[j];
				index = j;
			}
		}
		res.push_back(max);
		swap(num[i], num[index]);
	}
	return res;
}


int main() {
	vector<int> num;
	num.push_back(2); num.push_back(8); num.push_back(3); num.push_back(7);
	num.push_back(1); num.push_back(4); num.push_back(6); num.push_back(5);

	vector<int> res;
	res = getKLargest1(num, 5);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}