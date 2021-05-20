# 2048 Game ![alt text](https://github.com/AndresSM415/C-language/blob/main/images/2048%20exxx.png "Saquenme de Latinoamerica")
## Remember 2048 game? If not, there´s a quick recap: 
2048 is a game where there's a 4x4 matrix with tiles that have even numbers. 
The goal is to reach a tile with a value of 2048.
First you start with a sole tile of value 2, then by moving that tile back and forth it appears another one with value 2 as well.
If 2 tiles are in the same axis, and there is no tiles between them, by making a movement in that axis the two tiles will add together.

## Target
My goal in this program is to replicate the game with the addition of a max points' recording system.

### How to play ![alt text](https://github.com/AndresSM415/C-language/blob/main/images/wasd.jpg "WASD keys")
You will see the current matrix and by typying a single WASD letter the matrix will move as it is known intuitively:
* W: Up
* A: Left
* S: Downwards
* D: Right 

## Logic
The algorithm works as follows:
1. First you have to generate a random tile coordinate [j][i] where there's no number yet, and then put a 2 there.
2. After that, ask the user what´s the next movement.
3. Move the tile(s) in that direction.
4. Add the tiles with same numbers.
5. Move again the tiles if there was a new tile created in step 4.
6. Check if there is a tile with no numbers or neighbor tiles with same value. If not, game over.
7. If step 6 was successfully achieved, repeat from step 1.

In case of a game over: count matrix´s values and compare with the latest record registered.

![alt text](https://github.com/AndresSM415/C-language/blob/main/images/algoritmo.PNG "Saquenme de Latinoamerica")

## Video
[compiling video](https://youtu.be/Q9C4poj57p8)

## Autoevaluation

Complexity 3: It is complex due to the heavily use of pointers used to stack the tiles in any direction.

Functionality 3: It doesn´t crack with any key, and I haven´t seen an error during game.

Code 3: Pretty neat, functions well applied. All code´s lines commented.

Storage 3: Scores are saved permanently. Every matrix open is freed after use. Intuitive communication user-console.

Documentation 3: I think video was lovely. The game logic was discussed before, all code instructions are well explained.

Total: 14pts.

---
## References
Dave T. (2019, 29 julio). ¡APRENDE a JUGAR al 2048 con este TUTORIAL! (Y haz números grandes FÁCIL con esta ESTRATEGIA 😎) [Vídeo]. YouTube. https://www.youtube.com/watch?v=dUi4AcI7efM&t=548s

Ritchie, D. (1988). C Programming Language (1st ed.) [Libro electrónico]. Pearson. https://www.goodreads.com/book/show/515601.The_C_Programming_Language

Satu Elisa Schaeffer. (s. f.). satuelisa. twitch. https://www.twitch.tv/satuelisa
