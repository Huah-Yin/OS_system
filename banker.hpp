#ifndef BANKER_HPP
#define BANKER_HPP
#include <vector>
using namespace std;
class available
{
public:
    vector<int> available_matrix;
    available(vector<int> const &read_matrix)
    {
        for (auto tmp : read_matrix)
        {
            available_matrix.emplace_back(tmp);
        }
    }
};

void read_csv(vector<int> &available, string &csv_path);
void read_csv(vector<vector<int>> &two_matrix, string &csv_path);
void print_matrix(vector<vector<int>> const &matrix);
void print_matrix(vector<int> const &matrix);
#endif
