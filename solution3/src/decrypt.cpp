#include <iostream>
#include <fstream>
#include <string>

void encryptDecrypt(const std::string &inputFile, const std::string &outputFile, char key)
{
    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile, std::ios::binary);

    if (!inFile.is_open() || !outFile.is_open())
    {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }

    char ch;
    while (inFile.get(ch))
    {
        outFile.put(ch ^ key);
    }

    inFile.close();
    outFile.close();
}

int main()
{
    std::string inputFile = "input.txt";
    std::string encryptedFile = "encrypted.txt";
    std::string decryptedFile = "decrypted.txt";
    char key = 'K'; // Simple XOR key

    // Encrypt the file
    encryptDecrypt(inputFile, encryptedFile, key);
    std::cout << "File encrypted successfully." << std::endl;

    // Decrypt the file
    encryptDecrypt(encryptedFile, decryptedFile, key);
    std::cout << "File decrypted successfully." << std::endl;

    return 0;
}