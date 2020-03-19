#include <stdio.h>
int countDigit(int number);
int main()
{
    printf("%d :",countDigit(241));


}


void  countDigit(int number,int *ans)
{
    if(number==0)
    {

    }
    else{
        *ans=1+countDigit(number/10,*ans);
    }
}
