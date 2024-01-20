/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
Addition.h
*/


#ifndef ADDITION_H
#define ADDITION_H

#include "NumberOperator.h"
#include "Number.h"


class Addition : public NumberOperator {

  private:

  public:
    Addition(BinaryOperator operato) : NumberOperator(operato) {}

    int op(const Number &num1, const Number &num2) {return num1.getValue() + num2.getValue(); }



};





#endif