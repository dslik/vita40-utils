// ---------------------------------------------------------------------------------
// VITA 40-2020 Indicator Definitions - Header
// ---------------------------------------------------------------------------------
// Constants for VITA 40 colours and blink patterns
// ---------------------------------------------------------------------------------
// SPDX-FileCopyrightText: Copyright 2023 David Slik (VE7FIM)
// SPDX-FileAttributionText: https://github.com/dslik/vita40-utils/
// SPDX-License-Identifier: CERN-OHL-S-2.0
// ---------------------------------------------------------------------------------
#include <stdint.h>
#include <stdbool.h>

// Definitions
#define	vita40_off				0,  0,  0
#define	vita40_red_steady		10, 0,  0
#define	vita40_white_fast		8,  8,  10
#define	vita40_blue_steady		0,  0,  10
#define	vita40_amber_slow		10, 10, 0
#define	vita40_amber_steady		10, 10, 0
#define	vita40_green_standby	0,  10, 0
#define	vita40_green_steady		0,  10, 0
#define	vita40_green_slow		0,  10, 0
#define	vita40_green_feedback	0,  10, 0

// Prototypes
uint32_t vita40_to_urgb(char* vita40_state, uint32_t counter);
bool vita40_to_bit(char* vita40_state, uint32_t counter);
