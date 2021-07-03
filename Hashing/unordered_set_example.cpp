#include <iostream>
#include <unordered_set>

using namespace std;
int main() {
    unordered_set<int> s{1,2,3,8,11,15,0};

    // Insertion is O(1)
    s.insert(111);

    // Deletion is O(1)
    s.erase(11);
    
    // Searching works in O(1) in average case.
    int key;
    cin >> key;
    if(s.find(key) != s.end())
        cout << key << " is present" << endl;
    else
        cout << key << " is not present" << endl;

    // Print all the elements of unordered set.
    for(int x: s)
        cout << x << ", " << endl;
    return 0;


}
