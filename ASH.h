#ifndef ASH_H
#define ASH_H

#include <string>
#include <iostream>



enum AbstractSyntax {
    number,     
    exponent,        
    multiplication,  
    division,        
    addition,        
    subtraction, 
    none    
};

const std::string SYNTAX[6] = {
    "number",    
    "exponent",        
    "multiplication",  
    "division",        
    "addition",        
    "subtraction",  
};


struct Node{
    AbstractSyntax val;
    int size;
    Node* left;
    Node* right;

    Node() : val(none), size(0), left(nullptr), right(nullptr) {}
    Node(AbstractSyntax value) : val(value), size(1), left(nullptr), right(nullptr) {}
    Node(AbstractSyntax value, int si) : val(value), size(1 + si), left(nullptr), right(nullptr) {}
};



//Abstract syntax heap
class ASH {

    private:
        Node* root;
        

    public:

        //Constructors
        ASH() : root(nullptr) {}
        
        //Getters
        AbstractSyntax getVal() {return root->val; }
        Node* getRight() {return root->right; }
        Node* getLeft() {return root->left; }
        int getSize() {return root->size; }

        int getHeapSize(Node* root);


        //Setters
        void setVal(AbstractSyntax val) {root->val = val; }
        void setRight(Node* right) {root->right = right; }
        void setLeft(Node* left) {root->left = left; }
        void setSize(int si) {root->size = si; }


        //Methods
        //append left function

        Node* insertFromRoot(Node* root, AbstractSyntax value);
        void insert(AbstractSyntax value);

        ASH* deleteNode(Node* &root);


        //in order to compile our code we need a way to read the tree from the leafs
        //ASH* getBranch();

        ASH& operator++();
        ASH& operator++(int);
        ASH& operator--();
        ASH& operator--(int);

        friend std::ostream& operator<<(std::ostream &os, const ASH &tree);







};




#endif