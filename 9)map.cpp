#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, long long> statepopulation;

    statepopulation["maharashtra"] = 125600099;
    statepopulation["tamilnadu"] = 123456756;
    statepopulation["gujrat"] = 23456778;
    statepopulation["rajasthan"] = 78986578;
    statepopulation["uttar pradesh"] = 98078642;

    string statename;

    cout << "Enter the state name: ";
    getline(cin, statename);

    map<string, long long>::iterator it = statepopulation.find(statename);

    if (it != statepopulation.end())
    {
        cout << "The population of " << statename << " = "
             << it->second << endl;
    }
    else
    {
        cout << "State not found in the map" << endl;
    }

    return 0;
}
