#include<stdio.h>
#include<string.h>

struct info{
    int rollno;
    char name[20];
    float marks;
};

typedef struct info info;

void val(info*, int);
void disp(info*, int);
void initval(info*, int, char*,float);
void sortStudents(info*, int);
void search(info*, int);


int main(){
    int n;
    scanf("%d",&n);
    info s1[n];
    val(s1,n);
    disp(s1,n);
    sortStudents(s1, n);
    disp(s1, n);
    search(s1, n);
}

void val(info *ptr, int size){
    int id;
    char n[20];
    float marks;
    printf("Scanning\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &id);
        scanf("%s", n);
        scanf("%f", &marks);
        initval(&ptr[i], id, n, marks);
    }
}

void disp(info* s1, int n){
    for(int i=0;i<n;i++){
        printf("%d\t",s1[i].rollno);
        printf("%s\t",s1[i].name);
        printf("%.2f\n",s1[i].marks);
    }
}

void initval(info *ptr, int id, char *newname, float newmarks)
{
    ptr->rollno = id;
    ptr->marks = newmarks;
    strcpy(ptr->name, newname);
}

void sortStudents(info* students, int size) {
    int i, j;
    info temp;
    printf("After sorting in descending order\n");
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (students[j].marks < students[j + 1].marks) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void search(info* s1, int n){
    char searchname[20];
    printf("Enter the name you want to search\n");
    scanf("%s",searchname);
    for(int i=0;i<n;i++){
        if(strcmp(s1[i].name,searchname)==0){
            printf("rollno:%d\t name:%s\t marks:%.2f",s1[i].rollno,s1[i].name,s1[i].marks);
        }
    }
}
