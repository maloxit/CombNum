#pragma once
#include <string>
#include <vector>
using namespace std;

class CombNumCommandManager
{
private:
  using cmdFunc_p = void(*)(istream &istrm, ostream &ostrm);

  static inline unsigned int SafeNotZeroMult(unsigned int arg1, unsigned int arg2)
  {
    unsigned int res = arg1 * arg2;
    if (res / arg1 != arg2 || res % arg1 != 0) throw exception("Unsigned integer overflow.");
    return res;
  }

  static inline unsigned int SafeAdd(unsigned int arg1, unsigned int arg2)
  {
    unsigned int res = arg1 + arg2;
    if (res < arg1 || res < arg2) throw exception("Unsigned integer overflow.");
    return res;
  }

  static unsigned int CalcU(unsigned int m, unsigned int n);
  static unsigned int CalcA(unsigned int m, unsigned int n);
  static unsigned int CalcP(unsigned int m);
  static unsigned int CalcC(unsigned int m, unsigned int n);
  static unsigned int CalcS(unsigned int m, unsigned int n);
  static unsigned int CalcB(unsigned int m);

  static void CmdFuncHelp(istream& istrm, ostream& ostrm);
  static void CmdFuncU(istream& istrm, ostream& ostrm);
  static void CmdFuncA(istream& istrm, ostream& ostrm);
  static void CmdFuncP(istream& istrm, ostream& ostrm);
  static void CmdFuncC(istream& istrm, ostream& ostrm);
  static void CmdFuncS(istream& istrm, ostream& ostrm);
  static void CmdFuncB(istream& istrm, ostream& ostrm);

  using command_t = struct
  {
    cmdFunc_p func;
    char str[21];
  };
  vector<command_t>* commands;

  static unsigned int ScanArg(istream& istrm);
  command_t* ScanCommand(istream& istrm);

public:
  CombNumCommandManager();
  ~CombNumCommandManager();
  bool ProcessCommand(string& commandStr, ostream &ostrm);
};