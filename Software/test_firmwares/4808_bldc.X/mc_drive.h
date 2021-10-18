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

void MCDRIVE_init();
void MCDRIVE_setSpeed(uint8_t duty);


#ifdef	__cplusplus
}
#endif

#endif	/* MC_DRIVE_H */

