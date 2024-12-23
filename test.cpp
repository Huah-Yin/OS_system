#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "banker.hpp"
// #define int unsigned long long
using namespace std;
int main()
{
    string path_available = "F:\\EXCEL\\Available.csv";
    string path_max = "F:\\EXCEL\\Max.csv";
    vector<int> available;
    vector<vector<int>> max;
    read_csv(available, path_available);
    read_csv(max, path_max);
    return 0;
}