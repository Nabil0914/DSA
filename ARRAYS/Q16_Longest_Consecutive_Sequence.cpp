#include<bits/stdc++.h>
using namespace std;

int longestConsecutiveSequenceBetter(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int longest = 1;
    int currCnt = 0;
    int lastSmaller = INT_MIN;

    for(int i = 0; i<n ; i++){
        if(nums[i] - 1 == lastSmaller){
            currCnt += 1;
            lastSmaller = nums[i];
        }
        else if(lastSmaller != nums[i]){
            currCnt = 1;
            lastSmaller = nums[i];
        } 
        longest = max(longest, currCnt);
    }

    return longest;
}


//Think of:
// == st.end() → Not Found
// != st.end() → Found
int longestConsecutiveSequenceOptimal(vector<int> &nums){
    int n = nums.size();
    if(n == 0) return 1;
    int longest = 1;
    unordered_set<int>st;

    for(int i = 0; i<n; i++){
        st.insert(nums[i]);
    }

    for(auto it: st){
        if(st.find(it - 1) == st.end()){
            int cnt = 1;
            int x = it;

            while(st.find(x + 1) != st.end()){
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence Length: "
        << longestConsecutiveSequenceOptimal(nums) << endl;

}