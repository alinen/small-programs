#include <iostream>
#include <cstring>

using namespace std;

string processRow(char* crossword, int row, int R, int C)
{
   string best = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
   int z = 0;
   while (z < R)
   {
      while (z < R && crossword[row*C + z] == '#')
      {
         z++;
         if (z == R) return best;
      }

      string tmp = "";
      tmp += crossword[row*C+z];
      z++;
      while (crossword[row*C + z] != '#')
      {
         tmp += crossword[row*C+z];
         z++;
      }

      if (tmp.length() > 1 && tmp < best)
      {
         best = tmp;
      }

   }
   return best;
}

string processCol(char* crossword, int col, int R, int C)
{
   string best = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
   int z = 0;
   while (z < C)
   {
      while (z < C && crossword[z*C + col] == '#')
      {
         z++;
         if (z == C) return best;
      }

      string tmp = "";
      tmp += crossword[z*C + col];
      z++;
      while (crossword[z*C + col] != '#')
      {
         tmp += crossword[z*C+col];
         z++;
      }

      if (tmp.length() > 1 && tmp < best)
      {
         best = tmp;
      }

   }
   return best;
}


int main()
{
   int R, C;
   cin >> R;
   cin >> C;

   char* crossword = new char[(R+2)*(C+2)];
   memset(crossword, '#', sizeof(char)*(R+2)*(C+2));
   for (int i = 1; i < R+1; i++)
   {
      for (int j = 1; j < C+1; j++)
      {
         char c;
         cin >> c;
         crossword[i*(C+2)+j] = c;
      }
   }
   
   for (int i = 0; i < R+2; i++)
   {
      for (int j = 0; j < C+2; j++)
      {
         cerr << crossword[i*(C+2)+j];
      }
      cerr << "\n";
   }

   string bestRow = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
   for (int i = 1; i < R+1; i++)
   {
      string tmp = processRow(crossword, i, R+2, C+2);
      if (tmp < bestRow)
      {
         bestRow = tmp;
      }
   }
   cerr << bestRow << endl;

   string bestCol = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
   for (int i = 1; i < C+1; i++)
   {
      string tmp = processCol(crossword, i, R+2, C+2);
      if (tmp < bestCol)
      {
         bestCol = tmp;
      }
   }
   cerr << bestCol << endl;

   cout << min(bestCol, bestRow) << endl;
}

