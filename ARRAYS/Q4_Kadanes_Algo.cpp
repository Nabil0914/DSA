#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
    long long maxi = LONG_MIN;
    long long sum = 0;
    
    for(int i=0; i<n; i++){
        sum = sum + arr[i];

        if(sum > maxi){
            maxi = sum;
        }

        if(sum < 0){
            sum = 0;
        }
    }

    return maxi;
}

long long printMaxSubarraySum(int arr[], int n){
    long long maxi = LONG_MIN;
    long long sum = 0;
    long long start = 0;
    long long ansStart = -1;
    long long ansEnd = -1;
    
    for(int i=0; i<n; i++){
        if(sum == 0){
            start = i;
        }
        sum = sum + arr[i];

        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0){
            sum = 0;
        }
    }

    // 🔽 Print the subarray
    cout << "Subarray with maximum sum: ";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return maxi;
}


int main(){
    // int n;
    // cout << "Enter the size of the array: ";
    // cin >> n;
    // int arr[n];
    // cout << "Enter " << n << " elements: ";
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    // long long result = maxSubarraySum(arr, n);
    // cout << "Maximum subarray sum is: " << result << endl;

    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long maxSum = printMaxSubarraySum(arr, n);
    cout << "Maximum Subarray Sum: " << maxSum << endl;

    return 0;

}