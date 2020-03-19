#include <stdio.h>
struct Date{
    int day;
    int month;
    int year;

};
struct Task{
    char taskName[20];
    struct Date dueDate;

};


  void nextTask(Task arr[],int size);
void bubbleSort(struct Task arr[], int n)
{
   struct Task temp;
   for (int i = 0; i < n; i++)
       for (int j = 0; j < n-1; j++)
           if (arr[j].dueDate.year > arr[j+1].dueDate.year)
            { temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
            }
            else if(arr[j].dueDate.year == arr[j+1].dueDate.year)
            {
               if (arr[j].dueDate.month > arr[j+1].dueDate.month)
            { temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
            }
            else if(arr[j].dueDate.month == arr[j+1].dueDate.month)
            {
               if (arr[j].dueDate.day > arr[j+1].dueDate.day)
            { temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
            }
            }
            }



}
int main()
{
    FILE *fileptr;
    int count_lines = 1;
    char filechar[40], chr;

    printf("Enter file name: \n");
    scanf("%s", filechar);
    fileptr = fopen(filechar, "r");
   //extract character from file and store in chr
    chr = getc(fileptr);
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.

        chr = getc(fileptr);
    }
    fseek(fileptr,0,SEEK_SET);


    struct Task taskArr[count_lines];

    for(int i=0; i<count_lines; i++)
    {
    Task b;
     fscanf(fileptr,"%d%d%d%s",&b.dueDate.year,&b.dueDate.month,&b.dueDate.day,b.taskName);
    taskArr[i]=b;
    }
    bubbleSort(taskArr,count_lines);
    for(int i=0; i<count_lines; i++)
    {
        printf("> %s @ %d-%d-%d \n",taskArr[i].taskName,taskArr[i].dueDate.year,taskArr[i].dueDate.month,taskArr[i].dueDate.day);
    }
    nextTask(taskArr,count_lines);

    return 0;


}
    void nextTask(Task arr[],int size)
    {
      for(int i=0; i<size; i++)
      {
          if(arr[i].dueDate.year> 2019)
          {
             printf("Next Task: %s @ %d-%d-%d \n",arr[i].taskName,arr[i].dueDate.year,arr[i].dueDate.month,arr[i].dueDate.day);
             break;
          }
          else if(arr[i].dueDate.year == 2019)
          {
              if(arr[i].dueDate.month>3)
              {
                 printf("Next Task: %s @ %d-%d-%d \n",arr[i].taskName,arr[i].dueDate.year,arr[i].dueDate.month,arr[i].dueDate.day);
                 break;
              }
              else if(arr[i].dueDate.month=3)
              {
                  if(arr[i].dueDate.day>21)
                  {
                    printf("Next Task: %s @ %d-%d-%d \n",arr[i].taskName,arr[i].dueDate.year,arr[i].dueDate.month,arr[i].dueDate.day);
                    break;
                   }
                  }
              }


      }


    }







