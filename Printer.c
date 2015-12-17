/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include "Printer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INDENT_WIDTH 2

int _n_;
char* buf_;
int cur_;
int buf_size;

/* You may wish to change the renderC functions */
void renderC(Char c)
{
  if (c == '{')
  {
     bufAppendC('\n');
     indent();
     bufAppendC(c);
     _n_ = _n_ + INDENT_WIDTH;
     bufAppendC('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppendC(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppendC(c);
  }
  else if (c == '}')
  {
     int t;
     _n_ = _n_ - INDENT_WIDTH;
     for(t=0; t<INDENT_WIDTH; t++) {
       backup();
     }
     bufAppendC(c);
     bufAppendC('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppendC(c);
     bufAppendC(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppendC(c);
     bufAppendC('\n');
     indent();
  }
  else if (c == 0) return;
  else
  {
     bufAppendC(' ');
     bufAppendC(c);
     bufAppendC(' ');
  }
}
void renderS(String s)
{
  if(strlen(s) > 0)
  {
    bufAppendS(s);
    bufAppendC(' ');
  }
}
void indent(void)
{
  int n = _n_;
  while (n > 0)
  {
    bufAppendC(' ');
    n--;
  }
}
void backup(void)
{
  if (buf_[cur_ - 1] == ' ')
  {
    buf_[cur_ - 1] = 0;
    cur_--;
  }
}
char* printProgram(Program p)
{
  _n_ = 0;
  bufReset();
  ppProgram(p, 0);
  return buf_;
}
char* printFunction(Function p)
{
  _n_ = 0;
  bufReset();
  ppFunction(p, 0);
  return buf_;
}
char* printDecl(Decl p)
{
  _n_ = 0;
  bufReset();
  ppDecl(p, 0);
  return buf_;
}
char* printListFunction(ListFunction p)
{
  _n_ = 0;
  bufReset();
  ppListFunction(p, 0);
  return buf_;
}
char* printListStm(ListStm p)
{
  _n_ = 0;
  bufReset();
  ppListStm(p, 0);
  return buf_;
}
char* printListDecl(ListDecl p)
{
  _n_ = 0;
  bufReset();
  ppListDecl(p, 0);
  return buf_;
}
char* printListIdent(ListIdent p)
{
  _n_ = 0;
  bufReset();
  ppListIdent(p, 0);
  return buf_;
}
char* printStm(Stm p)
{
  _n_ = 0;
  bufReset();
  ppStm(p, 0);
  return buf_;
}
char* printExp(Exp p)
{
  _n_ = 0;
  bufReset();
  ppExp(p, 0);
  return buf_;
}
char* printListExp(ListExp p)
{
  _n_ = 0;
  bufReset();
  ppListExp(p, 0);
  return buf_;
}
char* printType(Type p)
{
  _n_ = 0;
  bufReset();
  ppType(p, 0);
  return buf_;
}
char* showProgram(Program p)
{
  _n_ = 0;
  bufReset();
  shProgram(p);
  return buf_;
}
char* showFunction(Function p)
{
  _n_ = 0;
  bufReset();
  shFunction(p);
  return buf_;
}
char* showDecl(Decl p)
{
  _n_ = 0;
  bufReset();
  shDecl(p);
  return buf_;
}
char* showListFunction(ListFunction p)
{
  _n_ = 0;
  bufReset();
  shListFunction(p);
  return buf_;
}
char* showListStm(ListStm p)
{
  _n_ = 0;
  bufReset();
  shListStm(p);
  return buf_;
}
char* showListDecl(ListDecl p)
{
  _n_ = 0;
  bufReset();
  shListDecl(p);
  return buf_;
}
char* showListIdent(ListIdent p)
{
  _n_ = 0;
  bufReset();
  shListIdent(p);
  return buf_;
}
char* showStm(Stm p)
{
  _n_ = 0;
  bufReset();
  shStm(p);
  return buf_;
}
char* showExp(Exp p)
{
  _n_ = 0;
  bufReset();
  shExp(p);
  return buf_;
}
char* showListExp(ListExp p)
{
  _n_ = 0;
  bufReset();
  shListExp(p);
  return buf_;
}
char* showType(Type p)
{
  _n_ = 0;
  bufReset();
  shType(p);
  return buf_;
}
void ppProgram(Program _p_, int _i_)
{
  switch(_p_->kind)
  {
  case is_Prog:
    if (_i_ > 0) renderC(_L_PAREN);
    ppListFunction(_p_->u.prog_.listfunction_, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Program!\n");
    exit(1);
  }
}

void ppFunction(Function _p_, int _i_)
{
  switch(_p_->kind)
  {
  case is_Global:
    if (_i_ > 0) renderC(_L_PAREN);
    ppType(_p_->u.global_.type_, 0);
    ppIdent(_p_->u.global_.ident_, 0);
    renderC(';');

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_Fun:
    if (_i_ > 0) renderC(_L_PAREN);
    ppType(_p_->u.fun_.type_, 0);
    ppIdent(_p_->u.fun_.ident_, 0);
    renderC('(');
    ppListDecl(_p_->u.fun_.listdecl_, 0);
    renderC(')');
    renderC('{');
    ppListStm(_p_->u.fun_.liststm_, 0);
    renderC('}');

    if (_i_ > 0) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Function!\n");
    exit(1);
  }
}

void ppDecl(Decl _p_, int _i_)
{
  switch(_p_->kind)
  {
  case is_Dec:
    if (_i_ > 0) renderC(_L_PAREN);
    ppType(_p_->u.dec_.type_, 0);
    ppListIdent(_p_->u.dec_.listident_, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Decl!\n");
    exit(1);
  }
}

void ppListFunction(ListFunction listfunction, int i)
{
  while(listfunction!= 0)
  {
    if (listfunction->listfunction_ == 0)
    {
      ppFunction(listfunction->function_, i);
      renderS("");
      listfunction = 0;
    }
    else
    {
      ppFunction(listfunction->function_, i);
      renderS("");
      listfunction = listfunction->listfunction_;
    }
  }
}

void ppListStm(ListStm liststm, int i)
{
  while(liststm!= 0)
  {
    if (liststm->liststm_ == 0)
    {
      ppStm(liststm->stm_, i);
      renderS("");
      liststm = 0;
    }
    else
    {
      ppStm(liststm->stm_, i);
      renderS("");
      liststm = liststm->liststm_;
    }
  }
}

void ppListDecl(ListDecl listdecl, int i)
{
  while(listdecl!= 0)
  {
    if (listdecl->listdecl_ == 0)
    {
      ppDecl(listdecl->decl_, i);

      listdecl = 0;
    }
    else
    {
      ppDecl(listdecl->decl_, i);
      renderC(',');
      listdecl = listdecl->listdecl_;
    }
  }
}

void ppListIdent(ListIdent listident, int i)
{
  while(listident!= 0)
  {
    if (listident->listident_ == 0)
    {
      ppIdent(listident->ident_, i);

      listident = 0;
    }
    else
    {
      ppIdent(listident->ident_, i);
      renderC(',');
      listident = listident->listident_;
    }
  }
}

void ppStm(Stm _p_, int _i_)
{
  switch(_p_->kind)
  {
  case is_SDecl:
    if (_i_ > 0) renderC(_L_PAREN);
    ppDecl(_p_->u.sdecl_.decl_, 0);
    renderC(';');

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SExp:
    if (_i_ > 0) renderC(_L_PAREN);
    ppExp(_p_->u.sexp_.exp_, 0);
    renderC(';');

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SBlock:
    if (_i_ > 0) renderC(_L_PAREN);
    renderC('{');
    ppListStm(_p_->u.sblock_.liststm_, 0);
    renderC('}');

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SIf:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("if");
    renderC('(');
    ppExp(_p_->u.sif_.exp_, 0);
    renderC(')');
    renderS("then");
    ppStm(_p_->u.sif_.stm_, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SIfElse:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("if");
    renderC('(');
    ppExp(_p_->u.sifelse_.exp_, 0);
    renderC(')');
    renderS("then");
    ppStm(_p_->u.sifelse_.stm_1, 0);
    renderS("else");
    ppStm(_p_->u.sifelse_.stm_2, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SFor:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("for");
    renderC('(');
    ppExp(_p_->u.sfor_.exp_1, 0);
    renderC(';');
    ppExp(_p_->u.sfor_.exp_2, 0);
    renderC(';');
    ppExp(_p_->u.sfor_.exp_3, 0);
    renderC(')');
    ppStm(_p_->u.sfor_.stm_, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SWhile:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("while");
    renderC('(');
    ppExp(_p_->u.swhile_.exp_, 0);
    renderC(')');
    ppStm(_p_->u.swhile_.stm_, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SReturn:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("return");
    ppExp(_p_->u.sreturn_.exp_, 0);
    renderC(';');

    if (_i_ > 0) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Stm!\n");
    exit(1);
  }
}

void ppExp(Exp _p_, int _i_)
{
  switch(_p_->kind)
  {
  case is_EAss:
    if (_i_ > 0) renderC(_L_PAREN);
    ppIdent(_p_->u.eass_.ident_, 0);
    renderC('=');
    ppExp(_p_->u.eass_.exp_, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_ELt:
    if (_i_ > 1) renderC(_L_PAREN);
    ppExp(_p_->u.elt_.exp_1, 2);
    renderC('<');
    ppExp(_p_->u.elt_.exp_2, 2);

    if (_i_ > 1) renderC(_R_PAREN);
    break;

  case is_EAdd:
    if (_i_ > 2) renderC(_L_PAREN);
    ppExp(_p_->u.eadd_.exp_1, 2);
    renderC('+');
    ppExp(_p_->u.eadd_.exp_2, 3);

    if (_i_ > 2) renderC(_R_PAREN);
    break;

  case is_ESub:
    if (_i_ > 2) renderC(_L_PAREN);
    ppExp(_p_->u.esub_.exp_1, 2);
    renderC('-');
    ppExp(_p_->u.esub_.exp_2, 3);

    if (_i_ > 2) renderC(_R_PAREN);
    break;

  case is_EMul:
    if (_i_ > 3) renderC(_L_PAREN);
    ppExp(_p_->u.emul_.exp_1, 3);
    renderC('*');
    ppExp(_p_->u.emul_.exp_2, 4);

    if (_i_ > 3) renderC(_R_PAREN);
    break;

  case is_Call:
    if (_i_ > 4) renderC(_L_PAREN);
    ppIdent(_p_->u.call_.ident_, 0);
    renderC('(');
    ppListExp(_p_->u.call_.listexp_, 0);
    renderC(')');

    if (_i_ > 4) renderC(_R_PAREN);
    break;

  case is_EVar:
    if (_i_ > 4) renderC(_L_PAREN);
    ppIdent(_p_->u.evar_.ident_, 0);

    if (_i_ > 4) renderC(_R_PAREN);
    break;

  case is_EStr:
    if (_i_ > 4) renderC(_L_PAREN);
    ppString(_p_->u.estr_.string_, 0);

    if (_i_ > 4) renderC(_R_PAREN);
    break;

  case is_EInt:
    if (_i_ > 4) renderC(_L_PAREN);
    ppInteger(_p_->u.eint_.integer_, 0);

    if (_i_ > 4) renderC(_R_PAREN);
    break;

  case is_EDouble:
    if (_i_ > 4) renderC(_L_PAREN);
    ppDouble(_p_->u.edouble_.double_, 0);

    if (_i_ > 4) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Exp!\n");
    exit(1);
  }
}

void ppListExp(ListExp listexp, int i)
{
  while(listexp!= 0)
  {
    if (listexp->listexp_ == 0)
    {
      ppExp(listexp->exp_, i);

      listexp = 0;
    }
    else
    {
      ppExp(listexp->exp_, i);
      renderC(',');
      listexp = listexp->listexp_;
    }
  }
}

void ppType(Type _p_, int _i_)
{
  switch(_p_->kind)
  {
  case is_TInt:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("int");

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_TDouble:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("double");

    if (_i_ > 0) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Type!\n");
    exit(1);
  }
}

void ppInteger(Integer n, int i)
{
  char tmp[16];
  sprintf(tmp, "%d", n);
  bufAppendS(tmp);
}
void ppDouble(Double d, int i)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppendS(tmp);
}
void ppChar(Char c, int i)
{
  bufAppendC('\'');
  bufAppendC(c);
  bufAppendC('\'');
}
void ppString(String s, int i)
{
  bufAppendC('\"');
  bufAppendS(s);
  bufAppendC('\"');
}
void ppIdent(String s, int i)
{
  renderS(s);
}

void shProgram(Program _p_)
{
  switch(_p_->kind)
  {
  case is_Prog:
  bufAppendC('(');

    bufAppendS("Prog");

  bufAppendC(' ');

    bufAppendC('[');
    shListFunction(_p_->u.prog_.listfunction_);
    bufAppendC(']');

  bufAppendC(')');

    break;


  default:
    fprintf(stderr, "Error: bad kind field when showing Program!\n");
    exit(1);
  }
}

void shFunction(Function _p_)
{
  switch(_p_->kind)
  {
  case is_Global:
  bufAppendC('(');

    bufAppendS("Global");

  bufAppendC(' ');

    bufAppendC('[');
    shType(_p_->u.global_.type_);
    bufAppendC(']');
  bufAppendC(' ');
    bufAppendC('[');
    shIdent(_p_->u.global_.ident_);
    bufAppendC(']');

  bufAppendC(')');

    break;

  case is_Fun:
  bufAppendC('(');

    bufAppendS("Fun");

  bufAppendC(' ');

    bufAppendC('[');
    shType(_p_->u.fun_.type_);
    bufAppendC(']');
  bufAppendC(' ');
    bufAppendC('[');
    shIdent(_p_->u.fun_.ident_);
    bufAppendC(']');
  bufAppendC(' ');
    bufAppendC('[');
    shListDecl(_p_->u.fun_.listdecl_);
    bufAppendC(']');
  bufAppendC(' ');
    bufAppendC('[');
    shListStm(_p_->u.fun_.liststm_);
    bufAppendC(']');

  bufAppendC(')');

    break;


  default:
    fprintf(stderr, "Error: bad kind field when showing Function!\n");
    exit(1);
  }
}

void shDecl(Decl _p_)
{
  switch(_p_->kind)
  {
  case is_Dec:
  bufAppendC('(');

    bufAppendS("Dec");

  bufAppendC(' ');

    bufAppendC('[');
    shType(_p_->u.dec_.type_);
    bufAppendC(']');
  bufAppendC(' ');
    bufAppendC('[');
    shListIdent(_p_->u.dec_.listident_);
    bufAppendC(']');

  bufAppendC(')');

    break;


  default:
    fprintf(stderr, "Error: bad kind field when showing Decl!\n");
    exit(1);
  }
}

void shListFunction(ListFunction listfunction)
{
  while(listfunction!= 0)
  {
    if (listfunction->listfunction_)
    {
      shFunction(listfunction->function_);
      bufAppendS(", ");
      listfunction = listfunction->listfunction_;
    }
    else
    {
      shFunction(listfunction->function_);
      listfunction = 0;
    }
  }
}

void shListStm(ListStm liststm)
{
  while(liststm!= 0)
  {
    if (liststm->liststm_)
    {
      shStm(liststm->stm_);
      bufAppendS(", ");
      liststm = liststm->liststm_;
    }
    else
    {
      shStm(liststm->stm_);
      liststm = 0;
    }
  }
}

void shListDecl(ListDecl listdecl)
{
  while(listdecl!= 0)
  {
    if (listdecl->listdecl_)
    {
      shDecl(listdecl->decl_);
      bufAppendS(", ");
      listdecl = listdecl->listdecl_;
    }
    else
    {
      shDecl(listdecl->decl_);
      listdecl = 0;
    }
  }
}

void shListIdent(ListIdent listident)
{
  while(listident!= 0)
  {
    if (listident->listident_)
    {
      shIdent(listident->ident_);
      bufAppendS(", ");
      listident = listident->listident_;
    }
    else
    {
      shIdent(listident->ident_);
      listident = 0;
    }
  }
}

void shStm(Stm _p_)
{
  switch(_p_->kind)
  {
  case is_SDecl:
  bufAppendC('(');

    bufAppendS("SDecl");

  bufAppendC(' ');

    bufAppendC('[');
    shDecl(_p_->u.sdecl_.decl_);
    bufAppendC(']');

  bufAppendC(')');

    break;

  case is_SExp:
  bufAppendC('(');

    bufAppendS("SExp");

  bufAppendC(' ');

    bufAppendC('[');
    shExp(_p_->u.sexp_.exp_);
    bufAppendC(']');

  bufAppendC(')');

    break;

  case is_SBlock:
  bufAppendC('(');

    bufAppendS("SBlock");

  bufAppendC(' ');

    bufAppendC('[');
    shListStm(_p_->u.sblock_.liststm_);
    bufAppendC(']');

  bufAppendC(')');

    break;

  case is_SIf:
  bufAppendC('(');

    bufAppendS("SIf");

  bufAppendC(' ');

    bufAppendC('[');
    shExp(_p_->u.sif_.exp_);
    bufAppendC(']');
  bufAppendC(' ');
    bufAppendC('[');
    shStm(_p_->u.sif_.stm_);
    bufAppendC(']');

  bufAppendC(')');

    break;

  case is_SIfElse:
  bufAppendC('(');

    bufAppendS("SIfElse");

  bufAppendC(' ');

    bufAppendC('[');
    shExp(_p_->u.sifelse_.exp_);
    bufAppendC(']');
  bufAppendC(' ');
    shStm(_p_->u.sifelse_.stm_1);
  bufAppendC(' ');
    shStm(_p_->u.sifelse_.stm_2);

  bufAppendC(')');

    break;

  case is_SFor:
  bufAppendC('(');

    bufAppendS("SFor");

  bufAppendC(' ');

    shExp(_p_->u.sfor_.exp_1);
  bufAppendC(' ');
    shExp(_p_->u.sfor_.exp_2);
  bufAppendC(' ');
    shExp(_p_->u.sfor_.exp_3);
  bufAppendC(' ');
    bufAppendC('[');
    shStm(_p_->u.sfor_.stm_);
    bufAppendC(']');

  bufAppendC(')');

    break;

  case is_SWhile:
  bufAppendC('(');

    bufAppendS("SWhile");

  bufAppendC(' ');

    bufAppendC('[');
    shExp(_p_->u.swhile_.exp_);
    bufAppendC(']');
  bufAppendC(' ');
    bufAppendC('[');
    shStm(_p_->u.swhile_.stm_);
    bufAppendC(']');

  bufAppendC(')');

    break;

  case is_SReturn:
  bufAppendC('(');

    bufAppendS("SReturn");

  bufAppendC(' ');

    bufAppendC('[');
    shExp(_p_->u.sreturn_.exp_);
    bufAppendC(']');

  bufAppendC(')');

    break;


  default:
    fprintf(stderr, "Error: bad kind field when showing Stm!\n");
    exit(1);
  }
}

void shExp(Exp _p_)
{
  switch(_p_->kind)
  {
  case is_EAss:
  bufAppendC('(');

    bufAppendS("EAss");

  bufAppendC(' ');

    bufAppendC('[');
    shIdent(_p_->u.eass_.ident_);
    bufAppendC(']');
  bufAppendC(' ');
    bufAppendC('[');
    shExp(_p_->u.eass_.exp_);
    bufAppendC(']');

  bufAppendC(')');

    break;

  case is_ELt:
  bufAppendC('(');

    bufAppendS("ELt");

  bufAppendC(' ');

    shExp(_p_->u.elt_.exp_1);
  bufAppendC(' ');
    shExp(_p_->u.elt_.exp_2);

  bufAppendC(')');

    break;

  case is_EAdd:
  bufAppendC('(');

    bufAppendS("EAdd");

  bufAppendC(' ');

    shExp(_p_->u.eadd_.exp_1);
  bufAppendC(' ');
    shExp(_p_->u.eadd_.exp_2);

  bufAppendC(')');

    break;

  case is_ESub:
  bufAppendC('(');

    bufAppendS("ESub");

  bufAppendC(' ');

    shExp(_p_->u.esub_.exp_1);
  bufAppendC(' ');
    shExp(_p_->u.esub_.exp_2);

  bufAppendC(')');

    break;

  case is_EMul:
  bufAppendC('(');

    bufAppendS("EMul");

  bufAppendC(' ');

    shExp(_p_->u.emul_.exp_1);
  bufAppendC(' ');
    shExp(_p_->u.emul_.exp_2);

  bufAppendC(')');

    break;

  case is_Call:
  bufAppendC('(');

    bufAppendS("Call");

  bufAppendC(' ');

    bufAppendC('[');
    shIdent(_p_->u.call_.ident_);
    bufAppendC(']');
  bufAppendC(' ');
    bufAppendC('[');
    shListExp(_p_->u.call_.listexp_);
    bufAppendC(']');

  bufAppendC(')');

    break;

  case is_EVar:
  bufAppendC('(');

    bufAppendS("EVar");

  bufAppendC(' ');

    bufAppendC('[');
    shIdent(_p_->u.evar_.ident_);
    bufAppendC(']');

  bufAppendC(')');

    break;

  case is_EStr:
  bufAppendC('(');

    bufAppendS("EStr");

  bufAppendC(' ');

    bufAppendC('[');
    shString(_p_->u.estr_.string_);
    bufAppendC(']');

  bufAppendC(')');

    break;

  case is_EInt:
  bufAppendC('(');

    bufAppendS("EInt");

  bufAppendC(' ');

    bufAppendC('[');
    shInteger(_p_->u.eint_.integer_);
    bufAppendC(']');

  bufAppendC(')');

    break;

  case is_EDouble:
  bufAppendC('(');

    bufAppendS("EDouble");

  bufAppendC(' ');

    bufAppendC('[');
    shDouble(_p_->u.edouble_.double_);
    bufAppendC(']');

  bufAppendC(')');

    break;


  default:
    fprintf(stderr, "Error: bad kind field when showing Exp!\n");
    exit(1);
  }
}

void shListExp(ListExp listexp)
{
  while(listexp!= 0)
  {
    if (listexp->listexp_)
    {
      shExp(listexp->exp_);
      bufAppendS(", ");
      listexp = listexp->listexp_;
    }
    else
    {
      shExp(listexp->exp_);
      listexp = 0;
    }
  }
}

void shType(Type _p_)
{
  switch(_p_->kind)
  {
  case is_TInt:

    bufAppendS("TInt");




    break;

  case is_TDouble:

    bufAppendS("TDouble");




    break;


  default:
    fprintf(stderr, "Error: bad kind field when showing Type!\n");
    exit(1);
  }
}

void shInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppendS(tmp);
}
void shDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppendS(tmp);
}
void shChar(Char c)
{
  bufAppendC('\'');
  bufAppendC(c);
  bufAppendC('\'');
}
void shString(String s)
{
  bufAppendC('\"');
  bufAppendS(s);
  bufAppendC('\"');
}
void shIdent(String s)
{
  bufAppendC('\"');
  bufAppendS(s);
  bufAppendC('\"');
}

void bufAppendS(const char* s)
{
  int len = strlen(s);
  int n;
  while (cur_ + len > buf_size)
  {
    buf_size *= 2; /* Double the buffer size */
    resizeBuffer();
  }
  for(n = 0; n < len; n++)
  {
    buf_[cur_ + n] = s[n];
  }
  cur_ += len;
  buf_[cur_] = 0;
}
void bufAppendC(const char c)
{
  if (cur_ == buf_size)
  {
    buf_size *= 2; /* Double the buffer size */
    resizeBuffer();
  }
  buf_[cur_] = c;
  cur_++;
  buf_[cur_] = 0;
}
void bufReset(void)
{
  cur_ = 0;
  buf_size = BUFFER_INITIAL;
  resizeBuffer();
  memset(buf_, 0, buf_size);
}
void resizeBuffer(void)
{
  char* temp = (char*) malloc(buf_size);
  if (!temp)
  {
    fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
    exit(1);
  }
  if (buf_)
  {
    strncpy(temp, buf_, buf_size); /* peteg: strlcpy is safer, but not POSIX/ISO C. */
    free(buf_);
  }
  buf_ = temp;
}
char *buf_;
int cur_, buf_size;

