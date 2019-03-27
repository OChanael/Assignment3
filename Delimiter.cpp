#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "GenStack.h"
#include "Delimiter.h"

using namespace std;

Delimiter::Delimiter() // constructor
{
}

Delimiter::~Delimiter() // destructor
{
}

// stacks for unpaired characters
GenStack<char> parenthesis(4);
GenStack<char> curlyBrace(4);
GenStack<char> bracket(4);

// stacks for line number of errors
GenStack<int> parenthesisLine(4);
GenStack<int> curlyBraceLine(4);
GenStack<int> bracketLine(4);

bool Delimiter::setInputFile(string name)
{
  ifstream fileTest;
  fileTest.open(name.c_str()); // opening file

  if (fileTest.is_open())
  {
    cout << "\n" << name.c_str() << " was loaded." << endl;
    fileTest.close();
    fileName = name;
    return true;
  }
  else
  {
    return false;
  }
}

void Delimiter::scanFile() // reading file
{
  ifstream inputFile;
  inputFile.open(fileName.c_str());

  string line;
  int lineNum = 1;
  int lineLength;
  bool errorFree = true;

  if (inputFile.is_open())
  {
    while(getline(inputFile, line) && errorFree)
    {
      lineLength = line.length();

      for(int i = 0; i < lineLength; ++i)
      {
        if(line[i] == '(') // checking for parenthesis
        {
          parenthesis.push(line[i]);
          parenthesisLine.push(lineNum);
        }
        else if(line[i] == ')')
        {
          if(parenthesis.isEmpty())
          {
            cout << "\nError: Missing '(' on or before line: " << lineNum << '\n' << endl;
            errorFree = false;
          }
          else
          {
            parenthesis.pop();
            parenthesisLine.pop();
          }
        }
          if(line[i] == '{') // checking for curly braces
          {
            curlyBrace.push(line[i]);
            curlyBraceLine.push(lineNum);
          }
          else if(line[i] == '}')
          {
            if(curlyBrace.isEmpty())
            {
              cout << "\nError: Missing '{' on or before line: " << lineNum << '\n' << endl;
              errorFree = false;
            }
            else
            {
              curlyBrace.pop();
              curlyBraceLine.pop();
            }
          }
          if(line[i] == '[') // checking for brackets
          {
            bracket.push(line[i]);
            bracketLine.push(lineNum);
          }
          else if(line[i] == ']')
          {
            if(bracket.isEmpty())
            {
              cout << "\nError: Missing '[' on or before line: " << lineNum << '\n' << endl;
              errorFree = false;
            }
            else
            {
              bracket.pop();
              bracketLine.pop();
            }
          }
        }
      ++lineNum;
    }
    if(errorFree)
    {
      if(!parenthesisLine.isEmpty())
      {
        cout << "\nError: Missing ')' on or after line: " << parenthesisLine.pop() << '\n' << endl;
      }
      else if(!curlyBraceLine.isEmpty())
      {
        cout << "\nError: Missing '}' on or after line: " << curlyBraceLine.pop() << '\n' << endl;
      }
      else if(bracketLine.isEmpty())
      {
        cout << "\nError: Missing ']' on or after line: " << bracketLine.pop() << '\n' << endl;
      }
    }
    if(errorFree && parenthesis.isEmpty() && curlyBrace.isEmpty() && bracket.isEmpty())
    {
      cout << "\nNo errors were found." << endl;
    }
  }
  inputFile.close();
}
void Delimiter::reset() // resets stacks so another file can be entered
{
  while(!parenthesis.isEmpty())
  {
    bracket.pop();
  }
  while(!curlyBrace.isEmpty())
  {
    bracket.pop();
  }
  while(!bracket.isEmpty())
  {
    bracket.pop();
  }
  while(!parenthesisLine.isEmpty())
  {
    bracket.pop();
  }
  while(!curlyBraceLine.isEmpty())
  {
    bracket.pop();
  }
  while(!bracketLine.isEmpty())
  {
    bracket.pop();
  }
}
