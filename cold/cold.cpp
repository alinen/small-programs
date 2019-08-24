#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
  int n;
  std::cin >> n;
  //std::cout << "n = " << n << std::endl;

  int count = 0;
  for (int i = 0; i < n; i++)
  {
    int val;
    std::cin >> val;
    //std::cout << "v = " << val << std::endl;
    if (val < 0) count++;

  }
  std::cout << count << std::endl;

  return 0;
}

