// #include <string>
// #include <vector>
// #include <list>
// #include <iostream>
// #include <sstream>
// #include "banker.hpp"
// #define int unsigned long long
// using namespace std;

// str_to_int(string &amp; s, vector &lt; int &gt; &amp; tmp)
// {

//     istringstream input(s);
//     int num;
//     while (input & gt; &gt; num)
//     {
//         tmp.push_back(num);
//     }
//     return tmp;
// }
// class process
// {
// public:
//     string name;
//     int pid;
//     vector &lt;
//     int &gt;
//     max_matrix;
//     vector &lt;
//     int &gt;
//     allocation_matrix;
//     vector &lt;
//     int &gt;
//     need_matrix;

//     process(string n, int pid) : name(n), pid(pid) {}
//     string get_name() const
//     {
//         return name;
//     }
//     int get_pid() const
//     {
//         return pid;
//     }
//     void my_print() const
//     {
//         cout & lt;
//         &lt;
//         "process name and pid :" & lt;
//         &lt;
//         this - &gt;
//         name & lt;
//         &lt;
//         this - &gt;
//         pid & lt;
//         &lt;
//         endl;
//         cout & lt;
//         &lt;
//         "max_matrix : " & lt;
//         &lt;
//         endl;
//         for (auto tmp : need_matrix)
//         {
//             cout & lt;
//             &lt;
//             tmp & lt;
//             &lt;
//             "  ";
//         }
//         cout & lt;
//         &lt;
//         endl;
//         cout & lt;
//         &lt;
//         " max_matrix :" & lt;
//         &lt;
//         endl;
//         for (auto tmp : max_matrix)
//         {
//             cout & lt;
//             &lt;
//             tmp & lt;
//             &lt;
//             "  ";
//         }
//     }
// };
// void push_value(process &amp; proce_i)
// {
// }
// int main()
// {
//     int num;
//     num = 5;
//     list & lt;
//     process & gt;
//     proce;
//     string name_pid;

//     for (int i = 0; i & lt; num; i++)
//     {
//         cout & lt;
//         &lt;
//         " please input name_pid" & lt;
//         &lt;
//         endl;
//         getline(cin, name_pid);
//         istringstream input(name_pid);
//         string name;
//         int pid;
//         input & gt;
//         &gt;
//         name & gt;
//         &gt;
//         pid;
//         process tmp(name, pid);

//         string max;
//         getline(cin, max);
//         vector & lt;
//         int &gt;
//         tmp;
//         prname_pid.max_matrix = str_to_int(max, tmp);
//         proce.push_back()
//     }
//     return 0;
// }