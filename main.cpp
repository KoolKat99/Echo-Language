/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
main.cpp
*/

#include <iostream>
#include "ASH.h"
#include "ASH.cpp"
#include "Lexer.h"
#include "Lexer.cpp"
#include "Parser.h"
#include "Parser.cpp"
//#include <vector>


int main() {
  ASH root;
  std::string temp;
  

  std::cout << "Would you like to see my Parser, Abstract Syntax Tree, or leave?(1, 2, 3) : ";
  int choice;
  std::cin >> choice;
  getline(std::cin, temp);
  
  if(choice == 1) {
    std::string text;
    std::cout << "input an equation (valid : number, +, *): \n";
    getline(std::cin, text);
    std::cout << std::endl << text << std::endl;

    //throw the text into the lexer and the constructor throws it into a Stack<char>
    Lexer myLexer = Lexer(text);
    //Parser groups chars from lexer stack and forms a Stack<string>
    Parser myParser = Parser(myLexer);
    myParser.printAll();
    delete myParser.getHead();
    
  } else if(choice == 2) {
    int option;
    
    do {
      std::cout << "\nWould you like insert a node? 1)\n"
        <<"Traverse heap to show all nodes? 2)\n"
        <<"End this awesome experience? :( 3)\n";
      std::cin >> option;

      if(option == 1) {
        int value;
        std::cout << "\nEnter a value : ";
        std::cin >> value;
        root.insert(value);
      } else if(option == 2) {
        root.traverseFromRoot();
      } else {
        root.deleteList();
        return 0;
      }
      
    } while(option != 3);
  } else {
    std::cout << "\nbye\n";
  }
  
  root.deleteList();
  /**
  while(!myParser.getHead()->empty()) {
    auto op = myParser.getHead()->pop();
    root.insert(op);
  }
  **/
  
  std::cout << std::endl << std::endl;

}