#include<bits/stdc++.h>
using namespace std;

vector<int> hashingApproach(vector<int> &arr){
    int n = arr.size();
    int hash[n+1] = {0};
    int repeating = -1;
    int missing = -1;

    for(int i = 0; i<n; i++){
        hash[arr[i]]++;
    }

    for(int i = 1; i<n; i++){
        if(hash[i] == 2){
            repeating = i;
        }
        else if(hash[i] == 0){
            missing = i;
        }

        if(repeating != -1 && missing != -1){
            break;
        }
    }
    return {repeating, missing};
}

vector<int> equationApproachOptimal(vector<int> &arr){
    long long n = arr.size();

    long long SN = n * (n + 1) / 2;
    long long S2N = n * (n + 1) * (2 * n + 1) / 6;
    long long S1 = 0;
    long long S2 = 0;

    for(int i = 0; i<n; i++){
        S1 += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }
    long long val1 = S1 - SN; // X - Y
    long long val2 = S2 - S2N;
    val2 = val2 / val1; // X + Y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

int main(){

    vector<int> arr = {4, 3, 6 , 2, 1, 1}; // Example input: 3 is repeating, 2 is missing
    // vector<int> result = hashingApproach(arr);
    vector<int> result = equationApproachOptimal(arr);

    cout << "Repeating: " << result[0] << endl;
    cout << "Missing: " << result[1] << endl;

    return 0;

}