
/*  Container With Most Water 
Given n non-negative integers a1, a2, ..., an, where each represents a point 
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints 
of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
forms a container, such that the container contains the most water.
Note: You may not slant the container. */

int maxArea(vector<int> &height) {
    int start = 0, end = height.size()-1;        
    int largestArea = 0;

    while (start <= end) {
        int area = min(height[start], height[end]) * (end - start);
        largestArea = max(largestArea, area);

        if (height[start] <= height[end]) {
            start++;
        } else {
            end--;
        }
    }
    return largestArea;
}