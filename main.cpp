#include <iostream>
#include "GenStack.h"
#include "Delimiter.h"

using namespace std;

int main(int argc, char** argv)
{
  bool run = true;
  Delimiter d;

  if (argc == 2) // check that there's only a single command line argument
  {
    if(d.setInputFile(argv[1])) // chcking for filepath in command line
    {
      d.scanFile();
      while (run)
      {
        cout << "\nDo you want to enter another file? (Y/N)" << endl;
        string answer;
        cin >> answer;

        if((answer == "y") || (answer == "Y"))
        {
          cout << "\nInput file name." << endl;
          string inputName;
          cin >> inputName;

          d.reset(); // emptying stacks before entering new file
          if(d.setInputFile(inputName))
          {
            d.scanFile();
          }
          else
          {
            cout << "\nFile not found, try again." << endl;
          }
        }
        else if((answer == "n") || (answer == "N"))
        {
          cout << "\nExiting program" << endl;
          run = false;
        }
        else
        {
          cout << "\nInvalid answer, please enter a valid response." << endl;
        }
      }
    }
  }
  else
  {
    cout << "\nYou must enter a single file name in the command line." << endl;
  }
  return 0;
}
