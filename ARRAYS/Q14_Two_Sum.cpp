#include<bits/stdc++.h>
using namespace std;

vector<int> twoSumSortingApproach(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    //Step 1: Sort
    sort(nums.begin(), nums.end());

    //Step 2: 2-pointer Approach
    while(low < high){
        int sum = nums[low] + nums[high];

        if(sum == target){
            return {low, high};
        } else if(sum < target){
            low++;
        } else {
            high--;
        }
    }

    return {-1, -1};
}

vector<int> twoSumHashmapApproach(vector<int> &nums, int target){
    int n = nums.size();
    map<int,int>mpp;

    for(int i = 0; i<n; i++){
        int num = nums[i];
        int moreNeeded = target - num;

        //If the number I need to complete the target sum is already in the map, then I’ve found my answer
        if(mpp.find(moreNeeded) != mpp.end()){ 
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }

    return {-1, -1};
}


int main(){
    vector<int> nums = {2, 6, 5, 8, 11};
    int target = 14;

    vector<int> result = twoSumHashmapApproach(nums, target);

    if(result[0] != -1){
        cout << "Pair found at indices: " << result[0] << " and " << result[1] << endl;
    } 
    else {
        cout << "No pair found." << endl;
    }

    return 0;
    
}