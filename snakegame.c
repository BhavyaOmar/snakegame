

// #include <stdio.h>
// #include <stdlib.h>

// // Node structure for the snake body
// typedef struct Node
// {
//     int x, y;
//     struct Node *next;
// } Node;

// // Snake structure with head and tail pointers
// typedef struct
// {
//     Node *head;
//     Node *tail;
// } Snake;

// // Function to create a new node
// Node *createNode(int x, int y)
// {
//     Node *newNode = (Node *)malloc(sizeof(Node));
//     newNode->x = x;
//     newNode->y = y;
//     newNode->next = NULL;
//     return newNode;
// }

// // Initialize the snake with a given length
// Snake *initSnake(int length)
// {
//     Snake *snake = (Snake *)malloc(sizeof(Snake));
//     snake->head = createNode(5, 5); // Initial position
//     snake->tail = snake->head;

//     // Create additional body segments
//     for (int i = 1; i < length; i++)
//     {
//         Node *newSegment = createNode(snake->tail->x - 1, snake->tail->y);
//         snake->tail->next = newSegment;
//         snake->tail = newSegment;
//     }
//     return snake;
// }

// // Move the snake in the given direction (dx, dy)
// void moveSnake(Snake *snake, int dx, int dy)
// {
//     int prev_x = snake->head->x, prev_y = snake->head->y;
//     snake->head->x += dx;
//     snake->head->y += dy;

//     // Update the body positions
//     Node *current = snake->head->next;
//     while (current)
//     {
//         int temp_x = current->x, temp_y = current->y;
//         current->x = prev_x;
//         current->y = prev_y;
//         prev_x = temp_x;
//         prev_y = temp_y;
//         current = current->next;
//     }
// }

// // Add a new segment at the tail
// void growSnake(Snake *snake)
// {
//     Node *newSegment = createNode(snake->tail->x, snake->tail->y);
//     snake->tail->next = newSegment;
//     snake->tail = newSegment;
// }

// // Display the snake body
// void displaySnake(Snake *snake)
// {
//     Node *current = snake->head;
//     while (current)
//     {
//         printf("(%d, %d) -> ", current->x, current->y);
//         current = current->next;
//     }
//     printf("NULL\n");
// }

// // Free memory allocated for the snake
// void freeSnake(Snake *snake)
// {
//     Node *current = snake->head;
//     while (current)
//     {
//         Node *temp = current;
//         current = current->next;
//         free(temp);
//     }
//     free(snake);
// }

// // Main function
// int main()
// {
//     Snake *snake = initSnake(3);
//     displaySnake(snake);

//     // Move the snake to the right
//     moveSnake(snake, 1, 0);
//     displaySnake(snake);

//     // Grow the snake
//     growSnake(snake);
//     displaySnake(snake);

//     // Clean up memory
//     freeSnake(snake);

//     return 0;
// }
