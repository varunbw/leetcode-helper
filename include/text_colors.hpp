#pragma once

#ifndef LCH_TEXT_COLORS_HPP
#define LCH_TEXT_COLORS_HPP

// -- Escape sequences for printing colored text to console
/*
    To start printing colored text, use any of the _START macros,
    and it will accordingly reflect on your output.
    To go back to normal white text, print RESET_COLOR

    Ex:
    cout << RED_START << "This is red text" << RESET_COLOR;
    cout << "This is normal text";
*/

// Regular text colors
#define BLACK_START "\033[30m"
#define RED_START "\033[31m"
#define GREEN_START "\033[32m"
#define YELLOW_START "\033[33m"
#define BLUE_START "\033[34m"
#define MAGENTA_START "\033[35m"
#define CYAN_START "\033[36m"
#define WHITE_START "\033[37m"

// Bold text colors
#define BLACK_BOLD_START "\033[1;30m"
#define RED_BOLD_START "\033[1;31m"
#define GREEN_BOLD_START "\033[1;32m"
#define YELLOW_BOLD_START "\033[1;33m"
#define BLUE_BOLD_START "\033[1;34m"
#define MAGENTA_BOLD_START "\033[1;35m"
#define CYAN_BOLD_START "\033[1;36m"
#define WHITE_BOLD_START "\033[1;37m"

// Underlined text colors
#define BLACK_UNDERLINE_START "\033[4;30m"
#define RED_UNDERLINE_START "\033[4;31m"
#define GREEN_UNDERLINE_START "\033[4;32m"
#define YELLOW_UNDERLINE_START "\033[4;33m"
#define BLUE_UNDERLINE_START "\033[4;34m"
#define MAGENTA_UNDERLINE_START "\033[4;35m"
#define CYAN_UNDERLINE_START "\033[4;36m"
#define WHITE_UNDERLINE_START "\033[4;37m"

// Background colors
#define BLACK_BG_START "\033[40m"
#define RED_BG_START "\033[41m"
#define GREEN_BG_START "\033[42m"
#define YELLOW_BG_START "\033[43m"
#define BLUE_BG_START "\033[44m"
#define MAGENTA_BG_START "\033[45m"
#define CYAN_BG_START "\033[46m"
#define WHITE_BG_START "\033[47m"

// Reset color
#define RESET_COLOR "\033[0m"


#endif