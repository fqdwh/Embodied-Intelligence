#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;
// 单向链表节点
typedef struct Node{
    int val;
    Node* next;
}Node;

// 单向链表 有头结点
class LinkNode{
private:
    Node* begin;
    int length;
public:
    LinkNode() {begin = new Node{0, nullptr}; length = 0;}
    LinkNode(vector<int>& l) {
        length = l.size();
        begin = new Node{0, nullptr};
        Node* cur = begin;
        for(int i=0;i<length;i++)
        {
            Node* s = new Node{l[i],nullptr};
            cur->next = s;
            cur = cur->next;
        }
    }
    ~LinkNode() {
        if(!begin->next)  // 空链表
        {
            delete begin;
        }
        else              // 前后双指针判断释放
        {
            Node* cur = begin->next;
            Node* pre = begin;
            while(cur)
            {
                delete pre;
                pre = cur;
                cur = cur->next;
            }
            delete pre;
        }
    }
    void Print(void) {
        Node* cur = begin->next;
        for(int i=0;i<length;i++)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    // 插入到第 pos 个节点后 头结点为位置为 0
    void Insert(int val,int pos) {
        if(pos < 0) cout <<"插入位置无效\n";
        else if(pos>=length)  // 超过现有长度直接插入末尾
        {
            Node* cur = begin;
            while(cur->next) cur = cur->next;
            Node* s = new Node{val,nullptr};
            cur->next = s;
            length++;
        }
        else
        {
            Node* cur = begin;
            for(int i=0;i<pos;i++) cur = cur->next;
            Node* s = new Node{val,cur->next};
            cur->next = s;
            length++;
        }
    }
    // 按位置删除节点
    void Delete_bypos(int pos) {
        if(pos < 0) cout <<"删除位置无效\n";
        else if(pos>=length)  // 超过现有长度直接删除末尾
        {
            Node* cur = begin;
            while(cur->next->next) cur = cur->next;
            delete cur->next;
            cur->next = nullptr;
            length--;
        }
        else
        {
            Node* cur = begin;
            for(int i=1;i<pos;i++)
            {
                cur = cur->next;
            }
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            length--;
        }
    }
    // 按值删除节点 删除第一个
    void Delete_byval(int val) {
        Node* cur = begin;
        int isfind=0;
        while(cur->next)
        {
            if(cur->next->val==val)
            {
                Node* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                length--;
                isfind=1;
                break;
            }
            cur = cur->next;
        }
        if(!isfind) cout << "未找到该值\n"; 
    }
};
int main(void)
{
    SetConsoleOutputCP(65001);
    system("chcp 65001 >nul");

    vector<int> l = {1,2,3,4,5,6,7,8,9,10};
    LinkNode ln(l);
    ln.Insert(100,5);
    ln.Delete_bypos(3);
    ln.Delete_byval(3);
    ln.Print();


    return 0;
}