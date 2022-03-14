#include "mat.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

string ariel::mat(int col, int row, char first_shape, char second_shape)
{
    // Here we make 2 const int variables one is for the min ascii that we can except in this program and the second one is for the max ascii char.
    const int min_ascii = 33;
    const int max_ascii = 126;

    // Now we crate 3 matrices using vectors
    vector<vector<int>> matrix(row, vector<int>(col));
    vector<vector<int>> reversed_matrix(row, vector<int>(col));
    vector<vector<int>> ans_matrix(row, vector<int>(col));
    string ans;

    /*
    First thing we will check if the given col and row numbers from the user are odd and positive,
    also check that the symbols are between 33 - 126 in the ascii table.
    */
    if (row % 2 == 0 || col % 2 == 0 || row <= 0 || col <= 0 ||
        first_shape < min_ascii || second_shape < min_ascii || first_shape > max_ascii || second_shape > max_ascii)
    {
        throw invalid_argument("Please make sure to enter positive and odd number, also check that the symbols are between 33 - 126 in the ascii table !");
    }

    /* 
    Now we fill the 3 matrices, matrix is a regular matrix, each [i][j] is the min between i and j,
    reversed_matrix is an opposite matrix which is the matrix from above but change its angle 180 degrees,
    and the ans_matrix is the final form of the matrix but we will need to change the 0 to first shape and the 1 to the second shape.
    */
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix.at(i).at(j) = min(i, j);
            reversed_matrix.at(i).at(j) = min(col - 1 - j, row - 1 - i);
            ans_matrix.at(i).at(j) = min(matrix.at(i).at(j), reversed_matrix.at(i).at(j));
        }
    }

    // Here we are changing the 1 and 0 with the shapes that the user gave us in the input and make it to a string, 0 = first shape 1 = second shape.
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans += (ans_matrix.at(i).at(j) % 2 == 0) ? first_shape : second_shape;
        }
        if (i < row - 1)
        {
            ans += "\n";
        }
    }
    cout << ans << endl; //This is just so I could see the results.
    return ans;
}