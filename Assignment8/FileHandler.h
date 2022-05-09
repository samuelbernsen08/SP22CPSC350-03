/**
 * @file FileHandler.h
 * @author Samuel Bernsen
 * @brief Header file for FileHandler class
 * @version 0.2
 * @date 2022-03-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class FileHandler
{
    private:
        ifstream fileReader;
        ofstream fileWriter;

    public:
        FileHandler();
        ~FileHandler();

        void OpenInFile(string fileName);
        int NumLines();
        string ReadLine();
        string ReadFile();
        void CloseInFile();

        void OpenOutFile(string fileName);
        void WriteLineToFile(string line);
        void CloseOutFile();

        bool IsEndOfFile();
};


#endif