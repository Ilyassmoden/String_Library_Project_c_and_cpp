#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
extern "C" {
   #include "MY_LIBFT_C-main/LIBFT_STRING.h"
}
using namespace std;
class clsString
{
    class clsLtter
    {
    public:
        static void Convert_first_in_Upper1(string &str)
        {
            
            int len  = str.length();
            char *str2 = new char[len + 1];
            strcpy(str2,str.c_str());
            UPPER_ferst_char(str2);
            str = str2;
            delete[] str2;
        }
        static void Convert_first_letter_inWord_Lower1(string &str)
        {
            int len  = str.length();
            char *str2 = new char[len + 1];
            strcpy(str2,str.c_str());
            Lower_ferst_char(str2);
            str = str2;
            delete[] str2;
        }
        static int count_letters22(string &str)
        {
            int len  = str.length();
            char *str2 = new char[len + 1];
            strcpy(str2,str.c_str());
            int count  = count_letters2(str2,ALL);
            delete[] str2;
            return count;
        }
        static int Coun_frequency_of_a_specific_letter1(string &str,char c)
        {
            int len  = str.length();
            char *str2 = new char[len + 1];
            strcpy(str2,str.c_str());
            int count  = count_charater_in_string(str2,c);
            delete[] str2;
            return count;
        }
        static void invert_all_letter(string &str)
        {
            int len  = str.length();
            char *str2 = new char[len + 1];
            strcpy(str2,str.c_str());
            Invert_all_leter(str2);
            delete[] str2;
        }
        static void pint_Vowel1(string str)
        {
            int len  = str.length();
            char *str2 = new char[len + 1];
            strcpy(str2,str.c_str());
            print_Vowel_in_string(str2);
            delete[] str2;
        }
        static short count_Vowel1(string &str)
        {
            int len  = str.length();
            char *str2 = new char[len + 1];
            strcpy(str2,str.c_str());
            short count  = count_Vowel_in_string(str2);
            delete[] str2;
            return count;
        }
    };
    class clsWord
    {
    public:
        static void print_word(string str)
        {
            int len  = str.length();
            char *str2 = new char[len + 1];
            strcpy(str2,str.c_str());
            print_WORD(str2);
            delete[]  str2;
        }
        static int contWord1(string str)
        {
            int count = 0;
            split_string(str.c_str()," ",&count);
            return count;
        }
        static void delete_space_end_start1(string str)
        {
            int len  = str.length();
            char *str2 = new char[len + 1];
            strcpy(str2,str.c_str());
            trim(str2);
            delete[] str2;
        }
        static string Join_string(string *str,int len)
        {
           
            char **str2 = new char*[len + 1];
            for(int i = 0;i < len;i++)
            {
                str2[i] = new char[str[i].length() + 1];
                strcpy(str2[i],str[i].c_str());
            }
            char j[] = "/##/";
            str2[len] = NULL;
            return JOIN_string_ARRAY(str2,j);
        }
        static string revers_word(string str)
        {
            size_t len  = str.length();
            char *str2 = new char[len + 1];
            strcpy(str2,str.c_str());
            str =   RVERSE_word(str2);
            delete[] str2;
            return str;
        }
        static string repalce_word(string str,string serch,string replace)
        {
            size_t len  = str.length();
            char *str2 = new char[len + 1];
            strcpy(str2,str.c_str());
            str =   REPLACE_word_CUSTOM(str2,replace.c_str(),serch.c_str());
            delete[] str2;
            return str;
        }   
        static void remove_puntuation(string str)
        {
            size_t len  = str.length();
            char *str2 = new char[len + 1];
            strcpy(str2,str.c_str());
            str =   REMOVE_puntuation(str2);
            delete[] str2;
        }
        static string *Splite_Word(string str,int &size2)
        {
            size_t len  = str.length();
            char *str2 = new char[len + 1];
            strcpy(str2,str.c_str());
            int size  = 0;
            name str3 =  split_string(str2," ",&size);
            string *stringss =  new string[size + 1];
            int i = 0;
            while(i < size)
            {
                stringss[i] = (char *)str3.arr[i];
                i++;
            }
            size2 = size;
            return stringss;
        }
    };
    string _Value;
public:
    
    
    clsString()
    {
        _Value = "";
    }
    clsString(string Value)
    {
        _Value = Value;
    }
    void SetValue(string Value) {
        _Value = Value;
    }
    string GetValue() {
        return _Value;
    }
                    //---->letter<-----//

    ///-->Convirting<--

    void Convert_first_letter_inWord_uper()
    {
       clsString::clsLtter::Convert_first_in_Upper1(_Value);
    }
    void Convert_first_letter_inWord_uper(string str)
    {
       clsString::clsLtter::Convert_first_in_Upper1(str);
    }
    void Convet_first_letter_in_Word_lower()
    {
        clsString::clsLtter::Convert_first_letter_inWord_Lower1(_Value);
    }
    void Convet_first_letter_in_Word_lower(string V)
    {
        clsString::clsLtter::Convert_first_letter_inWord_Lower1(V);
    }
    //-->count_letter<--

    int count_letter()
    {
        return clsString::clsLtter::count_letters22(_Value);
    }
    int count_letter(string str)
    {
       return clsString::clsLtter::count_letters22(str);
    }
    int Count_frequency_of_a_specific_letter(char c)
    {
        return clsString::clsLtter::Coun_frequency_of_a_specific_letter1(_Value,c);
    }
    int Coun_frequency_of_a_specific_letter(string str,char c)
    {
         return clsString::clsLtter::Coun_frequency_of_a_specific_letter1(str,c);
    }
    //-->invert_letter<--

    void invert_all_letter()
    {
        clsString::clsLtter::invert_all_letter(_Value);
    }
    void invert_all_letter(string str)
    {
        clsString::clsLtter::invert_all_letter(str);
    }
    //chek_vowle and print

    bool IS_VOWEL1(char c)
    {
        return IS_VOWEL(c);
    }
    short count_VOWEL()
    {
        return clsString::clsLtter::count_Vowel1(_Value);
    }
    short count_VOWEL(string str)
    {
        return clsString::clsLtter::count_Vowel1(str);
    }
    void Print_vowels_from_string()
    {
        clsString::clsLtter::pint_Vowel1(_Value);
    }
    void Print_vowels_from_string(string str)
    {
        clsString::clsLtter::pint_Vowel1(str);
    }
                    //----->WORD<-----//

    //print_word

    void printWord()
    {
        clsString::clsWord::print_word(_Value);
    }
    void printWord(string str)
    {
        clsString::clsWord::print_word(str);
    }
    //count word

    int contWord()
    {
        return clsString::clsWord::contWord1(_Value);
    }
    int contWord(string str)
    {
        return clsString::clsWord::contWord1(str);
    }
    //delete_space

    void delete_space_end_start()
    {
        clsString::clsWord::delete_space_end_start1(_Value);
    }
    void delete_space_end_start(string str)
    {
        clsString::clsWord::delete_space_end_start1(str);
    }
    // join
    string join_string(string *str,int len)
    {
        return clsString::clsWord::Join_string(str,len);
    }
    //revers word
    string rverse_Word()
    {
        return clsString::clsWord::revers_word(_Value);
    }
    string rverse_Word(string str)
    {
        return clsString::clsWord::revers_word(str);
    }
    //replace word
    string repalce_word(string serch,string replace)
    {
        return clsString::clsWord::repalce_word(_Value,serch,replace);
    }
    string replace_word(string str,string serch ,string replace)
    {
        return clsString::clsWord::repalce_word(str,serch,replace);
    }
    //reamove puntuation
    void  rEMOVE_puntuation()
    {
        return clsString::clsWord::remove_puntuation(_Value);
    }
    void rEMOVE_puntuation(string str)
    {
        return clsString::clsWord::remove_puntuation(str);
    }
    //splite_word
    string *splite_Word(int &size)
    {
        return clsString::clsWord::Splite_Word(_Value,size);
    }
    string *splite_Word(string str,int &size)
    {
        return clsString::clsWord::Splite_Word(str,size);
    }
};