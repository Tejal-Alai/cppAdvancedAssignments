# Assignment 7 - Lambda Expression with Generalised Capture with Initialization
 
## Overview
 
This assignment involves utilizing a lambda expression in the `Reader.cpp` file to define a function named `isFileExist`. The lambda expression returns a string which is a copy of a string from the user function stack and it is locally initialised in **Capture Clause** itself, also in order to change the string in the Lambda Expression we have to specify `mutable` keyword, and this string is then outputted to the user with `std::cout`. **mutable** keyword is not necessary here.
 
## Updated Function Definition
 
1. **Function File:**
   - Function Definition: `Reader.cpp` funtion `void Reader::getTriangles(std::vector<Triangle> &triangles)`
     
2. **Lambda Expression:**
   - Define a lambda expression named `isFileExist` with capture clause as `[errorMsg = "File not found!"]`.
   - We used mutable keyword in order to specify that the variables in the capture clause will be `mutable` and not `const`.
   - Due to mutable keyword the value of string got changed  to value in the Capture Clause itself.
   - But the thing to remember is it's just a copy so original user stack variable string hasn't yet be changed.
   - Remember if we hadn't used mutable keyword the variable is passed as const so we can't change it inside the Lambda Expression.
   - It can be analogous to Initialisation List in the functions.
   - The lambda expression returns a string indicating a file not found error.
 
## Usage
 
1. **Lambda Expression in Action:**
   - Defined `std::string errorMsg = "File not exist!`
   - Call the lambda expression `isFileExist` in the `Reader.cpp` file.
 
2. **Output to User:**
   - Use `std::cout` to output the string returned by the lambda expression.
   - The output will be changed to `"File not found!`.
