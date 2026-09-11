#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "VECTOR_VOID.h"

// دالة تجعل الحرف الأول من كل كلمة داخل النص حرفا كبيرا
void UPPER_ferst_char(char *str)
{
    int  i = 0;

    bool first_char = true;
    while(str[i])
    {
        if(str[i] != ' ' && first_char == true)
        {
            str[i] -= 32; 
        }
        first_char = (str[i] == ' ') ? true : false; 
        i++;
    }
    printf("String after conversion: %s\n",str);
}
void Lower_ferst_char(char *str)
{
    int  i = 0;

    bool first_char = true;
    while(str[i])
    {
        if(str[i] != ' ' && first_char == true)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32; 
            }
        }
        first_char = (str[i] == ' ') ? true : false; 
        i++;
    }
    printf("String after conversion: %s\n",str);
}
// دالة تحول جميع حروف النص المدخل بلا استثناء إلى حروف كبيرة
void UPPER_ALL_WORD(char *str)
{
    int  i = 0;
    while(str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32; 
        }
        i++;
    }
   
}

// دالة تحول جميع حروف النص المدخل بلا استثناء إلى حروف صغيرة
void LOWER_ALL_word(char *str)
{
    int  i = 0;
    while(str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = tolower(str[i]); 
        }
        i++;
    }
}

// دالة تعكس حالة الحرف الواحد الفردي من صغير إلى كبير أو العكس
void IVERT_CHAR_CASE(char *char_t)
{
    if (*char_t >= 'a' && *char_t <= 'z')
        *char_t -= 32;
    else if (*char_t >= 'A' && *char_t <= 'Z')
        *char_t += 32;
}

// دالة تمر على كامل النص وتعكس حالة جميع الحروف الموجودة فيه
void Invert_all_leter(char *str)
{
    for(int  i = 0;str[i];i++)
    {
            IVERT_CHAR_CASE(&str[i]);
    }
}

// دالة تحسب عدد الحروف الكبيرة أو الصغيرة أو الإجمالية بناء على اختيار المستخدم
enum what_to_count {cappital = 0, samll = 1,ALL};
int  count_letters2(char *str, enum what_to_count W)
{
    if(W == ALL)
    {
        return strlen(str);
    }
    int count = 0;
    for(int  i = 0;str[i];i++)
    {
        if((W == samll) &&str[i] >= 'a' && str[i] <= 'z')
        {
            count++;
        }
        if((W == cappital) &&str[i] >= 'A' && str[i] <= 'Z')
        {
            count++;
        }
    }
    return count;
}

// دالة تحسب كم مرة تكرر حرف معين بذاته داخل النص المدخل
int count_charater_in_string(char *str,char c)
{
    int i = 0;
    int count  = 0;
    while(str[i])
    {
        if(str[i] == c)
        {
            count++;
        }
        i++;
    }
    return count;
}

// دالة تحسب تكرار حرف معين مع إمكانية تفعيل أو تجاهل مطابقة حالة الأحرف
int count_any_in_string(char *str,char c,bool Matchcase)
{
    int i = 0;
    int count  = 0;
    int done = 0;
    while(str[i])
    {
        if(Matchcase)
        {
            if(str[i] == c)
            {
                count++;
            }
        }
        else
        {
            if(c >= 'a' && c <= 'z' && (done == 0))
            {
                LOWER_ALL_word(str);
                done++;
            }
            else if(c >= 'A' && c <= 'Z' &&(done == 0))
            {
                UPPER_ALL_WORD(str);
                done++;
            }
            if(str[i] == c)
            {
                count++;
            }
        }
        i++;
    }
    return count;
}

// دالة تفحص حرفا واحدا لتحدد ما إذا كان ينتمي إلى حروف العلة الخمسة أم لا
bool IS_VOWEL(char char_t)
{
    if(char_t >= 'A' && char_t <= 'Z')
    {
        char_t += 32;
    }
   
    return ((char_t == 'a') ||  (char_t == 'e') ||  (char_t == 'i') || (char_t == 'o') || (char_t == 'u')) ? true : false;
}

// دالة تحسب إجمالي عدد حروف العلة المتواجدة داخل النص بالكامل
int count_Vowel_in_string(char *str)
{
    int i = 0;
    int count  = 0;
    while(str[i])
    {
        if(IS_VOWEL(str[i]))
        {
            count++;
        }
        i++;
    }
    return count;
}

// دالة تقوم بطباعة كافة حروف العلة المتواجدة في النص على الشاشة
void print_Vowel_in_string(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(IS_VOWEL(str[i]))
        {
            printf("%c ",str[i]);
        }
        i++;
    }
}

// دالة تبحث عن نص فرعي داخل نص رئيسي وتعيد موقع بداية أول حرف متطابق
int find_str(const char *str, const char *search)
{
    int i = 0;
    if (search[0] == '\0') return 0;

    while (str[i])
    {
        if (str[i] == search[0])
        {
            int j = 0;
            while (search[j] && str[i + j] == search[j])
            {
                j++;
            }
            if (search[j] == '\0')
            {
                return i; 
            }
        }
        i++;
    }
    
    return -1; 
}

// دالة تستخلص الكلمات من النص بناء على الفراغات وتطبع كل كلمة منفردة
void print_WORD(char *str)
{
    char dilim[] = " ";
    int pos = 0;
    int len  = strlen(str);
    char *word = malloc(len + 1 * sizeof(char));
    char *ptr = (char *)str;
    while((pos = find_str(ptr,dilim)) != -1)
    {
        if(pos > 0)
        {
            strncpy(word,ptr,pos);
            word[pos] = '\0';
            printf("%s \n",word);
        }
        ptr = ptr + pos + strlen(dilim); 
    }
    if(ptr[0] != '\0')
    {
        printf("%s",ptr);
    }
    free(word);
}

// دالة تقسم النص الأصلي إلى مصفوفة نصوص ديناميكية بناء على رمز فاصل محدد
name split_string(const char *str, const char *sec, int *count)
{
    name string;

    string.arr = malloc(2 * sizeof(void *));
    string.all_size = 2;
    string.size = 0;

    int pos = 0;
    int len = strlen(str);

    char *word = malloc((len + 1) * sizeof(char));
    const char *ptr = str;

    while ((pos = find_str(ptr, sec)) != -1)
    {
        if (pos > 0)
        {
            strncpy(word, ptr, pos);
            word[pos] = '\0';

            (*count)++;

            char *saved_word = strdup(word);
            VECTOR_PUSH_BACK(&string, saved_word);
        }

        ptr = ptr + pos + strlen(sec);
    }

    if (ptr[0] != '\0')
    {
        strcpy(word, ptr);

        char *saved_word = strdup(word);
        VECTOR_PUSH_BACK(&string, saved_word);

        (*count)++;
    }

    free(word);

    return string;
}

// دالة تفحص الحرف لتبين ما إذا كان مسافة فارغة أو علامة قفز مجدولة
bool is_ispace(char c)
{
    return (c == ' ' ||c == '\t');
}

// دالة تحذف كافة المسافات الفارغة الموجودة في بداية النص من جهة اليسار
char *trim_left(char *str)
{
    char *save = strdup(str);
    char *ptr = (char *)str;
    int i = 0;
    while(str[i] && is_ispace(str[i]))
    {
        i++;
    }
    ptr = ptr + i;
    strcpy(save,ptr);
    return save;
}

// دالة تحذف كافة المسافات الفارغة المتواجدة في نهاية النص من جهة اليمين
char *trim_right(char *str)
{
    char *save = strdup(str);
    int i = strlen(str) - 1;
    while(i >= 0 && is_ispace(str[i]))
    {
        i--;
    }
    save[i + 1] = '\0';
    return save;
}

// دالة تنظف النص تماما عن طريق مسح المسافات من البداية والنهاية معا
char *trim(char *str)
{
    char *left = trim_left(str);
    char *rigt  = trim_right(left);
    free(left);
    return rigt;
}

// دالة تجمع عناصر مصفوفة نصوص ديناميكية في نص واحد متصل بفاصل محدد
char *JOIN_string_VECTOR(name String,char *sec)
{
    if (String.size == 0 || String.arr == NULL) return NULL;
    int total_length = 0;
    for (size_t i = 0; i < String.size; i++) {
        total_length += strlen(String.arr[i]);
    }
    int len_sec = strlen(sec);
    total_length += (String.size - 1) * len_sec + 1;
    char *str = malloc(total_length* sizeof(char));
    if(!str) return NULL;
    str[0] = '\0';
    for(size_t i = 0; i < String.size;i++)
    {
        strcat(str,String.arr[i]);
        if(i + 1 < String.size)
        {
            strcat(str,sec);
        }
    }
    size_t i = 0;
    while(i < String.size)
    {
        free(String.arr[i++]);
    }
    free(String.arr);
    return str;
}

// دالة تجمع عناصر مصفوفة نصوص ثابتة وتنتهي بمؤشر فارغ داخل نص واحد
char *JOIN_string_ARRAY(char **arr,char *sec)
{
    if (arr == 0 || arr[0] == NULL) return NULL;

    int len_word = 0;
    int total_length = 0;
    for (int i = 0;arr[i] != NULL; i++) {
        total_length += strlen(arr[i]);
          len_word++;
    }

    int len_sec = strlen(sec);
    total_length += (len_word - 1) * len_sec + 1;

    char *str = malloc(total_length * sizeof(char));
    if(!str) return NULL;

    str[0] = '\0';
    for(int i = 0; arr[i];i++)
    {
        strcat(str,arr[i]);
        if(i + 1 < len_word)
        {
            strcat(str,sec);
        }
    }
    return str;
}

// دالة تعكس ترتيب الكلمات داخل الجملة النصية لتجعل الكلمة الأخيرة أولا
char *RVERSE_word(char *str)
{
    int len_word = 0;
    if(!str || str[0] == '\0') return NULL;
    char *sec = " ";
    name string = split_string(str,sec,&len_word);
  
    int total = 0;
    for(int i = 0; i < len_word;i++)
    {
        total += strlen(string.arr[i]);
    }
   
    total += 1 + strlen(sec)  * (len_word - 1);
    char *new_str = malloc(total  * sizeof(char));
    if(!new_str) 
    {
        int  i = 0;
        while(i < len_word)
        {
            free(string.arr[i++]);
        }
        return NULL;
    }
   
    new_str[0] = '\0';
    for(int  i = len_word - 1; i >= 0;i--)
    {
        strcat(new_str,string.arr[i]);
        if(i > 0)
        {
            strcat(new_str,sec);
        }
       
    }
    int i = 0;
    while(i < len_word)
    {
        free(string.arr[i++]);
    }
  
    free(string.arr);
    return new_str;
}

// دالة تستبدل كلمة معينة بكلمة أخرى داخل النص مع تجاهل حالة الأحرف تماما
char *REPLACE_word_CUSTOM(char *str,const char *replace,const char *serch)
{
    if((!str || str[0] == '\0') || 
    (!replace || replace[0] == '\0' ) || 
    (!serch || serch[0] == '\0')) 
    return NULL;
    int len_word = 0;
    int replace_len = strlen(replace);
    name string = split_string(str," ",&len_word);

    char *serch_w = malloc((strlen(serch) + 1) * sizeof(char));
    serch_w[0] = '\0';
    strcpy(serch_w,serch);
    LOWER_ALL_word(serch_w);

    for(int i = 0; i < len_word;i++)
    {   char *save = malloc((strlen(string.arr[i]) + 1) * sizeof(char));

        strcpy(save,string.arr[i]);

        LOWER_ALL_word(save);

        if(strcmp(serch_w,save) == 0)
        {
            free(string.arr[i]);
            
            string.arr[i] = malloc((replace_len + 1) * sizeof(char));
            if(string.arr[i])
            {
                strcpy(string.arr[i],replace);
            }
        }
          free(save);
    }
    free(serch_w);
  
    return  JOIN_string_VECTOR(string," ");
}

// دالة تستبدل كلمة بكلمة أخرى داخل النص مع الالتزام والمطابقة التامة لحالة الأحرف
char *REPLACE_word(char *str,char *replace,char *serch)
{
    if((!str || str[0] == '\0') || 
    (!replace || replace[0] == '\0' ) || 
    (!serch || serch[0] == '\0')) 
    return NULL;
    int len_word = 0;

    name string = split_string(str," ",&len_word);

    if(!str || str[0] == '\0') return NULL;

    for(int i = 0; i < len_word;i++)
    {
      
        if(strcmp(serch,string.arr[i]) == 0)
        {
            free(string.arr[i]);

            string.arr[i] = malloc((strlen(replace) + 1) * sizeof(void *));
            if(string.arr[i])
            {
                 strcpy(string.arr[i],replace);
            }
        }
    }
    char *new_str = JOIN_string_VECTOR(string," ");
    return new_str;
}

// دالة تبحث عن علامات الترقيم داخل النص وتقوم بحذفها لتصفية النص تماما
char *REMOVE_puntuation(char *str)
{
    int  i = 0;
    int pos = 0;
    int j = 0;
    while(str[i])
    {
        if(ispunct(str[i]))
        {
            j++;
        }
        i++;
    }
    char *strq = malloc((strlen(str)  + 1  - j) * sizeof(char));
    strq[0] = '\0';
    char *ptr = str;
    i = 0;
    while(str[i])
    {
        if(ispunct(str[i]))
        {
            printf("[%c]\n",str[i]);
            pos = &str[i] - ptr;
            strncat(strq,ptr,pos);
            printf("[%s]\n",ptr);
            ptr =  &str[i] + 1;
           
        }
        i++;
    }
    if(ptr[0] != '\0')
    {
        strcat(strq,ptr);
    }
    return strq;
}