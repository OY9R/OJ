#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s1[105], s2[105]; 
    int l1, l2, i, i1 , i2;//i1, i2:s1与s2转化为新字符串过程中填充字符串时用的下标 
    cin.getline(s1, 105);//读入带空格的字符串 
    cin.getline(s2, 105);
    l1 = strlen(s1);
    l2 = strlen(s2);
    for(i = 0, i1 = 0; i < l1; ++i)//把字符串s1转为只有小写字母无空格的字符串 
    {
        if(s1[i] >= 'a' && s1[i] <= 'z')
            s1[i1++] = s1[i];
        else if(s1[i] >= 'A' && s1[i] <= 'Z')
            s1[i1++] = s1[i] + 32;
    }
    s1[i1] = '\0';
    for(i = 0, i2 = 0; i < l2; ++i)//把字符串s2转为只有小写字母无空格的字符串 
    {
        if(s2[i] >= 'a' && s2[i] <= 'z')
            s2[i2++] = s2[i];
        else if(s2[i] >= 'A' && s2[i] <= 'Z')
            s2[i2++] = s2[i] + 32;
    }
    s2[i2] = '\0';
    cout << (strcmp(s1,s2) == 0 ? "YES" : "NO");
    return 0;
}