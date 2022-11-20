#include <iostream>
#include <sstream>
#include "Header.h"
#include <fstream>
#include <vector>
#include <random>
#include <string>
#include <bitset>
#include <algorithm>


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Error: Use three parameters\n";
        return 5;
    }
    const std::string mode(argv[1]);
    const std::string pass(argv[2]);
    int passw = std::stoi(pass);
    if (mode == "encryption") {
        encrypt(passw);
    } else if (mode == "decryption") {
        decrypt(passw);
    }
    return 0;
} 


