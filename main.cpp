 //
//  main.cpp
//  BinaryTree
//
//  Created by Todor Ivanov on 2/8/16.
//  Copyright © 2016 Todor Ivanov. All rights reserved.
//

#include <iostream>
using namespace std;


struct node
{
    int data;
    node* left;
    node* right;
};

class btree
{
public:
    btree()

    {
        root = new node;
        root->data = 10;
        root->left = NULL;
        root->right = NULL;
    }
    void insert(int data, node** node );
    node* search(int data, node* node);
    node* root;
    
};



node* btree::search(int data, node* node)
{
    if (node != NULL)
    {
        if(data == node -> data)
        {
            return node;
        }
        else if( data < node -> data)
        {
            search(data, node->left);
        }
        else search(data, node->right);
    }
    
    return NULL;
}

void btree::insert(int data, node** node)
{
    if(*node!= NULL)
    {
        if((*node)->data < data)
        {
            insert(data, &(*node)->left);
            
        }
        else
        {
            insert(data, &(*node)->right);
        }
    }
    else{
        (*node) = new struct node;
        (*node)->data  = data;
        (*node)->left = NULL;
        (*node)->right = NULL;
    }
}

int main(int argc, const char * argv[]) {

    btree binTree;
    binTree.insert(11, &binTree.root);
    cout << binTree.root->data << endl;
    if (binTree.root->right->data!= NULL ) {
        cout << "Da desniq node e razlichen  " << endl;
    }
    cout << binTree.root->right->data << endl;
    return 0;
}

