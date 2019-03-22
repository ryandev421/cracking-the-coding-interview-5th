#include <iostream>
#include <string>
#include <vector>
using namespace std;

string compressString(string str);
string shortenWithSameAlpha(char alpha, int duplicated_cnt);

void make_zeros(vector<vector<int> > &matrix)
{
    if (matrix.size() == 0) {
        return ;
    }
    vector<bool> rows (matrix.size(), false);
    vector<bool> columns (matrix[0].size(), false);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0) {
                rows[i] = true;
                columns[j] = true;
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (rows[i] || columns[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int> > matrix;

    for (int i = 0; i < 5; i++) {
        vector<int> row;
        for(int j = 0; j < 8; j++) {
            if ((i*8+j)%14 ==0){
                row.push_back(0);
            } else {
                row.push_back(i*8+j);
            }
        }
        matrix.push_back(row);
    }
    make_zeros(matrix);

    for (int i = 0; i <  5; i++) {
        for(int j = 0;j < 8; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}