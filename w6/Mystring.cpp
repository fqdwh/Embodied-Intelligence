#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
class Mystring{
private:
    char* str;
    int length;
public:
    Mystring() {str = nullptr;length = 0;}
    Mystring(const char* str1) {length = strlen(str1);str = new char[length+1];strcpy(str,str1);}
    Mystring(const Mystring& other) {length = other.length;str = new char[length+1];strcpy(str,other.str);}
    ~Mystring() {delete str;}
    int size(void){return length;}
    friend ostream& operator<<(ostream& os,Mystring str){os << str.str;return os;}
    Mystring& operator+(Mystring& str1){
        char* strre = new char[length+str1.length+1];
        strcpy(strre,str);
        for(int i=0;i<str1.length;i++) strre[i+length]=str1.str[i];
        strre[length+str1.length]='\000';
        delete str;
        str = strre;
        length = length+str1.length;
        return *this;
    }
    int operator==(Mystring& str1){return strcmp(str,str1.str);}

};

int main(void) {
    SetConsoleOutputCP(65001);
    system("chcp 65001 >nul");
    Mystring str1("123456"),str2("789");
    cout << str1.size() << endl << str1 << endl;
    str1 = str1+str2;
    cout << str1 << endl << str2 << endl;
    cout << (str1==str2);

    return 0;
}