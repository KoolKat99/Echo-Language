//The abstract syntax tree is going to sort different statements based on their order in enumeration
//we can have rules such as 

#include <string>
#include <stack>
#include <iostream>

using namespace std;


//creating a max heap with largest numbers on top
enum AbstractSyntax {
    none,
    number,
    parentheses,     
    exponent,        
    multiplication,  
    division,        
    addition,        
    subtraction,     
};



//we will create a tree with the largest enums
struct Tree {

    Tree* leftNode;
    Tree* rightNode;
    AbstractSyntax value;
    Tree() : value(none), leftNode(nullptr), rightNode(nullptr) {}

};

void createTree(Tree* &t, stack<AbstractSyntax> &input);
void printInOrder(Tree* root);
void deleteTree(Tree* &root);


int main() {
    Tree* root = new Tree();

    stack<AbstractSyntax> st;
    st.push(number);
    st.push(multiplication);
    st.push(number);
    st.push(addition);
    st.push(number);

    

    createTree(root, st);

    printInOrder(root);

    deleteTree(root);


    return 0;
}

//first we classify what each character is and then we can start parsing


void createTree(Tree* &t, stack<AbstractSyntax> &input) {
    while (!input.empty()) {
        AbstractSyntax s = input.top();
        input.pop();

        if (t->value == none) {
            t->value = s;
        } else if (s > t->value) {
            // If the enum value is greater than the current, it goes on the right
            if (t->rightNode == nullptr) {
                t->rightNode = new Tree();
            }
            createTree(t->rightNode, input);
        } else {
            // If the enum value is less than or equal to the current, it goes on the left
            if (t->leftNode == nullptr) {
                t->leftNode = new Tree();
            }
            createTree(t->leftNode, input);
        }
    }
}


void deleteTree(Tree* &root) {
    if (root != nullptr) {
        deleteTree(root->leftNode);
        deleteTree(root->rightNode);
        delete root;
        root = nullptr; // Set the pointer to null after deletion to avoid using a dangling pointer
    }
}


void printInOrder(Tree* root) {
    if (root != nullptr) {
        printInOrder(root->leftNode);
        cout << root->value << "\n";
        printInOrder(root->rightNode);
    } 
}
