/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
Parser.h
*/



#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"
#include "NumberOperator.h"
#include "Number.h"
#include "Multiplication.h"
#include "Addition.h"
#include <iostream>




class Parser {

  private:
    Stack<NumberOperator>* mHead;

  public:
    Parser(Lexer lex);

    //~Parser() {delete mHead; }

    Stack<NumberOperator>* getHead() const {return mHead; }

    NumberOperator* findOperator(std::string word);

    void printAll() const {mHead->print(); }
    

    
    


};


#endif