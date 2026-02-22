#include <iostream>
#include <string>
using namespace std;

// Simple list of keywords
string keywords[] = {"int", "float", "return", "if", "else", "while", "for", "void"};

// Check if a word is a keyword
bool isKeyword(string word) {
    for (string k : keywords)
        if (k == word) return true;
    return false;
}

int main() {
    string code;
    cout << "Enter code: ";
    getline(cin, code);

    string token = "";
    for (char ch : code) {
        if (ch == ' ' || ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='=' || ch=='<' || ch=='>' || ch=='(' || ch==')' || ch==';') {
            if (!token.empty()) {
                if (isKeyword(token)) cout << token << " : Keyword\n";
                else if (isdigit(token[0])) cout << token << " : Number\n";
                else cout << token << " : Identifier\n";
                token = "";
            }
            if (ch != ' ') cout << ch << " : Operator/Symbol\n";
        } else {
            token += ch;
        }
    }
    if (!token.empty()) {
        if (isKeyword(token)) cout << token << " : Keyword\n";
        else if (isdigit(token[0])) cout << token << " : Number\n";
        else cout << token << " : Identifier\n";
    }
    return 0;
}
