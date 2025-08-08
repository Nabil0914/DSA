#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    long long m = n;
    double ans = 1;

     if(m < 0){
        x = 1 / x;
        m = -m;
    }

    while(m > 0){
        //For Odd
        if(m % 2 == 1){
            ans = ans * x;
            m = m - 1;
        }
        //For even
        else {
            m = m / 2;
            x = x * x;
        }
    }

    return ans;
}


int main(){
    double x;
    int n;
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    double result = myPow(x, n);
    cout << x << "^" << n << " = " << result << endl;

    return 0;

}