// Problem (Angry Birds) - There is a long wire at straight line, which 
// contains N bird nests at positions X1, X2,...XN. There are B (B <= N) birds, 
// which become angry towards each other once put into a nest. To put the birds 
// from hurting each other you want to assign birds to nests such that minimum 
// distance between any two birds is as large as possible. What is the largest 
// minimum distance?

#include <bits/stdc++.h>
using namespace std;

bool canPlaceBirds(int birds, int N, vector<int> nests, int sep)
{
    int placeBirds = 1;
    int location = nests[0];

    for(int i = 1; i < N - 1; i++){
        int current_location = nests[i];
        if(current_location - location >= sep){
            placeBirds++;
            location = current_location;
            if(placeBirds == birds)
                return true;
        }
    }
    return false;
}
int main() {
    int B = 3;
    vector<int> nests{1,2,4,8,9};
    // sorting needs to be there for nests.
    sort(nests.begin(), nests.end());
    int N = nests.size();
    int ans = -1;
    int s = 0;
    int e = nests[N - 1] - nests[0];
    while(s <= e){
        int mid = (s + e)/2;
        
        bool canPlace = canPlaceBirds(B, N, nests, mid);
        if(canPlace){
            s = mid + 1;
            ans = mid;
        }
        else
            e = mid - 1;
    }
    cout << ans;
}
