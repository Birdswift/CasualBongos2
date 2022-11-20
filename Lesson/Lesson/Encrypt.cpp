#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include <algorithm>
#include "Header.h"
#include <vector>
#include <stdlib.h> 



void encrypt(int passw) 
{
    std::string text;
    std::string block;
    std::cout << "Please, input the text: ";
    getline(std::cin, text);
    srand(passw);
    while (text.size() % 4 != 0) {
        text += '\0';
    }
    std::ofstream outputFile;
    outputFile.open("C:\crypto.txt", std::ios::binary); 
    for (size_t i = 0; i <= text.size()-4; i += 4) { 
        auto  part1 = std::bitset<8>(text[i]).to_string();
        auto part2 = std::bitset<8>(text[i + 1]).to_string();
        auto part3 = std::bitset<8>(text[i + 2]).to_string();
        auto  part4 = std::bitset<8>(text[i + 3]).to_string();            
        block = part1 + part2 + part3 + part4;
        auto  gamma = std::bitset<32>(rand());
        auto block_32 = std::bitset<32>(block);
        block_32 = (block_32 << 3) | (block_32 >> 29);
        block_32 = block_32 ^ gamma;
        auto block_32b = block_32.to_string();
        std::string str1;
        std::string str2;
        std::string str3;
        std::string str4;     
        for (int i = 0; i < 8; ++i) {
            str1 += block_32b[i];
        }
        std::bitset<8>m(str1);
        unsigned long i1 = m.to_ulong();
        char c1 = static_cast<unsigned char>(i1);
        outputFile.write(&c1, sizeof(c1));
        for (int i = 8; i < 16; ++i) {
            str2 += block_32b[i];
        }
        std::bitset<8>k(str2);
        unsigned long i2 = k.to_ulong();
        char c2 = static_cast<unsigned char>(i2);
        outputFile.write(&c2, sizeof(c2));
        for (int i = 16; i < 24; ++i) {
            str3 += block_32b[i];
        }
        std::bitset<8>l(str3);
        unsigned long i3 = l.to_ulong();
        char c3 = static_cast<unsigned char>(i3);
        outputFile.write(&c3, sizeof(c3));
        for (int i = 24; i < 32; ++i) {
            str4 += block_32b[i];
        }
        std::bitset<8>n(str4);
        unsigned i4 = n.to_ulong();
        char c4 = static_cast<unsigned char>(i4);
        outputFile.write(&c4, sizeof(c4));
    }
    outputFile.close();
    std::cout << "Encryption completed, please, check the file" << std::endl;
}