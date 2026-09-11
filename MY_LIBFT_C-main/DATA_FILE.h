#pragma
#include "CONVERT.h"
#include "LIBFT_STRING.h"
//!  save data in file
void SAVE_DATA_TO_FILL()
{
    struct data client;
    FILE *f = fopen("client_data.txt","a");
    if(!f)
    {
        return;
    }
    int chek = 1; 
    do
    {
        Read_data(&client);
        char *str = invert_data(client);
        fprintf(f,"\n%s\n",str);
        free(str);
        free_struct(&client);
        printf("client added Succesfully , do you want to add more clinets\n entre 1 or 0 -->");
        scanf("%d", &chek);
        
        // تنظيف الـ Buffer الخاص بـ stdin لتفادي مشاكل القراءة القادمة
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        
    } while (chek == 1);
    printf("\nAll data saved and file closed successfully.\n");
    fclose(f);
}
//! show data from file
void PRINT_PERSON(struct data *clients_list,int client_count)
{
    printf("\n\t--- PRINTING ALL %d CLIENTS AT ONCE ---\n", client_count);
    for (int i = 0; i < client_count; i++)
    {
        printf("\nClient #%d:", i + 1);
        print_structer(clients_list[i]);
    }
}
void SHOW_DATA()
{
    FILE *f;
    struct data *client_lest = NULL;
    int client_count = 0;
    f = fopen("client_data.txt","r");
    if(!f)
    {
        return;
    }   
    name DATA;
    char str[1000];
    while(fgets(str,sizeof(str),f))
    {
        if(str[0] == '\0' || str[0] == '\n')
        {
            continue;
        }
          struct data *temp = (struct data*)realloc(client_lest,(client_count + 1) * sizeof(struct data));
          if(!temp)
          {
            printf("Memory allocation failed!\n");
          }

        client_lest = temp;
        client_lest[client_count] = invert_structer(str);
        client_count++;
    }
    fclose(f);
    PRINT_PERSON(client_lest,client_count);
    for(int i = 0; i < client_count;i++)
    {
        free_struct(&client_lest[i]);
    }
    free(client_lest);
}