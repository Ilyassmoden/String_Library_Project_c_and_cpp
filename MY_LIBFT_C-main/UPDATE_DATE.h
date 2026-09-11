#pragma once
#include "LIBFT_TIME.h"

//? دالة تزيد التاريخ المعطى بمقدار عشرة أيام كاملة عبر التكرار المتتابع
struct Date increase_date_by_X_day(struct Date date)
{
    for(int  i = 0;i < 10;i++)
    {
        date = increase_date_by_one_day(date);
    }
    return date;
}

//?دالة تزيد التاريخ المعطى بمقدار أسبوع واحد كامل أي سبعة أيام
struct Date increase_date_by_one_week(struct Date date)
{
    for(int  i = 0;i < 7;i++)
    {
        date = increase_date_by_one_day(date);
    }
    return date;
}

//? دالة تزيد التاريخ المعطى بمقدار عشرة أسابيع كاملة متتالية
struct Date increase_date_by_X_week(struct Date date)
{
    for(int  i = 0; i < 10;i++)
    {
        date = increase_date_by_one_week(date);
    }
    return date;
}

//? دالة تزيد التاريخ بمقدار شهر واحد كامل مع المحافظة على توافق الأيام وصحتها
struct Date increase_date_by_ONE_Month(struct Date date)
{
    int number_day_of_mont = number_day_of_month(date.year,date.month);
    if(date.day > number_day_of_mont)
    {
        date.day  = number_day_of_mont;
    }
   return Many_days_to_add(number_day_of_mont,date);
}

// دالة تزيد التاريخ المعطى بمقدار خمسة أشهر كاملة متلاحقة
struct Date increase_date_by_5_month(struct Date date)
{
    for(int i = 0 ;i < 5;i++)
    {
        date =  increase_date_by_ONE_Month(date);
    }
   return date;
}

// دالة تزيد التاريخ المعطى بمقدار سنة واحدة كاملة عن طريق تقديم رقم العام
struct Date increase_date_by_one_year(struct Date date)
{
   date.year++;
   return date;
}

// دالة تزيد التاريخ بمقدار عشر سنوات عبر تكرار زيادة السنوات الفردية
struct Date increase_date_by_X_year(struct Date date)
{
    for(int i = 0;i < 10;i++)
    {
        date = increase_date_by_one_year(date);
    }
    return date;
}

// دالة تزيد التاريخ بمقدار عشر سنوات بشكل رياضي مباشر وسريع للغاية
struct Date increase_date_by_X_year_faster(struct Date date)
{
   date.year += 10;
   return date;
}

// دالة تزيد التاريخ بمقدار عقد زمني كامل وهو ما يعادل عشر سنوات مباشرة
struct Date increase_date_by_Decade(struct Date date)
{
   date.year += 10;
   return date;
}

// دالة تزيد التاريخ بمقدار مئة عام كاملة عبر تكرار حلقات الزيادة السنوية
struct Date increase_date_by_X_Decade(struct Date date)
{
    int i = 0;
    while(i < 100)
    {
        date = increase_date_by_one_year(date);
        i++;
    }
    return date;
}

// دالة تزيد التاريخ بمقدار مئة عام كاملة بشكل رياضي مباشر وفوري
struct Date increase_date_by_X_Decade_faster(struct Date date)
{
    date.year += 10 * 10;
    return date ;
}

// دالة تزيد التاريخ بمقدار قرن كامل أي مئة عام مباشرة على خانة السنوات
struct Date increase_date_by_Century(struct Date date)
{
    date.year += 100;
   return date;
}

// دالة تزيد التاريخ بمقدار ألفية كاملة أي ألف عام مباشرة دفعة واحدة
struct Date increase_date_by_ONE_millennium(struct Date date)
{
    date.year += 1000;
   return date; 
}

// دالة تنقص من التاريخ يوما واحدا مع معالجة الانتقال العكسي بين الشهور والسنوات
struct Date Subtracting_date_by_one_day(struct Date date)
{
    int befor_month = 0;
    if(date.month == 1 && date.day == 1)
    {
        date.month = 12;
        date.year--;
        befor_month = 12;
        
        date.day = 31;
        return date;
    }
    else if(date.day == 1)
    {
        date.month--;
        
        date.day =  number_day_of_month(date.year,date.month);;
        return date;
    }
    date.day--;
    return date;
}

// دالة تنقص من التاريخ المعطى عشرة أيام كاملة متتالية عبر التكرار
struct Date Subtracting_date_by_X_day(struct Date date)
{
    for(int  i = 0;i < 10;i++)
    {
        date = Subtracting_date_by_one_day(date);
    }
    return date;
}

// دالة تنقص من التاريخ المعطى أسبوعا واحدا كاملا أي سبعة أيام
struct Date Subtracting_date_by_one_week(struct Date date)
{
    for(int  i = 0;i < 7;i++)
    {
        date = Subtracting_date_by_one_day(date);
    }
    return  date;
}

// دالة تنقص من التاريخ المعطى عشرة أسابيع كاملة متتالية عبر الحلقات
struct Date Subtracting_date_by_X_week(struct Date date)
{
    for(int  i = 0; i < 10 * 7;i++)
    {
        date = Subtracting_date_by_one_day(date);
    }
    return date;
}

// دالة تنقص من التاريخ شهرا واحدا كاملا مع ضبط توازن الأيام والسنوات عكسيا
struct Date Subtracting_date_by_ONE_Month(struct Date date)
{
    int number_day_of_mont = number_day_of_month(date.year,date.month);

    if(date.day > number_day_of_mont)
    {
        date.day  = number_day_of_mont;
    }
    if(date.month == 1)
    {
        date.month = 12;
        date.year--;
    }
    else 
    {
         date.month--;
    }
   return date;
}

// دالة تنقص من التاريخ المعطى خمسة شهور كاملة متلاحقة
struct Date Subtracting_date_by_5_month(struct Date date)
{
    for(int i = 0 ;i < 5;i++)
    {
        date =  Subtracting_date_by_ONE_Month(date);
    }
   return date;
}

// دالة تنقص من التاريخ سنة واحدة كاملة مع حماية وضمان سلامة السنوات الكبيسة
struct Date Subtracting_date_by_one_year(struct Date date)
{
    if(date.month == 2 && date.day == 29 && is_leap_year(date.year))
    {
        date.year--;
        date.day--;
    }
   return date;
}

// دالة تنقص من التاريخ عشر سنوات كاملة عبر الحلقات المتكررة للسنوات
struct Date Subtracting_date_by_X_year(struct Date date)
{
    for(int i = 0;i < 10;i++)
    {
        date = Subtracting_date_by_one_year(date);
    }
    return date;
}

// دالة تنقص من التاريخ عشر سنوات كاملة بشكل حسابي مباشر وفوري
struct Date Subtracting_date_by_X_year_faster(struct Date date)
{
   date.year -= 10;
   return date;
}

// دالة تنقص من التاريخ عقدا زمنيا كاملا أي عشر سنوات مباشرة من خانة السنين
struct Date Subtracting_date_by_Decade(struct Date date)
{
   date.year -= 10;
   return date;
}

// دالة تنقص من التاريخ مئة عام كاملة عبر تكرار إنقاص السنوات الفردية
struct Date Subtracting_date_by_X_Decade(struct Date date)
{
    int i = 0;
    while(i < 100)
    {
        date = Subtracting_date_by_one_year(date);
        i++;
    }
    return date;
}

// دالة تنقص من التاريخ مئة عام كاملة بشكل رياضي مباشر وسريع للغاية
struct Date Subtracting_date_by_X_Decade_faster(struct Date date)
{
    date.year -= 10 * 10;
    return date ;
}

// دالة تنقص من التاريخ قرنا كاملا أي مئة عام مباشرة من قيمة السنوات
struct Date Subtracting_date_by_Century(struct Date date)
{
    date.year -= 100;
   return date;
}

// دالة تنقص من التاريخ ألفية كاملة أي ألف عام مباشرة دفعة واحدة
struct Date Subtracting_date_by_ONE_millennium(struct Date date)
{
    date.year -= 1000;
   return date; 
}
