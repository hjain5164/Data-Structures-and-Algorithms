// Problem - Return all the possible pairs of integers that sum to a value K

#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> pairSum(vector<int> v, int K){

    vector<pair<int, int>> result;
    unordered_set<int> traversedNums;
    for(int i = 0; i < v.size(); i++){
        int x = K - v[i];
        if(traversedNums.find(x) != traversedNums.end()){
            pair<int, int> p;
            p.first = v[i];
            p.second = x;
            result.push_back(p);
        }
        traversedNums.insert(v[i]);
    }
    return result;
}

int main() {
    vector<int> v = {10, 5, 2, 3, -6, 9, 11, 2};
    int sum = 55;
    vector<pair<int, int>> res = pairSum(v, sum);
    if(res.size() != 0){
        for (auto r: res)
            cout << "(" << r.first << ", " << r.second << ")" << endl;
    }
    else
        cout << "No pairs found";
}