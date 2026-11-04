#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<windows.h>
using namespace std;
class Student{
private:
    string name,sex,subject;
    int id,age,grade;
public:
    Student(void):name(""),id(0),sex(""),age(0),subject(""),grade(0){}
    Student(string& n,int i,string& s,int a,string& su,int g):name(n),id(i),sex(s),age(a),subject(su),grade(g){}
    ~Student() {}
    void show(){ cout<<"ID:"<<id << "   姓名:" << name << "   性别:" << sex<<"   年龄:"<<age<<"   专业:"<<subject<<"   成绩:"<<grade<<endl;}
    void setname(string& n) {name = n;}
    void setid(int i) {id = i;}
    void setsex(string& s) {sex = s;}
    void setage(int a) {age =a;}
    void setsubject(string& s) {subject = s;}
    void setgrade(int g) {grade = g;}
    string& getname() {return name;}
    int getid() {return id;}
    string& getsex() {return sex;}
    int getage() {return age;}
    string& getsubject() {return subject;}
    int getgrade() {return grade;}
};
//  ==========全局变量=========
vector<Student*> students;


// 15 ---------------
class Screen{
public:
    void hall() {
        cout << "---------------学生管理系统(c++)---------------\n    1.新增数据\n    2.删除数据\n    3.修改数据\n    4.查询数据\n    0.退出系统\n";
        cout <<"-----------------------------------------------\n";
        int choose;
        cout <<"请输入选项:";cin >> choose;
        // 错误输入直接退出
        switch(choose)
        {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Update();
            break;
        case 4:
            Query();
            break;
        default:
            cout << "\n已退出系统...\n";
            break;

        }
    }
    void Insert() {
        string name,sex,subject;
        int id,age,grade;
        cout << "\n---------------正在输入新数据---------------\n";
        cout << " 姓名:";cin >> name;
        cout << " ID:"; cin >> id;
        cout << " 性别:";cin >> sex;
        cout << " 年龄:";cin >> age;
        cout << " 专业:";cin >> subject;
        cout << " 成绩:";cin >> grade;
        Student* s = new Student(name,id,sex,age,subject,grade);
        students.push_back(s);

        cout << "---------------新数据录入成功---------------\n";
        s->show();
        cout <<"--------------------------------------------\n\n";
        hall();
    }
    void Delete() {
        cout<< "\n---------------正在删除数据---------------\n";
        cout << " 请输入要删除的学生ID:";
        int id,isfind=0;
        cin >> id;
        for(auto it = students.begin(); it != students.end(); ++it) {
            if((*it)->getid() == id) {
                isfind=1;
                (*it)->show();
                delete *it;
                students.erase(it);
                cout << "---------------数据删除成功---------------\n";
                break;
            }
        }
        if(!isfind) cout << "      未找到该学生\n---------------数据删除失败---------------\n";
        hall();
    }
    void Update() {
        cout<< "\n---------------正在修改数据---------------\n";
        cout << " 请输入要修改的学生ID:";
        int isfind=0;
        string name,sex,subject;
        int id,age,grade;
        cin >> id;
        for(auto it = students.begin(); it != students.end(); ++it) {
            if((*it)->getid() == id) {
                isfind=1;
                int choose;
                cout << "    1.修改姓名\n    2.修改ID\n    3.修改性别\n    4.修改年龄\n    5.修改专业\n    6.修改成绩\n    7.取消修改\n";
                cout << "请输入选项:";cin >> choose;
                switch(choose)
                {
                    case 1:
                        cout << " 请输入新的姓名:";cin >> name;
                        (*it)->setname(name);
                        break;
                    case 2:
                        cout << " 请输入新的ID:";cin >> id;
                        (*it)->setid(id);
                        break;
                    case 3:
                        cout << " 请输入新的性别:";cin >> sex;
                        (*it)->setsex(sex);
                        break;
                    case 4:
                        cout << " 请输入新的年龄:";cin >> age;
                        (*it)->setage(age);
                        break;
                    case 5:
                        cout << " 请输入新的专业:";cin >> subject;
                        (*it)->setsubject(subject);
                        break;
                    case 6:
                        cout << " 请输入新的成绩:";cin >> grade;
                        (*it)->setgrade(grade);
                        break;
                    case 7:
                        cout << "---------------取消修改---------------\n";
                        break;
                    default:
                        cout << "---------------无效选项---------------\n";

                }

                (*it)->show();
                cout << "---------------数据修改成功---------------\n";
                break;
            }
        }
        if(!isfind) cout << "      未找到该学生\n---------------数据修改失败---------------\n";
        hall();
    }
    void Query() {
        cout << "---------------正在查询数据---------------\n";
        cout << "  请输入要查找学生的ID:";
        int id,isfind=0;
        cin >> id;
        for(auto it = students.begin(); it != students.end(); ++it) {
            if((*it)->getid() == id) {
                isfind=1;
                (*it)->show();
                break;
            }
        }
        if(!isfind) cout << "      未找到该学生\n---------------数据查询失败---------------\n";
        hall();
    }
};

int readdat(void) {
    string name,sex,subject;
    int id,age,grade;
    int n;

    ifstream in("data.dat", ios_base::binary);
    in >> n;
    for(int i=0;i<n;i++)
    {
        in >> name >> id >> sex >> age >> subject >> grade;
        
        Student* s = new Student(name,id,sex,age,subject,grade);//new Student(name,id,sex,age,subject,grade);
        students.push_back(s);
        
    }
    in.close();
    return 0;   // 正常读取数据
}

int savedat(void) {
    ofstream out("data.dat", ios_base::binary);
    int n = students.size();
    out << n << endl;
    for(int i=0;i<n;i++) out << students[i]->getname() << " " << students[i]->getid() << " " << students[i]->getsex() << " " << students[i]->getage() << " " << students[i]->getsubject() << " " << students[i]->getgrade() << endl;
    out.close();
    return 0;   // 正常保存数据
}

void showall(void) {
    int n = students.size();
    for(int i=0;i<n;i++) students[i]->show();
}

int main() {
    SetConsoleOutputCP(65001);   // 需要 #include <windows.h>
    system("chcp 65001 >nul");

    if(readdat()) cout << "\n!!!读取历史数据错误!!!\n\n";
    Screen s;
    s.hall();
    showall();
    savedat();
    return 0;
}