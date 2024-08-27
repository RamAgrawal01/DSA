#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int x) {
    if (matrix.empty() || matrix[0].empty()) return false;
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    int row = 0;        
    int col = m - 1;   
    
    while (row < n && col >= 0) {
        if (matrix[row][col] == x) {
            return true;  // Target found
        } else if (matrix[row][col] > x) {
            col--; 
        } else {
            row++;  
        }
    }
    
    return false; 
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Printing array is :" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    bool found = searchMatrix(matrix, target);

    if (found) {
        cout << target << " is Found" << endl;
    } else {
        cout << target << " is Not Found" << endl;
    }

    return 0;
}
