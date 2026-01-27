#include <stdio.h>
#include <string.h>

int main()
{
    char long_str[200] = "cdcjcnwcjnosjc";
    char short_str[200] = "jc";
    int l = strlen(long_str);
    int s = strlen(short_str);
    int count = 0;
    int count_sum = 0;
    
    for (int i = 0; i < l - s + 1; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (short_str[j] == long_str[i + j])
            {
                count += 1;
            } else {break;}
            
        }
        
        if (count == s)
        {
            count_sum += 1;
        }
        
        count = 0;
    }
    
    printf("%d", count_sum);


    return 0;
}