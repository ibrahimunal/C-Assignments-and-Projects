#include <stdio.h>
   void recursion(int x,int y, int *ptr);
int main()
{
    int arr[5]={1,5,2,6,8};
    int *arrP=arr;
    printf("%d",*(arrP+2));


    int x=10;
    int y=5;
    int result;
    recursion(x,y,&result);
    printf("%d",result);

    return 0;
}



    void recursion(int x,int y, int *ptr)
    {
      *ptr=x+y;


    }
