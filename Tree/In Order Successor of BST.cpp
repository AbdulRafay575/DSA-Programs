#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the minimum value node in a BST
TreeNode* findMin(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the inorder successor of a given node in a BST
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = NULL;

    while (root != NULL) {
        if (p->val < root->val) {
            successor = root;
            root = root->left;
        } else if (p->val > root->val) {
            root = root->right;
        } else {
            // Node p is found
            if (root->right != NULL) {
                successor = findMin(root->right);
            }
            break;
        }
    }

    return successor;
}

int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    TreeNode* nodeToFind = root->left->right; // Node with value 15

    TreeNode* successor = inorderSuccessor(root,nodeToFind);

    if (successor != NULL) {
        std::cout << "Inorder successor of " << nodeToFind->val << " is " << successor->val << std::endl;
    } else {
        std::cout << "No inorder successor found for " << nodeToFind->val << std::endl;
    }

    return 0;
}

