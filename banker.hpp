#ifndef BANKER_HPP
#define BANKER_HPP
#include <vector>
using namespace std;
class matrix_one
{
public:
    vector<int> matrix;
    matrix_one(vector<int> const &read_matrix)
    {
        for (auto tmp : read_matrix)
        {
            matrix.emplace_back(tmp);
        }
    }
    matrix_one(int size, int value = 0)
    {
        matrix.resize(size, value);
    }
    int rows() const
    {
        return matrix.size();
    }
    matrix_one operator+(matrix_one const &other)
    {
        if (other.rows() != rows())
        {
            throw invalid_argument("矩阵维度不匹配");
        }
        else
        {
            matrix_one result(this->rows());
            for (int i = 0; i < rows(); ++i)
            {
                result.matrix[i] = matrix[i] + other.matrix[i];
            }
        }
    }
    matrix_one operator-(matrix_one const &other)
    {
        if (other.rows() != rows())
        {
            throw invalid_argument("矩阵维度不匹配");
        }
        else
        {
            matrix_one result(this->rows());
            for (int i = 0; i < rows(); ++i)
            {
                result.matrix[i] = matrix[i] - other.matrix[i];
            }
        }
    }
};
class matrix_two
{
public:
    vector<vector<int>> matrix;
    matrix_two(const vector<vector<int>> &read_matrix, bool select = false)
    {
        if (!select)
        {
            matrix = move(read_matrix); // quickly copy
        }
        else
        {
            for (auto tmp : read_matrix)
            {
                matrix.push_back(tmp);
            }
        }
    }

    matrix_two(int row, int column, int value = 0)
    {

        matrix.resize(row, vector<int>(column, value));
    }
    // 获取行数和列数
    int rows() const
    {
        return matrix.size();
    }
    int cols() const
    {
        return matrix.empty() ? 0 : matrix[0].size();
    }
    matrix_two operator+(matrix_two const &other)
    {
        if (other.rows() != rows() || other.cols() != cols())
        {
            throw invalid_argument("矩阵维度不匹配");
        }
        else
        {
            matrix_two result(this->rows(), this->cols());
            for (int i = 0; i < rows(); ++i)
            {
                for (int j = 0; j < cols(); ++j)
                {
                    result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
                }
            }
        }
    }
    matrix_two operator-(matrix_two const &other)
    {
        if (other.rows() != rows() || other.cols() != cols())
        {
            throw invalid_argument("矩阵维度不匹配");
        }
        else
        {
            matrix_two result(this->rows(), this->cols());
            for (int i = 0; i < rows(); ++i)
            {
                for (int j = 0; j < cols(); ++j)
                {
                    result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
                }
            }
        }
    }
};
void read_csv(vector<int> &available, string &csv_path);
void read_csv(vector<vector<int>> &two_matrix, string &csv_path);
void print_matrix(vector<vector<int>> const &matrix);
void print_matrix(vector<int> const &matrix);
void str_to_int(string &s, int &id, vector<int> &request);
string sec_str(matrix_one &available, matrix_two &allocation, matrix_two &max, string &request);
#endif
