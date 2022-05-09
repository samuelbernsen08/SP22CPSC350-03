/**
 * @file FileHandler.cpp
 * @authors Samuel Bernsen
 * @brief Implementations of methods needed to load a map from file and other file related functions
 * @version 0.2
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "FileHandler.h"

/**
 * @brief Construct a new File Processor:: File Processor object
 * 
 */
FileHandler::FileHandler() 
{
}


/**
 * @brief Destroy the File Processor:: File Processor object
 * 
 */
FileHandler::~FileHandler() 
{
    delete this;
}


/**
 * OpenInFile
 * @brief Opens the inFile for use in other code
 * 
 * @param fileName 
 */
void FileHandler::OpenInFile(string fileName)
{
    fileReader.open(fileName);
}


/**
 * Readline
 * @brief Reads individual lines from the inFile and returns them
 * 
 * @return string 
 */
string FileHandler::ReadLine()
{
    string str;
    getline(fileReader, str);

    return str;
}


/**
 * ReadFile
 * @brief Reads all lines from a file and stores them in a single string
 * 
 * @return string 
 */
string FileHandler::ReadFile()
{
    string str;
    string tp;
    while(getline(fileReader, tp))
    {
        if ((tp[0] == '#' || (tp.find('/') != -1 && tp[tp.find('/')] == tp[tp.find('/')+1])))
        {
            // do nothing
        }
        else
        {
            str += tp + '\n';
        }
    }
    // cout << str << endl;
    return str;
}

int FileHandler::NumLines()
{
    int numLines = 0;
    string line;

    while (getline(fileReader, line))
    {
        numLines++;
    }
    return numLines;
}


/**
 * CloseInFile
 * @brief Closes the inFile
 * 
 */
void FileHandler::CloseInFile()
{
    fileReader.close();
}


/**
 * OpenOutFile
 * @brief Opens the OutFile given the name of said file
 * 
 * @param fileName 
 */
void FileHandler::OpenOutFile(string fileName)
{
    fileWriter.open(fileName);
}


/**
 * WritelineToFile
 * @brief Writes a line of the board to the outFile
 * 
 * @param line 
 */
void FileHandler::WriteLineToFile(string line)
{
    fileWriter << line << endl;
}


/**
 * CloseOutFile
 * @brief Closes the outFile
 * 
 */
void FileHandler::CloseOutFile()
{
    fileWriter.close();
}


/**
 * IsEndOfFile
 * @brief Returns a boolean value showing whether the end of the file has been reached
 * 
 * @return true 
 * @return false 
 */
bool FileHandler::IsEndOfFile()
{
    return fileReader.eof();
}