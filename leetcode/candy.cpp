/* Candy
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
*/

int candy(vector<int> &ratings) {
	int n = ratings.size();
	if (n == 0) return 0;
	vector<int> left(n, 1);
	vector<int> right(n, 1);

	for (int i = 1; i < n; i++) {
		if (ratings[i] > ratings[i-1]) {
			left[i] = left[i-1] + 1;
		}
	}        
	for (int i = n-2; i >= 0; i--) {
		if (ratings[i] > ratings[i+1]) {
			right[i] = right[i+1] + 1;
		}
	}
	int out = 0;
	for (int i = 0; i < n; i++) {
		out += max(left[i], right[i]);
	}
	return out;
}