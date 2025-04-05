#include "ClassWithFile.h"

void ClassWithFile::writeToBinaryFile(const std::string &filename) const {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile.is_open()) {
        throw std::string("Failed to open file for writing");
    }
    outFile.write(reinterpret_cast<const char *> (&intValue), sizeof(intValue));
    size_t stringSize = stringValue.size();
    outFile.write(reinterpret_cast<const char *>(&stringSize), sizeof(stringSize));
    outFile.write(stringValue.c_str(), stringSize);
    outFile.close();
}


void ClassWithFile::readFromBinaryFile(const std::string &filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile.is_open()) {
        throw std::string("Failed to open file for reading");
    }
    inFile.read(reinterpret_cast<char *>(&intValue), sizeof (intValue));

    size_t stringSize;
    inFile.read(reinterpret_cast<char *>(&stringSize), sizeof (size_t));
    stringValue.resize(stringSize);
    inFile.read(&stringValue[0], stringSize);

    inFile.close();
}

std::ostream &operator<<(std::ostream &os, const ClassWithFile &obj) {
    os << "Data: " << std::endl;
    os << obj.intValue << " " << obj.stringValue << std::endl;
    return os;
}