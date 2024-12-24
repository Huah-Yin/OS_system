#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "banker.hpp"
using namespace std;

void read_csv(vector<int> &available, string &csv_path)
{
    ifstream file(csv_path);
    if (!file.is_open())
    {
        cout << "error->无法读取该文件" << endl;
    }
    else
    {
        string line; // 按行读取
        int row = 0;
        while (getline(file, line))
        {
            if (row)
            {
                string cell;
                stringstream ss(line); // 分割
                while (getline(ss, cell, ','))
                {
                    int num = stoi(cell);
                    available.emplace_back(num); // 将字符串转换为整数
                }
            }
            row++; // 跳过第一行
        }
    }
}
void read_csv(vector<vector<int>> &two_matrix, string &csv_path)
{
    ifstream file(csv_path);
    if (!file.is_open())
    {
        cout << "error->无法读取该文件" << endl;
    }
    else
    {
        string line; // 按行读取
        int row = 0;
        while (getline(file, line))
        {
            if (row)
            {
                int column = 0;
                string cell;
                stringstream ss(line); // 分割
                vector<int> temp;
                while (getline(ss, cell, ','))
                {
                    if (column)
                    {
                        if (cell.empty())
                            break;
                        int num = stoi(cell);
                        temp.emplace_back(num); // 将字符串转换为整数
                    }
                    column++; // 读取第二列
                }
                two_matrix.push_back(temp);
            }
            row++; // 跳过第一行
        }
    }
}
void print_matrix(vector<vector<int>> &matrix)
{
    string col = " | ";
    for (auto &row : matrix)
    {
        for (auto &cell : row)
        {
            cout << col << cell;
        }
        cout << endl;
    }
}
void print_matrix(vector<int> &matrix)
{
    string col = " | ";
    for (auto &cell : matrix)
    {
        cout << col << cell;
    }
    cout << endl;
}
void str_to_int(string &s, int &id, vector<int> &request)
{
    istringstream input(s);
    string num;
    input >> num;
    id = stoi(num); // 获取进程编号
    while (input >> num)
    {
        request.push_back(stoi(num)); // 获取请求向量
    }
}
string sec_str(matrix_one &available, matrix_two &allocation, matrix_two &max, const matrix_one &request, int &id)
{
    string str = "";
    matrix_two need = max - allocation;
    int kinds = available.rows();                     // 资源的种类
    int process = allocation.rows();                  // 进程数
    if (request <= matrix_one(need.matrix[id], true)) // deep copy
    {
        if (request <= available)
        {
            // deep copy
            matrix_one available_tmp(available.matrix, true);
            matrix_two allocation_tmp(allocation.matrix, true);
            matrix_two need_tmp(need.matrix, true);

            // 运算符重载 -矩阵运算
            available_tmp = available_tmp - request;
            allocation_tmp.add_two_one(request, id);
            need_tmp.sub_two_one(request, id);
            
        }
        else
        {
            str = "error-> process" + to_string(id) + " 请求的资源数大于可用资源数,该进程需等待 !!!";
            cout << str << endl;
        }
    }
    else
    {
        str = "error-> process" + to_string(id) + " 请求的资源数大于该进程声称的资源,该进程需等待 !!!";
        cout << str << endl;
    }
}
