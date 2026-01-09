#include <stdio.h>
#include <string.h>

int judge(const char* target, const char* introduction, int i);

int main()
{
    char self_introduction[200];
    gets(self_introduction);
    int length = strlen(self_introduction);
    int start_year, end_year;
    int start_major, end_major;
    char start_year_c[] = ", born in ";
    char end_year_c[] = ", from ";
    char start_major_c[] = ". My major is ";
    char end_major_c[] = ". I ";
    
    for (int i = 0; i < length; i++) {
        if (judge(start_year_c, self_introduction, i)) {
            start_year = i;
            break;
        }
    }

    for (int i = 0; i < length; i++) {
        if (judge(end_year_c, self_introduction, i)) {
            end_year = i;
            break;
        }
    }

    for (int i = start_year + strlen(start_year_c); i < end_year; i++)
    {
        printf("%c", self_introduction[i]);
    }
    

    for (int i = 0; i < length; i++) {
        if (judge(start_major_c, self_introduction, i)) {
            start_major = i;
            break;
        }
    }

    for (int i = 0; i < length; i++) {
        if (judge(end_major_c, self_introduction, i)) {
            end_major = i;
            break;
        }
    }
    
    printf(", ");

    for (int i = start_major + strlen(start_major_c); i < end_major; i++)
    {
        printf("%c", self_introduction[i]);
    }
    
    

    return 0;
}

int judge(const char* target, const char* introduction, int i)
{
    int length = strlen(target);
    int result = 1;
    for (int j = 0; j < length; j++) {
        if (introduction[i + j] != target[j]) {
            result = 0;
            break;
        }
    }
    return result;
}