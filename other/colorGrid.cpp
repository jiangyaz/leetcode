#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 10;

int distance(int xa, int ya, int xb, int yb) {
  return abs(xa - xb) + abs(ya - yb);
}

void printGrid(int A[N][N], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout<< A[i][j] << " ";
    }
    cout << endl;
  }
}

int getColor(int i, int j, vector<vector<int> > colorInfo) {
  int minDist = N+N, bestColor = 0;
  for (int k = 0; k < int(colorInfo.size()); k++) {
    int dist = distance(i, j, colorInfo[k][0], colorInfo[k][1]);
    if (dist < minDist) {
      minDist = dist;
      bestColor = colorInfo[k][2];
    }
  }
  return bestColor;
}

// Method 1: using distance array
// time complexity: O(N^2 * k)
// space complexity: O(k)
void colorGrid(int A[N][N], int N) {
  // Store color info and it's root position
  vector<vector<int> > colorInfo;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++){
      if (A[i][j] > 0) {
        vector<int> color;
        color.push_back(i);
        color.push_back(j);
        color.push_back(A[i][j]);
        colorInfo.push_back(color);
      }
    }
  }
  
  if (colorInfo.size() == 0) {
    cout << "Err: input contains all zeros!";
    return;
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (A[i][j] == 0) {
        A[i][j] = getColor(i, j, colorInfo);
      }
    }
  }
}

/* -------------------------------------------- */

struct Node {
  int i;
  int j;
  int color;
  Node(){};
  Node(int x, int y, int c): i(x), j(y), color(c) {};
};

// Method 2: using BFS
// Time complexity: O(N^2)

void colorGrid2(int A[N][N], int N) {
  queue<Node *> q;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (A[i][j] > 0) {
        Node *newNode = new Node(i, j, A[i][j]);
        q.push(newNode);
      }
    }
  }
  while(!q.empty()) {
    Node *node = q.front();
    int i = node->i;
    int j = node->j;
    if (i > 0 && A[i-1][j] == 0) { // check up
      Node *newNode = new Node(i-1, j, node->color);
      q.push(newNode);
      A[i-1][j] = node->color;
    }
    if (j > 0 && A[i][j-1] == 0) { // check left
      Node *newNode = new Node(i, j-1, node->color);
      q.push(newNode);
      A[i][j-1] = node->color;
    }
    if (j < N-1 && A[i][j+1] == 0) { // check right
      Node *newNode = new Node(i, j+1, node->color);
      q.push(newNode);
      A[i][j+1] = node->color;
    }
    if (i < N-1 && A[i+1][j] == 0) { // check down
      Node *newNode = new Node(i+1, j, node->color);
      q.push(newNode);
      A[i+1][j] = node->color;
    }
    q.pop();
  }
}


int main() {
  int grid[][N] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 6, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 5, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {3, 0, 0, 0, 0, 0, 0, 0, 0, 4}
  };
  
  // colorGrid(grid, N);
  colorGrid2(grid, N);
  printGrid(grid, N);
  
  return 0;
}






