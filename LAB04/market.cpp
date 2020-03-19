#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char day;
    char month;
    char year;

}Date;
typedef struct{
    char tag;
     Date packaging_date;
     Date best_before;
}Meat;

typedef struct{
     Date best_before;
}DairyProducts;
typedef struct
{
  Date best_before;
  int aisle_number;
  char aisle_side;

}CannedFood;
typedef struct
{
    char tag;
    int aisle_number;
    char aisle_side;
}Non_FoodItems;
union type{
  Meat meat;
  DairyProducts dairyProducts;
  CannedFood cannedFood;
  Non_FoodItems nonFood;
};
typedef struct{
    char* name;
    int unit_cost;
    char product_category;
    union type item_type;

}item;


void load_item(item itemArr[],char fileName[])
{
    FILE *fp;
    fp=fopen(fileName,"r");
    printf("hello1");
    for( int i=0; !feof(fp); i++)
    {
    itemArr[i].name = (char*)malloc(sizeof(char)*64);
    itemArr[i].unit_cost = (int*)malloc(sizeof(int)*4);
    itemArr[i].product_category = (char*)malloc(sizeof(char)*64);

    fscanf(fp,"%s %d %c",itemArr[i].name,&itemArr[i].unit_cost,&itemArr[i].product_category);
    }
}





int main()
{
    item itemArr[30];
    char fileName[20];
    printf("Enter the file that you want to read\n");
    scanf("%s",fileName);
    load_item(itemArr,fileName);
    printf("%s",itemArr[0].name);
    printf("%s",itemArr[0].unit_cost);



    return 0;
}
