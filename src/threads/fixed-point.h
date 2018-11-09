#ifndef FIXED_POINT_H
#define FIXED_POINT_H

//define fixed type as int
typedef int fixed_t;

//Define fixed point shift as 16 bits
#define FIXPNT_SHIFT 16

/* Some helpful macros. */
/* Convert a value to fixed-point value. */
#define FIXPNT_CONVERT(X) ((fixed_t)(X << FIXPNT_SHIFT))
/* Add two fixed-point value. */
#define FIXPNT_ADD(X,Y) (X + Y)
/* Add a fixed-point value A and an int value B. */
#define FIXPNT_ADD_INT(X,Y) (X + (Y << FIXPNT_SHIFT))
/* Substract two fixed-point value. */
#define FIXPNT_SUBTRACT(X,Y) (X - Y)
/* Substract an int value B from a fixed-point value A */
#define FIXPNT_SUBTRACT_INT(X,Y) (X - (Y << FIXPNT_SHIFT))
/* Multiply a fixed-point value A by an int value B. */
#define FIXPNT_MULTIPLY_INT(X,Y) (X * Y)
/* Multiply two fixed-point value. */
#define FIXPNT_MULTIPLY(X,Y) ((fixed_t)(((int64_t) X) * Y >> FIXPNT_SHIFT))
/* Divide two fixed-point value. */
#define FIXPNT_DIVIDE(X,Y) ((fixed_t)((((int64_t) X) << FIXPNT_SHIFT) / Y))
/* Divide a fixed-point value A by an int value B. */
#define FIXPNT_DIVIDE_INT(X,Y) (X / Y)
/* Get integer part of a fixed-point value. */
#define FIXPNT_GET_INT(X) (X >> FIXPNT_SHIFT)
/* Get rounded integer of a fixed-point value. */
#define FIXPNT_ROUND(X) (X >= 0 ? ((X + (1 << (FIXPNT_SHIFT - 1))) >> FIXPNT_SHIFT) \
                            : ((X - (1 << (FIXPNT_SHIFT - 1))) >> FIXPNT_SHIFT))

#endif /* thread/fixed_point.h */
