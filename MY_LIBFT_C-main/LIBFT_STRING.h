#ifndef LIBFT
#define LIBFT

#include <stdbool.h>
#include "VECTOR_VOID.h"

/* 
   تحديد نوع الحروف التي نريد حسابها:
   cappital = الحروف الكبيرة
   samll    = الحروف الصغيرة
   ALL      = جميع الحروف
*/
enum what_to_count
{
    cappital = 0,
    samll = 1,
    ALL
};


/* ==================== تحويل حالة الحروف ==================== */

/* تجعل الحرف الأول من كل كلمة حرفاً كبيراً */
void UPPER_ferst_char(char *str);
void Lower_ferst_char(char *str);
/* تحول جميع الحروف في النص إلى حروف كبيرة */
void UPPER_ALL_WORD(char *str);

/* تحول جميع الحروف في النص إلى حروف صغيرة */
void LOWER_ALL_word(char *str);

/* تعكس حالة حرف واحد:
   الحرف الكبير يصبح صغيراً والصغير يصبح كبيراً */
void IVERT_CHAR_CASE(char *char_t);

/* تعكس حالة جميع الحروف الموجودة في النص */
void Invert_all_leter(char *str);


/* ==================== حساب الحروف ==================== */

/* تحسب عدد الحروف:
   - الكبيرة
   - الصغيرة
   - أو جميع الحروف
   حسب الاختيار W */
int count_letters2(char *str, enum what_to_count W);

/* تحسب عدد مرات ظهور حرف معين داخل النص */
int count_charater_in_string(char *str, char c);

/* تحسب عدد مرات ظهور حرف معين،
   مع إمكانية تجاهل حالة الحرف */
int count_any_in_string(char *str, char c, bool Matchcase);


/* ==================== حروف العلة Vowels ==================== */

/* تتحقق هل الحرف من حروف العلة:
   a, e, i, o, u */
bool IS_VOWEL(char char_t);

/* تحسب العدد الإجمالي لحروف العلة داخل النص */
int count_Vowel_in_string(char *str);

/* تطبع جميع حروف العلة الموجودة داخل النص */
void print_Vowel_in_string(char *str);


/* ==================== البحث والتقسيم ==================== */

/* تبحث عن نص فرعي داخل نص آخر،
   وتعيد موقع أول تطابق */
int find_str(const char *str, const char *search);

/* تقسم النص إلى كلمات باستخدام المسافة
   ثم تطبع كل كلمة لوحدها */
void print_WORD(char *str);

/* تقسم النص إلى أجزاء حسب Separator معين
   وتعيد الأجزاء داخل name (Dynamic Array)
   وتضع عدد الأجزاء في count */
name split_string(const char *str, const char *sec, int *count);


/* ==================== التعامل مع المسافات ==================== */

/* تتحقق هل الحرف مسافة ' ' أو Tab '\t' */
bool is_ispace(char c);

/* تحذف المسافات من بداية النص */
char *trim_left(char *str);

/* تحذف المسافات من نهاية النص */
char *trim_right(char *str);

/* تحذف المسافات من بداية ونهاية النص */
char *trim(char *str);


/* ==================== دمج النصوص ==================== */

/* تجمع عناصر name في String واحد
   وتضع Separator بين كل عنصر */
char *JOIN_string_VECTOR(name String, char *sec);

/* تجمع عناصر Array من Strings في String واحد
   وتضع Separator بين العناصر */
char *JOIN_string_ARRAY(char **arr, char *sec);


/* ==================== عكس الكلمات ==================== */

/* تعكس ترتيب الكلمات داخل النص:
   "Hello World" -> "World Hello" */
char *RVERSE_word(char *str);


/* ==================== استبدال الكلمات ==================== */

/* تستبدل كلمة بكلمة أخرى مع تجاهل حالة الأحرف:
   hello = HELLO = Hello */
char *REPLACE_word_CUSTOM(char *str, const char *replace, const char *serch);

/* تستبدل كلمة بكلمة أخرى مع المطابقة التامة لحالة الأحرف */
char *REPLACE_word(char *str, char *replace, char *serch);


/* ==================== علامات الترقيم ==================== */

/* تحذف علامات الترقيم من النص:
   "Hello, World!" -> "Hello World" */
char *REMOVE_puntuation(char *str);


#endif