//
// Created by Kristen Wright on 10/1/20.
//

#include "TicTacToe.h"

TicTacToe::TicTacToe() = default;

void TicTacToe::play() {
  while (!checkWin() && n != 9) {
    draw();
    input();
    n++;
    togglePlayer();
  }

  if (n == 9 && !checkWin()) {
    std::cout << "Tied game!";
  }
}

void TicTacToe::draw() {

  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      std::cout << " " << board[row][col] << " ";
      if (col != 2) {
        std::cout << "|";
      }
    }
    std::cout << std::endl;
    if (row != 2)
      std::cout << "---+---+---" << std::endl;
  }
}

void TicTacToe::togglePlayer() {

  if (player == 'X')
    player = 'O';
  else
    player = 'X';
}

void TicTacToe::input() {

  char a;
  std::cout << "Press a number on the board: ";
  std::cin >> a;
  std::cout << std::endl;

  // Check that input is in valid range 1-9 and space is available
  while (!(a >= '1' && a <= '9') || !(validInput(a))) {
    if (!(a >= '1' && a <= '9'))
      std::cout << "Invalid input. Select from range 1-9" << std::endl;
    else
      std::cout
          << "Invalid input. Space already taken. Select from open spaces."
          << std::endl;
    std::cin >> a;
  }

  insert(a);
  if (checkWin()) {
    std::cout << "Player " << player << " wins!" << std::endl;
  }
}

void TicTacToe::insert(char a) {
  switch (a) {
  case '1':
    board[0][0] = player;
    break;
  case '2':
    board[0][1] = player;
    break;
  case '3':
    board[0][2] = player;
    break;
  case '4':
    board[1][0] = player;
    break;
  case '5':
    board[1][1] = player;
    break;
  case '6':
    board[1][2] = player;
    break;
  case '7':
    board[2][0] = player;
    break;
  case '8':
    board[2][1] = player;
    break;
  case '9':
    board[2][2] = player;
    break;
  }
}

bool TicTacToe::checkWin() {

  // checks each row
  if (board[0][0] == board[0][1] && board[0][0] == board[0][2])
    return true;

  else if (board[1][0] == board[1][1] && board[1][0] == board[1][2])
    return true;

  else if (board[2][0] == board[2][1] && board[2][0] == board[2][2])
    return true;

  // checks reach column
  else if (board[0][0] == board[1][0] && board[0][0] == board[2][0])
    return true;

  else if (board[0][1] == board[1][1] && board[0][1] == board[2][1])
    return true;

  else if (board[0][2] == board[1][2] && board[0][2] == board[2][2])
    return true;

  // check diagonal
  else if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    return true;

  else
    return board[0][2] == board[1][1] && board[0][2] == board[2][0];
}

bool TicTacToe::validInput(char a) {

  if (a == '1' && board[0][0] == '1')
    return true;
  else if (a == '2' && board[0][1] == '2')
    return true;
  else if (a == '3' && board[0][2] == '3')
    return true;
  else if (a == '4' && board[1][0] == '4')
    return true;
  else if (a == '5' && board[1][1] == '5')
    return true;
  else if (a == '6' && board[1][2] == '6')
    return true;
  else if (a == '7' && board[2][0] == '7')
    return true;
  else if (a == '8' && board[2][1] == '8')
    return true;
  else
    return a == '9' && board[2][2] == '9';
}
