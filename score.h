typedef struct{
    int no;
    char name[20];
    int kor;
    int eng;
    int math;
    int sum;
    float avg;
} Score;
 
void addUpScore(Score *s, int index, int n);
void readScore(Score s);
int selectMenu();
void listScore(Score *s[], int index, int n);
int selectDataNum(Score *s[], int index);
int loadFile(Score *s[]);
int saveFile(Score *s[], int index);
void searchName(Score *s[], int index);