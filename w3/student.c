#include<stdio.h>
typedef struct Student{
    char name[20];
    long long id;
    char sex[3];
    int age;
    char subject[20];
    int grade;
}Student;

void show(Student* s)
{
    printf("姓名:%s  ID:%lld  性别:%s  年龄:%d  专业:%s  成绩:%d\n",s->name,s->id,s->sex,s->age,s->subject,s->grade);
}

Student* STUDENT[100];
int index=0;

void showall(void)
{
    for(int i=0;i<index;i++)
    {
        if(STUDENT[i]->id)
            show(STUDENT[i]);
    }
}

void readdat(void)
{

}

void savedat(void)
{
    
}

void screen_insert(void)
{
    Student new;
    printf("正在录入新数据...\n");
    printf("姓名:");
    scanf("%s",new.name);
    printf("ID:");
    scanf("%lld",&new.id);
    printf("性别:");
    scanf("%s",new.sex);
    printf("年龄:");
    scanf("%d",&new.age);
    printf("专业:");
    scanf("%s",new.subject);
    printf("成绩:");
    scanf("%d",&new.grade);
    STUDENT[index++]=&new;
    printf("\n---成功录入信息---\n");
    show(&new);
    printf("------------------\n");
    screen_hall();
}

void screen_delete(void)
{
    long long id;
    int isfind=0;
    printf("请输入要删除数据的ID:");
    scanf("%lld",&id);
    for(int i=0;i<index;i++)
    {
        if(STUDENT[i]->id == id)
        {
            printf("---成功删除信息---\n");
            show(STUDENT[i]);
            printf("------------------\n");
            Student new={id=0};
            STUDENT[i]=&new;
            isfind=1;
            break;
        }
    }
    if(!isfind)
    {
        printf("------------------------------------\n未找到id=%lld的数据，删除失败\n------------------------------------\n",id);
    }
    screen_hall();
}

void screen_upadte(void)
{
        long long id;
    int isfind=0;
    printf("请输入要更改数据的id:");
    scanf("%lld",&id);
    for(int i=0;i<index;i++)
    {
        if(STUDENT[i]->id == id)
        {
            int choose;
            printf("--------------------\n    1.更改姓名\n    2.更改性别\n    3.更改年龄\n    4.更改专业\n    5.更改成绩\n--------------------\n");
            printf("请输入选项:");scanf("%d",&choose);
            // 防呆懒的写
            switch(choose)
            {
            case 1:
                char name[20];
                printf("输入新的姓名:");
                scanf("%s",name);
                strcpy(STUDENT[i]->name,name);
                break;
            case 2:
                char sex[3];
                printf("输入新的性别:");
                scanf("%s",&sex);
                strcpy(STUDENT[i]->sex,sex);
                break;
            case 3:
                int age;
                printf("输入新的年龄:");
                scanf("%d",&age);
                STUDENT[i]->age = age;
                break;
            case 4:
                char subject[20];
                printf("输入新的学科:");
                scanf("%s",subject);
                strcpy(STUDENT[i]->subject,subject);
                break;
            case 5:
                int grade;
                printf("输入新的成绩:");
                scanf("%d",&grade);
                STUDENT[i]->grade = grade;
                break;
            }

            printf("---更改成功---\n");
            show(STUDENT[i]);
            printf("--------------");
            isfind = 1;
            break;
        }
    }
    if(!isfind) printf("------------------------------------\n未找到id=%lld的数据，更改失败\n------------------------------------\n",id);
    screen_hall();
}

void screen_query(void)
{
    long long id;
    int isfind=0;
    printf("请输入id查询:");
    scanf("%lld",&id);
    for(int i=0;i<index;i++)
    {
        if(STUDENT[i]->id == id)
        {
            printf("---查询成功---\n");
            show(STUDENT[i]);
            printf("--------------");
            isfind = 1;
            break;
        }
    }
    if(!isfind) printf("------------------------------------\n未找到id=%lld的数据，查询失败\n------------------------------------\n",id);
    screen_hall();
}

void screen_hall(void)
{
    printf("-------------学生管理系统--------------\n    1.新增数据\n    2.删除数据\n    3.更改数据\n    4.查询数据\n    0.退出系统\n---------------------------------------");
    int choose;
    printf("\n请输入选项:");
    scanf("%d",&choose);
    if(choose>4||choose<0)
    {
        printf("输入错误，请重新输入选项:");
        scanf("%d",&choose);
    }
    switch(choose)
    {
    case 0:
        savedat();
        printf("\n已退出系统\n");
        break;
    case 1:
        screen_insert();
        break;
    case 2:
        screen_delete();
        break;
    case 3:
        screen_upadte();
        break;
    case 4:
        screen_query();
        break;
    default:
        break;
    }
}


int main(void) {
    
    screen_hall();

    showall();
    
    return 0;
}