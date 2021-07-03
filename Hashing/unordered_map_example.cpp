#include <iostream>
#include <unordered_map>

using namespace std;
int main() {
    unordered_map<string, int> menu;

    // Insertion in Map (Hash Table) is O(1).
    menu["maggi"] = 15;
    menu["colddrink"] = 20;
    menu["dosa"] = 99;
    menu["indianplatter"] = 299;

    // Update the items in Map is O(1).
    menu["dosa"] = (1 + 0.1) * menu["dosa"];

    // Delete an item from the Map is O(1).
    menu.erase("dosa");

    // Searching in Map (Hash Table) is O(1).
    string item;
    cin >> item;
    if(menu.count(item) == 0)
        cout << item << " is not available" << endl;
    else
        cout << item << " is available and its cost is " << menu[item] << endl;

    // Iterate over all the key-value pairs in the Map O(N)
    // Random order
    for(pair<string, int> k: menu)
        cout << k.first << " - " << k.second << endl;
}
