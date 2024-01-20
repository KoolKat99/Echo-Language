/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
NumberOperator.h
*/

#ifndef NUMBEROPERATOR_H
#define NUMBEROPERATOR_H

#include <iostream>


//parser will check that there is a binary operator inbetween each digit


const std::string SYNTAX[] = {
    "none",
    "number",    
    "exponent",      
    "modulo",
    "multiplication",  
    "division",        
    "addition",        
    "subtraction",  
};


enum BinaryOperator { 
  none,
  number,
  exponent,    
  modulo,
  multiplication,  
  division,        
  addition,        
  subtraction,  
};



class NumberOperator {

  protected:
    std::string mName;
    BinaryOperator mOperation;


  public:
    NumberOperator(BinaryOperator operato) : mName(SYNTAX[operato]), mOperation(operato) {}

    //virtual ~NumberOperator() {}

    std::string getName() const {return mName; }
    BinaryOperator getOperation() const {return mOperation; }


    //virtual std::string print() const {return mName; }

    friend std::ostream& operator<<(std::ostream &os, const NumberOperator &no) {return os << no.mName; }
    
    



};



#endif