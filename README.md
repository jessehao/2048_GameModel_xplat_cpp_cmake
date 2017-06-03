# 2048 Game Model
a cross-platform game model of 2048.
cmake project (minimum required: 2.8). 
programming language: c++.

## Classes
### SW2048Game : 
The main class of the Game.
#### Public Members:
**`SW2048Game(int order)` : the constructor of the class.**

*order* : order of the matrix(the game board: order*order).

**`restart()` : for start or restart the game.**

**`move(const Vector2& direction);` : operation method.**

*direction* : moving direction.

**`int getCell(int x, int y)` : returns value of specific cell accroding to a 2-dimension point.**

*x* : horizontal index.

*y* : vertical index.

**`int getMaxCell()` : returns value of the maximum cell from the game board.**

**`int getScore()` : returns score of the game.**

**`bool isPlaying()` : whether the game is still playing?**

**`bool isWin()` : whether the player is win?**

### ProcessingQueue : 
A specific queue data structure for processing cells in board after a specific operation.

### Vector2 : 
Representation of 2D vectors and points.


## Build
before build this project, you need [CMake](https://cmake.org/) first.

then change to the directory, and use the shell or cmd run following command.

```
cmake .
make
```
