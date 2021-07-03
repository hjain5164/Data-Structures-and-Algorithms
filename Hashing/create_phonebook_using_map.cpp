#include <iostream>
#include <map>
#include <list>

using namespace std;
int main() {
    map<string, list<string> > phonebook;
    phonebook["Harsh"].push_back("11111111");
    phonebook["Harsh"].push_back("11111122");
    phonebook["Harsh"].push_back("11111133");
    phonebook["Tom"].push_back("777777777");
    phonebook["Harry"].push_back("99999999");


    for(pair<string, list<string> > k: phonebook){
        cout << k.first << " - ";
        for(string number: k.second)
            cout << number << ", ";
        cout << endl;
    }
}
