#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#endif // _DEBUG
#include <stdlib.h>
#ifdef _DEBUG
#include <crtdbg.h>
#endif // _DEBUG
#include "CombNumCommandManager.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  CombNumCommandManager* cM = new CombNumCommandManager();
  bool isContinue = true;
  string* lineStr = new string(101, '\0');
  cout << "Type command 'H' for instructions." << endl << endl;
  while (isContinue && getline(cin, *lineStr))
  {
    cout << endl;

    try
    {
      isContinue = cM->ProcessCommand(*lineStr, cout);
    }
    catch (const std::exception& err)
    {
      cout << err.what() << endl;
    }
    cout << endl;
  }
  delete lineStr;
  delete cM;
#ifdef _DEBUG
  _CrtDumpMemoryLeaks();
#endif // _DEBUG
  return 0;
}