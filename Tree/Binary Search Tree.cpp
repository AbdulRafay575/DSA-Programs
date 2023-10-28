#include <iostream>
using namespace std;
// Definition of a binary search tree node
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
    	key=val; 
		left=NULL;
		right=NULL;
	}  
};

// Function to search for a key in the BST
TreeNode* search(TreeNode* root, int key) {
    // If the tree is empty or the key is found at the root, return the root
    if (root == NULL || root->key == key) {
        return root;
    }

    // If the key is greater than the root's key, search in the right subtree
    if (key > root->key) {
        return search(root->right, key);
    }

    // If the key is smaller than the root's key, search in the left subtree
    return search(root->left, key);
}

int main() {
    // Create a simple BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
	
    int key_to_search ;
    cin>>key_to_search;
    TreeNode* result = search(root, key_to_search);

    if (result) {
        cout << "Key " << key_to_search << " found in the BST." << endl;
    } else {
        cout << "Key " << key_to_search << " not found in the BST." << endl;
    }

    return 0;
}

