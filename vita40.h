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

// Permitted VITA 40 Indicator Colours
#define	vita40_red 				40, 0,  0
#define	vita40_white			40, 40, 20
#define	vita40_blue				0,  0,  20
#define	vita40_amber			40, 40, 0
#define	vita40_green			0,  40, 0

// Permitted VITA 40 Indicator Colours and Behaviours
#define	vita40_off				0,  0,  0
#define	vita40_red_steady		vita40_red
#define	vita40_white_fast		vita40_white
#define	vita40_blue_steady		vita40_blue
#define	vita40_amber_steady		vita40_amber
#define	vita40_amber_slow		vita40_amber
#define	vita40_green_steady		vita40_green
#define	vita40_green_standby	vita40_green
#define	vita40_green_slow		vita40_green
#define	vita40_green_feedback	vita40_green

// Non-permitted VITA 40 Indicator Colours and Behaviours
#define	vita40_red_slow			vita40_red
#define	vita40_red_fast			vita40_red
#define	vita40_white_steady		vita40_white
#define	vita40_white_slow		vita40_white
#define	vita40_blue_slow		vita40_blue
#define	vita40_blue_fast		vita40_blue
#define	vita40_amber_fast		vita40_amber
#define	vita40_green_fast		vita40_green

// Prototypes
uint32_t vita40_to_urgb(char* vita40_state, uint32_t counter);
bool vita40_to_bit(char* vita40_state, uint32_t counter);
