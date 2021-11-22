#include <iostream>
#include <string>
 using namespace std;
int main()
{
    string str1 = "45";
    string str2 = "3.14159";
    string str3 = "31337 with words";
    string str4 = "words and 2";
 
    int myint1 = stoi(str1);
    int myint2 = stoi(str2);
    int myint3 = stoi(str3);
     error: 'std::invalid_argument';
    int myint4 = stoi(str4);
 
    cout << "std::stoi(\"" << str1 << "\") is " << myint1 << '\n';
    cout << "std::stoi(\"" << str2 << "\") is " << myint2 << '\n';
    cout << "std::stoi(\"" << str3 << "\") is " << myint3 << '\n';
    cout << "std::stoi(\"" << str4 << "\") is " << myint4 << '\n';
}