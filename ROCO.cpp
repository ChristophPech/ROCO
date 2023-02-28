// ROCO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>


void ROCO(const std::string &InputFileName, const std::string &OutputFileName) {
    std::ifstream inf(InputFileName, std::ios::binary);
    std::ofstream ouf(OutputFileName, std::ios::binary);
    unsigned char s = 31;
    int count = 0;
    std::cout << InputFileName << ":" << inf.is_open() << std::endl;
    if (inf.is_open()) {
        char b;
        while (!inf.eof()) {
            inf.read(&b, 1);
            b = b ^ s;
            s++;
            ouf.write(&b,1);
            count++;
        }
        std::cout << OutputFileName << ":" << count << std::endl;
        inf.close();
        ouf.close();
    }
}

int main(int argc, char *argv[]) {
    std::string InputFileName;
    std::string OutputFileName;

    if (argc == 3) {
        ROCO(argv[1], argv[2]);
    } else {
        std::cout << "Error! Arguments!" << std::endl;
    }
	return 0;
}

