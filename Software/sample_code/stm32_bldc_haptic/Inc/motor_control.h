#ifndef _MOTOR_CONTROL_H
#define _MOTOR_CONTROL_H

#include <stdint.h>
#include "stm32f1xx_hal.h"

void MOTOR_init(TIM_HandleTypeDef timer, UART_HandleTypeDef uart);
void MOTOR_process(uint16_t rawAngle);

#endif
