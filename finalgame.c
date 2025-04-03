#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.H>
#include <conio.h>

#define height 20
#define width 60

int foodX, foodY, headX, headY, bodyX, bodyY, score, highestScore, gameOver = 0;

// Node for snake body
typedef struct Node
{
    int x, y;
    struct Node *next;
} Node;

char direction = 'R';

// Linked List Operations

// Initialize snake

typedef struct
{
    Node *head = NULL;
    Node *tail = NULL;

} Snake;

Snake snake;

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
    snake.tial = newTail;
}

void help()
{
    printf("Welcome to the SNAKE GAME !!!");
}
void init()
{
    srand(time(NULL));
    score = 0;
}

void foodCoordinates()
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
                headY--;
            }
            else if (key == 77)
            { // Right
                headX++;
            }

            else if (key == 80)
            { // Down
                headY++;
            }
            else if (key == 75)
            { // Left
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

            // Snake

            else if (i == head->Y && j == head->X)
            {

                printf("O"); // Head
            }
            // else if (temp->next != NULL)
            // {
            //     while (temp)
            //     {
            //         printf("%c", 254); // Body
            //     }
            // }

            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{

    display();
}