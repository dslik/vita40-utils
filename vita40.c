// ---------------------------------------------------------------------------------
// VITA 40-2020 Indicator Utilities
// ---------------------------------------------------------------------------------
// Routines for VITA 40 colours and blink patterns
// ---------------------------------------------------------------------------------
// SPDX-FileCopyrightText: Copyright 2023 David Slik (VE7FIM)
// SPDX-FileAttributionText: https://github.com/dslik/vita40-utils/
// SPDX-License-Identifier: CERN-OHL-S-2.0
// ---------------------------------------------------------------------------------
#include <string.h>

#include "vita40.h"

extern uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b);

// Functions
uint32_t vita40_to_urgb(char* vita40_state, uint32_t counter)
{
    if(strcmp(vita40_state, "vita40_off") == 0)
    {
        return(urgb_u32(vita40_off));
    }

    if(strcmp(vita40_state, "vita40_red_steady") == 0)
    {
        return(urgb_u32(vita40_red_steady));
    }

    if(strcmp(vita40_state, "vita40_white_fast") == 0)
    {
        if(counter % 2 == 0)
        {
            return(urgb_u32(vita40_white_fast));
        }
        else
        {
            return(urgb_u32(vita40_off));
        }
    }

    if(strcmp(vita40_state, "vita40_blue_steady") == 0)
    {
        return(urgb_u32(vita40_blue_steady));
    }

    if(strcmp(vita40_state, "vita40_amber_slow") == 0)
    {
        if((counter / 5) % 2 == 0)
        {
            return(urgb_u32(vita40_amber_slow));
        }
        else
        {
            return(urgb_u32(vita40_off));
        }
    }

    if(strcmp(vita40_state, "vita40_amber_steady") == 0)
    {
        return(urgb_u32(vita40_amber_steady));
    }

    if(strcmp(vita40_state, "vita40_green_standby") == 0)
    {
        if(counter % 10 == 0)
        {
            return(urgb_u32(vita40_green_standby));
        }
        else
        {
            return(urgb_u32(vita40_off));
        }
    }

    if(strcmp(vita40_state, "vita40_green_steady") == 0)
    {
        return(urgb_u32(vita40_green_steady));
    }

    if(strcmp(vita40_state, "vita40_green_slow") == 0)
    {
        if((counter / 5) % 2 == 0)
        {
            return(urgb_u32(vita40_green_slow));
        }
        else
        {
            return(urgb_u32(vita40_off));
        }
    }

    return(urgb_u32(vita40_off));
}


bool vita40_to_bit(char* vita40_state, uint32_t counter)
{
    if(vita40_to_urgb(vita40_state, counter) == 0)
    {
        return(false);
    }
    else
    {
        return(true);
    }
}
