#include <iostream>

using namespace std;
int main() {
    int N, total = 0, point;
    cin >> N;
    int scores[11][2];
    
    // Reformulate the scores into a 2D array, where each row represents results from 1 frame
    int row = 0, index = 0;
    while (index < N) {
        cin >> point;
        scores[row][0] = point;
        if (point == 10) { 
            scores[row][1] = 0;
            index++;
        } else {
            cin >> point;
            scores[row][1] = point;
            index +=2;
        }
        row++; 
    }

    // Calculate the scores
    for (int i = 0; i < 10; i++) {
        total += scores[i][0];
        total += scores[i][1];
        if (scores[i][0] == 10) {   // If we hit a spike, add the next two numbers.
            if (scores[i+1][0] == 10)
                total += scores[i+1][0] + scores[i+2][0];
            else
                total += scores[i+1][0] + scores[i+1][1];   
        } else if (scores[i][0] + scores[i][1] == 10) {
            total += scores[i+1][0];
        }
    }

    cout << total;
    
    return 0;
}