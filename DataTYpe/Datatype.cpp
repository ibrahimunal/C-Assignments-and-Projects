#include <stdio.h>

struct Point
{
    int x,y;
};

void display(Point p1);
void show(Point *p1);
int main()
{

printf("fsdf");

    return 0;
}

void display(Point p1)
{
    printf("point is %d,%d\n",p1.x,p1.y);
}
void show(Point *p1)
{
    printf("Point is %d-%d",p1->x,p1->y);

}
