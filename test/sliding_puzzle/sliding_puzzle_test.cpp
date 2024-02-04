#include "sliding_puzzle/sliding_puzzle.h"
#include "gtest/gtest.h"

#include <exception>

namespace sp {

std::pair<size_t, size_t> findFreeTile(const Board &board) {
  for (size_t i = 0; i < board.size(); i++) {
    for (size_t j = 0; j < board.size(); j++) {
      if (board[i][j] == 0)
        return {i, j};
    }
  }
  throw std::out_of_range{"can not find free tile"};
}

TEST(BoardTests, emptyBoard) {
  ASSERT_THROW(SlidingPuzzle{0}, std::out_of_range);
}

TEST(BoardTests, moveUp) {
  SlidingPuzzle puzzle{3};
  const Board &board{puzzle.getBoard()};
  auto [r1, c1] = findFreeTile(board);

  // movement of the numbered tile is opposite of the free tile
  puzzle.moveDown();
  auto [r2, c2] = findFreeTile(board);

  ASSERT_EQ(c2, c1);
  if (r1 == 2)
    ASSERT_EQ(r2, r1);
  else
    ASSERT_EQ(r2, r1 + 1);
}

TEST(BoardTests, moveDown) {
  SlidingPuzzle puzzle{3};
  const Board &board{puzzle.getBoard()};
  auto [r1, c1] = findFreeTile(board);

  // movement of the numbered tile is opposite of the free tile
  puzzle.moveUp();
  auto [r2, c2] = findFreeTile(board);

  ASSERT_EQ(c2, c1);
  if (r1 == 0)
    ASSERT_EQ(r2, r1);
  else
    ASSERT_EQ(r2, r1 - 1);
}

TEST(BoardTests, moveLeft) {
  SlidingPuzzle puzzle{3};
  const Board &board{puzzle.getBoard()};
  auto [r1, c1] = findFreeTile(board);

  // movement of the numbered tile is opposite of the free tile
  puzzle.moveRight();
  auto [r2, c2] = findFreeTile(board);

  ASSERT_EQ(r2, r1);
  if (c1 == 2)
    ASSERT_EQ(c2, c1);
  else
    ASSERT_EQ(c2, c1 + 1);
}

TEST(BoardTests, moveRight) {
  SlidingPuzzle puzzle{3};
  const Board &board{puzzle.getBoard()};
  auto [r1, c1] = findFreeTile(board);

  // movement of the numbered tile is opposite of the free tile
  puzzle.moveLeft();
  auto [r2, c2] = findFreeTile(board);

  ASSERT_EQ(r2, r1);
  if (c1 == 0)
    ASSERT_EQ(c2, c1);
  else
    ASSERT_EQ(c2, c1 - 1);
}

} // namespace sp
