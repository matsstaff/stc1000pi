/*
 * STC1000+, improved firmware and Arduino based firmware uploader for the STC-1000 dual stage thermostat.
 *
 * Copyright 2014 Mats Staffansson
 *
 * This file is part of STC1000+.
 *
 * STC1000+ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * STC1000+ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with STC1000+.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "stc1000pi.h"


#define EEPROM_DEFAULTS_F(name, led10ch, led1ch, led01ch, minv, maxv, dvc, dvf) \
    dvf,
#define EEPROM_DEFAULTS_C(name, led10ch, led1ch, led01ch, minv, maxv, dvc, dvf) \
    dvc,

/* Initial EEPROM data, note temperatures are multiplied by 10 (for 1 decimal point precision) */
#ifdef FAHRENHEIT
	__code const int __at(0xF000) eedata[] = {
			600, 24, 620, 24, 640, 24, 660, 24, 680, 144, 770, 48, 400, 0, 0, 0, 0, 0, 0, // Pr0 (SP0, dh0, ..., dh8, SP9)
			600, 24, 620, 24, 640, 24, 660, 24, 680, 144, 770, 48, 400, 0, 0, 0, 0, 0, 0, // Pr1 (SP0, dh0, ..., dh8, SP9)
			600, 24, 620, 24, 640, 24, 660, 24, 680, 144, 770, 48, 400, 0, 0, 0, 0, 0, 0, // Pr2 (SP0, dh0, ..., dh8, SP9)
			600, 24, 620, 24, 640, 24, 660, 24, 680, 144, 770, 48, 400, 0, 0, 0, 0, 0, 0, // Pr3 (SP0, dh0, ..., dh8, SP9)
			600, 24, 620, 24, 640, 24, 660, 24, 680, 144, 770, 48, 400, 0, 0, 0, 0, 0, 0, // Pr4 (SP0, dh0, ..., dh8, SP9)
			SET_MENU_DATA(EEPROM_DEFAULTS_F)
};
#else // CELSIUS
	__code const int __at(0xF000) eedata[] = {
			160, 24, 170, 24, 180, 24, 190, 24, 200, 144, 250, 48, 40, 0, 0, 0, 0, 0, 0, // Pr0 (SP0, dh0, ..., dh8, SP9)
			160, 24, 170, 24, 180, 24, 190, 24, 200, 144, 250, 48, 40, 0, 0, 0, 0, 0, 0, // Pr1 (SP0, dh0, ..., dh8, SP9)
			160, 24, 170, 24, 180, 24, 190, 24, 200, 144, 250, 48, 40, 0, 0, 0, 0, 0, 0, // Pr2 (SP0, dh0, ..., dh8, SP9)
			160, 24, 170, 24, 180, 24, 190, 24, 200, 144, 250, 48, 40, 0, 0, 0, 0, 0, 0, // Pr3 (SP0, dh0, ..., dh8, SP9)
			160, 24, 170, 24, 180, 24, 190, 24, 200, 144, 250, 48, 40, 0, 0, 0, 0, 0, 0, // Pr4 (SP0, dh0, ..., dh8, SP9)
			SET_MENU_DATA(EEPROM_DEFAULTS_C)
	};
#endif
