//The abstract syntax tree is going to sort different statements based on their order in enumeration
//we can have rules such as 

#include <string>
#include <stack>
#include <iostream>

using namespace std;


//creating a max heap with largest numbers on top
enum AbstractSyntax {
    number,     
    exponent,        
    multiplication,  
    division,        
    addition,        
    subtraction, 
    none    
};

const string syntax[6] = {
    "number",    
    "exponent",        
    "multiplication",  
    "division",        
    "addition",        
    "subtraction",  
};




//we will create a tree with the largest enums
struct Node {

    Node* leftNode;
    Node* rightNode;
    AbstractSyntax value;
    Node() : value(none), leftNode(nullptr), rightNode(nullptr) {}
    Node(AbstractSyntax val) : value(val), leftNode(nullptr), rightNode(nullptr) {}

};


Node* insert(Node* &t, AbstractSyntax input);
void printInOrder(Node* root);
void deleteNode(Node* &root);
void appendNode(Node* &heap1, Node* &heap2);


int main() {
    Node* root = new Node();

    stack<AbstractSyntax> st;
    st.push(number);
    st.push(multiplication);
    st.push(number);
    st.push(addition);
    st.push(number);
    st.push(subtraction);
    st.push(number);

    
    while(!st.empty()) {
        AbstractSyntax value = st.top();
        st.pop();
        
        insert(root, value);
    }
    

    printInOrder(root);

    deleteNode(root);


    return 0;
}

//first we classify what each character is and then we can start parsing


Node* insert(Node* &t, AbstractSyntax input) {

    if (t->value == none) {
        t->value = input;

    } else if (input > t->value) {
        // if s is greater t then we will create a new node and append the old node to the left
        if (t->rightNode == nullptr) {
            t->rightNode = new Node(input);
        } else {
            insert(t->rightNode, input);
        }
        
    } else if (input < t->value) {
        // If the enum value is less than or equal to the current, it goes on the left
        if (t->leftNode == nullptr) {
            t->leftNode = new Node(input);
        } else {
            insert(t->leftNode, input);
        }
        
    } else {

    }
    
}


void deleteNode(Node* &root) {
    if (root != nullptr) {
        deleteNode(root->leftNode);
        deleteNode(root->rightNode);
        delete root;
        root = nullptr; // Set the pointer to null after deletion to avoid using a dangling pointer
    }
}


void printInOrder(Node* root) {
    if (root != nullptr) {
        printInOrder(root->leftNode);
        cout << syntax[root->value] << ": " << root->value << "\n";
        printInOrder(root->rightNode);
    } 
}


//we are always going to append other heaps on the leftNode
//We will only be using this function when heap1.size() = 1
void appendNode(Node* &heap1, Node* &heap2) {
    //if there is no values for heap1
    if(!heap1) {
        heap1 = heap2;
        return;
    }

    //append heap2 to the left node of heap1
    heap1->leftNode = heap2;
    //since heap2 in this case will always be the root node we say heap2 = heap1
    heap2 = heap1;
    return;


}
