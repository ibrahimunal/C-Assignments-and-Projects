#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct{
    double x,y;
}complex_t;
int scan_complex(complex_t *c);
void print_complex(complex_t c);
complex_t complex_abs(complex_t c);
complex_t add_complex(complex_t c1, complex_t c2);
int main()
{
    complex_t abs;
    printf("lutfen 2 deger gýrýnýzçç\n");
    complex_t c;
    scan_complex(&c);
    abs=complex_abs(c);
    print_complex(abs);
    return 0 ;
}

int scan_complex(complex_t *c)
{
    int result;
     result =scanf("%lf%lf",&c->x,&c->y);
     if(result ==2)
     {
         result = 1;
     }
     return (result);
}
void print_complex(complex_t c)
{

    printf("complex number is : %lf %lfi", c.x,c.y);

}
complex_t complex_abs(complex_t c)
{
    complex_t temp;
    temp.x=abs(c.x);
    temp.y=abs(c.y);
    return temp;
}
complex_t add_complex(complex_t c1, complex_t c2)
{
    complex_t temp;
    temp.x=c1.x+c2.x;
    temp.y=c1.y+c2.y;
    return temp;
}
