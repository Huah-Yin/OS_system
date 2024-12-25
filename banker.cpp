#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "banker.hpp"
using namespace std;
string read_error = "error->�޷���ȡ���ļ�\n";

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

void read_csv(vector<int> &available, string &csv_path)
{
    ifstream file(csv_path);
    if (!file.is_open())
    {
        cout << read_error;
    }
    else
    {
        string line; // ���ж�ȡ
        int row = 0;
        while (getline(file, line))
        {
            if (row)
            {
                string cell;
                stringstream ss(line); // �ָ�
                while (getline(ss, cell, ','))
                {
                    int num = stoi(cell);
                    available.emplace_back(num); // ���ַ���ת��Ϊ����
                }
            }
            row++; // ������һ��
        }
    }
}
void read_csv(vector<vector<int>> &two_matrix, string &csv_path)
{
    ifstream file(csv_path);
    if (!file.is_open())
    {
        cout << read_error;
    }
    else
    {
        string line; // ���ж�ȡ
        int row = 0;
        while (getline(file, line))
        {
            if (row)
            {
                int column = 0;
                string cell;
                stringstream ss(line); // �ָ�
                vector<int> temp;
                while (getline(ss, cell, ','))
                {
                    if (column)
                    {
                        if (cell.empty())
                            break;
                        int num = stoi(cell);
                        temp.emplace_back(num); // ���ַ���ת��Ϊ����
                    }
                    column++; // ��ȡ�ڶ���
                }
                two_matrix.push_back(temp);
            }
            row++; // ������һ��
        }
    }
}

void str_to_int(string &s, int &id, vector<int> &request)
{
    istringstream input(s);
    string num;
    input >> num;
    id = stoi(num); // ��ȡ���̱��
    while (input >> num)
    {
        request.push_back(stoi(num)); // ��ȡ��������
    }
}
string sec_str(matrix_one &available, matrix_two &allocation, matrix_two &max, const matrix_one &request, int &id)
{
    string str = "";
    matrix_two need = max - allocation;
    int kinds = available.rows();                     // ��Դ������
    int process = allocation.rows();                  // ������
    if (request <= matrix_one(need.matrix[id], true)) // deep copy
    {
        if (request <= available)
        {
            // deep copy
            matrix_one available_tmp(available.matrix, true);
            matrix_two allocation_tmp(allocation.matrix, true);
            matrix_two need_tmp(need.matrix, true);

            // ��������� -��������
            available_tmp = available_tmp - request;
            allocation_tmp.add_two_one(request, id);
            need_tmp.sub_two_one(request, id);
            str = is_safe(available_tmp, allocation_tmp, need_tmp);
        }
        else
        {
            str = "  error-> process  " + to_string(id) + " �������Դ�����ڿ�����Դ��,�ý�����ȴ� !!!";
            cout << str << endl;
        }
    }
    else
    {
        str = "  error-> process  " + to_string(id) + " �������Դ�����ڸý������Ƶ���Դ,�ý�����ȴ� !!!";
        cout << str << endl;
    }
    return str;
}
bool check(vector<int> &arr, int kinds)
{
    for (int i = 0; i < kinds; i++)
    {
        if (!arr[i])
            return false;
    }
    return true;
}
string is_safe(matrix_one &available, matrix_two &allocation, matrix_two &need)
{
    string str = "";
    int pid_kinds = need.rows(); // ������
    vector<int> pid_statue(pid_kinds, 0);
    int count = 0;
    matrix_one work = available;
    while (count < pid_kinds)
    {
        bool chosen_process = false; // Ĭ��û��ѡ�����.
        for (int i = 0; i < pid_kinds; i++)
        {
            if (!pid_statue[i] && matrix_one(need.matrix[i]) <= work)
            {
                work += matrix_one(allocation.matrix[i]);
                pid_statue[i] = 1;
                string tmp = "";
                if (count < pid_kinds - 1)      // ��ӡ��ʽ��
                    tmp = to_string(i) + "-->"; // itoa(i)��iת��Ϊ�ַ���
                else
                    tmp = to_string(i);
                count++;               // ��Ч�Ľ�������
                chosen_process = true; // ��ʾ�н��̱�ѡ��
                str += tmp;
                break;
            }
        }
        if (!chosen_process)
        {
            cout << " no process can be chosen ,please try agagin !!!" << endl;
            break;
        }
        if (check(pid_statue, pid_kinds))
        { // ȫ�����̵�״̬��Ϊ 1
            break;
        }
    }
    if (count < pid_kinds) // ������� 1-->3 -->  �����޽��̿�����������
        str = "";
    return str;
}
void printMenu()
{
    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*         ϵͳ��Դ�������               *" << endl;
    cout << "*                                        *" << endl;
    cout << "******************************************" << endl;
    cout << "1. �鿴ϵͳ��ǰ��Դʹ�����" << endl;
    cout << "2. ������ǰϵͳ��ȫ��" << endl;
    cout << "3. ������Դ" << endl;
    cout << "0. �˳�����" << endl;
    cout << "��ѡ��: ";
}
