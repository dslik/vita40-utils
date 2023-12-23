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
#include <stdlib.h>

#include "vita40.h"

extern uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b);

// =================================================================================
// Local Functions

// Convert a vita40 constant to an RGB LED colour value
uint32_t vita40_to_urgb(char* vita40_state, uint32_t counter)
{
    if(strcmp(vita40_state, "vita40_off") == 0)
    {
        return(urgb_u32(vita40_off));
    }

    // RED =================
    if(strcmp(vita40_state, "vita40_red_steady") == 0)
    {
        return(urgb_u32(vita40_red_steady));
    }

    if(strcmp(vita40_state, "vita40_red_slow") == 0)
    {
        if((counter / 5) % 2 == 0)
        {
            return(urgb_u32(vita40_red_slow));
        }
        else
        {
            return(urgb_u32(vita40_off));
        }
    }

    if(strcmp(vita40_state, "vita40_red_fast") == 0)
    {
        if(counter % 2 == 0)
        {
            return(urgb_u32(vita40_red_fast));
        }
        else
        {
            return(urgb_u32(vita40_off));
        }
    }

    // WHITE =================
    if(strcmp(vita40_state, "vita40_white_steady") == 0)
    {
        return(urgb_u32(vita40_white_steady));
    }

    if(strcmp(vita40_state, "vita40_white_slow") == 0)
    {
        if((counter / 5) % 2 == 0)
        {
            return(urgb_u32(vita40_white_slow));
        }
        else
        {
            return(urgb_u32(vita40_off));
        }
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

    // BLUE =================
    if(strcmp(vita40_state, "vita40_blue_steady") == 0)
    {
        return(urgb_u32(vita40_blue_steady));
    }

    if(strcmp(vita40_state, "vita40_blue_slow") == 0)
    {
        if((counter / 5) % 2 == 0)
        {
            return(urgb_u32(vita40_blue_slow));
        }
        else
        {
            return(urgb_u32(vita40_off));
        }
    }

    if(strcmp(vita40_state, "vita40_blue_fast") == 0)
    {
        if(counter % 2 == 0)
        {
            return(urgb_u32(vita40_blue_fast));
        }
        else
        {
            return(urgb_u32(vita40_off));
        }
    }

    // AMBER =================
    if(strcmp(vita40_state, "vita40_amber_steady") == 0)
    {
        return(urgb_u32(vita40_amber_steady));
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

    if(strcmp(vita40_state, "vita40_amber_fast") == 0)
    {
        if(counter % 2 == 0)
        {
            return(urgb_u32(vita40_amber_fast));
        }
        else
        {
            return(urgb_u32(vita40_off));
        }
    }

    // GREEN =================
    if(strcmp(vita40_state, "vita40_green_steady") == 0)
    {
        return(urgb_u32(vita40_green_steady));
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

    if(strcmp(vita40_state, "vita40_green_fast") == 0)
    {
        if(counter % 2 == 0)
        {
            return(urgb_u32(vita40_green_fast));
        }
        else
        {
            return(urgb_u32(vita40_off));
        }
    }

    // #RRGGBB =================
    if(vita40_state[0] == '#' && strlen(vita40_state) == 7)
    {
        char hexString[6] = "0x00";
        uint8_t red = 0;
        uint8_t green = 0;
        uint8_t blue = 0;

        hexString[2] = vita40_state[1];
        hexString[3] = vita40_state[2];
        red = strtol(hexString, NULL, 16);

        hexString[2] = vita40_state[3];
        hexString[3] = vita40_state[4];
        green = strtol(hexString, NULL, 16);

        hexString[2] = vita40_state[5];
        hexString[3] = vita40_state[6];
        blue = strtol(hexString, NULL, 16);

        return(urgb_u32(red, green, blue));
    }

    // #RRGGBB#RRGGBB =================
    if(vita40_state[0] == '#' && strlen(vita40_state) == 14)
    {
        char hexString[6] = "0x00";
        uint8_t red = 0;
        uint8_t green = 0;
        uint8_t blue = 0;

        if((counter / 5) % 2 == 0)
        {
            hexString[2] = vita40_state[1];
            hexString[3] = vita40_state[2];
            red = strtol(hexString, NULL, 16);

            hexString[2] = vita40_state[3];
            hexString[3] = vita40_state[4];
            green = strtol(hexString, NULL, 16);

            hexString[2] = vita40_state[5];
            hexString[3] = vita40_state[6];
            blue = strtol(hexString, NULL, 16);
        }
        else
        {
            hexString[2] = vita40_state[8];
            hexString[3] = vita40_state[9];
            red = strtol(hexString, NULL, 16);

            hexString[2] = vita40_state[10];
            hexString[3] = vita40_state[11];
            green = strtol(hexString, NULL, 16);

            hexString[2] = vita40_state[12];
            hexString[3] = vita40_state[13];
            blue = strtol(hexString, NULL, 16);
        }

        return(urgb_u32(red, green, blue));
    }

    return(urgb_u32(vita40_off));
}

// Indicates if a vita40 constant results in a colour
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
