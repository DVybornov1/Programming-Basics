#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Sol {
public:
    int maxPathSum(Node * root) {
        int max_sum = INT_MIN;
        maxPathSumHelper(root, max_sum);
        return max_sum;
    }
private:
    int maxPathSumHelper(Node * node, int& max_sum) {
        if (!node) {
            return 0;
        }
        int left_max = max(0, maxPathSumHelper(node->left, max_sum));
        int right_max = max(0, maxPathSumHelper(node->right, max_sum));
        max_sum = max(max_sum, left_max + right_max + node->val);
        return max(left_max, right_max) + node->val;
    };
};
int main() {
    Sol ans;

    Node * root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    int res = ans.maxPathSum(root);
    cout << "Maximum Path Sum: " << res << endl;

    delete root->left, root->right, root->right->left, root->right->right, root;
    return 0;
}