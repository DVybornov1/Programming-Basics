#include <iostream>
#include <math.h> 
#include <queue>
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

class MedianFinder {
public:
    MedianFinder() {};
private:
    priority_queue<int> MaH;
    priority_queue<int, vector<int>, greater<int>> MiH;
public:
    void addN() {
        int num;
        num = input(num);
        if (MaH.empty() || num < MaH.top()) {
            MaH.push(num);
        } else {
            MiH.push(num);
        }
        if (MaH.size() > MiH.size() + 1) {
            MiH.push(MaH.top());
            MaH.pop();
        } else if (MiH.size() > MaH.size() + 1) {
            MaH.push(MiH.top());
            MiH.pop();
        }
    };
    double MedianFinderDouble() {
        if (MaH.size() == MiH.size()) {
            return (MaH.top() + MiH.top()) / 2.0;
        } else if (MaH.size() > MiH.size()) {
            return MaH.top();
        } else {
            return MiH.top();
        };
    };
};

int main() {
int amount;
MedianFinder frog;
cout << "Input number amount: ";
amount = input(amount);
while (amount != 0) {
    frog.addN();
    amount = amount - 1;
};
double median = frog.MedianFinderDouble();
cout << "Median = " << median << "\n";
return 0;
}
