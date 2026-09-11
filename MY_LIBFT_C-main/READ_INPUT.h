#pragma once
#include "LIBFT_TIME.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"      
#define GREEN   "\033[32m"      
#define YELLOW  "\033[33m"      
#define BLUE    "\033[34m"      
#define MAGENTA "\033[35m"      
#define CYAN    "\033[36m"      
#define BOLD    "\033[1m"       

// دالة تقرأ اسما وتتحقق من طوله وتمنع قبول الأحرف غير الصالحة أو الرموز الغريبة
void chek_printble(char name[50])
{
    int i = 0;
     int is_valid;
    do {
         is_valid = 1;
        if (scanf(" %[^\n]99",name) == EOF) break;
        i = 0;
    while(name[i])
    {
        int len = strlen(name);
        if(len > 50)
        {
            printf(RED"Sorry , we cant't accept this name,can you return is\n"RESET);
        }
        else if(!((name[i] >= 'a' && name[i] <= 'z' ) || (name[i] >= 'A' && name[i]  <= 'Z' ) || name[i] == ' '))
        {
            printf(RED"Sorry , we cant't accept this name,can you return is\n"RESET);
            is_valid = 0;
            break;
        }
        i++;
    }
    if(!is_valid)
    {
        printf(YELLOW"please try again.! '\n"RESET);
    }
    }while(!is_valid);
}

// دالة تجبر المستخدم على كتابة عدد صحيح موجب فقط وترفض المدخلات النصية الخاطئة
int read_positive_number_int(char *string)
{
    int number =  0;
    do
    {
        int c;
        printf(" %s ",string); 
        if(scanf("%d",&number) != 1)
        {
            printf(RED"error number entr number positve\n"RESET);
            while((c = getchar()) != '\n' && c != EOF);
            number = -1; 
            continue;
        }
        if(((c = getchar()) != '\n' && c != EOF) == 1) number = -1;  
        if(number <= -1)
        {
            printf(RED"error number entr number positve\n"RESET);
        }
    }while (number <= -1);
    
 return number;   
}

// دالة تقرأ رقما وتجبر المستخدم على الالتزام بنطاق محدد بين قيمتين صغرى وعظمى
void chek_number_froom(int *many_round,int from,int to,char *string)
{
      do
     {
        *many_round = read_positive_number_int(string);
        if(*many_round < from || *many_round > to)
        {
            printf(RED"\nSoory entre 1 to 10\n"RESET);
            continue;
        }
      else
      {
        break;
      }
  }while (1);
}

// دالة تقرأ عناصر التاريخ الثلاثة بالكامل من المستخدم بشكل تتابعي مدقق وآمن
void Read_struct_date(struct Date *date)
{
    date->year = read_positive_number_int("plese entre a year-->");
    date->month = read_positive_number_int("please entre a Month-->");
    date->day = read_positive_number_int("pleas ente a day-->");
}

// دالة تقرأ تاريخ البداية وتاريخ النهاية بالكامل لتكوين وحفظ فترة زمنية مستقرة
void Read_period(struct Period *per)
{
    printf("entre start date\n");
    Read_struct_date(&per->dateStart);
    printf("entre end  date \n");
    Read_struct_date(&per->dateEnd);
}