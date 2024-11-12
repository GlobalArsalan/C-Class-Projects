#include <iostream>


/////////////////////////////////////////Main Functions
std::size_t length(char const *a); // returns length of C-style string
int compare(char const *str1, char const *str2); // compares whether two strings are equal or one comes before or after the other
void assign(char *str1, char const *str2);//overwrites str1 with the values of str2 so they are equal after the operation
////////////////////////////////////////Helper Functions
int beforeOrAfter(char const *str1, std::size_t k1, char const *char2, std::size_t k2);
void setToNull(char *str1);
//////////////////////////////////The main Function
int main();
/////////////////////////////////////////////////Main Project
std::size_t length(char const *a) {
    int count = 0;
    for(int i = 0;true;i++) {
        if(a[i] == '\0') {
            break;
        }
        count++;
    }
    return count;
}
int compare(char const *str1, char const *str2) {
    std::size_t k1 = 0;
    std::size_t k2 = 0;
    while(str1[k1] == str2[k2]) {
        if(str1[k1] == '\0' && str2[k2] == '\0') {
            return 0;
        }
        k1++; k2++;
    }
    if(str1[k1] == '\0') {
        return -1;
    }
    if(str2[k2] == '\0') {
        return 1;
    }
    return beforeOrAfter(str1, k1, str2, k2);
    
}
void assign(char *str1, char const *str2) {
    setToNull(str1);
    for(int i = 0; i <21; i++) {//Given that str1 and str2 will have size 21
        str1[i] = str2[i];
    }
}
//////////////////////////////////////Helper Functions///////////////////////////////////////////
int beforeOrAfter(char const *str1, std::size_t k1, char const *str2, std::size_t k2) { //determines whether str1 comes before or after str2
    char character1 = str1[k1];
    char character2 = str2[k2];
    int position1 = 0;
    int position2 = 0;
    char temp = 'a';
    for(int i = 0; i < 26; i++) {
        if((temp + i) == character1) {
            position1 = i;
        }
    }
    temp = 'a';
    for(int i = 0; i < 26; i++) {
        if((temp + i) == character2) {
            position2 = i;
        }
    }
    if(position1 < position2) {
        return -1;
    } else {
        return 1;
    }

}
void setToNull(char *str1) { //Sets all elements in the string to \0
    for(int i = 0; i < 21; i++) { //Given that size of str1 is 21 elements
        str1[i] = '\0';
    }
}
////////////////////////////////////The main Function////////////////////////////////////////////////
int main() {
    char *str1 = new char[21]{'a', '6', '\0'};
    char const *str2 = new char[21]{'a', 'r', 's', 'a', 'l', 'a', 'b','n', 'n', '\0'};
    assign(str1, str2);
    for(int i = 0; i <21; i++) {
        std::cout << str1[i];
    }
    return 0;
}
