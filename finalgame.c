#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.H>
#include <conio.h>

#define height 10
#define width 100

int foodX, foodY, score, highestScore, gameOver = 0, wallType;

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

    // Initiation snake from the center of the display screen...

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
    printf("Welcome to the SNAKE GAME !!!\n\nEnter 1 for solid walls and 2 for teleport walls\n");
    scanf("%d", &wallType);
    printf("Instructions :\n1. Use arrow keys to move the snake.\n");
}

void generateFood()
{

    foodX = rand() % (width - 2) + 1;
    foodY = rand() % (height - 2) + 1;
}

void moveSnake()
{

    int newX = snake.head->x;
    int newY = snake.head->y;

    // Motion

    switch (direction)
    {

    case 0:
        newX++;
        break;

    case 1:
        newY--;
        break;
    case 2:
        newX--;
        break;
    case 3:
        newY++;
        break;
    }

    // To make the snake move, we would create a new node at the 'new' coordinate and delete the last tail node from the old ones

    Node *newHead = (Node *)malloc(sizeof(Node));

    newHead->x = newX;
    newHead->y = newY;
    newHead->next = snake.head;
    snake.head = newHead;

    // If food eaten increase the size, else remove tail

    if (newX == foodX && newY == foodY)
    {
        score++;
        generateFood();
    }
    else
    {
        Node *prev = NULL;
        Node *curr = snake.head;

        while (curr->next)
        {
            prev = curr;
            curr = curr->next;
        }

        free(curr);
        prev->next = NULL;
        snake.tail = prev;
    }
}

void gameControl()
{
    int headX = snake.head->x;
    int headY = snake.head->y;

    // Arrow Controls
    if (_kbhit())
    {
        int changeDirection = direction;
        char key = getch();
        if (key == 224 || key == 0)
        {
            key = getch();

            switch (key)
            {

            case 72:
                // Up
                changeDirection = 1;
                break;

            case 77:
                // Right
                changeDirection = 0;
                break;
            case 80:
                // Down
                changeDirection = 3;
                break;
            case 75:
                // Left
                changeDirection = 2;
                break;
            }
        }

        if ((direction == 0 && changeDirection != 2) || (direction == 1 && changeDirection != 3) || (direction == 2 && changeDirection != 0) || (direction == 3 && changeDirection != 1))
        {

            direction = changeDirection;
        }
        else if (key == 27)
        {
            gameOver = 1;
        }
    }

    if (wallType == 1)
    {

        // Solid wall collision

        if (headX == 0 || headX == width - 1 || headY == 0 || headY == height - 1)
        {

            gameOver = 1;
        }
    }
    else
    {
        // Teleport Walls, even if user gives invalid input it would be the default wall type

        if (headX < 0)
        {
            snake.head->x = width - 2;
        }
        else if (headX > width - 1)
        {
            snake.head->x = 1;
        }
        else if (headY < 0)
        {
            snake.head->y = height - 2;
        }
        else if (headY > height - 1)
        {
            snake.head->y = 1;
        }
    }

    // Game over if snake's head collides on its body

    Node *temp = snake.head->next;
    while (temp)
    {
        if (snake.head->x == temp->x && snake.head->y == temp->y)
        {
            gameOver = 1;
            break;
        }
        temp = temp->next;
    }
}

// void snakeMovement(){

//     if(!_kbhit()){

//         switch(direction){
//             case 0;

//         }
//     }
// }

// void moveSnake(){

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
    help();
    init();
    initSnake();
    generateFood();
    hideCursor();

    while (!gameOver)
    {

        display();
        gameControl();
        moveSnake();
        Sleep(200);
        printf("\nScore : %d", score);
    }
}