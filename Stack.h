/*
Ian, Earnhart
CS 150 
December (15), (2023) 

Project #/Exam # 
CapstoneProject

Class
Stack.h
*/


#ifndef STACK_H
#define STACK_H

#include <iostream>

//StackNode Struct
template <typename T>
struct StackNode {
  T data;
  StackNode* next;

  StackNode(const T &dat, StackNode* nt = nullptr) : data(dat), next(nt) {}
  StackNode() : next(nullptr) {}
};

//Stack class
template <typename T>
class Stack {

  private:
    StackNode<T>* mHead;
    int mSize;

  public:
    Stack() : mHead(nullptr), mSize(0) {}

    ~Stack() {clearList(); }

    T getFrontValue() const {return mHead->next->data; }


    bool empty() {return ((mSize == 0) ? true : false); }


    void add(T data) {
      mHead = new StackNode<T>(data, mHead);
      ++mSize;
    }


    void print() const {
      StackNode<T>* temp = mHead;
      while (temp != nullptr) {
          std::cout << temp->data << ", ";
          temp = temp->next;
      }
    }



    void deleteFront() {
      StackNode<T>* temp = mHead;
      mHead = mHead->next; 
      delete temp;
      --mSize;
    }


    //grabs from front and deletes
    T pop() {
      if(mHead != nullptr) {
        T temp = mHead->data;
        StackNode<T>* tempNode = mHead;
        mHead = mHead->next;
        delete tempNode;
        --mSize;
        return temp;
      } else {
        return 0;
      }
    }

    //called by destructor
    void clearList() {
        while (mHead != nullptr) {
            StackNode<T>* temp = mHead;
            mHead = mHead->next;
            delete temp;
        }
    }
    

};



#endif
