#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "DATA_STRUCTER.h"

// دالة تفحص السنة المعطاة لتحديد ما إذا كانت سنة كبيسة تقبل القسمة على أربعمائة
bool is_leap_year(int year)
{
   return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

// دالة تعيد إجمالي عدد أيام السنة كاملة بناء على كونها كبيسة أو بسيطة
int  Number_day_of_year(int year)
{
    return is_leap_year(year) ? 366:365;
}

// دالة تعيد اسم اليوم المختصر باللغة الإنجليزية بناء على رقمه الترتيبي في الأسبوع
char *DayShort_name(int position_day)
{
    char *arr[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return arr[position_day];
}

// دالة تعيد اسم الشهر المختصر باللغة الإنجليزية بناء على ترتيبه الرقمي من واحد لـ اثني عشر
char *Mont_shortName(int position_month)
{
  char *arr[] = {
    "",          
    "January",   
    "February",  
    "March",     
    "April",     
    "May",       
    "June",      
    "July",      
    "August",    
    "September", 
    "October",   
    "November",  
    "December"   
};
    return arr[position_month];
}

// دالة تحسب بدقة وتحدد ترتيب اليوم من الأسبوع لتاريخ معين معبرا عنه برقم
int  DayOfWeek(int year,int month ,int day)
{
    int a = (14 - month) / 12;
    int y = year - a;
    int m = (month + 12 * a) - 2;
    int d = (day + y + (y / 4) - ( y / 100) + (y / 400) + (31 * m / 12) ) % 7;
   return d;
}

// دالة تحسب عدد الأيام الفعلي لشهر محدد مع مراعاة حالة شهر فبراير في السنوات الكبيسة
int  number_day_of_month(int year,int month)
{
   
    if(month < 0 || month > 12)
    {
        return 0;
    }
    int numberOfDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return (month == 2) ? (is_leap_year(year) ? 29 : 28) : numberOfDay[month - 1];
}

// دالة تطبع شكل تقويم شهر كامل بشكل منظم يوضح توزيع الأيام على الأسابيع
void print_Month_calendar(int month,int year)
{
    
    int number_day_of_monthm = number_day_of_month(year,month - 1);
    int day_position = DayOfWeek(year,month,1);
 
    printf("\n--------------------%s---------------------------\n",Mont_shortName(month));
    printf("sun\tMon\ttue\tWed\tThu\tFri\tSat\n");
    int  j = 0;
    while(j < day_position)
    {
        printf("\t"); j++;
    }         
    for(int i = 1; i <= number_day_of_monthm;i++)
    {   
        printf("%d\t",i);
       j++;
       if(j  == 7)
       {
        printf("\n"); j = 0;
       } 
    }
    printf("\n------------------------------------------------\n");
}

// دالة تطبع تقويم سنة كاملة متسلسلة لجميع الشهور الاثني عشر خلف بعضها
void print_year_calender(int year)
{
    printf("-------------------------------\n");
    printf("         Calendare  - %d         \n",year);
    printf("-------------------------------\n");
    for(int  month = 1; month <= 12;month++)
    {
        print_Month_calendar(month,year);
    }
}

// دالة تحسب عدد الأيام الإجمالي التي مرت من بداية السنة وحتى الوصول للتاريخ الحالي
int Number_Of_days_From_Th_eBegining_Of_TheYEar(int year,int month,int day)
{
    int beginning = 0;
    for(int  i = 1; i < month;i++)
    {
     
        beginning += number_day_of_month(year,i);
        
    }
    beginning += day;
    return beginning ;
}

// دالة تحول عدد أيام منقضية معطاة إلى تاريخ محدد متمثل في يوم وشهر وسنة
struct Date Date_Frome_Day_Order_InA_aYear(int debiginin,int year)
{

    struct Date date;
    date.year = year;
    date.month  = 1;
    while(true)
    {
        int mont_year = number_day_of_month(year,date.month);
        if(debiginin > mont_year)
        {
            debiginin -= mont_year;
            date.month++;
        }
        else 
        {
            date.day = debiginin;
            break;
        }
    }
    return date;
}

// دالة تفحص وتقارن لتبين ما إذا كان التاريخ الأول يأتي زمنيا قبل التاريخ الثاني
bool IsDate1Beforedate2(struct Date date1, struct Date date2)
{
   return (date1.year < date2.year) ? true : ((date1.year ==
date2.year) ? (date1.month < date2.month ? true : (date1.month ==
date2.month ? date1.day < date2.day : false)) : false);
}

// دالة تفحص تاريخين لتحديد ما إذا كانا متطابقين تماما في اليوم والشهر والسنة
bool  IsDate1EqulDate2(struct Date date1 ,struct Date date2) 
{
    return ((date1.year == date2.year) && (date1.month == date2.month) && (date1.day == date2.day));
}

// دالة تفحص وتحدد ما إذا كان اليوم الحالي هو اليوم الأخير في شهره
bool is_last_day(struct Date date)
{
    return (date.day == number_day_of_month(date.year,date.month)) ? true : false;
}

// دالة تفحص وتحدد ما إذا كان الشهر الحالي هو الشهر الأخير في السنة
bool is_last_mont(struct Date date)
{
    return (date.month == 12) ? true : false;
}

// دالة تجلب تاريخ نظام التشغيل الحالي وتخزنه داخل بنية التاريخ المخصصة
struct Date get_sestem_date()
{
    time_t t = time(0);

    struct tm  *gtmt = gmtime(&t)  ;
    struct Date dat2;
    dat2.year = gtmt->tm_year + 1900;
    dat2.month = gtmt->tm_mon + 1;
    dat2.day = gtmt->tm_mday;
    return dat2;
}

// دالة تضيف عددا معطى من الأيام إلى التاريخ لتقوم بحساب التاريخ الجديد الناتج
struct Date Many_days_to_add(int number_add,struct Date date)
{
   
    int RemainugDay = number_add + Number_Of_days_From_Th_eBegining_Of_TheYEar(date.year,date.month,date.day);
     date.month = 1;
    while(true)
    {
       
        int montDay = number_day_of_month(date.year,date.month);
        if(RemainugDay > montDay)
        {
            RemainugDay -= montDay;
            date.month++;
        if(date.month > 12)
        {
            date.month = 1;
            date.year++;
        }
        }
        else 
        {
            date.day = RemainugDay;
            break;
        }
        
    }
    return date;
}

// دالة تبادلية تقوم بتبديل القيم المخزنة بين تاريخين مختلفين عن طريق المؤشرات
void swap_date(struct Date *date1,struct Date *date2)
{
    struct  Date TempDate;
   
    TempDate.year = date1->year;
    TempDate.month = date1->month;
    TempDate.day = date1->day;

    date1->year = date2->year;
    date1->month = date2->month;
    date1->day = date2->day;

    date2->year = TempDate.year;
    date2->month = TempDate.month;
    date2->day = TempDate.day;
}

// دالة تزيد التاريخ بمقدار يوم واحد فقط مع الانتقال التلقائي للشهور والسنوات
struct Date increase_date_by_one_day(struct Date date)
{
    if(is_last_day(date))
    {
        if(is_last_mont(date))
        {
            date.month = 1;
            date.year++;
        }
        else{
            date.month++;
        }
       date.day = 1;
    }
    else{
        date.day++;
    }
    return date;
}

// دالة تحسب الفارق الإجمالي بالأيام بين تاريخين مع خيار احتساب اليوم الأخير أو تجاهله
int calcule_diffrence(struct Date date1,struct Date date2,bool IncludeEndDay)
{
    int day = 0;
    int s = 1;
    if(!IsDate1Beforedate2(date1,date2))
    {
        swap_date(&date1,&date2);
        s = -1;
    }
    while(IsDate1Beforedate2(date1,date2))
    {
        day++;
        date1 = increase_date_by_one_day(date1);
    }
  
    return (IncludeEndDay)? ++day * s : day * s;
}

// دالة تعيد الترتيب الرقمي لليوم في الأسبوع بناء على مؤشر لبنية التاريخ
int dayOfweek_NEW(struct Date *date)
{
    return  DayOfWeek(date->year,date->month,date->day);;
}

// دالة تفحص ما إذا كان التاريخ المدخل يوافق آخر يوم في الأسبوع وهو السبت
bool Is_End_Of_Week(struct Date date)
{
    return dayOfweek_NEW(&date) == 6;
}

// دالة تفحص وتحدد ما إذا كان التاريخ يقع ضمن عطلة نهاية الأسبوع الجمعة أو السبت
bool Is_WeekEnd(struct Date date)
{
    int position = dayOfweek_NEW(&date);
    return (position == 5 || position == 6);
}

// دالة تفحص وتؤكد ما إذا كان اليوم المعطى هو يوم عمل رسمي وليس عطلة أسبوعية
bool Is_business_Day(struct Date date)
{ 
    return !Is_WeekEnd(date) ;
}

// دالة تحسب عدد الأيام المتبقية من التاريخ الحالي وحتى بلوغ نهاية الأسبوع الحالي
int Days_Untill_end_of_week(struct Date date)
{
    return 6 - dayOfweek_NEW(&date);
}

// دالة تحسب عدد الأيام المتبقية من التاريخ الحالي وحتى الوصول لآخر يوم في الشهر
int Days_Untill_end_of_month(struct Date date)
{
    struct Date date2;
    date2.day = number_day_of_month(date.year,date.month);
    date2.month = date.month;
    date2.year = date.year;
    return  calcule_diffrence(date,date2,true);
}

// دالة تحسب عدد الأيام المتبقية من التاريخ الحالي وحتى انتهاء السنة الحالية بالكامل
int Days_Untill_end_of_year(struct Date date)
{
    struct Date date2;
    date2.day = 31;
    date2.month = 12;
    date2.year = date.year;
    return calcule_diffrence(date,date2,true);
}

// دالة تحسب تاريخ العودة الفعلي من الإجازة مع تمديدها تلقائيا في حال صادفت عطلات
struct Date calcule_vacation_return_date(int Vacation,struct Date date)
{
   
    while(Vacation > 0)
    {
        
        if(Is_WeekEnd(date))
        {
           Vacation++;
        }
        date = increase_date_by_one_day(date);
        Vacation--;
    }
    return date;
}

// دالة تحسب عدد أيام الإجازة الفعلية المستهلكة بين تاريخين مستبعدة عطلات نهاية الأسبوع
int calcule_actual_vocation_day(struct Date date1, struct Date date2)
{
    int day = 0;
    while(IsDate1Beforedate2(date1,date2))
    {
        if(!Is_WeekEnd(date1))
        {
            day++;
        }
        date1 = increase_date_by_one_day(date1);
    }
    return  day;
}

// دالة تفحص وتقارن لتبين ما إذا كان التاريخ الأول يأتي زمنيا بعد التاريخ الثاني
bool is_date1_after_date2(struct Date date1, struct Date date2)
{
    return (!IsDate1Beforedate2(date1,date2),!IsDate1EqulDate2(date1,date2));
}

// دالة تقارن بين تاريخين وتعيد حالة المقارنة سواء كانت قبل أو بعد أو تساوي
enum enumDateComare {Before = -1 , Equal = 0, After = 1};
int Compare_dates(struct Date date1,struct Date date2)
{
    return (IsDate1Beforedate2(date1,date2) ? Before : IsDate1EqulDate2(date1,date2) ? Equal : After);
}

// دالة تفحص فترتين زمنيتين وتحدد ما إذا كان بينهما أي تداخل أو تقاطع في الأيام
bool is_overlap(struct Period per1, struct Period per2)
{
    if(
        Compare_dates(per2.dateEnd,per1.dateStart) == Before 
        ||
        Compare_dates(per2.dateStart,per1.dateEnd) == After
    )
    return false;
    else 
    {
        return true;
    }
}

// دالة تحسب طول الفترة الزمنية الإجمالي بالأيام مع إمكانية تضمين تاريخ النهاية
int Period_leng_thInDays(struct Period per,bool IncludeEndDate)
{
    return calcule_diffrence(per.dateStart,per.dateEnd,IncludeEndDate);
}

// دالة تفحص وتؤكد ما إذا كان تاريخ معين يقع داخل نطاق وحدود فترة زمنية محددة
bool Is_within(struct Period per,struct Date date)
{
    return !(Compare_dates(date,per.dateStart) == Before
    ||
     Compare_dates(date,per.dateEnd) ==  After);
}





