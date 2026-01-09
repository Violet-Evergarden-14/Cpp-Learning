#include <stdio.h>
#include <string.h>

int main()
{
    char content[10001];
    gets(content);
    int l = strlen(content);

    char result[51] = {"\0"};
    int count_index = 0;
    char part[51] = {"\0"};
    int start = 0;
    int index = 0;
    int count = 0;
    int a = 0;

    while (content[start + index] != ' ')
    {
        part[index] = content[start + index];
        if (content[start + index] == 'a' || content[start + index] == 'A') count++;
        index++;
        if (count)
        {
            a++;
        }
        
    }
    strcpy(result, part);
    
    count_index = index;
    start += index + 1;
    index = 0;
    count = 0;
    

    while (start < l) {
        for (int i = 0; i < 51; i++)
        {
            part[i] = '\0';
        }

        while (content[start + index] != ' ' && content[start + index] != '\0') {
            part[index] = content[start + index];
            if (content[start + index] == 'a' || content[start + index] == 'A') count++;
            if (count) a++;
            index++;
        }

        if (index > count_index && count) {
            count_index = index;
            strcpy(result, part);
        }
        
        start += index + 1;
        index = 0;
        count = 0;
    }

    if (a)
    {
        puts(result);
    } else {
        printf("-1");
    }
    
}