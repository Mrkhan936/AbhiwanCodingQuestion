// program to reverse the word of the string without changing it's position
#include<iostream>
#include<string>
using namespace std;
void reverse(string &str,int i,int j){
    while (j > i)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    } 
}
string reverse_by_word(string str){
    int start = -1;
    int i = 0;
    int end = -1;
    while (i < str.length())
    {
        while (i < str.length() && str[i] == ' '){
            i++;
        }
        start = i;
        while (i < str.length() && str[i] != ' '){
            i++;
        }
        end = i - 1;
        reverse(str,start,end);
    }
    return str;
}
int main(int argc, char const *argv[])
{
    string str = "   abc    efg   hij   ";
    cout << reverse_by_word(str);
    return 0;
}
