#pragma once
#include <windows.h>
void add_new_in_file(struct data *person,int n)
{
    FILE *f = fopen("student_data.bin","ab+");
    if(f == NULL)
    {
        perror("Error opening file");
        return;
    }
    fwrite(person,sizeof(struct data),n,f);
    rewind(f);
    fclose(f);
    printf("Data saved successfully!\n");
}

void read_fill(struct data *person,int n)
{
    FILE *f = fopen("student_data.bin","rb+");
    if(f == NULL)
    {
        printf(RED"SORY file is NULL"RESET);
        return;
    }
    int i = 0;
    while(i < n && fread(&person[i],sizeof(struct data),1,f) == 1)
    {
        i++;
    }
    rewind(f);
    fclose(f);
}
