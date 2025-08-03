#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &arr){
    int ind = -1;
    int n = arr.size();

    //Observation 1: find the break point
    for(int i = n - 2; i>= 0; i--){
        if(arr[i] < arr[i+1]){
            ind = i;
            break;
        }
    }
    // If no break point found, it's the last permutation
    if(ind == -1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    //Observation 2: find the next bigger element and swap
    for(int i = n - 1; i>ind; i--){
        if(arr[i] > arr[ind]){
            swap(arr[i], arr[ind]);
            break;
        }
    }

    //Observation 3: reverse the remaining part
    reverse(arr.begin() + ind + 1, arr.end());
    return arr;
}

int main(){
    vector<int> arr = {3, 2, 1};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result = nextPermutation(arr);

    cout << "Next permutation: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;

}