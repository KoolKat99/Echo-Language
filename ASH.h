/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
ASH.h
*/

#ifndef ASH_H
#define ASH_H


#include "Node.h"
#include "Node.cpp"
#include <iostream>


//Abstract syntax heap
class ASH {

    private:
        Node* mRoot;


    public:

        //Constructors
        ASH() : mRoot(nullptr) {}

        //Getters
        Node* getRoot() const {return mRoot; }


        //Setters
        void setRoot(Node* root) {mRoot = root; }
        


        //Methods
        //append left function

        Node* insertFromRoot(Node* root, int value);
        void insert(int value);



        void deleteNode(Node* root);
        void deleteList();



        void traverse(const Node* root);
        void traverseFromRoot();


        int getHeapSize(Node* root);


        //in order to compile our binary operations we need a way to read the tree from the leafs
        //ASH* getBranch();







};




#endif