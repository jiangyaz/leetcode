#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

const int N = 8;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {};
    Point(int a, int b) : x(a), y(b) {};
};

void search(int altitute[][N], vector<vector<int> > &outMap, queue<Point> q) {
    while (!q.empty()) {
        Point node = q.front();
        q.pop();
        int i = node.x, j = node.y; 
        // check up
        if (i > 0 && outMap[i-1][j] == 0 && altitute[i-1][j] > altitute[i][j]) {
            outMap[i][j] = 1;
            Point p(i-1, j);
            q.push(p);
        }
        // check left
        if (j > 0 && outMap[i][j-1] == 0 && altitute[i][j-1] > altitute[i][j]) {
            outMap[i][j-1] = 1;
            Point p(i, j-1);
            q.push(p);
        }
        // check right
        if (j < N-1 && outMap[i][j+1] == 0 && altitute[i][j+1] > altitute[i][j]) {
            outMap[i][j+1] = 1;
            Point p(i, j+1);
            q.push(p);
        }
        // check down
        if (i < N-1 && outMap[i+1][j] == 0 && altitute[i+1][j] > altitute[i][j]) {
            outMap[i+1][j] = 1;
            Point p(i+1, j);
            q.push(p);
        }
    }
}

void bfsAtlantic(int altitute[][N], vector<vector<int> > &outMap) {
    queue<Point> q;
    for (int j = 0; j < N; j++) {
        Point p(0, j);
        outMap[0][j] = 1;
        q.push(p);
    }
    for (int i = 0; i < N-1; i++) {
        Point p(i, 0);
        outMap[i][0] = 1;
        q.push(p);
    }
    search(altitute, outMap, q);
}

void bfsPacific(int altitute[][N], vector<vector<int> > &outMap) {
    queue<Point> q;
    for (int j = 0; j < N; j++) {
        Point p(N-1, j);
        outMap[N-1][j] = 1;
        q.push(p);
    }
    for (int i = 0; i < N-1; i++) {
        Point p(i, N-1);
        outMap[i][N-1] = 1;
        q.push(p);
    }
    search(altitute, outMap, q);
}

void printMap(vector<vector<int> > &outMap) {
    if (outMap.size() == 0) return;

    for (int i = 0; i < outMap.size(); i++) {
        for (int j = 0; j < outMap[0].size(); j++) {
            cout << outMap[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int altitute[][N] = {{1,2,1,3,4,1,2,2}, 
                         {0,3,2,4,8,3,2,9},
                         {1,4,6,2,6,4,5,2},
                         {2,5,8,0,5,1,3,4},
                         {1,2,1,3,4,1,2,2}, 
                         {0,3,2,4,8,3,2,9},
                         {1,4,6,2,6,4,5,2},
                         {2,5,8,0,5,1,3,4}};

    vector<vector<int> > atlantic(N, vector<int>(N, 0));
    vector<vector<int> > pacific(N, vector<int>(N, 0));
    bfsAtlantic(altitute, atlantic);
    bfsPacific(altitute, pacific);

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++)
            atlantic[i][j] &= pacific[i][j];

    printMap(atlantic);
    return 0;
}