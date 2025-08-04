#include<bits/stdc++.h>
using namespace std;

void DNF(vector<int> &arr, int n){
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
     int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (0, 1, or 2 only): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    DNF(arr, n);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;

}