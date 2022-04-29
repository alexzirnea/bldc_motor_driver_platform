/*
 * motor_control.c
 *
 *  Created on: Sep 23, 2021
 *      Author: Alexandru Zirnea
 */

#include "motor_control.h"

#define POLE_PAIRS_NUMBER 4
#define SINE_TABLE_SIZE   360
#define BUFFER_SIZE 	12

static int32_t map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);
static uint16_t get_value(uint16_t angle);
static uint16_t get_angle(uint16_t pot_angle);
static uint16_t remove_offset(uint16_t value, uint16_t offset);

TIM_HandleTypeDef htim1;
UART_HandleTypeDef huart2;
uint8_t torque = 0;

static const uint16_t sine_table[SINE_TABLE_SIZE]= { 512, 521, 530, 539, 548, 557, 565, 574,
		583,
		592,
		601,
		610,
		618,
		627,
		636,
		644,
		653,
		661,
		670,
		678,
		687,
		695,
		703,
		712,
		720,
		728,
		736,
		744,
		752,
		760,
		768,
		775,
		783,
		790,
		798,
		805,
		812,
		820,
		827,
		834,
		840,
		847,
		854,
		861,
		867,
		873,
		880,
		886,
		892,
		898,
		903,
		909,
		915,
		920,
		925,
		931,
		936,
		941,
		945,
		950,
		955,
		959,
		963,
		967,
		971,
		975,
		979,
		982,
		986,
		989,
		992,
		995,
		998,
		1001,
		1003,
		1006,
		1008,
		1010,
		1012,
		1014,
		1015,
		1017,
		1018,
		1019,
		1020,
		1021,
		1022,
		1022,
		1023,
		1023,
		1023,
		1023,
		1023,
		1022,
		1022,
		1021,
		1020,
		1019,
		1018,
		1017,
		1015,
		1014,
		1012,
		1010,
		1008,
		1006,
		1003,
		1001,
		998,
		995,
		992,
		989,
		986,
		982,
		979,
		975,
		971,
		967,
		963,
		959,
		955,
		950,
		945,
		941,
		936,
		931,
		925,
		920,
		915,
		909,
		903,
		898,
		892,
		886,
		880,
		873,
		867,
		861,
		854,
		847,
		840,
		834,
		827,
		820,
		812,
		805,
		798,
		790,
		783,
		775,
		768,
		760,
		752,
		744,
		736,
		728,
		720,
		712,
		703,
		695,
		687,
		678,
		670,
		661,
		653,
		644,
		636,
		627,
		618,
		610,
		601,
		592,
		583,
		574,
		565,
		557,
		548,
		539,
		530,
		521,
		512,
		503,
		494,
		485,
		476,
		467,
		459,
		450,
		441,
		432,
		423,
		414,
		406,
		397,
		388,
		380,
		371,
		363,
		354,
		346,
		337,
		329,
		321,
		312,
		304,
		296,
		288,
		280,
		272,
		264,
		257,
		249,
		241,
		234,
		226,
		219,
		212,
		204,
		197,
		190,
		184,
		177,
		170,
		163,
		157,
		151,
		144,
		138,
		132,
		126,
		121,
		115,
		109,
		104,
		99,
		93,
		88,
		83,
		79,
		74,
		69,
		65,
		61,
		57,
		53,
		49,
		45,
		42,
		38,
		35,
		32,
		29,
		26,
		23,
		21,
		18,
		16,
		14,
		12,
		10,
		9,
		7,
		6,
		5,
		4,
		3,
		2,
		2,
		1,
		1,
		1,
		1,
		1,
		2,
		2,
		3,
		4,
		5,
		6,
		7,
		9,
		10,
		12,
		14,
		16,
		18,
		21,
		23,
		26,
		29,
		32,
		35,
		38,
		42,
		45,
		49,
		53,
		57,
		61,
		65,
		69,
		74,
		79,
		83,
		88,
		93,
		99,
		104,
		109,
		115,
		121,
		126,
		132,
		138,
		144,
		151,
		157,
		163,
		170,
		177,
		184,
		190,
		197,
		204,
		212,
		219,
		226,
		234,
		241,
		249,
		257,
		264,
		272,
		280,
		288,
		296,
		304,
		312,
		321,
		329,
		337,
		346,
		354,
		363,
		371,
		380,
		388,
		397,
		406,
		414,
		423,
		432,
		441,
		450,
		459,
		467,
		476,
		485,
		494,
		503
};

void MOTOR_init(TIM_HandleTypeDef timer, UART_HandleTypeDef uart)
{
	htim1 = timer;
	huart2 = uart;
}

void MOTOR_process(uint16_t raw_angle)
{
	static uint16_t ph1_duty=512, ph2_duty=512, ph3_duty=512;
	static int16_t ph1_angle=0, ph2_angle=0, ph3_angle=0, epos, error, directn, mech_pos, mech_pos_old, diff, flag=0, T=0, posabs, torque_temp;
	static uint8_t buffer[BUFFER_SIZE];
	static setpoint = 80;
	buffer[0]=0x03;
	buffer[BUFFER_SIZE-1]=0xFC;
	raw_angle = (raw_angle + 860) % 4096;

	//ph1_angle++;

	ph1_angle = map(raw_angle,0,4095,0,((SINE_TABLE_SIZE*4)-1));
	mech_pos_old = mech_pos;
	mech_pos = map(ph1_angle,0,((SINE_TABLE_SIZE*4)-1),0,360);


	diff=mech_pos_old-mech_pos; //calculate the change between old position and new position.
	diff=abs(diff);
	if (diff>50 && mech_pos_old>mech_pos && flag==1) T++; //if the change was larger than 50, then consider it as a turn in positive direction
	if (diff>50 && mech_pos_old<mech_pos && flag==1) T--; //if the change was larger than 50, then consider it as a turn in negative direction
	flag=1; //flag for first iteration's jump in values not to trigger the turn counter.
	posabs=(T*360)+mech_pos; //here we calculate the absolute position taking the current position plus the Turn counter

	error = posabs - setpoint;


	if(error<0)
	{
		directn = 90;
		if(abs(error)>10)
		{
			setpoint = setpoint - abs(error) + 10;
			if (setpoint<0) setpoint+= 360;
		}
	}
	else
	{
		if(abs(error)>10)
				{
					setpoint = setpoint + abs(error) - 10;
					setpoint %= 360;
				}
		directn = 270;
	}
	torque_temp = abs(error * 10);
	torque = (uint8_t)torque_temp;
	if(torque_temp > 255)
	{
		torque = 255;
	}

	if (abs(error) < 2)
	{
	torque = 0;
	}
	ph1_angle = (ph1_angle + directn)%360;
	ph2_angle = (ph1_angle + 120)%360;
	ph3_angle = (ph1_angle + 240)%360;
	ph1_duty=get_value(ph1_angle);
	ph2_duty=get_value(ph2_angle);
	ph3_duty=get_value(ph3_angle);
	buffer[2]=(uint8_t)(ph1_duty>>8);
	buffer[1]=(uint8_t)ph1_duty;
	buffer[4]=(uint8_t)(ph2_duty>>8);
	buffer[3]=(uint8_t)ph2_duty;
	buffer[6]=(uint8_t)(ph3_duty>>8);
	buffer[5]=(uint8_t)ph3_duty;
	buffer[8]=(uint8_t)(raw_angle>>8);
	buffer[7]=(uint8_t)raw_angle;
	buffer[10]=(uint8_t)(ph1_angle>>8);
	buffer[9]=(uint8_t)ph1_angle;

	__HAL_TIM_SET_COMPARE( &htim1, TIM_CHANNEL_1, ph1_duty );
	__HAL_TIM_SET_COMPARE( &htim1, TIM_CHANNEL_2, ph2_duty );
	__HAL_TIM_SET_COMPARE( &htim1, TIM_CHANNEL_3, ph3_duty );
	HAL_UART_Transmit(&huart2, buffer, BUFFER_SIZE, 500);
}

static int32_t map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

static uint16_t get_value(uint16_t angle)
{
	int16_t temp;
	uint8_t div_factor;
	if(angle>=360)
	{
		angle -= 360;
	}
	div_factor = map(torque, 0, 255, 255, 6);
	if(sine_table[angle] > 512)
		temp = 511 + (sine_table[angle]-512)/div_factor;
		else
	    temp = 511 - (512-sine_table[angle])/div_factor;
	return temp;
}


static uint16_t get_angle(uint16_t pot_angle)
{
	int16_t angle = pot_angle % 1023;
	return ((int32_t)angle*359)/1024;
}

static uint16_t remove_offset(uint16_t value, uint16_t offset)
{
	uint16_t temp;
	if (offset > value){
	 temp=(4095+value)-offset;
	}
	else
	{
		temp = value - offset;
	}
	return temp;
}
