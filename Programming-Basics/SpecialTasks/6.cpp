#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
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

int maxPosPr(vector<int>& prices) {
    int i = prices.size();
    if (i <= 1) {
        return 0;
    }

    vector<int> profb4(i, 0);
    vector<int> profaft(i, 0);

    int minprice = prices[0];
    for (int x = 1; x < i; x++) {
        minprice = min(minprice, prices[x]);
        profb4[x] = max(profb4[x - 1], prices[x] - minprice);
    }

    int maxprice = prices[i - 1];
    for (int x = i - 2; x >= 0; x--) {
        maxprice = max(maxprice, prices[x]);
        profaft[x] = max(profaft[x + 1], maxprice - prices[x]);

    }

    int maxprof = 0;
    for (int y = 0; y < i; y++) {
        maxprof = max(maxprof, profb4[y] + profaft[y]);
    }

    return maxprof;
}

int main() {

int l;
cout << "Enter price list length: ";
l = input(l);
vector<int> prl{};
for (int c = 0; c < l; c++) {
    int inp;    
    cout << "Enter price for the " << c + 1 << " day: ";
    inp = input(inp);
    prl.push_back(inp);
}
cout << maxPosPr(prl) << "\n";
return 0;
}
