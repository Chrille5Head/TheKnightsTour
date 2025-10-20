#ifndef KNIGHTS_TOUR_H
#define KNIGHTS_TOUR_H

#include <stdbool.h>
#include <stddef.h>

#define SIZE 8      /**< Board size. */
#define MOVE_COUNT 8 /**< Number of moves that a knight can make */


typedef unsigned int board_t[SIZE][SIZE]; //array, making the board according to SIZE


//Creating array for all possible 8 knight moves
extern const int MOVES_X[MOVE_COUNT]; 
extern const int MOVES_Y[MOVE_COUNT];

/** Determines whether a move is possible from a starting position.
 *
 * @param move_id One of the 8 moves that the knight wants to make [0, 7]
 * @param x Current horizontal position
 * @param y Current vertical position
 * @param visited A two-dimensional array that represents the squares. If a
 * value is positive, then the corresponding field was visited before.
 * @return True if the move is possible, else false.
 */
bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited);

/** Attempts a tour by picking the first accessible square.
 *
 * @param start_x Horizontal starting position on the board
 * @param start_y Vertical starting position on the board
 * @return The number of visited squares
 * @note An array is created for the attempt
 */
unsigned int tour_greedy(size_t start_x, size_t start_y);

/**
 * @brief Runs greedy tour starting from all squares
 * Prints table with all squares and amount of moves total from each
 */
void greedy_tour_from_each_square(void);

#endif