# Snake-Project

-----


This project is meant to be a recreation of the classic game snake, both in C++ and Qt. I will first start by coding a simple version of the
game in C++ and then attempting to port to Qt. The user will interact with the game through key presses if possible. The game board itself
and the snake/food will be simple characters in the console version, although hopefull I will be able to upgrade the graphics using Qt
resources. This will allow me to test the logic of my code as well as some Qt implementation practices. I will attempt to use the ui if
possible.

The use of the project is simple:

Simply download the files given and run, preferably through an IDE as I don't have any knowledge of other platforms.

## Current features
--------
- So far, nothing.

## Use of class material
--------
So far, the project uses git functionality, including branching and merging, commits, and remote repositories. If I get to it, it will also
incorporate Qt. As for other sections, I will go into those below.

### Inheritance and Polymorphism
Although my destructors currently do nothing, I made them virtual. This could, in theory, allow someone to inherit from the snake class
and properly delete memory on the heap that they may use in said derived class. In a game such as Snake inheritance could make sense as
perhaps one could have games with different snake types that behave differently.

### Function Pointers and Functors

### Memory Management
While I have used no heap memory so far, I implemented the copy and swap idiom for my Snakey and Food classes. If I ever choose to use 
the heap, this idiom makes my classes RAII (SBRM) compliant. This is because all heap memory is managed by classes, so that if anything 
goes wrong and the stack unwinds, all memory is dealt with properly. It also allows reuse of code, which is good for efficiency.

### Templates

### Smart Pointers

### Iterators
When using std::copy, I needed vector iterators to copy over the contents. While vector iterators are random access, in the case of copy
they only need to be input/output level, as all operations involve a simple read through of the vectors. There is no decrementing and 
the copy only needs one pass, so the simplest iterator level would be sufficient.

### Generic Algorithms, Lambdas, and Bind
I used std::copy in my copy constructor for certain vectors. While this doesn't really take advantage of the full use of generic 
algorithms it can definitely save time, especially for larger vectors/many vectors.

----------
## Test Cases and Problems
----------


-------
Note: Will add most files to gitignore (ie. the .exe file, debug, etc.) but want to finish project first.
