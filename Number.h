/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
Number.h
*/

#ifndef NUMBER_H
#define NUMBER_H

#include "NumberOperator.h"


class Number : public NumberOperator {

  private:
    int mValue;

  public:
    Number(BinaryOperator operato, int value) : NumberOperator(operato), mValue(value) {}

    int getValue() const {return mValue; }



};





#endif