#include <cstdlib>
#include <iostream>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    int depth;
    TreeNode(int x): val(x), left(NULL), right(NULL), depth(0) {}
    void generate(int layer) {
        if (layer == 5)
            return;
        int tmp = rand() % 100;
        if (tmp <= 80) {
            left = new TreeNode(rand() % 100);
            left -> depth = depth + 1;
            left -> generate(layer + 1);
        }
        tmp = rand() % 100;
        if (tmp >= 20) {
            right = new TreeNode(rand() % 100);
            right -> depth = depth + 1;
            right -> generate(layer + 1);
        }
    }
    void display() {
        deque<TreeNode> list;
        list.push_back(*this);
        int depth = 0;
        while (!list.empty()) {
            if (list.begin()->depth != depth) {
                cout << endl;
                depth = list.begin()->depth;
                cout << depth << ": ";
            }
            cout << list.begin()->val << '(';
            if (list.begin()->left) {
                cout << 1 << ", ";
                list.push_back(*list.begin()->left);
            }
            else 
                cout << 0 << ", ";
            if (list.begin()->right) {
                cout << 1 << ") ";
                list.push_back(*list.begin()->right);
            }
            else 
                cout << 0 << ") ";
            list.pop_front();
        }
        cout << endl;
    }
};

class Solution {
    int mymin;
private:
    void initDepth(TreeNode* root) {
        TreeNode* p = root;
        int depth = 1;
        while (p->left || p->right) {
            if (p->left)
                p = p -> left;
            else
                p = p -> right;
            depth ++;
        }
        mymin = depth;
    }
    
    void minDepth(TreeNode* root, int depth) {
        if (depth >= mymin) return;
        if (!root->left && !root->right) {
            mymin = depth;
        }
        else if (root->left)
            minDepth(root->left, depth + 1);
        if (root->right)
            minDepth(root->right, depth + 1);
    }   

public:
    Solution() : mymin(-1) {}
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        initDepth(root);
        minDepth(root, 1);
        return mymin;
    }
};


int main() {
    srand(time(0));
    TreeNode* root = new TreeNode(0);
    root->generate(1);
    root->display();
    Solution s;
    cout << s.minDepth(root) << endl;
    return 0;
}


