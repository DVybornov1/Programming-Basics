#include <iostream>
#include <vector>
#include <unordered_map>
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

class Sol {
public:
    bool containsDuplicate(vector<int>& nums, int inD, int vaD) {
        if (nums.size() <= 1 || inD <= 0 || vaD < 0) {
            return false;
        }
        unordered_map<long long, long long> bucketMap;

        for (int i = 0; i < nums.size(); ++i) {
            long long num = static_cast<long long>(nums[i]);
            long long bucket = num / (static_cast<long long>(vaD) + 1);
            if (bucketMap.count(bucket) ||
                (bucketMap.count(bucket - 1) && abs(num - bucketMap[bucket - 1]) <= vaD) ||
                (bucketMap.count(bucket + 1) && abs(num - bucketMap[bucket + 1]) <= vaD)) {
                return true;
                };
            if (i >= inD) {
                long long leftmostBucket = static_cast<long long>(nums[i - inD]) / (static_cast<long long>(vaD) + 1);
                bucketMap.erase(leftmostBucket);
            }; 
            bucketMap[bucket] = num;
        };
        return false;
    };
};

int main() {
    Sol ans;
    int n;
    cout << "Enter size: ";
    n = input(n);
    vector<int> nums(n);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; ++i) {
        nums[i] = input(i);
    }
    int inD, vaD;
    cout << "Enter index difference: ";
    inD = input(inD);
    cout << "Enter value difference: ";
    vaD = input(vaD);
    bool result = ans.containsDuplicate(nums, inD, vaD);
    cout << (result ? "true" : "false") << endl;
    return 0;

}
