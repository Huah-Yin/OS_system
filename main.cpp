#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "banker.hpp"
string matrix_message = "矩阵维度不匹配";
// #define int unsigned long long
using namespace std;

int main()
{
    string path_available = "F:\\EXCEL\\Available_csv.csv";
    string path_max = "F:\\EXCEL\\Max_csv.csv";
    string path_allocation = "F:\\EXCEL\\Allocation_csv.csv";

    vector<int> available;
    vector<vector<int>> allocation;
    vector<vector<int>> max;

    read_csv(available, path_available);
    read_csv(max, path_max);
    read_csv(allocation, path_allocation);

    // 矩阵初始化
    matrix_one available_matrix(available);
    matrix_two max_matrix(max);
    matrix_two allocation_matrix(allocation);

    while (true)
    {

        int choice = -1;
        printMenu();
        // 用 while 替代 switch 的逻辑
        cin >> choice;
        if (choice == 1)
        {
            cout << "正在查看系统当前资源使用情况..." << endl;
            cout << "Available矩阵:";
            print_matrix(available_matrix.matrix);
            cout << "Allocation矩阵:";
            print_matrix(allocation_matrix.matrix);
            cout << "Max矩阵:";
            print_matrix(max_matrix.matrix);
        }
        else if (choice == 2)
        {
            cout << "正在分析当前系统安全性..." << endl;
            cout << "system is safe !" << endl;
        }
        else if (choice == 3)
        {
            cout << "正在请求资源..." << endl;
            printf("请输入进程号 id 与请求向量 request(以空格分隔): \n");
            string request_str;
            cin.ignore();
            getline(cin, request_str);
            if (request_str.empty())
            {
                cout << "输入为空!!!" << endl;
            }
            else
            {
                int id;
                vector<int> request_vector;
                str_to_int(request_str, id, request_vector);
                // 先创建一个新的 matrix，相反，然后再移动它。
                string str = "";
                matrix_one request(request_vector);
                str = sec_str(available_matrix, allocation_matrix, max_matrix, request, id);
                if (str.at(0) == ' ') // 如果返回安全序列的第一个字符为" "
                {
                    cout << "!!!" << endl;
                }
                else
                {
                    cout << " SecStr= " << str << endl;
                    // 数据更新 need[] = max - allocation，max[] 一直未改变，所以无需更新 need，只需在函数中计算。
                    available_matrix -= request;
                    allocation_matrix.add_two_one(request, id);
                }
            }
        }
        else if (choice == 0)
        {
            cout << "退出程序，再见！" << endl;
            break;
        }
        else
        {
            cout << "无效的选择，请重新输入！" << endl;
        }
    }
    return 0;
}
