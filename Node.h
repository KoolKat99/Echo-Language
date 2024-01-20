/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
Node.h
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include "NumberOperator.h"
#include "Number.h"
#include "Multiplication.h"
#include "Addition.h"

/**
const std::string SYNTAX[] = {
    "none",
    "number",    
    "exponent",        
    "multiplication",  
    "division",        
    "addition",        
    "subtraction",  
};
**/

class Node {

  private:
    int mValue;
    int mSize;
    Node* mLeft;
    Node* mRight;


  public:
    //constructors
    Node(int value) : mValue(value), mSize(1), mLeft(nullptr), mRight(nullptr) {}

    Node(const Node&);


    //getters
    int getValue() const {return mValue; }
    int getSize() const {return mSize; }
    Node* getLeft() const {return mLeft; }
    Node* getRight() const {return mRight; }


    //setters
    void setValue(int value) {mValue = value; }
    void setSize(int size) {mSize = size; }
    void setLeft(Node* left) {mLeft = left; }
    void setRight(Node* right) {mRight = right; }


    //oerator overloads
    Node& operator++();
    Node& operator--();


    friend std::ostream& operator<<(std::ostream &os, const Node &n) {return os << n.mValue; }


    //Node* dup(Node* root);

};




#endif