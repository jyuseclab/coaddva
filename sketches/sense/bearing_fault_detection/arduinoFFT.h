/*

  FFT libray
  Copyright (C) 2010 Didier Longueville
  Copyright (C) 2014 Enrique Condes

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef arduinoFFT_h /* Prevent loading library twice */

#define arduinoFFT_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "defs.h"
//#include "types.h"

#define FFT_LIB_REV 0x14

/* Custom constants */

#define FFT_FORWARD 0x01
#define FFT_REVERSE 0x00

/* Windowing type */

#define FFT_WIN_TYP_RECTANGLE 0x00 /* rectangle (Box car) */
#define FFT_WIN_TYP_HAMMING 0x01 /* hamming */
#define FFT_WIN_TYP_HANN 0x02 /* hann */
#define FFT_WIN_TYP_TRIANGLE 0x03 /* triangle (Bartlett) */
#define FFT_WIN_TYP_NUTTALL 0x04 /* nuttall */
#define FFT_WIN_TYP_BLACKMAN 0x05 /* blackman */
#define FFT_WIN_TYP_BLACKMAN_NUTTALL 0x06 /* blackman nuttall */
#define FFT_WIN_TYP_BLACKMAN_HARRIS 0x07 /* blackman harris*/
#define FFT_WIN_TYP_FLT_TOP 0x08 /* flat top */
#define FFT_WIN_TYP_WELCH 0x09 /* welch */
/*Mathematial constants*/
#define twoPi 6.28318531
#define fourPi 12.56637061
#define sixPi 18.84955593

const double _c1[] = {
  0.0000000000, 0.7071067812, 0.9238795325, 0.9807852804,
  0.9951847267, 0.9987954562, 0.9996988187, 0.9999247018,
  0.9999811753, 0.9999952938, 0.9999988235, 0.9999997059,
  0.9999999265, 0.9999999816, 0.9999999954, 0.9999999989,
  0.9999999997
};
const double _c2[] = {
  1.0000000000, 0.7071067812, 0.3826834324, 0.1950903220,
  0.0980171403, 0.0490676743, 0.0245412285, 0.0122715383,
  0.0061358846, 0.0030679568, 0.0015339802, 0.0007669903,
  0.0003834952, 0.0001917476, 0.0000958738, 0.0000479369,
  0.0000239684
};

class arduinoFFT {

public:

  /* Constructor */

  arduinoFFT(void);
  arduinoFFT(double *vReal, double *vImag, unsigned short samples, double samplingFrequency);

  /* Destructor */

  ~arduinoFFT(void);

  /* Functions */

  unsigned char Revision(void);
  unsigned char Exponent(unsigned short value);

  void ComplexToMagnitude(double *vReal, double *vImag, unsigned short samples);
  void Compute(double *vReal, double *vImag, unsigned short samples, unsigned char dir);
  void Compute(double *vReal, double *vImag, unsigned short samples, unsigned char power, unsigned char dir);
  void DCRemoval(double *vData, unsigned short samples);
  double MajorPeak(double *vD, unsigned short samples, double samplingFrequency);
  void MajorPeak(double *vD, unsigned short samples, double samplingFrequency, double *f, double *v);
  void Windowing(double *vData, unsigned short samples, unsigned char windowType, unsigned char dir);

  void ComplexToMagnitude();
  void Compute(unsigned char dir);
  void DCRemoval();
  double MajorPeak();
  void MajorPeak(double *f, double *v);
  void Windowing(unsigned char windowType, unsigned char dir);

private:

  /* Variables */

  unsigned short _samples;
  double _samplingFrequency;
  double *_vReal;
  double *_vImag;
  unsigned char _power;

  /* Functions */

  void Swap(double *x, double *y);
};

#endif
