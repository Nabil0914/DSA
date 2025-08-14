#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> & num){
    int n = num.size();
    vector<vector<int>> ans;
    sort(num.begin(), num.end());

    for(int i = 0; i<n; i++){
        //If i is the first element and prev val is same then just continue
        //i > 0 ensures we don’t check i - 1 when i = 0
        //num[i] == num[i - 1] means this element is the same as previous → skip it.
        if(i>0 && num[i] == num[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;

        while(j < k){
            int sum = num[i] + num[j] + num[k];

            if(sum < 0){
                j++;
            } 
            else if(sum > 0){
                k--;
            }
            else { //Equal
                vector<int> temp = {num[i], num[j], num[k]};
                ans.push_back(temp);
                j++;
                k--;

                //Check if the prev value of j and k are same, if yes move the pointer 
                while(j < k && num[j] == num[j - 1]) j++;
                while(j < k && num[k] == num[k + 1]) k--;
            }
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {2, -2, -2, 2, 2, -1, 2, -2, -1, 0, 0, 0, -1};

    vector<vector<int>> res = threeSum(nums);

    cout << "Triplets summing to 0:\n";
    for (auto &triplet : res) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

}