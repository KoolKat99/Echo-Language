/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
Lexer.cpp
*/



#include "Lexer.h"
#include <cctype>
#include <cstdlib>
#include <iostream>


//appending every char to a stack ie (linked list)
Lexer::Lexer(std::string text) {
  mHead = new Stack<char>();
  int count = 0;
  for(char x : text) {
    //std::cout << x << " ";
    ++count;
    //check if the char is valid
    if(checkValid(x)) {
      mHead->add(x);
    } else {
      //end program with an error if char isnt valid
      std::cout << "Invalid Character at position : " << count << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}



bool Lexer::checkValid(char x) {
  //std::cout << std::endl << "check : " << x;
  if(isdigit(x)) {
    //std::cout << " is digit";
    return true;
  } else if (x == ' ') {
    //std::cout << " is space";
    return true;
  } else if(ispunct(x)) {
    //std::cout << " is Special Character";
      switch(x) {
        case '+':
        case '-':
        case '/':
        case '=':
        case '*':
        case '%':
        case '^':
          return true;
        default:
          return false; 
      }
  }
  return false;
}

