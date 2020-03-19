#include <stdio.h>
#include <string.h>

struct film
{
    unsigned int id;
    char name[20];
    char format[3];
    char show_date[11];
    char show_time[6];
    int price;
    int capacity;


};
void menu()
{
    puts("CINEMA MANAGEMENT SYSTEM");
    puts("1-add film");
    puts("2-remove film");
    puts("3-sell ticket");
    puts("4-print available films");
    puts("5-export as the text file");
    puts("6-end program");

}

void add_record(FILE *fptr)
{
    int id;
    printf("Enter the id of the film:");
    scanf("%d",&id);
    struct film test;
    rewind(fptr);
    fseek(fptr,(id-1)*sizeof(struct film),SEEK_SET);
    fread(&test,sizeof(struct film),1,fptr);
    if(test.id != 0)
    {
        puts("already exist");
    }

    else
    {
        test.id = id;

        int ch = 0;
        while ((ch = getchar()) != '\n' && ch != EOF);

        printf("Film Name:");

        fgets(test.name,20,stdin);

        test.name[strcspn(test.name, "\n")] = 0;

        printf("Format:");
        scanf("%s",test.format);
        printf("Show Date: ");
        scanf("%s",test.show_date);
        printf("Show Time: ");
        scanf("%s",test.show_time);
        printf("Price: ");
        scanf("%d",&test.price);
        printf("Capacity: ");
        scanf("%d",&test.capacity);
        rewind(fptr);
        fseek(fptr,(id-1)*sizeof(struct film),SEEK_SET);
        fwrite(&test,1,sizeof(test),fptr);
    }

}

void show_records (FILE *fptr)
{
    fseek(fptr,0,SEEK_SET);
    struct film test;

    puts("ID No\tFilm Name\tFormat\t  Show Date   Show Time     Price  Capacity");

    int status = fread(&test,sizeof(test),1,fptr);
    while(status)
    {
        if(test.id!=0)
        {

            printf("%-8d%-16s%-10s%-11s%10s%10d%10d\n",test.id,test.name,test.format,test.show_date,test.show_time,test.price,test.capacity);

        }
        status = fread(&test,sizeof(test),1,fptr);

    }
}


void delete_record (FILE *fptr)
{
    int id;
    printf("Enter id to remove");
    struct film temp= {0,"","","","",0,0};

    scanf("%d",&id);
    struct film test;
    rewind(fptr);
    fseek(fptr,(id-1)*sizeof(struct film),SEEK_SET);
    fread(&test,sizeof(struct film),1,fptr);
    if(test.id == 0)
    {
        puts("already exist");
    }
    else
        rewind(fptr);
    fseek(fptr,(id-1)*sizeof(struct film),SEEK_SET);
    fwrite(&temp,sizeof(struct film),1,fptr);

}

void export_text_file (FILE *fptr)
{
    film b;
    int len;
    FILE *textp;
    textp=fopen("film.txt","w");
    rewind(fptr);

    while(!feof(fptr))
    {
        fread(&b,sizeof(struct film),1,fptr);
        if(b.id != 0)
        {
            fprintf(textp,"%d%s%s%s%s%d%d",b.id,b.name,b.format,b.show_date,b.show_time,b.price,b.capacity);
        }
    }
    fclose(textp);


}




int main(void)
{
    FILE *binaryp;
    binaryp=fopen("film.bin","rb+");
    int command;
//  printf("Enter the command");
//   scanf("%d",command);

    do
    {
        menu();

        printf("Enter: ");
        scanf("%d",&command);

        switch(command)
        {
        case 1:
            add_record(binaryp);
            break;
        case 2:
            delete_record(binaryp);
            break;
        case 3:
            sell_ticket(binaryp);
            break;
        case 4:

            show_records(binaryp);
            break;
        case 5:
            export_text_file(binaryp);
            break;

        }



    }
    while(command != 6);



    return 0;
}

