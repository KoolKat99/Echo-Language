

#include "ASH.h"
#include <iostream>

//checking if something is 2^n
bool div2(int num) {
    //this number is 2 instead of 1 because we want to go left if the size on the left is 0
    if(num == 2) {
        return true;
    } else if(num%2 == 0) {
        return div2(num/2);
    } else {
        return false;
    }
}


//METHODS
void ASH::insert(AbstractSyntax value) {
    root = insertFromRoot(root, value);
}


//we will start our heap insertion
Node* ASH::insertFromRoot(Node* root, AbstractSyntax value) {
    if(root->val == none) {
        root->val = value;
        //theres a possible problem such that we need to initialize the nullptr in the left or right
        return new Node(value);
    } else if(value <= root->val) {
        //we will look on the leftnodes first to see if theres any open spots



       //if the left node is 2^n - 1 then its full so go for the right 
        if(div2(root->left->size + 1)) {
            root->right = insertFromRoot(root->right, value);
        } else {
            root->left = insertFromRoot(root->left, value);
        }
        //since we are adding a value below that means we have to increase the size by 1 on top
        ++root;
        return root;


        
        //else if(value > root->val) 
    } else {
        //if the value is greater than the root the throw the entire root to the left of a new node
        //But if this is a recursive step then we swap the values
        Node* newNode = new Node(value, root->size);
        newNode->left = root;
        return newNode;
    } 
    
}

/*
         x
     x       x
 x      x x     x 



*/





int ASH::getHeapSize(Node* root) {
    
    if(!root->left && !root->right) {
        return 1;
    } else {
        int size = 1;
        size += getHeapSize(root->left);
        size += getHeapSize(root->right);
        return size;
        
    }

}


ASH& ASH::operator++() {
    ++root->size;
    return *this;
}

ASH& ASH::operator++(int) {
    ASH temp = *this;
    ++*this;
    return temp;
}

ASH& ASH::operator--() {
    --root->size;
    return *this;
}

ASH& ASH::operator--(int) {
    ASH temp = *this;
    --*this;
    return temp;
}

ostream& ASH::operator<<(ostream &os, const ASH &tree) {
    //not sure how i would even use this
}











