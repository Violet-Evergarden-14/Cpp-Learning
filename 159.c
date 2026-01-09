#include <stdio.h>
#include <string.h>

void replaceStr(char A[], const char B[], const char C[]);
void countStr(char A[], char B[]);
void deleteStr(char A[], char B[]);
void addStr(char A[], const char B[], const char C[]);

int main()
{
    char target[210] = {"\0"};
    gets(target);

    char choose;
    scanf("%c", &choose);

    switch (choose)
    {
    case 'C':
        char strc[110];
        scanf("%s", strc);
        countStr(target, strc);
        break;
    case 'D':
        char strd[110];
        scanf("%s", strd);
        deleteStr(target, strd);
        break;
    case 'I':
        char stri1[110], stri2[110];
        scanf("%s%s", stri1, stri2);
        addStr(target, stri1, stri2);
        break;
    case 'R':
        char strr1[110], strr2[110];
        scanf("%s%s", strr1, strr2);
        replaceStr(target, strr1, strr2);
        printf("%s", target);
        break;
    default:
        break;
    }

    return 0;
}

void addStr(char A[], const char B[], const char C[])
{
    int lenA = strlen(A);
    int lenB = strlen(B);
    int lenC = strlen(C);

    int a = 1;
    int start[210];
    int index = 0;
    int count = 0;
    char result[200] = {"\0"};

    for (int i = 0; i < lenA - lenB + 1; i++)
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
                start[count] = i;
                i = start[count] + lenB - 1;
                count++;
            }
        }
    }

    char p[200] = {"\0"};
    if (count) {
        for (int i = 0; i < start[count - 1]; i++) {
            result[i] = A[i];
        }
        strcat(result, C);
        for (int i = start[count - 1]; i < lenA; i++)
        {
            p[i - start[count - 1]] = A[i];
        }
        strcat(result, p);
        strcpy(A, result);
    }
    printf("%s", A);
}

void deleteStr(char A[], char B[])
{
    int lenA = strlen(A);
    int lenB = strlen(B);

    int a = 1;
    int start;
    int index = 0;
    int count = 0;
    char result[200] = {"\0"};

    for (int i = 0; i < lenA - lenB + 1; i++)
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
                count++;
                break;
            }
        }
    }

    char p[200] = {"\0"};
    if (count) {
        for (int i = 0; i < start; i++) {
            result[i] = A[i];
        }
        
        if (start + lenB != lenA)
        {
            for (int i = start + lenB; i < lenA; i++)
            {
                p[i - start - lenB] = A[i];
            }
            strcat(result, p);
        }
        
        strcpy(A, result);
    }

    printf("%s", A);
}

void countStr(char A[], char B[])
{
    int lenA = strlen(A);
    int lenB = strlen(B);

    int a = 1;
    int start[210];
    int count = 0;

    for (int i = 0; i < lenA - lenB + 1; i++)
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
                start[count] = i;
                i = start[count] + lenB - 1;
                count++;
            }
        }
    }

    printf("%d", count);
}

void replaceStr(char A[], const char B[], const char C[])
{
    int lenA = strlen(A);
    int lenB = strlen(B);
    int lenC = strlen(C);

    int a = 1;
    int start[210];
    int index = 0;
    int count = 0;
    char result[200] = {"\0"};

    for (int i = 0; i < lenA - lenB + 1; i++)
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
                start[count] = i;
                i = start[count] + lenB - 1;
                count++;
            }
        }
    }

    char p[200] = {"\0"};
    if (count) {
        for (int i = 0; i < start[0]; i++) {
            result[i] = A[i];
        }
        for (int k = 0; k < count - 1; k++) {
            for (int i = start[k] + lenB; i < start[k + 1]; i++) {
                p[i - (start[k] + lenB)] = A[i];
            }
            strcat(result, C);
            strcat(result, p);
            memset(p, 0, sizeof(p));
        }
        strcat(result, C);
        if (start[count - 1] + lenB != lenA) {
            for (int i = start[count - 1] + lenB; i < lenA; i++) {
                p[i - (start[count - 1] + lenB)] = A[i];
            }
            strcat(result, p);
        }
        strcpy(A, result);
    }
}