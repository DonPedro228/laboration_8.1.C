#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


using namespace std;

int Find_Three_Oklyk(char* s) {
    int k = 0, pos = 0;
    char* t;
    while ( t = strchr(s + pos, '!')) {
        pos = t - s + 1;
        if (s[pos] == '!') {
            pos = t - s + 2;
            if (s[pos] == '!') {
                k++;
                pos++;
            }
        }
    }
    if (k > 0) {
        return k;
    }
    else
        return 0;
}

void Replace_Group_With_Oklyk(char* s) {
    char* t = new char[strlen(s) + 1];
    char* p;
    int pos1 = 0;
    *t = 0;

    while ((p = strstr(s + pos1, "!!!")) != nullptr) {
        int groupStart = p - s;
        int groupEnd = groupStart + 2;

        strncat(t, s + pos1, groupStart - pos1);

        strcat(t, "**");

        pos1 = groupEnd + 1;
    }
    strcat(t, s + pos1);

    strcpy(s, t);

    delete[] t;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int count = 0;
    count = Find_Three_Oklyk(str);
    cout << "Count of Group !!! = " << count << endl;
    Replace_Group_With_Oklyk(str);
    cout << str << endl;
    return 0;
}