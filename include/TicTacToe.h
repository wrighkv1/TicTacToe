//
// Created by Kristen Wright on 10/1/20.
//

#ifndef TICTACTOE_TICTACTOE_H
#define TICTACTOE_TICTACTOE_H

#include <iostream>

class TicTacToe {

  char board[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int N = 3;
  char player = 'X';
  int n = 0;

  /**
   * Inserts user input into desired space on board
   *
   * @param a
   */
  void insert(char a);

  /**
   * Checks that user input is valid.
   *
   * @param a
   * @return bool
   */
  bool validInput(char a);

  /**
   * Alternates between player X and player O
   */
  void togglePlayer();

  /**
   * Ask for input from the user.
   */
  void input();

  /**
   * Checks if a player has won the game
   */
  bool checkWin();

public:
  /**
   * Default constructor that creates an empty board.
   */
  TicTacToe();

  /**
   * Sets game in motion until a player wins or there is a tie
   */
  void play();

  /**
   * Prints most updated board onto the screen
   */
  void draw();
};

#endif // TICTACTOE_TICTACTOE_H
