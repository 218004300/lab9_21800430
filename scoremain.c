#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "score.h"

int main(void){
    Score *sp[100];
    int count = 0, index = 0, i = 0;
    int menu, no;
    int file = 0;

    file = access("./score.txt", F_OK);
    if(file == 0) {
        count = loadFile(sp);
        index = count;
        printf("=> �ε� ����!\n");
    } else {
        printf("=> ���� ����\n");
    }

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if (count > 0) {
                listScore(sp, index, -1);
            } else {
                index = 0;
                printf("����� �����ϴ�.\n");
            }
        }
        else if (menu == 2){
            index++;
            sp[index] = (Score *)malloc(sizeof(Score));
            count++;
            addUpScore(sp[index], index, 2);
        }
        else if (menu == 3){
            int no = selectDataNum(sp, index);
            if(no > 0) {
                addUpScore(sp[no], no, 3);
            } else {
                printf("=> �ش� ��ȣ ����\n");
            }
        } else if (menu == 4){
            int no = selectDataNum(sp, index);
            if(no > 0) {
                int delOk;
                printf("������ �����Ͻðڽ��ϱ�?(���� : 1) ");
                scanf("%d", &delOk);
                if(delOk == 1) {
                    free(sp[no]);
                    sp[no] = NULL;
                    count--;
                    printf("=> ������!\n");
                } else {
                    printf("=> ��ҵ�!\n");
                }
            } else {
            printf("=> �ش� ��ȣ ����\n");
            }
        } else if (menu == 5) {
            saveFile(sp, index);
        } else if (menu == 6) {
            searchName(sp, index);
        } else {
            printf("�߸��� ��ȣ�Դϴ�.\n");
        }
    }
    printf("�����!\n");
    return 0;
}