#include <stdio.h>
#define size 10



void swap(int *a, int *b)
{
    int temp = *a;
    *a= *b;
    *b = temp;
}


int main()
{
       printf("Filename:\n");
    char fileName[30];
    scanf("%s",fileName);
  FILE *Ptr =fopen(fileName, "r");
    int matrix[size][size];
    int rowSum,colSum;
    int rowArr[10],colArr[10];

    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
    {
    fscanf(Ptr,"%d",&matrix[i][j]);
    }



    for(int i=0; i<size; i++)
    {


        rowSum=0;
        colSum=0;
        for(int k=0; k<size; k++)
        {
        rowSum += matrix[i][k];
        rowArr[i]=rowSum;
        colSum += matrix[k][i];
        colArr[i]=colSum;
        }
    }

      for (int i = 0; i < size-1; i++){
     for (int j = 0; j < size-i-1; j++){
          if (rowArr[j] > rowArr[j+1]){
          for(int k=0; k<size; k++){
                swap(&matrix[j][k],&matrix[j+1][k]);


}}}}

   for(int i=0; i<size; i++){
               for(int j=0; j<size; j++)
    {
    printf("%d ",matrix[i][j]);
    }
        printf("\n");
       }
    printf("\n");

    for (int i = 0; i < size-1; i++){
     for (int j = 0; j < size-i-1; j++){
          if (colArr[j] > colArr[j+1]){
          for(int k=0; k<size; k++){
                swap(&matrix[k][j],&matrix[k][j+1]);
          }}}}
       for(int i=0; i<size; i++){
               for(int j=0; j<size; j++)
    {
    printf("%d ",matrix[i][j]);
    }
        printf("\n");
       }







    return 0;
}
