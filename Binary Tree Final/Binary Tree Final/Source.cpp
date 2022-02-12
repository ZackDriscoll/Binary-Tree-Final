#include <iostream>
#include <malloc.h>
#include "Node.h";
#include "BinaryTree.h";

using namespace std;


//Create an array of random ints
int myNum[8];

//Main Function
int main()
{
    //Instantiate the tree with set data
    struct node* root = NULL;

    //Assign random values to the array until it is full
    for (int i = 0; i < 8; i++)
    {
        myNum[i] = (rand() % 100) + 1;
        
        root = Insert(root, myNum[i]);
    }    

    //Welcome the user
    cout << "\n\t\t*** Welcome to the Binary Tree Showcase! ***\n\n";

    //Print the tree
    cout << "Inorder traversal of the given tree \n";
    Inorder(root);
    cout << endl;
    system("pause");

    //Delete the third item and reprint the tree
    cout << "\nDelete the third item in the tree. \n";
    root = DeleteNode(root, myNum[2]);
    cout << "Inorder traversal of the modified tree. \n";
    Inorder(root);
    cout << endl;
    system("pause");

    //Delete the sixth item and reprint the tree
    cout << "\nDelete the sixth item in the tree. \n";
    root = DeleteNode(root, myNum[4]);
    cout << "Inorder traversal of the modified tree. \n";
    Inorder(root);
    cout << endl;
    system("pause");

    //Delete the forth item and reprint the tree
    cout << "\nDelete the fifth item in the tree. \n";
    root = DeleteNode(root, myNum[1]);
    cout << "Inorder traversal of the modified tree. \n";
    Inorder(root);
    cout << endl;
    system("pause");

    return 0;
}