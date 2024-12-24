#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "banker.hpp"
// #define int unsigned long long
using namespace std;

int main()
{
    string path_available = "F:\\EXCEL\\Available.csv";
    string path_max = "F:\\EXCEL\\Max.csv";
    string path_allocation = "F:\\EXCEL\\Allocation.csv";

    vector<int> available;
    vector<vector<int>> allocation;
    vector<vector<int>> max;

    read_csv(available, path_available);
    read_csv(max, path_max);
    read_csv(allocation, path_allocation);
    // 浅拷贝
    matrix_one available_matrix(available);
    matrix_two max_matrix(max);
    matrix_two allocation_matrix(allocation);
    while (true)
    {
        string request_str;
        printf(" please input id  and request matrix :");
        getline(cin, request_str);
        if (request_str.empty())
        {
            cout << "no null !!!" << endl;
        }
        else
        {
            int id;
            vector<int> request_vector;
            str_to_int(request_str, id, request_vector);
            // 先构造一个新的matrix，相减，然后再 move。
            string str = "";
            matrix_one request(request_vector);
            str = sec_str(available_matrix, allocation_matrix, max_matrix, request, id);
            if (str.at(0) == ' ')
            {
                cout << "  !!!" << endl;
            }
            else
            {
                cout << " SecStr= " << str << endl;
                // 数值更新 need[]=max-allocation,max一直未改变，所以不用更新need,只需在函数中计算
                available_matrix -= request;
                allocation_matrix.add_two_one(request, id);
                // print_matrix(available_matrix.matrix);
            }
        }
    }
    return 0;
}
