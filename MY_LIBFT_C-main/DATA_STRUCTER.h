#pragma once

// بنية مخصصة لتخزين التاريخ متمثلا في أرقام اليوم والشهر والسنة
struct Date
{
    int year;
    int month;
    int day;
};

// بنية لتخزين فترة زمنية محددة تعتمد على تاريخ بداية وتاريخ نهاية
struct Period 
{
    struct Date dateStart;
    struct Date dateEnd;
};