#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <sstream>
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
        cout << " 请输入进程 id 与请求向量 (最初始的进程用 0 表示,以空格分开):";
        getline(cin, request_str);
        if (request_str.empty())
        {
            cout << "输入不可为空 !!!" << endl;
        }
        else
        {
            int id;
            vector<int> request_vector;
            str_to_int(request_str, id, request_vector);
            // 先构造一个新的matrix，相减，然后再 move。
            string str = sec_str(available_matrix, allocation_matrix, max_matrix, matrix_one(request_vector),id);
            if (str.empty())
            {
                cout << "  不存在安全序列为!!!" << endl;
            }
            else
            {
                cout << "  安全序列为:  " << str << endl;
            }
        }
    }

    print_matrix(available);
    print_matrix(max);
    return 0;
}
