/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
ASH.cpp
*/

#include "ASH.h"




bool div2(int num) {
    //std::cout << "call div2" << std::endl;
    if(num == 2) {
        return true;
    } else if(num%2 == 0) {
        return div2(num/2);
    } else {
        return false;
    }
}





void ASH::insert(int value) {

    if(mRoot == nullptr) {
      mRoot = insertFromRoot(mRoot, value);
    } else {
      mRoot = insertFromRoot(mRoot, value);
      //mRoot->setSize(mRoot->getSize() + 1);
      ++(*mRoot);
    }
}


Node* ASH::insertFromRoot(Node* root, int value) {
    if(root == nullptr) {
        //std::cout << "root is nullptr so place " << value << " as leaf" << std::endl;
        return new Node(value); 
    } 
    //std::cout << "root is not a nullptr, value : " << root->getValue() << std::endl;

    //make a copy of root and then use it instead of root
    Node* copy = new Node(*root);
    
    
    if(value <= copy->getValue()) {

         //cout to check div2     
        //std::cout << root->getLeft()->getSize() << std::endl;
        //std::cout << div2(root->getLeft()->getSize() + 1) << std::endl;

        if(copy->getLeft() == nullptr) {
            copy->setLeft(new Node(value));
        } else if(div2(copy->getLeft()->getSize() + 1)) {
            //std::cout << "recursion to the right with value = " << value << std::endl;
            copy->setRight(insertFromRoot(copy->getRight(), value));
        } else {
            //std::cout << "recursion to the left with value = " << value << std::endl;
            copy->setLeft(insertFromRoot(copy->getLeft(), value));
        }
        return copy;
 
    } else {

        //first we create a new node and change its size
        Node* newNode = new Node(value);
        newNode->setSize(copy->getSize());

        //then we copy the current root
        //Node dup = Node(*root);
        //traverse(&dup);
        //std::cout << value << " > " << copy->getValue() << std::endl;
        //newNode->setLeft(&dup);

        newNode->setLeft(new Node(*copy));
      
        //newNode->setValue(value);
        //traverse(newNode);
        return newNode;
    } 

}





void ASH::traverseFromRoot() {
  std::cout << "\ncalling traverse" << std::endl;
  traverse(mRoot);
  std::cout << "\nend traversal\n" << std::endl;
}

void ASH::traverse(const Node* root) {
  if(root != nullptr) {
    //std::cout << "traversing left" << std::endl;
    traverse(root->getLeft());
    std::cout << root->getValue() << ", ";
    //std::cout << root->getSize() << ", ";
    //std::cout << "\ntraversing right" << std::endl;
    traverse(root->getRight());
  }
  //std::cout << "end call" << std::endl;
}





void ASH::deleteList() {
  deleteNode(mRoot);
}

void ASH::deleteNode(Node* root) {
  if(root != nullptr) {
    deleteNode(root->getLeft());
    deleteNode(root->getRight());
    delete root;
    root = nullptr;
  }
}





int ASH::getHeapSize(Node* root) {

    if(!root->getLeft() && !root->getRight()) {
        return 1;
    } else {
        int size = 1;
        size += getHeapSize(root->getLeft());
        size += getHeapSize(root->getRight());
        return size;
    }
}





