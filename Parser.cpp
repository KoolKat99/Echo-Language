#include <string>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

//Seperate components by ',' and '.'
//Lets start with periods

//We will builds a binary tree with the stack



struct Parser {
    queue<string> list;
};


void initializeQueue(Parser &p, stack<char> input);


int main() {
    Parser myParser;

    stack<char> st;
    st.push('t');
    st.push('h');
    st.push('t');
    st.push('h');
    st.push('h');
    st.push('g');
    st.push('.');
    st.push('y');
    st.push('o');

    initializeQueue(myParser, st);


    /**
    cout << myParser.list.size() << endl;

    while(!myParser.list.empty()) {
        cout << myParser.list.front() << endl;
        myParser.list.pop();
    }
    **/


    return 0;
}



//we create a copy of the stack
void initializeQueue(Parser &p, stack<char> input) {
    //we have delimeters like '.' ',' ' ' '()'
    //if we see a delimeter then we say its a string
    //[o, y, ., g, h, h, t, h, t]

    stack<char> tp;
    char c;
    
    while (!input.empty()) {
        c = input.top(); //o
        input.pop(); //delete o
        //cout << c << endl;

        if (c == '.' || c == ',' || c == ' ' || c == ')' || c == '(' || input.empty()) {
            // Extract the string from the temporary stack
            if(input.empty()) {
                tp.push(c);
            }
            string temp = "";
            while (!tp.empty()) {
                temp += tp.top();
                tp.pop();
            }

            // Push the string into the queue
            p.list.push(temp);
        } else {
            tp.push(c);
        }
    }
}