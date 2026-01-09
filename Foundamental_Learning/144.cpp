#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>
using namespace std;

int replaceStr(char A[ ], const char B[ ], const char C[ ])
{
//补充代码，完成此函数

    int lenA = strlen(A);
    int lenB = strlen(B);
    int lenC = strlen(C);

    int a = 1;
    int start;
    int index = 0;

    for (int i = 0; i < lenA - lenB; i++)
    {
        a = 1;
        if (A[i] == B[0])
        {
            for (int j = i; j < i + lenB; j++)
            {
                if (A[j] != B[j - i])
                {
                    a = 0;
                    break;
                }
            }

            if (a)
            {
                start = i;
                index = 1;
                break;
            }
        }
    }

    char result[200] = {"\0"};
    if (index)
    {
        for (int i = 0; i < start; i++)
        {
            result[i] = A[i];
        }
        for (int i = 0; i < lenC; i++)
        {
            result[start + i] = C[i];
        }
        for (int i = start; i < lenA - lenB; i++)
        {
            result[i + lenC] = A[i + lenB];
        }
        
        strcpy(A, "\n");
        strcat(A, result);

        return 1;
    } else {
        
        char d[200];
        strcpy(d, A);
        strcpy(A, "\n");
        strcat(A, d);
        strcat(A, C);
        return 0;
    }
    

}



int main()
{
    char str1[110], str2[110], str3[110];
    int nRes;

    cin.getline(str1, 100);
    cin.getline(str2, 100);
    cin.getline(str3, 100);

    nRes = replaceStr(str1, str2, str3);
    printf("%d", nRes);
    printf("%s", str1);
    return 0;

}

