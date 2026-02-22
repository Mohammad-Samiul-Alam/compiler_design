#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream fin("input_code.txt");// ifsteam = input file stream
    ofstream fout("output_code.txt");//ofstream = ouput file stream
    char ch, next;
    /*
    ch	= Input file থেকে বর্তমান character পড়া
    next = ch এর পরের character দেখার জন্য, যাতে comment detect করা যায়
    */
   while(fin.get(ch)) {
    if(ch == '/') {
        fin.get(next);
        // single line
        if(next == '/') { 
            while(fin.get(ch) && ch != '\n'); //এই লাইনটি comment skip করার জন্য। // তাই এই লুপ সব character পড়ে ফেলে কিন্তু output-এ লিখে না, অর্থাৎ comment ignore করে।
            fout << '\n';            
        }
        // multiple line
        else if(next == '*') {
            while(fin.get(ch)) {
                if(ch == '*') {
                    fin.get(next);
                    if(next == '/') {
                        break;
                    }
                }
            }
        } else {
            fout << ch << next; //// <-- comment নয়, normal code
            //next != '/' এবং next != '*'
            // তাই else fout << ch << next; চালু হবে
        }
    }
    else {
        fout << ch; // <-- "/" নয়, normal character
    }
   }
   fin.close();
   fout.close();

   cout << "comment removed. Check output_text.txt \n";
   return 0;
}