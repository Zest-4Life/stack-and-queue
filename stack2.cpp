#include <iostream>
#include <vector>
using namespace std;

// Визначення структури вузла бінарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Рекурсивна функція для обходу Inorder Traversal
void inorderTraversalHelper(TreeNode* root, vector<int>& result) {
    if (!root) return;
    // Спочатку обходимо ліве піддерево
    inorderTraversalHelper(root->left, result);
    // Додаємо значення вузла
    result.push_back(root->val);
    // Потім обходимо праве піддерево
    inorderTraversalHelper(root->right, result);
}

// Головна функція для Inorder Traversal
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderTraversalHelper(root, result);
    return result;
}

// Допоміжна функція для створення тестових прикладів
TreeNode* createExampleTree() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

// Головна функція
int main() {
    TreeNode* root = createExampleTree();

    vector<int> result = inorderTraversal(root);
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
