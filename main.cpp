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
        scanf("%d", &choice);
        if (choice == 1)
        {
            cout << "      正在查看系统当前资源使用情况..." << endl;
            cout << "              Available矩阵:";
            print_matrix(available_matrix.matrix);
            cout << "              Allocation矩阵:" << endl;
            print_matrix(allocation_matrix.matrix);
            cout << "                     Max矩阵:" << endl;
            print_matrix(max_matrix.matrix);
        }
        else if (choice == 2)
        {
            cout << "         正在分析当前系统安全性..." << endl;
            string str = "";
            matrix_two need_matrix = max_matrix - allocation_matrix;
            str = is_safe(available_matrix, allocation_matrix, need_matrix);
            cout << "             正在计算安全序列..." << endl;
            if (str.length() == 0 || str.at(0) == ' ') // 如果返回安全序列的第一个字符为" "
            {
                cout << "             系统处于不安全状态, 安全序列为空!!! " << str << endl;
            }
            else
            {
                cout << "             系统处于安全状态, 安全序列为: " << str << endl;
            }
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
                if (str.length() == 0 || str.at(0) == ' ') // 如果返回安全序列的第一个字符为" "
                {
                    cout << "               无安全序列!!!" << endl;
                }
                else
                {
                    cout << " SecStr= " << str << endl;
                    // 数据更新 need[] = max - allocation，max[] 一直未改变，所以无需更新 need，只需在函数中计算。
                    matrix_two need_matrix = max_matrix - allocation_matrix;
                    // 为后续比较做准备
                    matrix_one need_id(need_matrix.matrix[id], true);
                    if (need_id == request) // 进程已结束
                    {
                        available_matrix += matrix_one(allocation_matrix.matrix[id], true); // 更新 Available
                        allocation_matrix.matrix[id].assign(allocation_matrix.cols(), 0);
                    }
                    else // 进程未结束
                    {
                        available_matrix -= request;
                        allocation_matrix.add_two_one(request, id);
                    }
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
