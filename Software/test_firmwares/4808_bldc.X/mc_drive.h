/* 
 * File:   mc_drive.h
 * Author: Alexandru Zirnea
 *
 * Created on March 17, 2021, 10:08 PM
 */

#ifndef MC_DRIVE_H
#define	MC_DRIVE_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define MCSTATE_OPENLOOP 3
#define MCSTATE_CLOSEDLOOP 2
#define MCSTATE_STOP 0
#define MCSTATE_FAULT 1

#define MCDIR_CW 0
#define MCDIR_CCW 1
    
void MCDRIVE_init();
void MCDRIVE_setSpeed(uint8_t duty);
uint8_t MCDRIVE_getState();
void MCDRIVE_startMotor();
void MCDRIVE_stopMotor();
uint8_t MCDRIVE_getDirection();
void MCDRIVE_setDirection(uint8_t direction);

#ifdef	__cplusplus
}
#endif

#endif	/* MC_DRIVE_H */

