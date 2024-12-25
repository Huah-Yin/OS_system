#ifndef _BANKER_HPP
#define _BANKER_HPP
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;
extern string matrix_message;
class matrix_one
{
public:
    vector<int> matrix;
    matrix_one(vector<int> const &read_matrix, bool flag = false)
    {
        if (!flag)
        {
            matrix = move(read_matrix);
        }
        else
        {
            int len = read_matrix.size();
            matrix.resize(len);
            for (int i = 0; i < len; ++i)
            {
                matrix[i] = read_matrix[i];
            }
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
    matrix_one operator=(const matrix_one &other)
    {
        bool flag = true;
        matrix_one(other.matrix, flag);
        return *this;
    }
    matrix_one operator+=(matrix_one const &other)
    {
        if (other.rows() != rows())
        {
            throw invalid_argument(matrix_message);
        }
        else
        {
            for (int i = 0; i < rows(); ++i)
            {
                this->matrix[i] += other.matrix[i];
            }
            return *this;
        }
    }
    matrix_one operator-(matrix_one const &other)
    {
        if (other.rows() != rows())
        {
            throw invalid_argument(matrix_message);
        }
        else
        {
            matrix_one result(this->rows());
            for (int i = 0; i < rows(); ++i)
            {
                result.matrix[i] = matrix[i] - other.matrix[i];
            }
            return result;
        }
    }
    matrix_one operator-=(matrix_one const &other)
    {
        if (other.rows() != rows())
        {
            throw invalid_argument(matrix_message);
        }
        else
        {
            for (int i = 0; i < rows(); ++i)
            {
                this->matrix[i] -= other.matrix[i];
            }
            return *this;
        }
    }

    // 计算是否符合条件，返回一个布尔值。
    bool operator<=(const matrix_one &other) const
    {
        if (other.rows() != this->rows())
            throw invalid_argument(matrix_message);
        else
        {
            // 比较每个元素，如果有任何不满足条件的，返回 false。
            for (int i = 0; i < this->rows(); i++)
            {
                if (this->matrix[i] > other.matrix[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool operator==(const matrix_one &other) const
    {
        if (other.rows() != this->rows())
            throw invalid_argument(matrix_message);
        else
        {
            // 比较每个元素，如果有任何不满足条件的，返回 false。
            for (int i = 0; i < this->rows(); i++)
            {
                if (this->matrix[i] != other.matrix[i])
                {
                    return false;
                }
            }
        }
        return true;
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
            matrix = move(read_matrix); // move copy
        }
        else
        {
            int row = read_matrix.size();
            int column = read_matrix[0].size();
            matrix.resize(row, vector<int>(column));
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    matrix[i][j] = read_matrix[i][j];
                }
            }
        }
    }

    matrix_two(int row, int column, int value = 0)
    {

        matrix.resize(row, vector<int>(column, value));
    }
    // 获取矩阵维度
    int rows() const
    {
        return matrix.size();
    }
    int cols() const
    {
        return matrix.empty() ? 0 : matrix[0].size();
    }

    matrix_two add_two_one(matrix_one const &other, int row)
    {
        if (this->cols() != other.rows())
        {
            throw invalid_argument(matrix_message);
        }
        else
        {
            for (int i = 0; i < this->cols(); i++)
            {
                this->matrix[row][i] += other.matrix[i];
            }
            return *this;
        }
    }
    matrix_two sub_two_one(matrix_one const &other, int row)
    {
        if (this->cols() != other.rows())
        {
            throw invalid_argument(matrix_message);
        }
        else
        {
            for (int i = 0; i < this->cols(); i++)
            {
                this->matrix[row][i] -= other.matrix[i];
            }
            return *this;
        }
    }
    matrix_two operator+=(matrix_two const &other)
    {
        if (other.rows() != rows() || other.cols() != cols())
        {
            throw invalid_argument(matrix_message);
        }
        else
        {
            for (int i = 0; i < rows(); ++i)
            {
                for (int j = 0; j < cols(); ++j)
                {
                    this->matrix[i][j] += other.matrix[i][j];
                }
            }
            return *this;
        }
    }
    matrix_two operator-(matrix_two const &other)
    {
        if (other.rows() != rows() || other.cols() != cols())
        {
            throw invalid_argument(matrix_message);
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
            return result;
        }
    }
    matrix_two operator=(matrix_two const &other)
    {
        bool flag = true;
        matrix_two(other.matrix, flag);
        return *this;
    }
    bool operator<=(matrix_two const &other)
    {
        if (other.rows() != rows() || other.cols() != cols())
        {
            throw invalid_argument(matrix_message);
        }
        else
        {
            // 比较每个元素，如果有任何不满足条件的，返回 false。
            for (int i = 0; i < rows(); ++i)
            {
                for (int j = 0; j < cols(); ++j)
                {
                    if (matrix[i][j] > other.matrix[i][j])
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
};
// 函数声明
void read_csv(vector<int> &available, string &csv_path);
void read_csv(vector<vector<int>> &two_matrix, string &csv_path);
void print_matrix(vector<int> &matrix);
void print_matrix(vector<vector<int>> &matrix);
void str_to_int(string &s, int &id, vector<int> &request);
string sec_str(matrix_one &available, matrix_two &allocation, matrix_two &max, const matrix_one &request, int &id);
string is_safe(matrix_one &available, matrix_two &allocation, matrix_two &need);
bool check(vector<int> &arr, int kinds);
void printMenu();
#endif
