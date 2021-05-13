# 2048 Game ![alt text](https://github.com/AndresSM415/C-language/blob/main/images/2048%20exxx.png "Saquenme de Latinoamerica")
## Remember 2048 game? If not, there´s a quick recap: 
2048 is a game where there's a 4x4 matrix with tiles that have even numbers. 
The goal is to reach a tile with a value of 2048.
First you start with a sole tile of value 2, then by moving that tile back and forth it appears another one with value 2 as well.
If 2 tiles are in the same axis, and there is no tiles between them, by making a movement in that axis the two tiles will add together.

## Target
Our goal in this program is to replicate the game with the addition of a max points' recording system.

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

In case of a game over: count matrix´s value and compare with the latest record registered.

![alt text](https://github.com/AndresSM415/C-language/blob/main/images/algoritmo.PNG "Saquenme de Latinoamerica")

---
## Beta
To show a progress this is what I´ve done so far. It basically covers step 2 till number 4. So it shows a pre-established matrix that you can move with WASD keys
