#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "score.h"

void addUpScore(Score *s, int index, int n) {
    printf("�̸���? ");
    scanf("%s", s->name);

    printf("�����? ");
    scanf("%d", &s->kor);

    printf("�����? ");
    scanf("%d", &s->eng);

    printf("������? ");
    scanf("%d", &s->math);

    s->no = index;
    s->sum = s->kor + s->eng + s->math;
    s->avg = s->sum / 3.0;

    if(n == 2)
        printf("=> �߰���!\n");
    else
        printf("=> ������!\n");
};

void readScore(Score s) {
    printf("%d %s %d %d %d %d %.1f\n", s.no, s.name, s.kor, s.eng, s.math, s.sum, s.avg);
};

int selectMenu(){
    int menu;
    printf("\n*** �������� ***\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("5. ��������\n");
    printf("6. �̸��˻�\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
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
    printf("\n��ȣ�� (��� :0)? ");
    scanf("%d", &num);
    if(s[num] == NULL) {
        printf("�߸��� ��ȣ�Դϴ�.\n");
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
    printf("�����!\n");
}

void searchName(Score *s[], int index) {
    char search[20];
    int n = 0, i;
    int scnt = 0;

    printf("�˻��� �̸���? ");
    scanf("%s", search);

    for(i = 1; i <= index; i++) {
        if(s[i] == NULL) continue;
        if(strcmp(s[i]->name, search) == 0) {
            n = i;
            scnt++;
            break;
        }
    }

    if(scnt > 0) {
        listScore(s, index, n);
    } else {
        printf("=> �ش� �̸��� �����ϴ�.\n");
    }
}