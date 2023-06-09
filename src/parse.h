#ifndef MINI_PARSE_H
#define MINI_PARSE_H

#include "lex.h"
#include "types.h"
#include "vector.h"
#include <stdint.h>
#include <stdbool.h>

typedef struct Node Node;
typedef enum NodeKind NodeKind;

typedef struct FuncDecl FuncDecl;
typedef struct VarDecl VarDecl;

typedef struct AssignStmt AssignStmt;
typedef struct RetStmt RetStmt;
typedef struct CondStmt CondStmt;

typedef enum UnaryOp UnaryOp;
typedef enum BinaryOp BinaryOp;
typedef struct UnaryExpr UnaryExpr;
typedef struct BinaryExpr BinaryExpr;

typedef enum ValueKind ValueKind;
typedef struct Value Value;

struct FuncDecl
{
  char *name;
  Type return_type;
  Node *params;
  Node *body;
};

struct VarDecl 
{
  char *name;
  Type type;
  Node *init;
};

struct AssignStmt 
{
  char *name;
  Node *value;
};

struct RetStmt
{
  Node *value;
};

struct CondStmt 
{
  Node *expr;
  Node *body;
};

enum UnaryOp
{
  UN_UNKNOWN = 0,
  UN_NEG     = 1,
  UN_NOT,
  UN_DEREF,
  UN_ADDR,
};

struct UnaryExpr
{
  UnaryOp un_op;
  Node *expr;
};

// NOTE: The order of these matter
enum BinaryOp
{
  BIN_UNKNOWN = 0,
  BIN_ADD     = 5,
  BIN_SUB,
  BIN_MUL,
  BIN_DIV,
  BIN_CMP,
  BIN_CMP_NOT,
  BIN_CMP_LT,
  BIN_CMP_GT,
  BIN_CMP_LT_EQ,
  BIN_CMP_GT_EQ,
};

struct BinaryExpr
{
  BinaryOp bin_op;
  Node *lhs;
  Node *rhs;
};

enum ValueKind
{
  VAL_INT,
  VAL_UINT,
  VAL_FLOAT,
  VAL_DOUBLE,
  VAL_CHAR,
  VAL_BOOL,
  VAL_STRING,
  VAL_SIZE,
};

struct Value 
{
  ValueKind kind;
  union
  {
    intmax_t i_val;
    uintmax_t u_val;
    float f_val;
    double d_val;
    char c_val;
    bool b_val;
    struct {
      char *s_val;
      size_t s_len;
    };
    size_t size;
  };
};

void dump_value(Value literal);
uint8_t *copy_value(Value *literal, size_t *literal_size);

enum NodeKind
{
  NODE_UNKNOWN,
  NODE_NOOP,
  NODE_FUNC_DECL,
  NODE_VAR_DECL,
  NODE_RET_STMT,
  NODE_COND_STMT,
  NODE_FUNC_CALL_EXPR,
  NODE_ASSIGN_STMT,
  NODE_UNARY_EXPR,
  NODE_BINARY_EXPR,
  NODE_LITERAL_EXPR,
  NODE_REF_EXPR,
};

struct Node
{
  NodeKind kind;
  Type type;
  bool visited;
  int line, col;
  union
  {
    FuncDecl func_decl;
    VarDecl var_decl;
    RetStmt ret_stmt;
    CondStmt cond_stmt;
    AssignStmt assign;
    UnaryExpr unary;
    BinaryExpr binary;
    Value literal;
    char *ref;
  };
  Node *next;
};

Node *parse(Vector tokens);
void dump_ast(Node *program, int level);

#endif
