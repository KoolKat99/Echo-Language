//Going to grab the first string and then parse through it

//THE RULES FOR GRAMMAR ARE '.' and ' ', periods and spaces are delimeters



//With the current lexer lets just get it to seperate a line by spaces and periods and () and ; and {}

//We also need calcualtor functions such as * / + - = !
//We wont be using || or && and replace them with or and

#include <string>
#include <iostream>
#include <cctype>
#include <stack>

using namespace std;


//we have a line of text with a pos of the char and the current char

//always pop position 0 and if size = 0 then go to next line
// create a queue
struct Lexer {
    stack<char> st;
};


bool checkValidChar(char a);
void advance(Lexer a);
void initializeLexer(string text, Lexer &a);


int main() {


    cout << "Echo Shell\n";
    while(true) {
        string text;
        Lexer myLine;
        cout << ">> ";
        getline(cin, text);

        if(text == "end()") {
            return 0;
        }

        initializeLexer(text, myLine);
        bool invalid = false;

        //while the queue is not empty keep looping
        int col = text.size();
        while(!myLine.st.empty() && !invalid) {
            //cout << "hello";

            char x = myLine.st.top();
            myLine.st.pop();
            //if char is not valid then we break
            if(!checkValidChar(x)) {
                invalid = true;
                cout << "invalid char on column: " << col << endl; 
            }
            col--;

        }
    }
    

    
    return 0;

}



void initializeLexer(string text, Lexer &a) {

    for(char x : text) {
        a.st.push(x);
        //cout << x << endl;
    }
}


bool checkValidChar(char a) {
    if(isalnum(a)) {
        return true;
    } else if(ispunct(a)) {
        switch(a) {
            case '+':
            case '-':
            case '/':
            case '=':
            case '*':
            case '%':
            case '^':
                //cout << "\nUsing calculator\n";
                return true;
            case '.':
            case '(':
            case ')':
            case ':':
            case '[':
            case ']':
            case '{':
            case '}':
            case '\t':
            case '<':
            case '>':
            case ',':
                //cout << "\nUsing other characters\n";
                return true;
            default:
                //cout << "\nInvalid Character\n";
                return false; 
        }
    }
    return false;

}