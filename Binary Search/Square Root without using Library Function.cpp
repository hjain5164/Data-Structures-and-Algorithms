// Given an integer N and an integer P,  you need to find the square root
// of number N upto P places. Without any library function.


#include <bits/stdc++.h>
using namespace std;

float square_root(int N, int P){
    int s = 0;
    int e = N;
    float ans = 0;

    // Binary Search for integer part
    while(s <= e){
        int mid = (s + e)/2;
        if(mid * mid == N)
            return mid;
        else if(mid*mid < N){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }

    // Linear Search for floating part
    float inc = 0.1;
    for(int place = 1; place <= P; place++){
        while(ans*ans <= N){
            ans += inc;
        }
        ans = ans - inc;
        inc = inc/10.0;
    }
    return ans;
}

int main() {
    int N = 10, P = 3;
    cout << square_root(N, P);
}
