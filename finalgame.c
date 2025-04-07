#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.H>
#include <conio.h>

#define height 10
#define width 100

int foodX, foodY, headX, headY, bodyX, bodyY, score, highestScore, gameOver = 0;

int direction = 0; // Direction : 0 (right), 1 (up), 2 (left), 3 (down) ; Initially set to right

// Node for snake body
typedef struct Node
{
    int x, y;
    struct Node *next;
} Node;

void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    // Get current cursor info
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);

    cursorInfo.bVisible = FALSE; // Hide the cursor
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void init()
{
    srand(time(NULL));
    score = 0;
}

// Linked List Operations

// Initialize snake

struct Snake
{
    Node *head, *tail;
} snake;

void initSnake()
{

    snake.head = (Node *)malloc(sizeof(Node));
    snake.head->next = NULL;

    // starting the game from the center of the screen...

    snake.head->x = width / 2;
    snake.head->y = height / 2;
    snake.tail = snake.head;
}

void addTail(int x, int y)
{
    Node *newTail = (Node *)malloc(sizeof(Node));

    newTail->x = x;
    newTail->y = y;
    snake.tail->next = newTail;
    newTail->next = NULL;
    snake.tail = newTail;
}

void help()
{
    printf("Welcome to the SNAKE GAME !!!");
}

void generateFood()
{

    foodX = rand() % (width - 2) + 1;
    foodY = rand() % (height - 2) + 1;
}

void gameControl()
{
    headX = snake.head->x;
    headY = snake.head->y;

    // Arrow Controls
    if (_kbhit())
    {
        char key = getch();
        if (key == 224)
        {
            key = getch();
            if (key == 72)
            { // Up
                direction = 1;
                headY--;
            }
            else if (key == 77)
            { // Right
                direction = 0;
                headX++;
            }

            else if (key == 80)
            { // Down
                direction = 3;
                headY++;
            }
            else if (key == 75)
            { // Left
                direction = 2;
                headX--;
            }
        }
    }

    // Instead of wall collision, if snake goes in from one side, it would get out from other side

    if (headX == 0)
    {
        snake.head->y = width - 2;
    }
    else if (headX == width - 1)
    {
        snake.head->y = 1;
    }
    else if (headY == 0)
    {
        snake.head->x = height - 2;
    }
    else if (headY == height - 1)
    {
        snake.head->x = 1;
    }

    // Game over if snake's head collides on its body
}

// void snakeMovement(){

//     if(!_kbhit()){

//         switch(direction){
//             case 0;

//         }
//     }
// }

void display()
{
    system("cls");

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Node *temp = snake.head; // From here we would traverse across the body to print the body

            // Walls
            if (j == 0 && i == 0)
            {
                printf("%c", 218);
            }
            else if (j == width - 1 && i == 0)
            {
                printf("%c", 191);
            }
            else if (j == 0 && i == height - 1)
            {
                printf("%c", 192);
            }
            else if (j == width - 1 && i == height - 1)
            {
                printf("%c", 217);
            }
            else if (j == 0 || j == width - 1)
            {
                printf("%c", 179);
            }
            else if (i == 0 || i == height - 1)
            {
                printf("%c", 196);
            }

            // Food
            else if (i == foodY && j == foodX)
            {

                printf("O");
            }

            // Snake
            // Head
            else if (i == snake.head->y && j == snake.head->x)
            {

                switch (direction)
                {
                case 0:
                    printf(">");
                    break;

                case 1:
                    printf("^");
                    break;
                case 2:
                    printf("<");
                    break;
                case 3:
                    printf("v");
                    break;
                }
            }

            // Body
            else
            {
                Node *temp = snake.head->next;

                while (temp)
                {

                    if (i == temp->y && j == temp->x)
                    {

                        printf("0");
                        break;
                    }
                    temp = temp->next;
                }

                // If the given coordinate does not even belong to snake's body, it must be white space

                if (!temp)
                {

                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main()
{
    init();
    initSnake();
    generateFood();
    hideCursor();

    while (1)
    {
        if (_kbhit())
        {

            char key = getch();

            if (key == 27)
            {

                break;
            }
        }
        display();
        // gameControl();
    }
}