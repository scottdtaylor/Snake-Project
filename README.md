# Snake-Project

-----


This project is meant to be a recreation of the classic game snake, both in C++ and Qt. I will first start by coding a simple version of the
game in C++ and then attempting to port to Qt. The user will interact with the game through key presses if possible. The game board itself
and the snake/food will be simple characters in the console version, although hopefull I will be able to upgrade the graphics using Qt
resources. This will allow me to test the logic of my code as well as some Qt implementation practices. I will attempt to use the ui if
possible.

Unfortunately, during a switch between the master and experimental branches, I somehow lost the .sln file on my local machine. I thus have been trying to find a way to clone these files into a new solution, but haven't had much luck yet.

It took a long time of moving files around and attempting to clone, but it appears I have solved the issue.  

The use of the project is simple:

Simply download the files given and run, preferably through an IDE as I don't have any knowledge of other platforms.

## Current features
--------
- The game now works on the console! All features of the base game have been implemented, and the only visual issue is the flickering, which is more a consequence of the platform used.

## Use of class material
--------
  So far, the project uses git functionality, including branching and merging, commits, and remote repositories. If I get to it, it will also incorporate Qt. As for other sections, I will go into those below. Another important note is that while I realize most of these are not being used in an efficient manner. However, I wanted to display what I've learned and where it can be applied rather than trying to find the perfect instance for each topic.

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
Later on, I used templates to create a variation on the pair class. I thought about inheriting from it but decided to write my own instead. 

### Smart Pointers
  As I have no heap memory yet, I haven't added any smart pointer functionality. 

### Iterators
  When using std::copy, I needed vector iterators to copy over the contents. While vector iterators are random access, in the case of copy
they only need to be input/output level, as all operations involve a simple read through of the vectors. There is no decrementing and 
the copy only needs one pass, so the simplest iterator level would be sufficient.
  Another use of iterators was using iterator parameters to check collisions. This requires less memory and does not require the full container be passed or referenced. I know there are other locations that would benefit from use of iterators, but for time's sake and minimal efficiency gain I have chosen to ignore them.

  Since I'm using mostly standard containers, there is no real need to implement my own iterators. Furthermore, most of the classes I use will probably have fairly high level iterators.

### Generic Algorithms, Lambdas, and Bind
  I used std::copy in my copy constructor for certain vectors. While this doesn't really take advantage of the full use of generic 
algorithms it can definitely save time, especially for larger vectors/many vectors.
  I attempted to use a lambda function at one point for sorting, but due to issues with the way the sort worked, it ultimately failed. However, if it had worked I would have been able to save a lot of effort due to the capture functionality of the lambda.

----------
## Test Cases and Problems
----------
  There have definitely been some problems, mainly with drawing the game board. The most interesting problem so far has been getting the snake to print correctly when moving. The reason for this is that, due to the way I wrote the print section for the snake, it printed incorrectly when traveling right, or when going right on a sharp 180 turn. Because I have to account for the added snake pieces while drawing the board, I increase the counter for width, but this can result in skipping of other parts. A solution was to sort the positions by width to solve the skipping.
  Other interesting problems have been implementing unfamiliar parts such as clearing and redrawing the game board and taking user keyboard input. I had to do my own research for some of these, and it's interesting to see how much other functionality there is to C++.
  I'm still looking for a way to fix the problem of the screen flicker due to the redrawing, although perhaps this has more to do with the size of the game board or complexity of the program. As a video game player myself, it has definitely made me quite curious as to how professional devs do what they do, especially in terms of graphics. If my computer has trouble perfectly rendering a simple console snake game, I can't imagine how the graphically intense images of modern games are rendered and redrawn/altered. That's probably the coolest insight I've had so far.
  Another massive problem was git, surprisingly. In trying to retroactively ignore files and remove them from the repo as suggested in the syllabus, the removal from git simultaneously removed them from my local filesystem. This meant that, when I removed the solution file, I could not longer open the project or edit it. Furthermore, this occured when switching branches a while after merging, which meant that, for a reason I don't know, I could not simply revert the commit and regain the file. Eventually, after a few hours of trying, I managed to clone the github repo into a new solution and that worked. Trying to ignore files was one of the larger issues I faced, and it definitely showed a downside of git when used with visual studio.

-------
## Lessons Learned
  Honestly, my end product isn't that impressive, and considering the game there are definitely easier ways to implement it, even if they are less standard and object-oriented. However, I'm still proud of it, especially considering the hours I put in, and I think I learned things from it that are much more important than the final product. For example, I definitely learned to be careful with git, and that sometimes using an interface such as visual studio can be misleading or unhelpful. I also found plenty on how to retroactively ignore files, clone and use a remote repository, and how to resolve conflicts between remote and local versions. 
  I also realized how easy it is to forget things, even those that should be common sense. For example partway through, due to some of the git issues, I stopped using the experimental branch and performed all my changes in master, which was not really intentional. I also spent a lot of time figuring out how to fix the printing loop, and later found a solution that was barely a few lines of code and made some longer changes I made fairly useless. Lastly, I often got caught up in the coding and forgot to apply some of the things I've learned where they would actually be most useful. For example I passed my snake vector by copy, instead of as iterators, which in this case was not a big deal but in a professional game would surely be bad. 
  Finally, I gained more respect for game programmers and devs in general. It takes time, effort, and suffering to make something, and then you have to turn right back around and fix all the bugs you picked up along the way. Synthesizing the knowledge of what and when to use techniques and the like was a challenge for this level of project; I now have a better perspective on how projects must work at a business level. Overall, I'd say that while the program itself is fairly basic, I learned some intangibles that I see as quite valuable.
