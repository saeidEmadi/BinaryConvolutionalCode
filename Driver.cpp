#include <iostream>
#include <bitset>
#include "encoder.h"
#include "decoder.h"
#include <vector>
#include <string>

int main() {
    std::cout << "\n [Binary Convolutional Code run ...]\n";
    std::cout << "  Errors and Error Correcting Codes\n";
    std::cout << "  e : encode || d : decode \n";
    std::vector<bool> bits;
    char bitInput;
    bool encoderFlag = true;
    std::cout << "  select Encoder : e or Decoder : d :[default : encoder]:  ";
    std::cin >> bitInput;
    bitInput = bitInput == 'd' ? encoderFlag = false : encoderFlag = true;
    if (encoderFlag) {
        std::cout << "  f : end of stream || q : exit\n";
    }
    std::cout << std::endl << std::endl;
    while (encoderFlag) {
        std::cout << ">";
        std::cin >> bitInput;
        if (bitInput == 'q') {
            exit(1);
        }
        if (bitInput == 'f') {
            break;
        }
        if (bitInput != '0' && bitInput != '1') {
            std::cout << "\n\n[Expected a binary sequence, found " << bitInput << "]" << std::endl;
            exit(1);
        }
        bool bit = bitInput - '0';
        bits.push_back(bit);
    }
    if (encoderFlag) {
        encoder e = encoder();
        for (int i = 0; i < bits.size(); i++) {
            //e.encodeDetail(bool(stream[i] & 0x1));
            e.encode(bits[i]);
        }
    }else {
        std::cout << " example 0xHex :: D4 for 11010100" << std::endl;
        std::cout << "enter 0xHEX value for Decodeing : ";
        std::string str;
        std::cin >> str;
        int i = stoi(str, 0, 16);
        decoder d = decoder();
        d.decode(i & 0xFF);
    }
    // pause console 
    system("pause");
    return 0;
}