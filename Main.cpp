#include <iostream>
#include "mat.hpp"

using namespace std;

int main()
{
    int col, row;
    char first_shape, second_shape;
    cout << "Enter 2 positive and odd numbers first is col second is row, then enter 2 symbols for the mat" << endl;
    cin >> col >> row >> first_shape >> second_shape;
    ariel::mat(col, row, first_shape, second_shape);
    return 1;
}