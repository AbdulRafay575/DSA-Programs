#include <iostream>
using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
    	key=val;
    	left=NULL;
    	right=NULL;
	}
};

class BST {
private:
    TreeNode* root;
public:
    BST(){
    	root=NULL;
	}
	 
    TreeNode* search(int key) {
        TreeNode* node = root;
        while (node != NULL && node->key != key) {
            if (key > node->key) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return node;
    }

    void insert(int key) {
        if (root == NULL) {
            root = new TreeNode(key);
            return;
        }
        TreeNode* parent = NULL;
        TreeNode* current = root;
        while (current != NULL) {
            parent = current;
            if (key < current->key) {
                current = current->left;
            } else if (key > current->key) {
                current = current->right;
            }
        }

        if (key < parent->key) {
            parent->left = new TreeNode(key);
        } else if (key > parent->key) {
            parent->right = new TreeNode(key);
        }
    }

    void deleteKey(int key) {
        TreeNode* current = root;
        TreeNode* parent = NULL;

        while (current != NULL && current->key != key) {
            parent = current;

            if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (current == NULL) {
            return;
        }

        if (current->left == NULL) {
            if (current == root) {
                root = current->right;
            } else if (current == parent->left) {
                parent->left = current->right;
            } else {
                parent->right = current->right;
            }
            delete current;
        } else if (current->right == NULL) {
            if (current == root) {
                root = current->left;
            } else if (current == parent->left) {
                parent->left = current->left;
            } else {
                parent->right = current->left;
            }
            delete current;
        } else {
            TreeNode* minNode = current->right;
            while (minNode->left != NULL) {
                minNode = minNode->left;
            }
            current->key = minNode->key;
            deleteKey(minNode->key);
        }
        
    }

    void inorderTraversal() {
        inorderTraversal(root);
        cout << endl;
    }

private:
    void inorderTraversal(TreeNode* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            cout << node->key << " ";
            inorderTraversal(node->right);
        }
    }
};

int main() {
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(18);

    int key_to_search;
    cin >> key_to_search;
    TreeNode* node = bst.search(key_to_search);

    if (node) {
        cout << "Key " << key_to_search << " found in the BST." << endl;
    } else {
        cout << "Key " << key_to_search << " not found in the BST." << endl;
    }

    cout << "Inorder traversal of the BST: ";
    bst.inorderTraversal();

    int key_to_delete;
    cin >> key_to_delete;
    bst.deleteKey(key_to_delete);

    cout << "Inorder traversal of the BST after deleting " << key_to_delete << ": ";
    bst.inorderTraversal();

    return 0;
}

