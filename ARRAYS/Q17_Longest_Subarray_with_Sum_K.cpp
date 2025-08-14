#include<bits/stdc++.h>
using namespace std;

//For Postives, Negatives and Zeroes this is Optimal
int longestSubarraySumK(vector<int> &arr, long long k){
    map<long long, int>mpp;
    long long sum = 0;
    int maxLen = 0;

    for(int i = 0; i<arr.size(); i++){
        sum += arr[i];

        if(sum == k){
            maxLen = max(maxLen, i+1);
        }

        long long rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            int len = i - mpp[rem];
            maxLen = max(maxLen, len);
        }

        if(mpp.find(sum) == mpp.end()){
            mpp[sum] = i;
        }
    }
    return maxLen;
}

//For Only Postives
int longestSubarraySumKOptimal(vector<int> &arr, long long k){
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int maxLen = 0;
    int n = arr.size();

    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n){
            sum += arr[right];
        }
    }
    return maxLen;
}

int main(){
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    long long k = 6;

    cout << "Longest subarray length with sum " << k << " is: "
         << longestSubarraySumKOptimal(arr, k) << endl;

    return 0;

}