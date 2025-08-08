#include<bits/stdc++.h>
using namespace std;

int majorityElementBrute(vector<int> & v){
    int n = v.size();
    map<int, int>mpp;
    for(int i = 0; i<n; i++){
        mpp[v[i]]++;
    }

    for(auto it: mpp){
        if(it.second > n / 2){
            return it.first;
        }
    }

    return -1;
}

int majorityElementOptimal(vector<int> & v){
    int el;
    int cnt = 0;
    int n = v.size();

    for(int i = 0; i<n; i++){
        //New section / Start 
        if(cnt == 0){
            el = v[i];
            cnt = 1;
        } else if(v[i] == el){
            cnt++;
        } else{
            cnt--;
        }
    }

    //Verification
    int cnt2 = 0;
    for(int i = 0; i<n; i++){
        if(v[i] == el){
            cnt2++;
        }
    }

    if(cnt2 > n / 2){
        return el;
    }

    return -1;
}

int main(){
    vector<int> v = {7, 7, 5, 7, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
    // int ans = majorityElementBrute(v);
    int ans = majorityElementOptimal(v);

    if (ans != -1){
        cout << "Majority element is: " << ans << endl;
    }
        
    else{
        cout << "No majority element found." << endl;
    }
    
    return 0;
}