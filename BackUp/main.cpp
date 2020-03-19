#include <stdio.h>
int main()
{

    FILE *input,*copyTo;
    char ch,inputName[20],outputName[20];
    printf("Enter the file name\n");
    scanf("%s",inputName);

    input=fopen(inputName,"r");
    if(input== NULL)
    {
        printf("Error");
    }
    copyTo=fopen("copyTo.txt","r");

    while((ch=fgetc(input))!=EOF)
    {
        printf("%c",ch);
    }

    return 0;
}
