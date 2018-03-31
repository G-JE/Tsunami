/*
 * PitchShift.c
 *
 *  Created on: Mar 30, 2018
 *      Author: ericksong
 */

#include "PitchShift.h"

float grain[WLEN];
float* results;

float KaiserWindow[WLEN] = { 0.438676279837049
							,0.445557311677873
							,0.452437354582552
							,0.459315417763538
							,0.466190508575394
							,0.473061632693291
							,0.479927794292029
							,0.486787996225532
							,0.493641240206791
							,0.500486526988217
							,0.507322856542359
							,0.514149228242969
							,0.520964641046359
							,0.527768093673027
							,0.534558584789511
							,0.541335113190430
							,0.548096677980689
							,0.554842278757792
							,0.561570915794246
							,0.568281590220006
							,0.574973304204933
							,0.581645061141219
							,0.588295865825753
							,0.594924724642385
							,0.601530645744050
							,0.608112639234724
							,0.614669717351162
							,0.621200894644394
							,0.627705188160937
							,0.634181617623686
							,0.640629205612446
							,0.647046977744077
							,0.653433962852204
							,0.659789193166464
							,0.666111704491252
							,0.672400536383925
							,0.678654732332441
							,0.684873339932376
							,0.691055411063306
							,0.697200002064504
							,0.703306173909918
							,0.709372992382399
							,0.715399528247144
							,0.721384857424311
							,0.727328061160780
							,0.733228226201023
							,0.739084444957041
							,0.744895815677347
							,0.750661442614947
							,0.756380436194294
							,0.762051913177179
							,0.767674996827524
							,0.773248817075038
							,0.778772510677722
							,0.784245221383162
							,0.789666100088603
							,0.795034304999753
							,0.800349001788299
							,0.805609363748087
							,0.810814571949953
							,0.815963815395155
							,0.821056291167390
							,0.826091204583357
							,0.831067769341830
							,0.835985207671229
							,0.840842750475637
							,0.845639637479250
							,0.850375117369222
							,0.855048447936874
							,0.859658896217250
							,0.864205738626977
							,0.868688261100409
							,0.873105759224031
							,0.877457538369077
							,0.881742913822365
							,0.885961210915291
							,0.890111765150982
							,0.894193922329556
							,0.898207038671493
							,0.902150480939066
							,0.906023626555815
							,0.909825863724056
							,0.913556591540369
							,0.917215220109075
							,0.920801170653651
							,0.924313875626079
							,0.927752778814098
							,0.931117335446339
							,0.934407012295320
							,0.937621287778285
							,0.940759652055857
							,0.943821607128496
							,0.946806666930734
							,0.949714357423167
							,0.952544216682196
							,0.955295794987484
							,0.957968654907126
							,0.960562371380495
							,0.963076531798770
							,0.965510736083111
							,0.967864596760480
							,0.970137739037074
							,0.972329800869371
							,0.974440433032776
							,0.976469299187832
							,0.978416075944004
							,0.980280452921018
							,0.982062132807735
							,0.983760831418553
							,0.985376277747323
							,0.986908214018781
							,0.988356395737457
							,0.989720591734083
							,0.991000584209468
							,0.992196168775844
							,0.993307154495661
							,0.994333363917844
							,0.995274633111477
							,0.996130811696936
							,0.996901762874441
							,0.997587363450036
							,0.998187503858984
							,0.998702088186572
							,0.999131034186334
							,0.999474273295664
							,0.999731750648847
							,0.999903425087472
							,0.999989269168258
							,0.999989269168258
							,0.999903425087472
							,0.999731750648847
							,0.999474273295664
							,0.999131034186334
							,0.998702088186572
							,0.998187503858984
							,0.997587363450036
							,0.996901762874441
							,0.996130811696936
							,0.995274633111477
							,0.994333363917844
							,0.993307154495661
							,0.992196168775844
							,0.991000584209468
							,0.989720591734083
							,0.988356395737457
							,0.986908214018781
							,0.985376277747323
							,0.983760831418553
							,0.982062132807735
							,0.980280452921018
							,0.978416075944004
							,0.976469299187832
							,0.974440433032776
							,0.972329800869371
							,0.970137739037074
							,0.967864596760480
							,0.965510736083111
							,0.963076531798770
							,0.960562371380495
							,0.957968654907126
							,0.955295794987484
							,0.952544216682196
							,0.949714357423167
							,0.946806666930734
							,0.943821607128496
							,0.940759652055857
							,0.937621287778285
							,0.934407012295320
							,0.931117335446339
							,0.927752778814098
							,0.924313875626079
							,0.920801170653651
							,0.917215220109075
							,0.913556591540369
							,0.909825863724056
							,0.906023626555815
							,0.902150480939066
							,0.898207038671493
							,0.894193922329556
							,0.890111765150982
							,0.885961210915291
							,0.881742913822365
							,0.877457538369077
							,0.873105759224031
							,0.868688261100409
							,0.864205738626977
							,0.859658896217250
							,0.855048447936874
							,0.850375117369222
							,0.845639637479250
							,0.840842750475637
							,0.835985207671229
							,0.831067769341830
							,0.826091204583357
							,0.821056291167390
							,0.815963815395155
							,0.810814571949953
							,0.805609363748087
							,0.800349001788299
							,0.795034304999753
							,0.789666100088603
							,0.784245221383162
							,0.778772510677722
							,0.773248817075038
							,0.767674996827524
							,0.762051913177179
							,0.756380436194294
							,0.750661442614947
							,0.744895815677347
							,0.739084444957041
							,0.733228226201023
							,0.727328061160780
							,0.721384857424311
							,0.715399528247144
							,0.709372992382399
							,0.703306173909918
							,0.697200002064504
							,0.691055411063306
							,0.684873339932376
							,0.678654732332441
							,0.672400536383925
							,0.666111704491252
							,0.659789193166464
							,0.653433962852204
							,0.647046977744077
							,0.640629205612446
							,0.634181617623686
							,0.627705188160937
							,0.621200894644394
							,0.614669717351162
							,0.608112639234724
							,0.601530645744050
							,0.594924724642385
							,0.588295865825753
							,0.581645061141219
							,0.574973304204933
							,0.568281590220006
							,0.561570915794246
							,0.554842278757792
							,0.548096677980689
							,0.541335113190430
							,0.534558584789511
							,0.527768093673027
							,0.520964641046359
							,0.514149228242969
							,0.507322856542359
							,0.500486526988217
							,0.493641240206791
							,0.486787996225532
							,0.479927794292029
							,0.473061632693291
							,0.466190508575394
							,0.459315417763538
							,0.452437354582552
							,0.445557311677873
							,0.438676279837049 };

uint16_t* ShiftPitch(uint16_t* audio, double ratio){
	for(uint16_t i = 0; i < WLEN; i++){
		grain[i] = KaiserWindow[i] * audio[i];
	}

	fftshift(grain);

	arm_cfft_f32((float*)audio, results, WLEN);
	return audio;
}

double PrincArg(double phaseIn){
	// remove additional phases
	double phase = phaseIn - (Round((phaseIn / (PI * 2.0))) * (PI * 2.0));
	return phase;
}

int Round(float num)
{
    return num < 0 ? num - 0.5 : num + 0.5;
}

// function used for swapping the right and left half of the grain (used on window)
void fftshift(uint16_t* array){
	uint16_t temp;

	for(uint8_t i = 0; i < (WLEN+1)/2; i++){
		temp = array[i];
		array[i] = array[WLEN/2 + i];
		array[WLEN/2 + i] = temp;
	}
}
