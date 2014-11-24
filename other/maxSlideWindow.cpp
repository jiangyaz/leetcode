/* Max Sliding Window
A long array A[] is given to you. There is a sliding window of size w which is moving from 
the very left of the array to the very right. You can only see the w numbers in the window. 
Each time the sliding window moves rightwards by one position. Following is an example:
The array is [1 3 -1 -3 5 3 6 7], and w is 3.
*/


// Time complexity: O(n), space: O(w)
void maxSlidingWindow(int A[], int n, int w, int B[]) {
	deque<int> d;
	for (int i = 0; i < w; i++) {
		while (!d.empty() && A[i] >= d.back()) 
			d.pop_back();
		d.push_back(i);
	}
	for (i = w; i < n; i++) {
		B[i-w] = A[d.front()];
		while (!d.empty() && A[i] >= d.back()) {
			d.pop_back();
		}
		while (!d.empty() && d.front <= i-w) {
			d.pop_front();
		}
		d.push_back(i);
	}
	B[n-w] = A[d.front()];
}