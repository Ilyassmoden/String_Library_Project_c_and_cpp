#include "Consoloap.h"


int main ()
{
    clsString string1;
    clsString string2("ilyas");
    string1.SetValue("ana");
    
  
    string2.Convert_first_letter_inWord_uper();
    cout << string2.GetValue() << endl;
    string2.Convet_first_letter_in_Word_lower();
    cout << string2.GetValue() << endl;
    cout << string2.count_letter() << endl;
    string *arr = new string[3];
    arr[0] = "Hello";
    arr[1] = "World";
    arr[2] = "C++";
    cout << string2.join_string(arr,3) << endl;
    clsString str2;
    int size = 0;
    string *strd = str2.splite_Word("ilyas ait elmouden",size);
    for(int i = 0; i < size;i++)
    {
        cout << strd[i] + " ";
    }
    cout << endl;

     
}
