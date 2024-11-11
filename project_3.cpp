#include <iostream>
#include <cassert>
double powerTo(double input, int power);
double *geometric(double a, double ratio, std::size_t cap);
double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1);
std::size_t shift_duplicates(int array[], std::size_t capacity);
void shiftLeft(int array[], std::size_t startIndex, std::size_t cap);
void deallocate(double *&ptr, bool is_array, std::size_t capacity = 0);

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
// std::size_t shift_duplicates(int array[], std::size_t capacity) {
//     std::size_t unique_count = 0;

//     // Iterate through the array
//     for (std::size_t i = 0; i < capacity; ++i) {
//         bool is_duplicate = false;
//         // Check if array[i] is a duplicate of any previous unique elements
//         for (std::size_t j = 0; j < unique_count; ++j) {
//             if (array[i] == array[j]) {
//                 is_duplicate = true;
//                 break;
//             }
//         }
//         // If it's not a duplicate, move it to the unique portion
//         if (!is_duplicate) {
//             int temp = array[unique_count];
//             array[unique_count++] = array[i];


//         } else {
            
//         }
//     }
//     return unique_count;  // Return the number of unique elements
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