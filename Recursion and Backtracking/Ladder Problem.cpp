// Problem - Given a ladder containing N steps. You can take a jump of
// 1, 2 or 3 at each step. Find the number of ways to climb the ladder.

#include <bits/stdc++.h>
using namespace std;

int countWays(int n){
    // To handle negative case
    if(n < 0)
        return 0;

    if(n==0)
        return 1;
    return countWays(n - 1) + countWays(n - 2) + countWays( n - 3);
}

int main() {
    int N = 4;
    cout << countWays(N);
}
