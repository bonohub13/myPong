# Simple PONG game for GNU/Linux

May be compatible for other OS but not tested!

- - -

## ::::: HOW TO... :::::
### 1. Compile game
#### 1.1. Dependencies
1. OpenGL
2. CMake
#### 1.2. Instructions
1. Clone this repository with
```
git clone https://github.com/bonohub13/myPong.git
```
2. Make a new directory ```build``` under ```myPong```
```
cd myPong && mkdir build
```
3. Make a ```Makefile``` with CMake
```
cmake .. && make
```
4. Run the game under the ```src``` directory, and have fun!
```
./src/pong
```

- - -

## ::::: GOALS :::::
> - If done ~~GOAL~~
1. ~~Learn the basis of C++~~
2. Learn how to make packages that are precompilable
    - cmake files not figured out to make the package easily available to other projects
3. Make this accessible via the AUR (Arch User Repository)
4. Add features that are not on the source website
    - ex) rotating paddles
5. Make use of OpenGL and other cross platform APIs as much as possible
    - Not using platform specific libraries
6. Make the length of ```main.cpp``` as minimal as possible
    - If there are assets that are repetetive or huge, make them into a library

- - -

## ::::: PLANS :::::
1. Add rotation to paddles
    - Visualization of rotating paddle &rarr; COMPLETED!
    - Hit detection based on rotation of paddle &rarr; Not yet...
2. Add horizontal movement to paddles
    - After hit detection has been figured out
3. Add maps
    - ex) Curved walls???

- - -

## ::::: UPDATES ::::
- Jul 4, 2021
    - Initialized repository

- - -

## ::::: References :::::
1. [noobtuts, C++ Pong Game](https://www.noobtuts.com/cpp/2d-pong-game)
2. [@shohirose, CMakeの使い方, Qiita](https://qiita.com/shohirose/items/45fb49c6b429e8b204ac)