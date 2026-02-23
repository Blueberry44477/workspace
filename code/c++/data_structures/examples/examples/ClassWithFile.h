#ifndef DATA_STRUCTURES_CLASSWITHFILE_H
#define DATA_STRUCTURES_CLASSWITHFILE_H

#include <string>
#include <fstream>
#include <ostream>

class ClassWithFile {
private:
    int intValue;
    std::string stringValue;
public:
    ClassWithFile() : intValue{0}, stringValue{""} {};
    ClassWithFile(int number, std::string &&value) : intValue{number}, stringValue{value} {};
    void writeToBinaryFile(const std::string &filename) const;
    void readFromBinaryFile(const std::string &filename);
    friend std::ostream &operator<<(std::ostream &os, const ClassWithFile &obj);
};


#endif
