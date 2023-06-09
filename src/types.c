#include "types.h"
#include <stdint.h>
#include <string.h>

const Type primitive_types[] =
{
    [TYPE_VOID] = {
        .kind = TYPE_VOID,
        .id = TYPE_VOID,
        .name = "void",
        .align = 0,
        .size = 0,
        .is_pointer = false,
    },
    [TYPE_INT] = {
        .kind = TYPE_INT,
        .id = TYPE_INT,
        .name = "int",
        .align = 0,
        .size = sizeof(intmax_t),
        .is_pointer = false,
    },
    [TYPE_UINT] = {
        .kind = TYPE_UINT,
        .id = TYPE_UINT,
        .name = "uint",
        .align = 0,
        .size = sizeof(uintmax_t),
        .is_pointer = false,
    },
    [TYPE_FLOAT] = {
        .kind = TYPE_FLOAT,
        .id = TYPE_FLOAT,
        .name = "float",
        .align = 0,
        .size = sizeof(float),
        .is_pointer = false,
    },
    [TYPE_DOUBLE] = {
        .kind = TYPE_DOUBLE,
        .id = TYPE_DOUBLE,
        .name = "double",
        .align = 0,
        .size = sizeof(double),
        .is_pointer = false,
    },
    [TYPE_CHAR] = {
        .kind = TYPE_CHAR,
        .id = TYPE_CHAR,
        .name = "char",
        .align = 0,
        .size = sizeof(char),
        .is_pointer = false,
    },
    [TYPE_BOOL] = {
        .kind = TYPE_BOOL,
        .id = TYPE_BOOL,
        .name = "bool",
        .align = 0,
        .size = sizeof(bool),
        .is_pointer = false,
    },
};
