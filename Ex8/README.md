# Assignment 8 - Use of std::vector<Template class>::iterator Container in C++ STL

## Overview

This assignment involves use of `std::vector<Triangle>::iterator` to container (basically pointer) to loop through a vector to output a string to the file. For looping we are using for_each() function in the library algorithm.

1. Iterators

Use: `std::vector<Triangle>::iterator start = triangles.begin();` 
we have used iterator object named start to reference the first element of the vector, and end to reference the last element.
Iterator is a pointer to the objects in the container.

2. for_each()

Use: `for_each(start, end, [&dataFile](Triangle triangle){} )`; 
for_each is the loop function in the library <algorithm> which takes 3 arguments,`for_each(vector.begin(), vector.end(), func() )`.
We have used lambda function in the for_each loop as the third argument and Capture clause element as Datafile as a reference which is a `std::ostream` object.