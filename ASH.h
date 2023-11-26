#ifndef ASH_H
#define ASH_H

#include <string>



enum AbstractSyntax {
    number,     
    exponent,        
    multiplication,  
    division,        
    addition,        
    subtraction, 
    none    
};

const string SYNTAX[6] = {
    "number",    
    "exponent",        
    "multiplication",  
    "division",        
    "addition",        
    "subtraction",  
};


struct Node{
    AbstractSyntax val;
    Node* left;
    Node* right;

    Node() : val(none), left(nullptr), right(nullptr) {}
    Node(AbstractSyntax value) : val(value), left(nullptr), right(nullptr) {}
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

        //Setters
        void setVal(AbstractSyntax val) {root->val = val; }
        void setRight(Node* right) {root->right = right; }
        void setLeft(Node* left) {root->left = left; }


        //Methods
        //append left function

        Node* insertFromRoot(Node* root, AbstractSyntax value);
        void insert(AbstractSyntax value);

        ASH* deleteNode(Node* &root);


        //in order to compile our code we need a way to read the tree from the leafs
        ASH* getBranch();




        








};




#endif