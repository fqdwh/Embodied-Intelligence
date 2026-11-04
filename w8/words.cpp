#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<map>
using namespace std;
void readtxt(string file,map<string,int>& l)
{
    ifstream in(file);
    char ch;
    string word;
    while(in.get(ch))
    {
        cout << ch << endl;
        if(ispunct(ch)||isspace(ch)){if(!word.empty())l[word]++;word.clear();}   // 标点空格
        else word+=ch;
    }
}
void writetxt(string file,map<string,int>& l)
{
    ofstream out(file);
    for(auto it = l.begin();it != l.end();it++)
    {
        out << it->first << ":" << it->second << endl;
    }
}
int main(void) {
    map<string,int> l;
    string file = "test";
    readtxt(file+".txt",l);
    writetxt(file+"_count.txt",l);
    return 0;
}