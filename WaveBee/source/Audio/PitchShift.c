/*
 * PitchShift.c
 *
 *  Created on: Mar 30, 2018
 *      Author: ericksong
 */

#include "PitchShift.h"

float32_t grain[WLEN*2];
float result[64];
float phi0[WLEN/2];
float r0[WLEN/2];
float psi[WLEN/2];
float b[WLEN/2];

void InitPitchShifting(void){
	memset(&phi0[0], 0, sizeof(double) << 7);
	memset(&r0[0], 0, sizeof(double) << 7);
	memset(&psi[0], 0, sizeof(double) << 7);
}

uint16_t* ShiftPitch(uint16_t* audio, double ratio){

	uint16_t max = GetMaximum();

	float delta_phi[WLEN/2];
	float delta_r[WLEN/2];
	float delta_psi[WLEN/2];
	float phi[WLEN/2];
	float psi[WLEN/2];
	float r[WLEN/2];
	float b[WLEN/2];
	float tmp;

	for(uint16_t i = 0; i < WLEN; i++)
		grain[i] = Kaiser[i] * ((float) audio[i] / (float) max);


	fftshift(grain);
	arm_cfft_f32(&arm_cfft_sR_f32_len256, (float*) grain, 0, 0);
	arm_cmplx_mag_f32(grain, r, 128);

	uint16_t j = 0;
	for(uint16_t i = 0; i < WLEN; i+=2)
		phi[j++] = atan2f(grain[i], grain[i+1]);

	for(uint16_t i = 0; i < WLEN/2; i++)
		delta_phi[i] = (1.5707963267948966 * i) + (phi[i] - phi0[i]) - (1.5707963267948966 * i);

	princarg(delta_phi, delta_phi);

	for(uint16_t i = 0; i < WLEN/2; i++){
		delta_r[i] = (r[i] - r0[i]) / 64.0;
		delta_psi[i] = (ratio * delta_phi[i]) / 64.0;
	}

	for (uint8_t k = 0; k < 64; k++) {
	      for (uint8_t i = 0; i < WLEN/2; i++) {
	        psi[i] +=  delta_psi[i];
	        b[i] = psi[i];
	        r0[i] += delta_r[i];
	      }

	      b_cos(b);

	      tmp = 0.0;
	      for (uint8_t i = 0; i < 128; i++) {
	        tmp += r0[i] * b[i];
	      }

	      result[k] = tmp * 4096;
	    }

    memcpy(&phi0[0], &phi[0], sizeof(double) << 7);
    memcpy(&r0[0], &r[0], sizeof(double) << 7);
    princarg(psi, psi);

	return (uint16_t*) result;

}

void princarg(const float Phasein[WLEN/2], float Phase[WLEN/2])
{
  int k;
  for (k = 0; k < 128; k++) {
    Phase[k] = Phasein[k] - rt_roundd_snf(Phasein[k] / 6.2831853071795862) *
      6.2831853071795862;
  }
}

void b_cos(float x[WLEN/2])
{
  int k;
  for (k = 0; k < 128; k++) {
    x[k] = cos(x[k]);
  }
}

float rt_roundd_snf(float u)
{
  float y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

// function used for swapping the right and left half of the grain (used on window)
void fftshift(float* array){
	float temp;

	for(uint8_t i = 0; i < (WLEN+1)/2; i++){
		temp = array[i];
		array[i] = array[WLEN/2 + i];
		array[WLEN/2 + i] = temp;
	}
}
