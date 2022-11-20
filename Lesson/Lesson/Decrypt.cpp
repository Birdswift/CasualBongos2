#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <fstream>
#include <istream>

void decrypt(int passw) {
    std::ofstream out;
    std::ifstream out1;
    std::string block;
    std::string srth;
    std::ifstream readFile;
    readFile.open("crypto.txt", std::ios::binary);
    std::vector<char> crypto_string((std::istreambuf_iterator<char>(readFile)),
    std::istreambuf_iterator<char>());
    readFile.close();
    srand(passw);
    out.open("C:\crypto.txt");
    if (out.is_open()) {
        for (size_t i = 0; i <= crypto_string.size() - 4; i += 4) {
            auto  part1 = std::bitset<8>(crypto_string[i]).to_string();
            auto part2 = std::bitset<8>(crypto_string[i + 1]).to_string();
            auto part3 = std::bitset<8>(crypto_string[i + 2]).to_string();
            auto  part4 = std::bitset<8>(crypto_string[i + 3]).to_string();
            block = part1 + part2 + part3 + part4;
            auto block_32 = std::bitset<32>(block);
            auto  gamma = std::bitset<32>(rand());
            block_32 = block_32 ^ gamma;
            block_32 = (block_32 >> 3) | (block_32 << 29);
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
            auto c1 = static_cast<unsigned char>(i1);
            out << c1;
            for (int i = 8; i < 16; ++i) {
                str2 += block_32b[i];
            }
            std::bitset<8>k(str2);
            unsigned long i2 = k.to_ulong();
            auto c2 = static_cast<unsigned char>(i2);
            out << c2;
            for (int i = 16; i < 24; ++i) {
                str3 += block_32b[i];
            }
            std::bitset<8>l(str3);
            unsigned long i3 = l.to_ulong();
            auto c3 = static_cast<unsigned char>(i3);
            out << c3;
            for (int i = 24; i < 32; ++i) {
                str4 += block_32b[i];
            }
            std::bitset<8>n(str4);
            unsigned i4 = n.to_ulong();
            auto c4 = static_cast<unsigned char>(i4);
            out << c4;
        }      
    }
    out.close();
    std::cout << "Decryption completed, please, check the file" << std::endl;
}