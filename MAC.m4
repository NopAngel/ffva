dnl macros.m4 - MAC FFVA
dnl Use: m4 macros.m4 > include/generated.h

define(`RIP_OFFSET', `16')
define(`RAX_OFFSET', `10')
define(`RBX_OFFSET', `11')

define(`COLOR_RED', `"\033[1;31m"')
define(`COLOR_GRAY', `"\033[1;90m"')
define(`COLOR_BLUE', `"\033[1;34m"')
define(`COLOR_RESET', `"\033[0m"')

define(`DEBUG_PRINT', `printf(COLOR_GRAY "DEBUG: $1\n" COLOR_RESET);')
define(`ERROR_PRINT', `printf(COLOR_RED "ERROR: $1\n" COLOR_RESET);')
define(`INFO_PRINT', `printf(COLOR_BLUE "INFO: $1\n" COLOR_RESET);')
