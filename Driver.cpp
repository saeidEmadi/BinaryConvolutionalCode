#include <iostream>
#include <bitset>
#include "encoder.h"
#include "decoder.h"

int main(){
    std::cout << "\n [Binary Convolutional Code run ...]\n";
    std::cout << " Errors and Error Correcting Codes\n";
    /*encoder e = encoder();
    int bit;
    while (true) {
        std::cout << "enter bit : ";
        std::cin >> bit;
        if (bit == 10) {
            break;
        }
        e.encode(bool(bit & 0x1));
    }*/

    decoder d = decoder();
    d.decode(0xD4);

    return 0;
}