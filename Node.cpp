/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
Node.cpp
*/

#include "Node.h"

//copy constructor
Node::Node(const Node& other) {
  mValue = other.mValue;
  mSize = other.mSize;
  mLeft = (other.mLeft != nullptr) ? new Node(*(other.mLeft)) : nullptr;
  mRight = (other.mRight != nullptr) ? new Node(*(other.mRight)) : nullptr;
}




//THESE OPERATORS ARE DESTROYING EVERYTHING
//operator overloads
Node& Node::operator++() {
  ++mSize;
  return *this;
}

Node& Node::operator--() {
  --mSize;
  return *this;
}

/**
std::ostream& operator<<(std::ostream &os, const Node* n) {
  return os << SYNTAX[n->getValue()-1];
}
**/