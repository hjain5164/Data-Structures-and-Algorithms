// Problem - Given an array, find the minimum number of swaps
// required to make the array sorted.

#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> arr){
    int ans = 0;
    pair<int, int> ap[arr.size()];
    for(int i = 0; i < arr.size(); i++){
        ap[i].first = arr[i];
        ap[i].second = i;
    }
    sort(ap, ap + arr.size());

    vector<bool> visited(arr.size(), false);
    for(int i = 0; i < arr.size(); i++){
        int old_position = ap[i].second;
        if(visited[i] == true || old_position == i){
            continue;
        }

        int node = i;
        int cycle = 0;
        while(visited[node] == false){
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle++;
        }
        ans += (cycle - 1);
    }

    return ans;
}

int main() {
    vector<int> input{5, 4, 3, 2, 1};
    int result = minSwaps(input);
    cout<< "Minimum number of Swaps: " << result;
}
