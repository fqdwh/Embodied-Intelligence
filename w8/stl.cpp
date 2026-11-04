#include<iostream>
#include<string>
#include<memory>   // 智能指针库
using namespace std;
// 相应指针模版定义
// 出代码块自动释放内存
template<class X>
class auto_ptr{
public:
    explicit auto_ptr(X* p=0) throw();
};
int main(void) {

    auto_ptr<string> ps(new string);
    
    return 0;
}