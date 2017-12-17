# Snake-Project

-----


This project is meant to be a recreation of the classic game snake, both in C++ and Qt. I will first start by coding a simple version of the
game in C++ and then attempting to port to Qt. The user will interact with the game through key presses if possible. The game board itself
and the snake/food will be simple characters in the console version, although hopefull I will be able to upgrade the graphics using Qt
resources. This will allow me to test the logic of my code as well as some Qt implementation practices. I will attempt to use the ui if
possible.

Unfortunately, during a switch between the master and experimental branches, I somehow lost the .sln file on my local machine. I thus have been trying to find a way to clone these files into a new solution, but haven't had much luck yet.


The use of the project is simple:

Simply download the files given and run, preferably through an IDE as I don't have any knowledge of other platforms.

## Current features
--------
- So far, the game displays a game board, fruit, and snake that respond to "wasd" keyboard movement. The snake can eat fruit and grow, the score works, and the game won't crash.

## Use of class material
--------
So far, the project uses git functionality, including branching and merging, commits, and remote repositories. If I get to it, it will also
incorporate Qt. As for other sections, I will go into those below. Another important note is that while I realize most of these are not 
being used in an efficient manner. However, I wanted to display what I've learned and where it can be applied rather than trying to find
the perfect instance for each topic.

### Inheritance and Polymorphism
Although my destructors currently do nothing, I made them virtual. This could, in theory, allow someone to inherit from the snake class
and properly delete memory on the heap that they may use in said derived class. In a game such as Snake inheritance could make sense as
perhaps one could have games with different snake types that behave differently.

Once I finish the base game, I want to create a derived class from Snake, an 'opposite' snake. The snake will do the opposite of what the user inputs compared to the normal snake. I may also request heap memory to show my ability to implement destructors and try catch blocks that are RAII compliant in my constructors.

### Function Pointers and Functors
I created the SnakeSetup class in one of my files, which is a functor as it overloads the operator(). While I don't call it in another function/template, I can see how it could be useful to clear up certain files in this case. 

### Memory Management
While I have used no heap memory so far, I implemented the copy and swap idiom for my Snakey and Food classes. If I ever choose to use 
the heap, this idiom makes my classes RAII (SBRM) compliant. This is because all heap memory is managed by classes, so that if anything 
goes wrong and the stack unwinds, all memory is dealt with properly. It also allows reuse of code, which is good for efficiency.

### Templates
I also used templates in my SnakeSetup functor, mostly to show that I know how to use them. Since I'm the one writing and using my code, there hasn't really been a need for me to set policy or create many template functions/classes. In this case I suppose there is a chance for storage of other types in the snake class, so a template could be useful.

### Smart Pointers
As I have no heap memory yet, I haven't added any smart pointer functionality. 
### Iterators
When using std::copy, I needed vector iterators to copy over the contents. While vector iterators are random access, in the case of copy
they only need to be input/output level, as all operations involve a simple read through of the vectors. There is no decrementing and 
the copy only needs one pass, so the simplest iterator level would be sufficient.

Since I'm using mostly standard containers, there is no real need to implement my own iterators. Furthermore, most of the classes I use will probably have fairly high level iterators.

### Generic Algorithms, Lambdas, and Bind
I used std::copy in my copy constructor for certain vectors. While this doesn't really take advantage of the full use of generic 
algorithms it can definitely save time, especially for larger vectors/many vectors.

----------
## Test Cases and Problems
----------
There have definitely been some problems, mainly with drawing the game board. The most interesting problem so far has been getting the snake to print correctly when moving. The reason for this is that, due to the way I wrote the print section for the snake, it printed incorrectly when traveling right, or when going right on a sharp 180 turn. Because I have to account for the added snake pieces while drawing the board, I increase the counter for width, but this can result in skipping of other parts. A solution was to sort the positions by width to solve the skipping.
Other interesting problems have been implementing unfamiliar parts such as clearing and redrawing the game board and taking user keyboard input. I had to do my own research for some of these, and it's interesting to see how much other functionality there is to C++.
I'm still looking for a way to fix the problem of the screen flicker due to the redrawing, although perhaps this has more to do with the size of the game board or complexity of the program. As a video game player myself, it has definitely made me quite curious as to how professional devs do what they do, especially in terms of graphics. If my computer has trouble perfectly rendering a simple console snake game, I can't imagine how the graphically intense images of modern games are rendered and redrawn/altered. That's probably the coolest insight I've had so far.

-------
Note: Will add most files to gitignore (ie. the .exe file, debug, etc.) but want to finish project first.
