// Given an array and an integer K. You need to find the maximum for each and every
// contiguous subarray of size K.

#include <bits/stdc++.h>
using namespace std;

void max_subarray(vector<int> a, int K){
    deque<int> Q(K);
    int i;
    for(i = 0; i < K; i++){
        while(!Q.empty() && a[i] > a[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    for(; i < a.size(); i++){
        cout << a[Q.front()] << " ";
        while(!Q.empty() && Q.front() <= i - K)
            Q.pop_front();
        while(!Q.empty() && a[i] >= a[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    cout << a[Q.front()];
    return;
}

int main() {
    vector<int> v = {1,2,3,1,4,5,2,3,6};

    max_subarray(v, 3);
}

