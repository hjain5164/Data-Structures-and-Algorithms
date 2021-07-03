// Problem - Return all the possible pairs of integers that sum to a value K

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> tripletSum(vector<int> v, int K){
    vector<vector<int>> result;
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size() - 3; i++){
        int remainingSum = K - v[i];
        int start = i + 1;
        int end = v.size() - 1;

        while(start < end){
            if(v[start] + v[end] == remainingSum){
                result.push_back({v[i], v[start], v[end]});
                start++;
                end--;
            }
            else if(v[start] + v[end] > remainingSum)
                end--;
            else    
                start++;
        }
    }
    return result;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int sum = 18;
    vector<vector<int>> triplets = tripletSum(v, sum);
    if(triplets.size() != 0){
        for (auto r: triplets)
            cout << "(" << r[0] << ", " << r[1] << ", " << r[2] << ")" << endl;
    }
    else
        cout << "No Triplets Found";
}