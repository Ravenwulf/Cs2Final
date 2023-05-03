#pragma once
#include <iostream>

class BST {
private:
	class TreeNode {
	    public:
        int value;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int value1,
            TreeNode* left1 = nullptr,
            TreeNode* right1 = nullptr)
        {
            value = value1;
            left = left1;
            right = right1;
        }
	};
    TreeNode* root;
    
    void insert(int val, TreeNode* &node) {
        if (!node) {
            node = new TreeNode(val);
            return;
        }
        
        if(node->value == val) {
            return;
        }
        
        if(val < node->value){
            insert(val, node->left);
        } else {
            insert(val, node->right);
        }
    }
    void printInOrder(TreeNode* &node) {
        if (node) {
            this->printInOrder(node->left);
            std::cout << node->value << " ";
            this->printInOrder(node->right);
        }
    };
    void printPreOrder(TreeNode* &node) {
        if (node) {
            std::cout << node->value << " ";
            this->printInOrder(node->left);
            this->printInOrder(node->right);
        }
    };
    void printPostOrder(TreeNode* &node) {
        if (node) {
            this->printInOrder(node->left);
            this->printInOrder(node->right);
            std::cout << node->value << " ";
        }
    };
    void destroySubtree(TreeNode* tree)
    {
        if (!tree) return;
        this->destroySubtree(tree->left);
        this->destroySubtree(tree->right);
        // Delete the node at the root.
        delete tree;
    }
public:
    BST()		// Constructor
    {
        this->root = nullptr;
    }
    ~BST()		// Destructor
    {
        this->destroySubtree(root);
    }
    void insert(int val) { this->insert(val, this->root); };
    void printInOrder() { this->printInOrder(this->root); };
    void printPreOrder() { this->printPreOrder(this->root); };
    void printPostOrder() { this->printPostOrder(this->root); };

};