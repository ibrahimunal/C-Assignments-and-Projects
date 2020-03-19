#include<stdio.h>
#define SHOW(first, second) printf("%d%d",first,second)
#define PI 3.14
#define CIRCLEAREA(x)PI*((x)*(x))
struct Student
{
    char name[25];

    int roll;
    int marks;
};

int main()
{
    int area=CIRCLEAREA(4);
    printf("%d\n",area);
    int x=5, y=6;
    FILE *fp;
    char ch;
    struct Student Stu= {"Hasan",12,45};
    struct Student Stu2= {"meHMET",11,42};

    fp=fopen("Student.bin","wb+");
    struct Student temp={"",0,0};
    rewind(fp);
    while(fread(&temp,sizeof(struct Student),1,fp)){
        printf("%s%d%d",temp.name,temp.roll,temp.marks);

    }






}
