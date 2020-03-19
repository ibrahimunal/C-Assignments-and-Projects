#include <stdio.h>

typedef struct {
    double x,y;

}Point;

void convexHull(Point pointArr[], int size);
int orientation(Point p, Point q, Point r);

int main()
{

    printf("Filename:\n");
    char fileName[30];
    scanf("%s",fileName);
    int size;
  FILE *Ptr =fopen(fileName, "r");
  fscanf(Ptr,"%d",&size);
      Point point[size];

        for(int i=0; i<size; i++)
        {
            fscanf(Ptr,"%lf %lf",&point[i].x,&point[i].y);
}
    convexHull(point,size);
    return 0;
}

int orientation(Point p, Point q, Point r)
{
    double val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
//if value =0 that meant points are linear...
    if (val == 0)
    {
        return 0;}
//if value smaller than 0 it's counter clock-wise(LEfT)
   else if(val<0)
   {
       return 2;
   }
//if value greater than 0 it's clock-wise(RIGHT)

   else{
    return 1;
   }

}



void convexHull(Point pointArr[], int size){


    Point hullArr[size];
    int p=0,q;
    int t=0;

    Point leftMost;
    leftMost.x = 99999.0;

    for(int i=0; i<size; i++)
    {
        if(pointArr[i].x<leftMost.x)
        {
           leftMost= pointArr[i];
           p=i;
        }
    }
    printf("Polygon points are: \n");
    do{
        q = (p+1)%size;
        //to prevent to null point exception in case p reaches the last elemeent
        hullArr[t]=pointArr[p];

        printf("(%lf ,%lf)\n",hullArr[t].x,hullArr[t].y);
        t++;
        for(int i=0; i<size; i++)
        {
            if(orientation(pointArr[p],pointArr[i],pointArr[q])==2)
            {
                q=i;
            }
        }
        p=q;

    }
    while(leftMost.x != pointArr[p].x);



}
