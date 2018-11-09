#ifndef FIXED_POINT_H
#define FIXED_POINT_H

//define fixed type as int
typedef int fixed_t;

//Define fixed point shift as 16 bits
#define FIXPNT_SHIFT 16

//Macro to convert integers to fixed point values
#define FIXPNT_CONVERT(X) ((fixed_t)(X << FIXPNT_SHIFT))

//macros to add two fixed point values or a fixed point and an integer
#define FIXPNT_ADD(X,Y) (X + Y)
#define FIXPNT_ADD_INT(X,Y) (X + (Y << FIXPNT_SHIFT))

//subtract two fixed point values or fixed point and an integer
#define FIXPNT_SUBTRACT(X,Y) (X - Y)
#define FIXPNT_SUBTRACT_INT(X,Y) (X - (Y << FIXPNT_SHIFT))

//multiply two fixed point values or fixed point and an integer
#define FIXPNT_MULTIPLY_INT(X,Y) (X * Y)
#define FIXPNT_MULTIPLY(X,Y) ((fixed_t)(((int64_t) X) * Y >> FIXPNT_SHIFT))


//divide two fixed point values or fixed point and an integer
#define FIXPNT_DIVIDE(X,Y) ((fixed_t)((((int64_t) X) << FIXPNT_SHIFT) / Y))
#define FIXPNT_DIVIDE_INT(X,Y) (X / Y)

//macros to get integer from fixed point value or rounded integer
#define FIXPNT_GET_INT(X) (X >> FIXPNT_SHIFT)
#define FIXPNT_ROUND(X) (X >= 0 ? ((X + (1 << (FIXPNT_SHIFT - 1))) >> FIXPNT_SHIFT) \
                            : ((X - (1 << (FIXPNT_SHIFT - 1))) >> FIXPNT_SHIFT))

#endif /* thread/fixed_point.h */
