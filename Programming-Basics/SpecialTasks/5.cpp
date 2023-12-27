#include <iostream>
#include <vector> 
using namespace std;
#include <math.h> 
#include <stack>

int input(int x) {
    cin >> x;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n" << "Invalid input." << "\n" << "\n";
        cin >> x;
    }
    return x;
}

char input(char x) {
    cin >> x;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n" << "Invalid input. (Boolean needed)" << "\n" << "\n";
        cin >> x;
    }
    return x;
}

int listRect(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }
    int rows = matrix.size();
    int columns = matrix[0].size();
    if (rows == matrix.size() && columns == matrix[0].size() && rows >= 1 && rows <= 200 && columns >= 1 && columns <= 200) {
        vector<int> height(columns, 0);
        int MA = 0;
        cout << "Enter booleans to fill the matrix.";
        for (int x = 0; x < rows; ++x) {
            for (int y = 0; y < columns; ++y) {
                char newc;
                do {
                    newc = input(newc);
                } while (!(newc == '0' || newc == '1'));
                matrix[x][y] = newc;
            }
        }
        for (int x = 0; x < rows; ++x) {
            for (int y = 0; y < columns; ++y) {
                if (matrix[x][y] == '1') {
                    height[y] += 1;
                } else {
                    height[y] = 0;
                }
            }
            stack<int> st;
            for (int y = 0; y <= columns; ++y) {
                while (!st.empty() && (y == columns || height[y] < height[st.top()])) {
                    int effheight = height[st.top()];
                    st.pop();
                    int width = st.empty() ? -1 : st.top();
                    MA = max(MA, effheight * (y - width - 1));
                }
                st.push(y);
            }
        }
        return MA;
    } else {
        cout << "Invalid input." << endl;
        return 0;
    }
}

int main() {
int rows, columns;
cout << "Enter number of rows: ";
rows = input(rows);
cout << "Enter number of columns: ";
columns = input(columns);
vector<vector<char>> matrix(rows, vector<char>(columns, '0')); 
int answer = listRect(matrix);
cout << "Rectangle area = " << answer << endl;
return 0;
}