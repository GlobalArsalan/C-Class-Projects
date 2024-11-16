#include <iostream>
#include <algorithm>

/////////////////////////////////////////Main Functions
std::size_t length(char const *a); // returns length of C-style string
int compare(char const *str1, char const *str2); // compares whether two strings are equal or one comes before or after the other
void assign(char *str1, char const *str2);//overwrites str1 with the values of str2 so they are equal after the operation
unsigned int distance(char const *str1, char const *str2);//returns the minimum numebr of changes needed to turn one string to the other.
std::size_t is_sorted(char *array[], std::size_t capacity); //check if an array of strings is sorted
void insert(char *array[], std::size_t capacity); //puts the last entry of the array into the right place lexographically
void insertion_sort(char *array[], std::size_t capacity); //implements an insertion sort algorithm to an array of C-style strings
////////////////////////////////////////Helper Functions
int beforeOrAfter(char const *str1, std::size_t k1, char const *char2, std::size_t k2);//determines if str1 comes before or after str2 lexographically
void setToNull(char *str1);//set ever character in the string to the null character
void deallocate(char *array[], std::size_t capacity); // deallocate every pointer in the array;
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
unsigned int distance(char const *str1, char const *str2) {
    if(length(str1) == 0 || length(str2) == 0) {
        if(length(str1) != 0) { //check which one is the empty string
            return length(str1);
        } else {
            return length(str2);
        }
    }
    if(str1[0] == str2[0]) { //check to see if the first character in both are equal
        return distance(str1 + 1, str2 + 1);
    }
    /////////////////////////////////////////////////////////error starts here
    //if((str1[0] != str2[0]) && (str1[1] != str2[1])) { //check to see if the first two characters are different
        unsigned int temp1 = distance(str1 + 1, str2 + 1);//Note : check the condition, what if the string is too short?
        unsigned int temp2 = distance(str1, str2 + 1);
        unsigned int temp3 = distance(str1 + 1, str2);
        return (std::min(std::min(temp1, temp2), temp3));
    // }
    //     return (1 + distance(str1 + 1, str2 + 1)); //case where only the first letters are different
}
std::size_t is_sorted(char *array[], std::size_t capacity) {
    for(int i = 0; i < capacity - 1; i++) {
        if(compare(array[i], array[i+1]) > 0) {
            return i+1;
        }
    }
    return capacity;
}
void insert(char *array[], std::size_t capacity) {
    char *value = new char[21]{}; //all strings in this projects have length 21
    for(int i =0; i < length(array[capacity -1]);i++) {
        value[i] = array[capacity-1][i];
    }
    for(int i = capacity -2; i >= 0; i--) {
        if(compare(value, array[i]) < 0) {
            assign(array[i+1], array[i]);
            if(i == 0) {
                array[i] = value;
                break;
            }
            
        } else {
            array[i + 1] = value;
            break;
        }
    }
}
void insertion_sort(char *array[], std::size_t capacity) {
    for(int i = 2; i <= capacity; i++) {
        insert(array, i);
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