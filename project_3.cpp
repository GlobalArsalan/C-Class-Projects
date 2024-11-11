#include <iostream>
#include <cassert>
double powerTo(double input, int power); // returns input^power
double *geometric(double a, double ratio, std::size_t cap); // returns the address of a dynamically allocated array that holds a, ar, ar^2 and so on where r is the ratio
double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1);//returns a dynamically allocated array where newArray[i+j] = array0[i]*array1[k]
std::size_t shift_duplicates(int array[], std::size_t capacity);//shifts all duplicates in the array to the end and returns the number of unique elements
void shiftLeft(int array[], std::size_t startIndex, std::size_t cap); //shifts all elements in the array to the left by 1 position starting from index startIndex
void deallocate(double *&ptr, bool is_array, std::size_t capacity = 0);// dealocates ptr

//////////////////////////////////////// Main Code
double *geometric(double a, double ratio, std::size_t cap) {
    double *dynamicArr = new double[cap];
    for (std::size_t i = 0; i < cap; i++) {
        dynamicArr[i] = a * powerTo(ratio, i);
    }
    return dynamicArr;
}
double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1) {
    assert(cap0 + cap1 >= 1);
    double *dynamicArr = new double[cap0 + cap1 - 1]{};
    for(std::size_t arr0 = 0; arr0 < cap0; arr0++) {
        for(std::size_t arr1 = 0; arr1 < cap1; arr1++) {
            dynamicArr[arr0 + arr1] += array0[arr0] * array1[arr1];
        }
    }
    return dynamicArr;

}
std::size_t shift_duplicates(int array[], std::size_t capacity) {
    std::size_t tempCap = capacity;
    std::size_t count = 0;
    for(std::size_t i = 0; i < capacity; i++) {
        bool isDuplicate = false;
        int temp = array[i];
        for(std::size_t x = i + 1; x < capacity; x++) {
            if(array[x] == temp) {
                shiftLeft(array, x, tempCap);
                isDuplicate = true;
                array[tempCap - 1] = temp;
                count++;
                capacity--; 
                x--;
            }

        }
    }
    return tempCap - count;

}


void deallocate(double *&ptr, bool is_array, std::size_t capacity) {
    if(is_array) {
        for(std::size_t i = 0; i < capacity; i++) {
            ptr[i] = 0;
        }
        delete[] ptr;
        } else {
        *ptr = 0;
        delete ptr;
    } 
    ptr = nullptr;
}
/////////////////////////////////// Helper Functions

double powerTo(double input, int power) { 
    double result  = 1;
    for(int i = 0; i < power; i++) {
        result *= input;
    }
    return result;
}
void shiftLeft(int array[], std::size_t startIndex ,std::size_t cap) { 
    for(std::size_t i = startIndex; i < cap - 1; i++) {
        array[i] = array[i + 1];
    }
}