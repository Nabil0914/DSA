#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingBrute(vector<vector<int>> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i = 0; i<n; i++){
        int start = arr[i][0];
        int end = arr[i][1];

        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }

        for(int j = i+1; j<n; j++){
            if(arr[j][0] <= end){
                end = max(end, arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

vector<vector<int>> mergeOverlappingOptimal(vector<vector<int>> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i = 0; i<n; i++){
        //For new subinterval
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        //merge intervals
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the intervals (start end):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> merged = mergeOverlappingBrute(intervals);

    cout << "Merged intervals:\n";
    for (auto interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;

}