#pragma once
#include "LIBFT_STRING.h"
#include <stdlib.h>
//! ========================================================
//! اولا كبيره مكتبة ادارة بيانات العملاء وتحويلها الى نصوص
//! ========================================================

//? هيكل بيانات مخصص لتخزين معلومات الحساب البنكي الخاص بالعميل
struct data
{
    char *acount_number;
    char *PIN_cod;
    char *name;
    char *phone;
    double AccountBalance;
};

//? دالة مخصصة لطباعة جميع تفاصيل بيانات العميل بشكل منظم على الشاشة
void print_structer(struct data client)
{
    printf("\n====================================");
    printf("\n         CLIENT DETAILS             ");
    printf("\n====================================");
    
    printf("\nAccount Number  : %s", client.acount_number);
    printf("\nPIN Code        : %s", client.PIN_cod);
    printf("\nName            : %s", client.name);
    printf("\nPhone           : %s", client.phone);
    
    printf("\nAccount Balance : %.2lf", client.AccountBalance);

    printf("\n====================================\n");
}

//? دالة تقوم بقراءة نص من المستخدم مع حجز الذاكرة ديناميكيا وتنظيف سطر الادخال
char *ReadString(char *string)
{
   char *str = (char *)malloc(100 * sizeof(char));
   if(!str) return NULL;
   if(string) printf("%s", string);
   fgets(str,100,stdin);
   int len =  strlen(str);
   if(len > 0 && str[len - 1] == '\n')
   {
    str[len - 1] = '\0';
    len--;
   }
    char *temp = (char *)realloc(str, (len + 1) * sizeof(char));
   if(temp) 
   {
       str = temp;
   }
   
   return str;
}

//? دالة لتعبئة بيانات العميل بالكامل من خلال استقبال المدخلات من المستخدم
void Read_data(struct data *client)
{
    client->acount_number = ReadString("Enter Account Number?---> ");
    client->PIN_cod       = ReadString("Enter PIN CODE?      ---> ");
    client->name          = ReadString("Enter Name?          ---> ");
    client->phone         = ReadString("Enter Phone?         ---> ");
    char *temp_balance = ReadString("Enter Account Balance?---> ");
    
    if (temp_balance)
    {
        client->AccountBalance = atof(temp_balance); 
        free(temp_balance); 
    }

    printf("\nDONE<:\n");
}

//? دالة تحول بيانات العميل من هيكل البيانات الى سطر نصي واحد يفصل بين المتغيرات رمز معين
char *invert_data(struct data client)
{
    char *str_accountbalance = (char *)malloc(20 * sizeof(char));
    if (!str_accountbalance) return NULL;
    sprintf(str_accountbalance,"%f",client.AccountBalance);
    char *arr[] = {client.acount_number,client.PIN_cod,client.name,client.phone,str_accountbalance,NULL};
    char *str = JOIN_string_ARRAY(arr,"#//#");
    free(str_accountbalance);
    return str;
}

//? دالة تقوم بتحرير وتفريغ الذاكرة المحجوزة لجميع نصوص بيانات العميل لحماية الذاكرة
void free_struct(struct data *client)
{
    free(client->acount_number);
    free(client->PIN_cod);
    free(client->name);
    free(client->phone);
}

//? دالة عكسية تحول السطر النصي المفصل برمز الى هيكل بيانات العميل وتوزع الكلمات عليه
struct data invert_structer(char *str)
{
    struct data client;
    int count_word = 0;
    name DATA = split_string(str,"#//#",&count_word);
    client.acount_number = strdup((char*)DATA.arr[0]);
    client.PIN_cod = strdup((char *)DATA.arr[1]);
    client.name = strdup((char *)DATA.arr[2]);
    client.phone  = strdup((char *)DATA.arr[3]);
    client.AccountBalance = atof((char *)DATA.arr[4]);
    for(int i = 0; i < count_word; i++) {
        free(DATA.arr[i]);
    }
    free(DATA.arr);
    return client;
}