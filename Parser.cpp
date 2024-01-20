/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
Parser.cpp
*/

#include "Parser.h"
#include <cctype>


Parser::Parser(Lexer lex) {
  mHead = new Stack<NumberOperator>();

  Stack<char>* tempStack = new Stack<char>();
  char c;
  while (!(lex.getHead()->empty())) {
      c = lex.getHead()->pop(); //o
      
      if (c == ' ' || lex.getHead()->empty()) {
          // Extract the string from the temporary stack
          if(lex.getHead()->empty()) {
              tempStack->add(c);
          }
          std::string temp = "";
          while (!(tempStack->empty())) {
              temp += tempStack->pop();
          }
          
          // call findOperator that returns a struct that we push into stack
          NumberOperator* operatorResult = findOperator(temp);
          if (operatorResult) {
            mHead->add(*operatorResult);
          }
      } else {
          tempStack->add(c);
      }
  }
  delete lex.getHead();
  delete tempStack;
}




NumberOperator* Parser::findOperator(std::string word) {
  if(word.size() == 1) {
    char c = word[0];
    if(isdigit(c)) {
      //cast the number to string number to an int
      return new Number(number, c - '0');
    } else {
        switch(c) {
          case '+':
            return new Addition(addition);
          //case '-':
            //return NumberOperator(subtraction, 0);
          //case '/':
            //return NumberOperator(division, 0);
          case '*':
            return new Multiplication(multiplication);
          //case '%':
            //return NumberOperator(modulo, 0);
          //case '^':
            //return NumberOperator(exponent, 0);
            
          default:
            return new NumberOperator(none); 
        }
    } 
  } else {
    //if word size is not equal to 1 then it must be a large digit
    char y = word[0];
    if(isdigit(y)) {
      for(char x: word) {
        if(!isdigit(x)) {
          return new NumberOperator(none);
        } 
      }
      return new Number(number, std::stoi(word));
    } else {
      return new NumberOperator(none);
    }
  } 
  return new NumberOperator(none);
}






















