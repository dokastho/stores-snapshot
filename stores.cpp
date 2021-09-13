// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <iostream>

using namespace std;

int find_furthest(vector<pair<int,int>> &vec, int r, int c) {
    int maxDist = 0, dist = 0;
    for (size_t i = 0; i < vec.size(); i++)
    {
        dist = abs(r - vec[i].first) + abs(c - vec[i].second);
        maxDist = max(maxDist,dist);
    }
    return maxDist;
}

int solution(int K, vector< vector<int> > &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<pair<int,int>> houses;
    size_t total = 0;
    for (int row = 0; row < (int)A.size(); row++)
    {
        for (int col = 0; col < (int)A[row].size(); col++)
        {
            if (A[row][col] == 1)
            {
                houses.push_back({row,col});
            }
        }
    }
    for (int row = 0; row < (int)A.size(); row++)
    {
        for (int col = 0; col < (int)A[row].size(); col++)
        {
            if (A[row][col] == 1)
            {
                continue;
            }
            
            if (find_furthest(houses,row,col) <= K) {
                total++;
            }
        }
    }
    
    return total;
}
int main() {
    vector<vector<int>> test = {
        // {0,0,0,1},
        // {0,1,0,0},
        // {0,0,1,0},
        // {1,0,0,0},
        // {0,0,0,0}
        // {0,0,0,0},
        // {0,0,1,0},
        // {1,0,0,1}
        {0,1},
        {0,0}
    };
    int k = 1;
    cout << solution(k,test);
}