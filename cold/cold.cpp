// g++ hello.cpp
// ./a.exe < cold-001.in > cold-001.out
// diff cold-001.out cold-001.ans
#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
  int n;
  std::cin >> n;
  std::cerr << "n = " << n << std::endl;

  int count = 0;
  for (int i = 0; i < n; i++)
  {
    int val;
    std::cin >> val;
    std::cerr << "v = " << val << std::endl;
    if (val < 0) count++;

  }
  std::cout << count << std::endl;

  return 0;
}

