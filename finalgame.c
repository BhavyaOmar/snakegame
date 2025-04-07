#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include<ncurses.h>
#include <string.h>

<<<<<<< HEAD
#define height 10
#define width 100
#define leaderboard_limit 3 // will display top 3 performers
=======
#define height 25
#define width 50
#define leaderboard_limit 3 // will display top 3 performers

char name[20];
>>>>>>> e35278c (Linux Ubuntu compatible snake game)

int foodX, foodY, score, highestScore = 0, gameOver = 0, wallType, sleepCount = 0;

int direction = 0; 
// Direction : 0 (right), 1 (up), 2 (left), 3 (down) ; Initially set to right

// Node for snake body
typedef struct Node
{
    int x, y;
    struct Node *next;
} Node;

struct Leaderboard
{
<<<<<<< HEAD

    char name[20];
    int userScore;

=======
    char name[20];
    int userScore;
>>>>>>> e35278c (Linux Ubuntu compatible snake game)
} entry[leaderboard_limit], temp;

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
    printf("Welcome to the SNAKE GAME !!!\n");
    printf("Enter your username :");
    scanf("%s", name);
    printf("Enter 1 for solid walls and 2 for teleport walls\n");
    scanf("%d", &wallType);
    printf("Instructions :\n1. Use arrow keys to move the snake.\n");
    getchar();
    getchar();
}
void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    // Get current cursor info
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);

    cursorInfo.bVisible = FALSE; // Hide the cursor
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
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

void gameControl(WINDOW *win)
{
    timeout(0);
    int headX = snake.head->x;
    int headY = snake.head->y;

    // Arrow Controls
        int changeDirection = direction;
        // Direction : 0 (right), 1 (up), 2 (left), 3 (down) ;
        int key = wgetch(win);
            switch (key)
            {

            case KEY_UP:
                // Up
                changeDirection = 1;
                break;

            case KEY_RIGHT:
                // Right
                changeDirection = 0;
                break;
            case KEY_DOWN:
                // Down
                changeDirection = 3;
                break;
            case KEY_LEFT:
                // Left
                changeDirection = 2;
                break;
            }

        if ((direction == 0 && changeDirection != 2) || (direction == 1 && changeDirection != 3) || (direction == 2 && changeDirection != 0) || (direction == 3 && changeDirection != 1))
        {

            direction = changeDirection;
        }
        else if (key == 27)
        {
            gameOver = 1;
        }

    if (wallType == 1)
    {

        // Solid wall collision

        if (headX == 0 || headX == width - 1 || headY == 0 || headY == height)
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

<<<<<<< HEAD
void display()
=======


void display(WINDOW *win)
>>>>>>> e35278c (Linux Ubuntu compatible snake game)
{
    werase(win);
    box(win, 0, 0);
    
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
        //Food
            if (i == foodY && j == foodX) {
                mvwprintw(win, i, j, "@");
            } else if (i == snake.head->y && j == snake.head->x) {
                switch (direction) {
                //snake head
                    case 0: mvwprintw(win, i, j, ">"); break;
                    case 1: mvwprintw(win, i, j, "^"); break;
                    case 2: mvwprintw(win, i, j, "<"); break;
                    case 3: mvwprintw(win, i, j, "v"); break;
                }
            } else {
                Node *temp = snake.head->next;
                while (temp) {
                //snake body
                    if (i == temp->y && j == temp->x) {
                        mvwprintw(win, i, j, "0");
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
    }
    mvwprintw(win, height-1, 1, "Score: %d", score);
    wrefresh(win);
}

// Leaderboard Functions

void loadHighScore()
{

    FILE *file = fopen("leaderboard.txt", "r");
    if (!file) {
    // Initialize default values
    for (int i = 0; i < leaderboard_limit; i++) {
        strcpy(entry[i].name, "None");
        entry[i].userScore = 0;
    }
    }

    int i = 0;

    while (i < leaderboard_limit && fscanf(file, "%s %d", entry[i].name, &entry[i].userScore) == 2)
    {
        i++;
    }
    fclose(file);

    // If entries are less than 3, fill with None 0

    for (; i < leaderboard_limit; i++)
    {
        strcpy(entry[i].name, "None");

        entry[i].userScore = 0;
    }
}

<<<<<<< HEAD
// Leaderboard Functions

void loadHighScore()
{

    FILE *file = fopen("leaderboard.txt", "r");

    int i = 0;

    while (i < leaderboard_limit && fscanf(file, "%s %d", entry[i].name, &entry[i].userScore) == 2)
    {
        i++;
    }
    fclose(file);

    // If entries are less than 3, fill with None 0

    for (; i < leaderboard_limit; i++)
    {
        strcpy(entry[i].name, "None");

        entry[i].userScore = 0;
    }
}

=======
>>>>>>> e35278c (Linux Ubuntu compatible snake game)
void updateLeaderboard(char playerName[20], int playerScore)
{

    for (int i = leaderboard_limit - 1; i >= 0; i--)
    {

        if (playerScore > entry[i].userScore)
        {
<<<<<<< HEAD
            for (int j = leaderboard_limit; j > i; j--)
=======
            for (int j = leaderboard_limit-1; j > i; j--)
>>>>>>> e35278c (Linux Ubuntu compatible snake game)
            { // Shifting one level down

                entry[j] = entry[j - 1];
            }

            // Inserting the new user

            strcpy(entry[i].name, playerName);
            entry[i].userScore = playerScore;
            break;
        }
    }

    // Save Leaderboard

    FILE *file = fopen("leaderboard.txt", "w");

    if (file)
    {

        for (int i = 0; i < leaderboard_limit; i++)
        {

            fprintf(file, "%s %d\n", entry[i].name, entry[i].userScore);
        }
        fclose(file);
    }
}

void gameOverDisplay()
{

    if (gameOver)
    {

        printf("\n=============\nGAME OVER !\n=============");
        printf("\nScore : %d", score);
    }
}
<<<<<<< HEAD
=======


>>>>>>> e35278c (Linux Ubuntu compatible snake game)
int main()
{
    char name[20];

    help();
<<<<<<< HEAD
    printf("Enter your username :");
    scanf("%s", name);
=======
    loadHighScore();
    initscr();
    noecho();
    curs_set(FALSE);
    
    WINDOW *win = newwin(height+2, width+2, 1, 1);
    keypad(win, TRUE);
    nodelay(win, TRUE);
    
>>>>>>> e35278c (Linux Ubuntu compatible snake game)
    init();
    initSnake();
    loadHighScore();
    generateFood();

    while (!gameOver)
    {
        display(win);
        gameControl(win);
        moveSnake();
<<<<<<< HEAD
        printf("\nScore : %d", score);

        // Gradually increasing the speed as score increases
        if (score < 45)
        {
            Sleep(200 - (score * 4));
        }
        else
        {
            Sleep(10);
        }
    }
    gameOverDisplay();
    updateLeaderboard(name, score);
}
=======
        usleep(200000);
    }
    endwin();
    gameOverDisplay();
    updateLeaderboard(name, score);
    return 0;
}
>>>>>>> e35278c (Linux Ubuntu compatible snake game)
