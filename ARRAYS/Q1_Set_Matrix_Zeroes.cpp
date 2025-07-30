#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> betterApproach(vector<vector<int>> &matrix, int n, int m){
    int row[n] = {0};
    int col[m] = {0};

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

vector<vector<int>> optimalApproach(vector<vector<int>> &matrix, int n, int m){
    // int row[n] = {0}; matrix[..][0]
    // int col[m] = {0}; matrix[0][..]
    int col0 = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(matrix[i][j] == 0){
                //mark the i-th row
                matrix[i][0] = 0;
                //mark the j-th col
                if(j != 0){
                    matrix[0][j] = 0;
                } else {
                    col0 = 0;
                }
            }
        }
    }

    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(matrix[i][j] != 0){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if(matrix[0][0] == 0){
        for(int j = 0; j<m; j++){
            matrix[0][j] = 0;
        }
    }

    if(col0 == 0){
        for(int i = 0; i<n; i++){
            matrix[i][0] = 0;
        }
    }

    return matrix;

}


int main(){
    vector<vector<int>> matrix = {
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    // vector<vector<int>> result = betterApproach(matrix, n, m);
    vector<vector<int>> result = optimalApproach(matrix, n, m);


    cout << "Modified Matrix:\n";
    for(const auto &row : result) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;

}