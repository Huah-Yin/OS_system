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
// int main()
// {
//     string path_available = "F:\\EXCEL\\Available.csv";
//     string path_max = "F:\\EXCEL\\Max.csv";
//     vector<int> available;
//     vector<vector<int>> max;
//     read_csv(available, path_available);
//     read_csv(max, path_max);
//     print_matrix(available);
//     print_matrix(max);
//     return 0;
// }