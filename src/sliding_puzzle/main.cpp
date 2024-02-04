void runPuzzle(size_t size);

int main() {
  std::cout << "q: Exit, Arrow Keys: Moving Tiles. Enter "
               "number of disks: ";

  size_t size{};
  std::cin >> size;

  if (size == 0) {
    std::cout << "Invalid size." << std::endl;
  }

  runPuzzle(size);
}
