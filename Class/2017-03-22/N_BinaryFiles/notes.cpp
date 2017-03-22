/* 
 * File:   notes.cpp
 * Author: rcc
 *
 * Created on March 22, 2017, 1:46 PM
 */

#include <cstdlib>

using namespace std;

/*
 * BINARY FILE I/O
 * 
 * seekg goes to position in input file
 * seekp goes to position in output file
 * 
 * inData.seekG(25L, ios::beg); //25 bytes after beginning of file
 * outData.seekp(-10L, ios::cur); //10 bytes before current cursor location
 * 
 * //if you're at the end of the file, you must clear before seeking
 * gradeFile.clear();
 * gradeFile.seekg(0L, ios::beg);
 * 
 * 
 * Utilize a "tell" to return your location in file
 * long int whereAmI;
 * whereAmI = inData.tellg();
 */
int main(int argc, char** argv) {

    return 0;
}

