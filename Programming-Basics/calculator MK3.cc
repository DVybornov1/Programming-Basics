#include <iostream>
#include <vector>
#include <math.h> 
using namespace std;

char func = 'x';
float a1 = 0;
float a2 = 0;
std::vector<std::vector<float>> m1;
std::vector<std::vector<float>> m2;
std::vector<std::vector<float>> m3;

float inp(float x) {
    cin >> x;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n" << "Invalid input." << "\n" << "\n";
        cin >> x;
    }
    return x;
}

float add(float a1, float a2) {
    cout << "\n" << a1 << " + " << a2 << " = " << (a1 + a2) << "\n";
    return 0;
}

float subtract(float a1, float a2) {
    cout << "\n" << a1 << " - " << a2 << " = " << (a1 - a2) << "\n";
    return 0;
}

float multiply(float a1, float a2) {
    cout << "\n" << a1 << " * " << a2 << " = " << (a1 * a2) << "\n";
    return 0;
}

float divide(float a1, float a2) {
    cout << "\n" << a1 << " : " << a2 << " = " << (a1 / a2) << "\n";
    return 0;
}

float power(float a1, float a2) {
    cout << "\n" << a1 << " ^ " << a2 << " = " << pow(a1,a2) << "\n";
    return 0;
}

float matrix() {
    m1.clear();
    m2.clear();
    m3.clear();
    cout << "\n" << "Choose matrix size. (X, Y)" << "\n" << "\n";
    int nrows;
    int ncols;
    cin >> nrows >> ncols;
    cout << "\n" << "Rows = " << nrows << ", columns = " << ncols << "." << "\n" << "\n";
    cout << "\n" << "Matrix 1" << "\n" << "\n";
    for (int i = 0; i < nrows; i++ ) {
        vector<float> row;
        for (int j = 0; j < ncols; j++) {
            float value;
            value = inp(value);
            row.push_back(value);
        }
        m1.push_back(row);
    }
    cout << "\n";
    cout << "\n" << "Matrix 2" << "\n" << "\n";
    for (int i = 0; i < nrows; i++ ) {
        vector<float> row;
        for (int j = 0; j < ncols; j++) {
            float value;
            value = inp(value);
            row.push_back(value);
        }
        m2.push_back(row);
    }
    cout << "\n";
    cout << "Choose operation.\n" << "\n";
    cin >> func;
    if (func == '+') {
        for (int i = 0; i < nrows; i++ ) {
            vector<float> row;
            for (int j = 0; j < ncols; j++) {
                float value;
                value = m1[i][j] + m2[i][j];
                row.push_back(value);
            }
            m3.push_back(row);
        }
    } else if (func == '-') {
        for (int i = 0; i < nrows; i++ ) {
            vector<float> row;
            for (int j = 0; j < ncols; j++) {
                float value;
                value = m1[i][j] - m2[i][j];
                row.push_back(value);
            }
            m3.push_back(row);
        }
    } else {
        cout << "\n" << "Operation canceled" << "\n";
        return 0;
    }
                cout << "Result: \n" << "\n";
                for (int i = 0; i < nrows; i++ ) {
                    for (int j = 0; j < ncols; j++) {
                        cout << m3[i][j] << " ";
                    }
                    cout << "\n";
                }
    return 0;
}

int main() {
    cout << "Press q to quit." << "\n";
    while (true) {
        cout << "\n";
        cout << "Choose operation." << "\n" << "\n";
        cin >> func;
        switch (func) {
            case '+':
                a1 = inp(a1);
                a2 = inp(a2);
                add(a1, a2);
                break;
            case '-':
                a1 = inp(a1);
                a2 = inp(a2);
                subtract(a1, a2);
                break;
            case '*':
                a1 = inp(a1);
                a2 = inp(a2);
                multiply(a1, a2);
                break;
            case ':':
                a1 = inp(a1);
                a2 = inp(a2);
                divide(a1, a2);
                break;
            case '^':
                a1 = inp(a1);
                a2 = inp(a2);
                power(a1, a2);
                break;
            case 'm':
                matrix();
                break;
            case 'q':
                return 0;
        }
    }
}