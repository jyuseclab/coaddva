#ifndef MODEL_DATA_H
#define MODEL_DATA_H

#include <avr/pgmspace.h>

extern const float W1_data[];
extern const float b1_data[];
extern const float W2_data[];
extern const float b2_data[];
extern const float W3_data[];
extern const float b3_data[];

const int INPUT_SIZE = 231;
const int DENSE1_SIZE = 64;
const int DENSE2_SIZE = 64;
const int DENSE3_SIZE = 2;

inline float W1(int i, int j) {
  return pgm_read_float_near(W1_data + i * INPUT_SIZE + j);
}

inline float b1(int i) {
    return pgm_read_float_near(b1_data + i);
}

inline float W2(int i, int j) {
  return pgm_read_float_near(W2_data + i * DENSE1_SIZE + j);
}

inline float b2(int i) {
    return pgm_read_float_near(b2_data + i);
}

inline float W3(int i, int j) {
  return pgm_read_float_near(W3_data + i * DENSE2_SIZE + j);
}

inline float b3(int i) {
    return pgm_read_float_near(b3_data + i);
}

#endif