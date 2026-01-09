#include <stdio.h>
#include <string.h>


class Character
{
public:
    char character;
    int time;
};

int main()
{
    Character list[26];

    char yiyiyi[250];
    gets(yiyiyi);
    int l = strlen(yiyiyi);
    int count = 1;
    int index = 1;

    if (yiyiyi[0] <= 'Z') {
        yiyiyi[0] -= 'A' -'a';
    }
    list[0].character = yiyiyi[0];
    list[0].time = 1;
    
    for (int i = 1; i < l; i++) {
        if (yiyiyi[i] <= 'Z') {
            yiyiyi[i] -= 'A' -'a';
        }
        
        for (int j = 0; j < count; j++) {
            if (yiyiyi[i] == list[j].character) {
                index = 0;
                break;
            }
        }

        if (index) {
            list[count].character = yiyiyi[i];
            list[count].time = 1;
            count++;
        } else {
            for (int j = 0; j < l; j++) {
                if (yiyiyi[i] == list[j].character) {
                    list[j].time++;
                    break;
                }
            }
        }

        index = 1;
    }

    char change;
    int _;
    for (int k = 0; k < count - 1; k++) {
        for (int i = 0; i < count - 1; i++) {
            if (list[i].time < list[i + 1].time || (list[i].time == list[i + 1].time && list[i].character > list[i + 1].character))
            {
                change = list[i].character;
                list[i].character = list[i + 1].character;
                list[i + 1].character = change;
                _ = list[i].time;
                list[i].time = list[i + 1].time;
                list[i + 1].time = _;
            }
        }
    }
    
    for (int i = 0; i < count; i++) {
        printf("%c %d\n", list[i].character, list[i].time);
    }
    

    return 0;
}
