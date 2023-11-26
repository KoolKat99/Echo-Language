

#include "ASH.h"


//METHODS
void ASH::insert(AbstractSyntax value) {
    root = insertFromRoot(root, value);
}

//we will start our heap insertion
Node* ASH::insertFromRoot(Node* root, AbstractSyntax value) {
    if(root->val == none) {
        root->val = value;
        //theres a possible problem such that we need to initialize the nullptr in the left or right
        return root;
    } else if(value < root->val) {
        //we will look on the leftnodes first to see if theres any open spots


        //This isnt needed because of IF ROOT->VAL == none then ROOT->VAL = value
        /**
        if(!root->left) {
            root->left = new Node(value);
            return root->left;
        } else if(!root->right) {
            root->right = new Node(value);
            return root->right;
        }
        **/



        if(root->left && root->right) {
            //if our enum is less than the root then we perform recursion
            root->left = insertFromRoot(root->left, value);

        } else {
            //if our left enum 
            root->right = insertFromRoot(root->right, value);

        } 

        
    } else if(value >= root->val) {
        //if the value is greater than the root the throw the entire root to the left of a new node
        Node* newNode = new Node(value);
        newNode->left = root;
        return newNode;
    } 
    
}
