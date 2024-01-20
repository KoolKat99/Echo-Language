/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
Multiplication.h
*/

#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "NumberOperator.h"
#include "Number.h"


class Multiplication : public NumberOperator {

  private:

  public:
    Multiplication(BinaryOperator operato) : NumberOperator(operato) {}

    int op(const Number &num1, const Number &num2) {return num1.getValue() * num2.getValue(); }



};





#endif