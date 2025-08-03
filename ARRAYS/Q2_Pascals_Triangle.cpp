#include<bits/stdc++.h>
using namespace std;

// Q: Find the element at that particular postiton in Pascal's triangle
int findNCR(int n, int r){
    int res = 1;
    for(int i =0; i<r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

//Q: Print the nth row of the Pascal's triangle
void nthRowPT(int n){
    int ans = 1;
    cout << ans << " ";

    for(int i = 1; i<n; i++){
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

//Q: Given n, print the entire Pascal's triangle
vector<int> generateRow(int row){
    vector<int> ansRow;
    long long ans = 1;
    ansRow.push_back(ans);

    for(int col = 1; col< row; col++){
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }

    return ansRow;
}

vector<vector<int>> pascalTriangle(int N){
    vector<vector<int>> ans;
    for(int i = 1; i<= N; i++){
        ans.push_back(generateRow(i));
    }

    return ans;
}


int main(){
    //Q1
    // int row = 5;
    // int col = 3;
    // int ans = findNCR(row - 1, col - 1);
    // cout << ans;

    //Q2
    // int n;
    // cout << "Enter the row number: ";
    // cin >> n;
    // nthRowPT(n);

    //Q3
    // int N;
    // cout << "Enter number of rows: ";
    // cin >> N;

    // vector<vector<int>> triangle = pascalTriangle(N);

    // Print the triangle
    // for (const auto& row : triangle) {
    //     for (int val : row) {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}