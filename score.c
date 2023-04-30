#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "score.h"

void addUpScore(Score *s, int index, int n) {
    printf("이름은? ");
    scanf("%s", s->name);

    printf("국어는? ");
    scanf("%d", &s->kor);

    printf("영어는? ");
    scanf("%d", &s->eng);

    printf("수학은? ");
    scanf("%d", &s->math);

    s->no = index;
    s->sum = s->kor + s->eng + s->math;
    s->avg = s->sum / 3.0;

    if(n == 2)
        printf("=> 추가됨!\n");
    else
        printf("=> 수정됨!\n");
};

void readScore(Score s) {
    printf("%d %s %d %d %d %d %.1f\n", s.no, s.name, s.kor, s.eng, s.math, s.sum, s.avg);
};

int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

void listScore(Score *s[], int index, int n) {
    printf("\nNo Name  Kor Eng Math Sum Avg\n");
    printf("=============================\n");
    int i;
    if(n == -1) {
        for(i = 1; i <= index; i++) {
            if (s[i] == NULL) continue;
            readScore(*s[i]);
        }
    } else {
        readScore(*s[n]);
    }
}

int selectDataNum(Score *s[], int index) {
    listScore(s, index, -1);
    int num;
    printf("\n번호는 (취소 :0)? ");
    scanf("%d", &num);
    if(s[num] == NULL) {
        printf("잘못된 번호입니다.\n");
    }


    return num;
}

int loadFile(Score *s[]) {
    int i, num;
    FILE *fs;

    fs = fopen("score.txt", "rt");
    for(i = 1; i <= 100; i++) {
        if(feof(fs)) break;
        s[i] = (Score *)malloc(sizeof(Score));
        s[i]->no = i;
        fscanf(fs, "%s", s[i]->name);
        fscanf(fs, "%d", &s[i]->kor);
        fscanf(fs, "%d", &s[i]->eng);
        fscanf(fs, "%d", &s[i]->math);

        s[i]->sum = s[i]->kor + s[i]->eng + s[i]->math;
        s[i]->avg = s[i]->sum / 3.0;
    }
    fclose(fs);
    return i-1;
}

int saveFile(Score *s[], int index) {
    FILE *fs;
    fs = fopen("score.txt", "wt");

    int i;
    for(i = 1; i <= index; i++) {
        if(s[i] == NULL) continue;
        fprintf(fs, "%s %d %d %d", s[i]->name, s[i]->kor, s[i]->eng, s[i]->math);
        if(i < index) fprintf(fs, "\n");
    }
    fclose(fs);
    printf("저장됨!\n");
}

void searchName(Score *s[], int index){


}

void searchName(Score *s[], int count){
    int scnt = 0;
    char search[20];

    printf("검색할 이름은?");
    scanf("%s", search);

    printf("\nNo Name for Kor Eng Math Sum Avg\n");
    printf("====================================\n");
    for(int i=0; i<count; i++){
        if(s[i] == NULL) continue;
        if(strstr(s[i]->name, search)){
            printf("%2d ", i+1);
            readScore(*s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("검색된 데이터가 없습니다.\n");
    
}