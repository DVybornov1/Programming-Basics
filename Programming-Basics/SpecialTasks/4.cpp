#include <iostream>
#include <math.h> 
using namespace std;

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

const int MAX_N = 9;
bool dormant(char field[MAX_N][MAX_N], int row, int column, int n) {
    for (int i = 0; i < row; ++i) {
        if (field[i][column] == 'Q') {
            return false;
        }
        if (column - (row - i) >= 0 && field[i][column - (row - i)] == 'Q') {
            return false;
        }
        if (column + (row - i) < n && field[i][column + (row - i)] == 'Q') {
            return false;
        }
    }
    return true;
}

void disField(char field[MAX_N][MAX_N], int n) {
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            cout << field[x][y] << " ";
        }
        cout << endl;
    }
    cout << "__________" << endl;
}

void allSafe(int row, int n, char field[MAX_N][MAX_N]) {
    if (row == n) {
        disField(field, n);
        return;
    }
    for (int column = 0; column < n; ++column) {
        if (dormant(field, row, column, n)) {
            field[row][column] = 'Q';
            allSafe(row + 1, n, field);
            field[row][column] = '.';
        }
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    n = input(n);
    if (n < 1 || n > 9) {
        cout << "Invalid input.\n";
        return 1;
    }
    char field[MAX_N][MAX_N];
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            field[x][y] = '.';
        }
    }
    allSafe(0, n, field);
    return 0;
}