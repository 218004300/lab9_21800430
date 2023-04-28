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
        printf("=> 로딩 성공!\n");
    } else {
        printf("=> 파일 없음\n");
    }

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if (count > 0) {
                listScore(sp, index, -1);
            } else {
                index = 0;
                printf("목록이 없습니다.\n");
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
                printf("=> 해당 번호 없음\n");
            }
        } else if (menu == 4){
            int no = selectDataNum(sp, index);
            if(no > 0) {
                int delOk;
                printf("정말로 삭제하시겠습니까?(삭제 : 1) ");
                scanf("%d", &delOk);
                if(delOk == 1) {
                    free(sp[no]);
                    sp[no] = NULL;
                    count--;
                    printf("=> 삭제됨!\n");
                } else {
                    printf("=> 취소됨!\n");
                }
            } else {
            printf("=> 해당 번호 없음\n");
            }
        } else if (menu == 5) {
            saveFile(sp, index);
        } else if (menu == 6) {
            searchName(sp, index);
        } else {
            printf("잘못된 번호입니다.\n");
        }
    }
    printf("종료됨!\n");
    return 0;
}