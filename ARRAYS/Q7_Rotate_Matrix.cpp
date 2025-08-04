#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &arr){
    int n = arr.size();

    //Step 1: Transpose the given matrix
    //Outerloop -> Row
    //Innerloop -> Col
    for(int i = 0; i<n-1; i++){ // Only need to go up to the second-last row
        for(int j = i+1; j<n; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }

    //Step 2: Reverse each row
    for(int i= 0; i<n; i++){
        reverse(arr[i].begin(), arr[i].end());
    }
}

int main(){

    int n;
    cout << "Enter size of square matrix (n x n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter matrix elements row-wise:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    rotateMatrix(matrix);

    cout << "Matrix after 90-degree clockwise rotation:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}