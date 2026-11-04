#include<stdio.h>
int Mystrlen(char* str)
{
    int len=0;
    int i=0;
    while(str[i]){
        i++;len++;
    }
    return len;
}
int Mystrcmp(char* str1,char* str2)
{
    int len1 = Mystrlen(str1);
    int len2 = Mystrlen(str2);
    if(len1==len2)
    {
        int n=len1;
        for(int i=0;i<n;i++)
        {
            if(str1[i]>str2[i]) return 1;
            else if(str1[i] < str2[i]) return -1;
        }
        return 0;
    }
    else
    {
        int n = len1 < len2 ? len1:len2;
        for(int i=0;i<n;i++)
        {
            if(str1[i]>str2[i]) return 1;
            else if(str1[i] < str2[i]) return -1;
        }
        return len1>len2?1:-1;
    }
}
void Mystrcpy(char* str1,const char* str2)
{
    int len = Mystrlen(str2);
    for(int i=0;i<len;i++)
    {
        str1[i] = str2[i];
    }
}
int main(void) {
    char str1[10]="123456789";
    char str2[10]="12";
    printf("%d\n", Mystrlen(str1));
    printf("%d\n", Mystrlen(str2));
    printf("%d\n", Mystrcmp(str2, str1));
    Mystrcpy(str2,str1);
    printf("%s\n", str2);

    return 0;
}