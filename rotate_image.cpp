#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
       int n=matrix.size();

       for(int i=0;i<n-1;i++)
       {
           for(int j=i+1;j<n;j++)
           {
            swap(matrix[i][j],matrix[j][i]);
           }
      }
       for(int i=0;i<n;i++)
       {
        reverse(matrix[i].begin(),matrix[i].end());
       }



    }
};


int main() {
    // Example matrix (3x3)
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Print original matrix
    cout << "Original Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Rotate the matrix
    Solution sol;
    sol.rotate(matrix);

    // Print rotated matrix
    cout << "\nRotated Matrix by 90 degrees clockwise:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}