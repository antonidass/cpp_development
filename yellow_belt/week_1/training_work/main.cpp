#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <stdexcept>


using namespace std;




class Matrix
{
private:
    int num_rows;
    int num_cols;
    vector <vector<int>> matrix;

public:

    Matrix()
    {
        num_cols = 0;
        num_rows = 0;
    }

    Matrix(int rows, int cols)
    {
        Reset(rows, cols);
    }

    int GetNumRows() const
    {
        return num_rows;
    }


    int GetNumColumns() const
    {
        return num_cols;
    }

    int At(int row, int col) const
    {
        if (row < 0 || col < 0 || row >= num_rows || col >= num_cols)
            throw out_of_range("out of range at");

        return matrix.at(row).at(col);
    }

    int& At(int row, int col)
    {
        if (row < 0 || col < 0 || row >= num_rows || col >= num_cols)
            throw out_of_range("out of range at");

        return matrix.at(row).at(col);
    }


    void Reset(int new_row, int new_col)
    {
        if (new_row < 0 || new_col < 0)
            throw out_of_range("error in size matrix!\n");

        matrix.assign(new_row, vector<int>(new_col));
        num_rows = new_row; 
        num_cols = new_col;
    }
};




ostream &operator << (ostream &out, const Matrix &matrix)
{
    out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;

    for (int i = 0; i < matrix.GetNumRows(); i++)
    {
        for (int j = 0; j < matrix.GetNumColumns(); j++)
        {
            out << matrix.At(i, j) << " ";
        }

        out << endl;
    }

    return out;
}




istream &operator >> (istream &in, Matrix &matrix)
{
    int row, col;

    in >> row >> col;

    matrix = Matrix(row, col);
    int num;



    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            in >> num;
            matrix.At(i, j) = num;
        }
    }

    return in;
}

bool operator == (const Matrix &first, const Matrix &second)
{
    if (first.GetNumColumns() != second.GetNumColumns() || first.GetNumRows() != second.GetNumRows())
        return false;

    for (int i = 0; i < first.GetNumRows(); i++)
    {
        for (int j = 0; j < first.GetNumColumns(); j++)
        {
            if (first.At(i, j) != second.At(i, j))
                return false;
        }
    }

    return true;    
}

Matrix operator + (const Matrix &first, const Matrix &second)
{
    if (first.GetNumColumns() != second.GetNumColumns())
        throw invalid_argument("cannot sum matrix ");

    if (first.GetNumRows() != second.GetNumRows())
        throw invalid_argument("invalid size matrix");


    Matrix res(first.GetNumRows(), first.GetNumColumns());

    for (int i = 0; i < first.GetNumRows(); i++)
    {
        for (int j = 0; j < first.GetNumColumns(); j++)
        {
            res.At(i, j) = first.At(i, j) + second.At(i, j);
        }
    }

    return res;
}





int main()
{
    Matrix one;
    Matrix two;

    cout << one + two << endl;

    return 0;
}