// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <iostream>

using namespace std;

int solution(int K, vector< vector<int> > &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<vector<bool>> layers(A.size(),vector<bool>(A.front().size(),true));
    for (int row = 0; row < (int)A.size(); row++)
    {
        for (int col = 0; col < (int)A[row].size(); col++)
        {
            if (A[row][col] == 1)
            {
                vector<vector<bool>> layer(A.size(),vector<bool>(A.front().size(),false));
                for (int i = max(0,row - K); i < min((int)A.size(),row + K + 1); i++)
                {
                    int startingCol = col - (K - abs(i - row)), endingCol =  min((int)A.front().size(),col + (abs(startingCol - col) + 1));
                    startingCol = max(0,startingCol);
                    fill(layer[i].begin() + startingCol,layer[i].begin() + endingCol, true);
                    
                }
                for (size_t layerRow = 0; layerRow < layers.size(); layerRow++)
                {
                    for (size_t layerCol = 0; layerCol < layers[layerRow].size(); layerCol++)
                    {
                        layers[layerRow][layerCol] = layers[layerRow][layerCol] && layer[layerRow][layerCol];
                    }
                }
            }
        }
    }
    size_t total = 0;
    for (size_t row = 0; row < layers.size(); row++)
    {
        for (size_t col = 0; col < layers[row].size(); col++)
        {
            if (layers[row][col] && A[row][col] == 0)
            {
                total++;
            }
        }
    }
    return total;
}
int main() {
    vector<vector<int>> test = {
        {0,0,0,1},
        {0,1,0,0},
        {0,0,1,0},
        {1,0,0,0},
        {0,0,0,0}
        // {0,0,0,0},
        // {0,0,1,0},
        // {1,0,0,1}
        // {0,1},
        // {0,0}
    };
    int k = 4;
    cout << solution(k,test);
}