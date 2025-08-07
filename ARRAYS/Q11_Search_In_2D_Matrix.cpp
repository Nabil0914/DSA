#include<bits/stdc++.h>
using namespace std;

bool searchIn2DMatrix(vector<vector<int>> &mat, int target){
    int n = mat.size(); // returns number of rows
    int m = mat[0].size(); // returns number of columns
    int low = 0;
    int high = n * m - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;

        if(mat[row][col] == target){
            return true;
        } else if(mat[row][col] < target){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 16;

    if (searchIn2DMatrix(matrix, target))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;

}