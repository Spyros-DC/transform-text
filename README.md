# Name

Spyros Tsimboulis

# Welcome!

This is my C++ solution for converting written numbers in words to digits.

# Design

I have designed my program in two separate parts.

The first is a library (under src/lib) and the second is the processing part (mainly at src/processing.cpp).

The library constructs a number from a list of 'words' (a struct defined in src/lib/include/word.h). 
This is very similar to reading one by one all the words from a number in a text.
For example, if the number is:
```text
one hundred twenty-five
```
I create a list from word structs that correspond to this number. 
From this list I create a number as a list of lists of 'numbers' (struct defined in src/lib/include/number.h).
The API of the library is exposed through the header files in src/lib/include, and mainly in src/lib/include/convert.h where are the most important functions.
I have used simple structs with only data members and no methods, 
since in my opinion, the functional approach (that I have used for this library) 
with functions operating on data has significant advantages over the object-oriented.


The second part is the processing part where from the text the program extracts the sub-strings of numbers, 
and from those sub-strings, a list of 'word' structs is created and is passed as input to the lib.

# Build
The build system is CMake. The executables are 'transformText' for the main app, 'transformTextTests' for the tests and a static lib 'libsmall_lib.a'.

# Usage
Run the app with:
```bash
./transformText
```
there are two different inputs, from terminal or from file and the program guides the user through messages to standard out.



# Running the tests
I have used googletest. 
There is no need for googletest to be installed on your machine, since the download and integration of googletest with the program is handled by CMake.


Run the tests with:
```bash
./transformTextTests
``
