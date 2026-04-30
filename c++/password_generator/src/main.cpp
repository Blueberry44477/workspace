#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>
#include <filesystem>
using namespace std;

// Function to calculate MD5 hash of a string
std::string calculateMD5(const std::string &input)
{
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5_CTX context;
    MD5_Init(&context);
    MD5_Update(&context, input.c_str(), input.length());
    MD5_Final(digest, &context);
    std::stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
    return ss.str();
}

// Function to append the password and its hash to a file
void appendPasswordToFile(const string &password, const string &filename)
{
    ofstream outfile(filename, ios::app); // Open the file for appending
    if (outfile.is_open())
    {
        string hashedPassword = calculateMD5(password); // Calculate MD5 hash of the password
        outfile << password << " - " << hashedPassword << endl; // Write the password and its hash to the file
        cout << "Password and its hash have been appended to the file: "
            << filename << endl;
        outfile.close(); // Close the file
    }
    else
        cout << "Error appending password and its hash to the file: " << filename << endl;
}

int main() {
    string password;
    string filename = "passwords.txt";

    std::cout << "Enter the password: ";
    std::getline(cin, password);

    appendPasswordToFile(password, filename);
    return 0;
}