#include "knights_tour.h"
#include <stdio.h>
#include <string.h>


/**
 * Knight move offsets
 *
 * Moves that a knight can make relative to the current position.
 * For example,
 * x += MOVES_X[0]; y += MOVES_Y[0]
 * corresponds to one of the eight moves that a knight can make, where `x` and
 * `y` represent the current position.
 */

const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};

/** Determines whether a move is possible from a starting position.
 *
 * @param move_id One of the 8 moves that the knight wants to make [0, 7]
 * @param x Current horizontal position
 * @param y Current vertical position
 * @param visited A two-dimensional array that represents the squares. If a
 * value is positive, then the corresponding field was visited before.
 * @return True if the move is possible, else false.
 */

bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited) //checks if move is within the board or not
{
    int new_x = (int)x + MOVES_X[move_id]; //new x position
    int new_y = (int)y + MOVES_Y[move_id]; //new y position

    if(new_x >= 0 && new_y >= 0 && new_x < SIZE && new_y < SIZE && visited[new_x][new_y] == 0) //This checks if knight move is within board and not yet visited
        return true; //its within parameters!
    else    
        return false; //Outside parameters
}

/** Attempts a tour by picking the first accessible square.
 *
 * @param start_x Horizontal starting position on the board
 * @param start_y Vertical starting position on the board
 * @return The number of visited squares
 * @note An array is created for the attempt
 */
unsigned int tour_greedy(size_t start_x, size_t start_y) //starts the greedy tour
{
    board_t visited;
    memset(visited, 0, sizeof(visited)); //all positions = 0

    size_t x = start_x; //current position x axis
    size_t y = start_y; //current position y axis

    unsigned int move_count = 1; //counter for visited squares

    visited[x][y] = move_count; //Start square = visited 
    while(1)
    {
        bool moved = false; //checks that we made successful move

        for (size_t i = 0; i < MOVE_COUNT; i++) //Iterates over up to 8 moves till it finds possible option
        {
            if(move_is_possible(i,x,y,visited))
            {
                //Moves knight and marks the new position
                x += MOVES_X[i];
                y += MOVES_Y[i];
                move_count++; //number of visited squares ++
                visited[x][y] = move_count; //marks visited square
                moved = true; //we found a valid move
                break; //greedy, first possible move
            }
        }
        if(!moved)
            break; //No possible moves = stop
    }
    return move_count; //returns the amount of visited squares before getting stuck
}


void greedy_tour_from_each_square(void)
{
    printf("GREEDY:\n");
    for (int y = 0; y < SIZE; y++) // Each row
    {
        for (int x = 0; x < SIZE; x++) //each column
        {
            unsigned int visited = tour_greedy(x,y); //starting square
            printf("%3u ", visited); //Print visited squares. %3u to format columns properly, especially for larger board sizes with 3 digits in each cell.
        }
        printf("\n"); //for new line after each finished row
    }

}