#include <iostream>
#include <cctype>
using namespace std;

// keyword list
string keywords[] = {
    "int","float","double","char","if","else","while",
    "for","return","void","break","continue"
};

// check keyword
bool isKeyword(string word) {
    for (string k : keywords)
        if (word == k)
            return true;
    return false;
}

// Letter (A–Z / a–z) বা underscore (_) দিয়ে শুরু হতে হবে
// পরে letter, digit (0–9), underscore থাকতে পারে
// Space বা special character (@, #, $, %, etc.) ব্যবহার করা যাবে না
// Keyword হতে পারবে না (int, float, return ইত্যাদি)

// check identifier
bool isIdentifier(string word) {
    if (word.length() == 0)
    // word.length() → word-এর কয়টা character আছে তা জানায়
    // যদি length = 0 হয় (➡️ মানে কোনো word দেওয়া হয়নি (empty string))
        return false;

    // first character must be letter or _
    if (!(isalpha(word[0]) || word[0] == '_'))
        return false;

    // remaining characters
    for (int i = 1; i < word.length(); i++) {
        if (!(isalnum(word[i]) || word[i] == '_'))
            return false;
    }
    /*
    isalnum() চেক করে character টি
    letter (A–Z / a–z) অথবা
    digit (0–9) কিনা
    */
   /*
   !(isalnum(word[i]) || word[i] == '_')
    এর মানে:
    যদি character টি letter না হয়
    এবং digit না হয়
    এবং underscore না হয়
    ➡️ তাহলে condition true হবে
   */

    // keyword not allowed
    if (isKeyword(word))
        return false;

    return true;
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    if (isIdentifier(word))
        cout << "Valid Identifier";
    else
        cout << "Invalid Identifier";

    return 0;
}