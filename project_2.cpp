#include <iostream>
#include <cassert>

void pattern(unsigned int n) {
    //std::cout << "n = "<< n << ":" << std::endl;
    int space = n * 2 + 1;
    for(unsigned int i = 1; i <= n; i++) {
        for(unsigned int x = 1; x < i; x++) {
            std::cout << " ";
        }
        for(unsigned int z = 1; z <= space - 2 * (i-1); z++) {
            std::cout << "*";
        }
        for(unsigned int x = 1; x < i; x++) {
            std::cout << " ";
        }
        std::cout << std::endl;    
    }
    for(unsigned int i = 1; i <= n; i++) {
        std::cout << " ";
    }
    std::cout << "*" << std::endl;
    // for(int i = 1; i <= n; i++) {
    //     std::cout << "a";
    // }
    for(unsigned int i = n; i >= 1; i--) {
        for(unsigned int x = 1; x <= i - 1; x++){
            std::cout << " ";
        }
        for(unsigned int x = 1; x <= 3 + 2 * (n - i) ; x++) {
            std::cout << "*";
        }
        for(unsigned int x = 1; x <= i - 1; x++) {
            std::cout << " ";
        }
        std::cout << std::endl;
    }

}
unsigned int log10(unsigned int n){
    assert(n != 0);
    unsigned int exponent = 0;
    unsigned int number = 1;
    // while(true) {
    //     unsigned int temp = 1;
    //     for(unsigned int i = 1; i <= exponent; i++) {
    //         temp = temp * 10;
    //     }
    //     if(temp > n) {
    //         exponent -= 1;
    //         break;
    //     } else if(temp == n) {
    //         break;
    //     }
    //     exponent++;
    // }
    while(n >= number) {
        exponent++;
        if (number > n / 10) {
            break;
        }
        number *= 10;
    }
    return exponent - 1;
}
unsigned int count(unsigned int n, unsigned int bit) {
    assert(bit == 0 || bit == 1);
    unsigned int counter = 0;
    unsigned int exponent = 0;
    do {
        unsigned int temp = 1;
        for(unsigned int i = 1; i <= exponent; i++) {
            temp = temp * 2;
            
        }
        //std::cout<< "Executed " << temp <<std::endl;
        exponent++;
        //std::cout << (n & temp) << std::endl;
        if(temp == (n & temp)) {
            counter++;
            //std::cout << counter;
        }
    } while(exponent <= 31);
    if(bit == 1) {
        return counter;
    } else {
        return 32 - counter;
    }
}
unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1) {
    assert((b0 >= 0 && b0 <= 3) && (b1 >= 0 && b1 <= 3));
    if(b0 == b1) {
        return n;
    }
    unsigned int mask0 = (0b11111111 << (b0 * 8));
    unsigned int mask1 = (0b11111111 << (b1 * 8));
    unsigned int temp0 = (n & mask0);
    unsigned int temp1 = (n & mask1);
    // std::cout << "temp0: " << temp0 << std::endl;
    // std::cout <<"temp1: " << temp1 << std::endl;
    if(b0 > b1) {
        temp1 = temp1 << ((b0-b1)*8);
        temp0 = temp0 >> ((b0-b1)*8);
    } else {
        temp0 = temp0 << ((b1-b0) * 8);
        temp1 = temp1 >> ((b1-b0) * 8);
    }
    // std::cout << "temp0: " << temp0 << std::endl;
    // std::cout << "temp1: " << temp1 << std::endl;
    n = n & ~(mask0 | mask1);
    n = n | (temp1 | temp0);
    return n;

}