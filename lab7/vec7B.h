// vec7B.h
// ENCM 335 Fall 2021 Lab 7 Exercise B

// Type information and function prototypes for operations on
// vectors in 3-space.

struct vec {
  double x;
  double y;
  double z;
};

typedef struct vec vec_t;

void print_vec(vec_t v);
// PROMISES:
//   Members of v are printed in a format as in this example:
//   (-1.25 0.5 19.0)


// REMARK: The interfaces below do not use a consistent style for
//   communication of inputs and results of functions.  That would be
//   annoying in production code, but in this exercise it helps
//   students learn when to use the . operator and when to use the ->
//   operator.

void scalar_product(double k, const vec_t *v, vec_t *w);
// REQUIRES: v and w point to vector objects.
// PROMISES:
//   *w contains the scalar product of k and *v.

double dot_product(vec_t left, vec_t right);
// PROMISES:
//   Return value is dot product of left and right. 

void sum(const vec_t* left, const vec_t *right, vec_t *sum);
// REQUIRES:
//   left, right and sum point to vector objects.
// PROMISES:
//  *sum contains the vector sum of *left and *right. 

vec_t cross_product(vec_t left, vec_t right);
// PROMISES:
//   Return value is cross product of left and right. 
