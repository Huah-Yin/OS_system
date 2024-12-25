#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "banker.hpp"
string matrix_message = "����ά�Ȳ�ƥ��";
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

    // �����ʼ��
    matrix_one available_matrix(available);
    matrix_two max_matrix(max);
    matrix_two allocation_matrix(allocation);

    while (true)
    {

        int choice = -1;
        printMenu();
        // �� while ��� switch ���߼�
        cin >> choice;
        if (choice == 1)
        {
            cout << "���ڲ鿴ϵͳ��ǰ��Դʹ�����..." << endl;
            cout << "Available����:";
            print_matrix(available_matrix.matrix);
            cout << "Allocation����:";
            print_matrix(allocation_matrix.matrix);
            cout << "Max����:";
            print_matrix(max_matrix.matrix);
        }
        else if (choice == 2)
        {
            cout << "���ڷ�����ǰϵͳ��ȫ��..." << endl;
            cout << "system is safe !" << endl;
        }
        else if (choice == 3)
        {
            cout << "����������Դ..." << endl;
            printf("��������̺� id ���������� request(�Կո�ָ�): \n");
            string request_str;
            cin.ignore();
            getline(cin, request_str);
            if (request_str.empty())
            {
                cout << "����Ϊ��!!!" << endl;
            }
            else
            {
                int id;
                vector<int> request_vector;
                str_to_int(request_str, id, request_vector);
                // �ȴ���һ���µ� matrix���෴��Ȼ�����ƶ�����
                string str = "";
                matrix_one request(request_vector);
                str = sec_str(available_matrix, allocation_matrix, max_matrix, request, id);
                if (str.at(0) == ' ') // ������ذ�ȫ���еĵ�һ���ַ�Ϊ" "
                {
                    cout << "!!!" << endl;
                }
                else
                {
                    cout << " SecStr= " << str << endl;
                    // ���ݸ��� need[] = max - allocation��max[] һֱδ�ı䣬����������� need��ֻ���ں����м��㡣
                    available_matrix -= request;
                    allocation_matrix.add_two_one(request, id);
                }
            }
        }
        else if (choice == 0)
        {
            cout << "�˳������ټ���" << endl;
            break;
        }
        else
        {
            cout << "��Ч��ѡ�����������룡" << endl;
        }
    }
    return 0;
}
