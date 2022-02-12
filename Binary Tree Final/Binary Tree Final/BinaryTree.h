#pragma once
#include <iostream>
using namespace std;


//Create a new node within the tree
struct node* NewNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

//Print out the tree using in order traversal
void Inorder(struct node* root)
{
    if (root != NULL) {
        Inorder(root->left);
        cout << root->key << " ";
        Inorder(root->right);
    }
}

//Insert a new item into the tree
struct node* Insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return NewNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = Insert(node->left, key);
    else
        node->right = Insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

//Find the minimum value within the tree as long as it isn't null
struct node* MinValueNode(struct node* node)
{
    struct node* current = node;

    //Loop down to find the leftmost leaf
    while (current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
struct node* DeleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = DeleteNode(root->left, key);

    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = DeleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left == NULL and root->right == NULL)
            return NULL;

        // node with only one child or no child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the Inorder successor
        // (smallest in the right subtree)
        struct node* temp = MinValueNode(root->right);

        // Copy the Inorder successor's content to this node
        root->key = temp->key;

        // Delete the Inorder successor
        root->right = DeleteNode(root->right, temp->key);
    }
    return root;
}