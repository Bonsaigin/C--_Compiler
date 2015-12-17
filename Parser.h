#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

#include "Absyn.h"

typedef union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Program program_;
  Function function_;
  Decl decl_;
  ListFunction listfunction_;
  ListStm liststm_;
  ListDecl listdecl_;
  ListIdent listident_;
  Stm stm_;
  Exp exp_;
  ListExp listexp_;
  Type type_;
} YYSTYPE;

#define _ERROR_ 258
#define _SYMB_0 259
#define _SYMB_1 260
#define _SYMB_2 261
#define _SYMB_3 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _SYMB_6 265
#define _SYMB_7 266
#define _SYMB_8 267
#define _SYMB_9 268
#define _SYMB_10 269
#define _SYMB_11 270
#define _SYMB_12 271
#define _SYMB_13 272
#define _SYMB_14 273
#define _SYMB_15 274
#define _SYMB_16 275
#define _SYMB_17 276
#define _SYMB_18 277
#define _STRING_ 278
#define _INTEGER_ 279
#define _DOUBLE_ 280
#define _IDENT_ 281

extern YYSTYPE yylval;
Program pProgram(FILE *inp);
Function pFunction(FILE *inp);
Decl pDecl(FILE *inp);
ListFunction pListFunction(FILE *inp);
ListStm pListStm(FILE *inp);
ListDecl pListDecl(FILE *inp);
ListIdent pListIdent(FILE *inp);
Stm pStm(FILE *inp);
Exp pExp(FILE *inp);
ListExp pListExp(FILE *inp);
Type pType(FILE *inp);


#endif
