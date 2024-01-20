/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
Lexer.h
*/


#ifndef LEXER_H
#define LEXER_H

#include <string>
#include "Stack.h"

//this class will grab the string and seperate the values and create a stack
//or a linked list essentially




class Lexer {
// linked list of chars
  private:
    Stack<char>* mHead;

  public:
    Lexer(std::string);

    //calling Stack class destructor
    //~Lexer() {delete mHead; }


    Stack<char>* getHead() const {return mHead; }

    bool checkValid(char x);

    

};

#endif