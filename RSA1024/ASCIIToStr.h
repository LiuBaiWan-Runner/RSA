#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

// 读取文件内容并打印
void printFileContents(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << fileName << "!" << endl;
        return;
    }

    // cout << "Contents of " << fileName << ":\n";
    cout << file.rdbuf() << endl;
    file.close();
}

// 读取文件内容，将其转换为ASCII码保存到temp.txt中（十六进制格式，大写字母）
void stringToASCII(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file!" << endl;
        return;
    }

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file!" << endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        int ascii_value = static_cast<int>(ch);
        outputFile << uppercase << hex << setw(2) << setfill('0') << ascii_value; // 输出为十六进制格式，大写字母
    }

    inputFile.close();
    outputFile.close();

    // printFileContents(outputFileName);

}

// 从temp.txt中读取ASCII码内容，将其还原为字符串保存到result.txt中
void ASCIIToString(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file!" << endl;
        return;
    }

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file!" << endl;
        return;
    }

    string hexValue;
    while (inputFile >> setw(2) >> hexValue) { // 每次读取两个字符
        int ascii_value;
        stringstream ss(hexValue); // 将字符串转换为整数
        ss >> hex >> ascii_value; // 从十六进制格式读取
        char decoded_char = static_cast<char>(ascii_value);
        outputFile << decoded_char;
    }

    inputFile.close();
    outputFile.close();

    // printFileContents(outputFileName);

}
