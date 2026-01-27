#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s1[30] = {"\0"}, s2[30] = {"\0"};
    scanf("%s\n%s", s1, s2);

    int l = strlen(s1);
    int l2 = strlen(s2);
    char s[l];
    int index;
    int a = 0;
    
    for (int i = 0; i < l; i++)
    {
        index = 1;

        for (int j = 0; j < l; j++) {
            s[j] = s1[(j + i) % l];
        }
        
        for (int i = 0; i < l2; i++)
        {
            if (s[i] != s2[i])
            {
                index = 0;
            }
        }

        if (index)
        {
            cout << "true";
            a = 1;
            break;
        }
    }
    
    if (a != 1)
    {
        cout << "false";
    }
    

}