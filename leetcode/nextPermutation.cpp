/* Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

void nextPermutation(vector<int> &num) {
	if (num.size() == 0) return;
    int x = num.size()-2, y = num.size()-1;
    
    // Step 1: find the first number num[x] that violates the increasing pattern
    while (x >= 0) {
        if (num[x] < num[x+1]) break;
        x--;
    }
    // Step 2: Find the first number num[y] that is greater than num[x]
    if (x >= 0) {
        while (y >= x) {
            if (num[y] > num[x]) break;
            y--;
        }
        swap(num[x], num[y]);
    }
    // Step 3: Flip all the numbers after index x
    int start = x+1, end = num.size()-1;
    while (start < end) {
	    swap(num[start++], num[end--]);
    }
}