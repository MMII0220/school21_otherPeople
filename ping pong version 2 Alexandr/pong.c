#include <stdio.h>

// ------------ input part ----------------
int leftRacketOffsetGlobal, rightRacketOffsetGlobal;

int getRightRacketOffset(int keyPressed);

int getLeftRacketOffset(int keyPressed);

void getInput();

int getBallXFromWall(int ballXOld, int ballX);

int getBallYFromWall(int ballYOld, int ballY);

int getracketY(int racketY, int offsetY);

int getBallXFromRacket(int ballXOld, int ballX);

int getBallYFromRacket(int ballYOld, int ballY);

int getBallCoordX(int ballOld, int ball);

int getBallCoordY(int ballOld, int ball);

void printGame(int ballX, int ballY,
    int leftRacket, int rightRacket,
    int leftPlayerScore, int rightPlayerScore);

int main() {
    Play();

    return 0;
}

int getLeftRacketOffset(int keyPressed) {
    if (keyPressed == 65 || keyPressed == 97) {  // if A or a pressed
        return -1;
    } else if (keyPressed == 122 || keyPressed == 90) {  // if Z or z pressed
        return 1;
    } else {
        return 0;
    }
}

int getRightRacketOffset(int keyPressed) {
    if (keyPressed == 75 || keyPressed == 107) {  // if K or k pressed
        return -1;
    } else if (keyPressed == 77 || keyPressed == 109) {  // if M or m pressed
        return 1;
    } else {
        return 0;
    }
}

void getInput() {
    int leftRacketOffset = 0, rightRacketOffset = 0;
    int keyPressed;

    keyPressed = getchar();

    if (keyPressed == 65 || keyPressed == 97 ||
    keyPressed == 122 || keyPressed == 90) {  // if A or Z in any case
       leftRacketOffset = getLeftRacketOffset(keyPressed);
       keyPressed = getchar();
       rightRacketOffset = getRightRacketOffset(keyPressed);
    } else if (keyPressed == 75 || keyPressed == 107 ||
    keyPressed == 77 || keyPressed == 109) {  // if K or M in any case
        rightRacketOffset = getRightRacketOffset(keyPressed);
        keyPressed = getchar();
        leftRacketOffset = getLeftRacketOffset(keyPressed);
    } else {  // if the first key is whitespace or invalid
        keyPressed = getchar();

        if (keyPressed == 65 || keyPressed == 97 ||
        keyPressed == 122 || keyPressed == 90) {
            leftRacketOffset = getLeftRacketOffset(keyPressed);
        } else {
            rightRacketOffset = getRightRacketOffset(keyPressed);
        }
    }

    leftRacketOffsetGlobal = leftRacketOffset;
    rightRacketOffsetGlobal = rightRacketOffset;
}

// -------------- positions part -------------

int getBallXFromWall(int ballXOld, int ballX) {
    int offset = ballX - ballXOld;

    return ballX + offset;
}

int getBallYFromWall(int ballYOld, int ballY) {
    int offset = ballYOld - ballY;

    return ballY + offset;
}

int getracketY(int racketY, int offsetY) {
    int updatedRacketY = racketY + offsetY;

    if (updatedRacketY < 0) {
        return 0;
    } else if (updatedRacketY > 22) {
        return 22;
    } else {
        return racketY + offsetY;
    }
}

int getBallXFromRacket(int ballXOld, int ballX) {
    int offset = ballXOld - ballX;

    return ballX + offset;
}

int getBallYFromRacket(int ballYOld, int ballY) {
    int offset = ballY - ballYOld;

    return ballY + offset;
}

int getBallCoordX(int ballOld, int ball) {
    int offset = ball - ballOld;
    int updatedBall = ball + offset;

    if (updatedBall < 0) {
        return 0;
    } else if (updatedBall > 79) {
        return 79;
    } else {
        return updatedBall;
    }
}

int getBallCoordY(int ballOld, int ball) {
    int offset = ball - ballOld;
    int updatedBall = ball + offset;

    if (updatedBall < 0) {
        return 0;
    } else if (updatedBall > 24) {
        return 24;
    } else {
        return updatedBall;
    }
}

//  -------------- paint part -----------

void clearConsole() {
    printf("\33[0d\33[2J");
}

void printGame(int ballX, int ballY,
    int leftRacket, int rightRacket,
    int leftPlayerScore, int rightPlayerScore) {  // prints everything: scores, field, balls rackets
    printf("\n\tScore: %d : %d\n\n", leftPlayerScore, rightPlayerScore);

    for (int y = -1; y < 26; y++) {
        for (int x = 0; x < 81; x++) {
            if (y == -1 || y == 25) {  // prints horizontal borders
                printf("-");
            } else if (x == 0 || x == 80) {  // prints vertical borders
                printf("|");
            } else if (x == ballX && y == ballY) {
                printf("o");
            } else if ((x == 1) && (y >= leftRacket && y <= leftRacket + 2)) {  // prints left racket
                printf("|");
            } else if ((x == 78) && (y >= rightRacket && y <= rightRacket + 2)) {  // prints right racket
                printf("|");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
}

void Play() {
    unsigned int leftPlayerScore = 0, rightPlayerScore = 0;
    int leftRacketY = 10, rightRacketY = 10;
    int ballX = 40, ballY = 12;
    int ballXOld = 41, ballYOld = 11;

    printGame(ballX, ballY, leftRacketY, rightRacketY, leftPlayerScore, rightPlayerScore);

    while (leftPlayerScore < 21 && rightPlayerScore < 21) {
        int leftRacketOffset, rightRacketOffset;

        getInput();  // changing global rackets offset values

        leftRacketOffset = leftRacketOffsetGlobal;
        rightRacketOffset = rightRacketOffsetGlobal;

        int updatedLeftracketY = getracketY(leftRacketY, leftRacketOffset);
        int updatedRightracketY = getracketY(rightRacketY, rightRacketOffset);
        int updatedBallX;
        int updatedBallY;

        if (ballY == 0 && ballX == 1 &&
        updatedLeftracketY == 0) {  // if left racket and ball in the top left corner
            updatedBallX = 2;
            updatedBallY = 1;
        } else if (ballY == 24 && ballX == 1 &&
        updatedLeftracketY == 22) {  // if left racket and ball in the bottom left corner
            updatedBallX = 2;
            updatedBallY = 23;
        } else if (ballY == 0 && ballX == 78 &&
        updatedRightracketY == 0) {  // if right racket and ball in the top right corner
            updatedBallX = 77;
            updatedBallY = 1;
        } else if (ballY == 24 && ballX == 78 &&
        updatedRightracketY == 22) {  // if right racket and ball in the bottom right corner
            updatedBallX = 77;
            updatedBallY = 23;
        } else if (ballY == 0 || ballY == 24) {  // ball hits horizontals walls
            updatedBallX = getBallXFromWall(ballXOld, ballX);
            updatedBallY = getBallYFromWall(ballYOld, ballY);
        } else if (ballX == 2 && ((ballY >= updatedLeftracketY
        && ballY <= updatedLeftracketY + 2))) {  // ball hits left racket
            updatedBallX = getBallXFromRacket(ballXOld, ballX);
            updatedBallY = getBallYFromRacket(ballYOld, ballY);
        } else if (ballX == 77 &&
        ((ballY >= updatedRightracketY
        && ballY <= updatedRightracketY + 2))) {  // ball hits right racket
            updatedBallX = getBallXFromRacket(ballXOld, ballX);
            updatedBallY = getBallYFromRacket(ballYOld, ballY);
        } else {
            updatedBallX = getBallCoordX(ballXOld, ballX);
            updatedBallY = getBallCoordY(ballYOld, ballY);
        }

        // updating vars

        ballXOld = ballX;
        ballYOld = ballY;

        ballX = updatedBallX;
        ballY = updatedBallY;

        leftRacketY = updatedLeftracketY;
        rightRacketY = updatedRightracketY;

        // goal event handling

        clearConsole();

        if (ballX == 0 || ballX == 79) {
            printf("\n\n\n\t\t\t\tGOAL!!!\n\n\n");

            leftRacketY = 10;
            rightRacketY = 10;

            if (ballX == 0) {
                rightPlayerScore++;

                ballXOld = 41;  // the ball will fly to the left at the start
                ballYOld = 11;
            } else {
                leftPlayerScore++;

                ballXOld = 39;;  // the ball will fly to the right at the start
                ballYOld = 13;
            }

            ballX = 40;
            ballY = 12;
        }

        printGame(ballX, ballY, leftRacketY, rightRacketY, leftPlayerScore, rightPlayerScore);
    }

    printf("GAME OVER\n");

    if (leftPlayerScore == 21) {
        printf("Player 1 wins! Congratulations!");
    } else if (rightPlayerScore == 21) {
        printf("Player 2 wins! Congratulations!");
    }
}

// ----------------------------

