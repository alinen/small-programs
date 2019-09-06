#include <iostream>
#include <string>

using namespace std;
int main(int argc, char** argv)
{
    cout << "Do you like jokes? (Y/N): ";
 
    string response;
    getline(std::cin, response);

    if (response == "Y") cout << "Me too!\n";
    else cout << "Ok, see you later\n"; 
}
