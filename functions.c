#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

/* 
   print/draw the menu and return 
   the user option choice back to main.c
*/
int run_menu(void)
{
    short int input = -2;
    static const char draw_menu[] =
    {
        "    "GREEN"==="PINK"  "PROGRAM_TITLE"  "GREEN"===\n\n"
        "    "BLUE"["YELLOW"1"BLUE"]"NORM"  "MENU_OPT1"\n"
        "    "BLUE"["YELLOW"2"BLUE"]"NORM"  "MENU_OPT2"\n"
        "    "BLUE"["YELLOW"3"BLUE"]"NORM"  "MENU_OPT3"\n"
        "    "BLUE"["YELLOW"4"BLUE"]"NORM"  "MENU_OPT4"\n"
        "    "BLUE"["YELLOW"5"BLUE"]"NORM"  "MENU_OPT5"\n"
        "    "BLUE"["YELLOW"6"BLUE"]"NORM"  "MENU_OPT6"\n"
        "    "BLUE"["YELLOW"7"BLUE"]"NORM"  "MENU_OPT7"\n"
        "    "BLUE"["YELLOW"8"BLUE"]"NORM"  "MENU_OPT8"\n"
        "    "BLUE"["YELLOW"9"BLUE"]"NORM"  "MENU_OPT9"\n"
        "    "BLUE"["YELLOW"10"BLUE"]"NORM" "MENU_OPT10"\n"
        "    "BLUE"["YELLOW"11"BLUE"]"NORM" "MENU_OPT11"\n"
        "    "BLUE"["YELLOW"12"BLUE"]"NORM" "MENU_OPT12"\n"
        "    "BLUE"["YELLOW"0"BLUE"]"RED"  "MENU_OPT0"\n"
        "    "GREEN""EQSIGNS"\n\n"NORM""
        "    ""Enter your choice:""  "
    };

    printf("%s", draw_menu);
    
    if (EOF == (scanf("%hd", &input))) {
      puts(BAD_HAPPENS);
      exit(EXIT_FAILURE);
    }
    getchar();  /* dispose the newline char */

    return input;
}

/*
   all commands passed to this function
   doesn't require user interaction, nor
   change anything to the system date and/or time
*/
void non_interactive(const unsigned short int x, const char *exec_str, const char *print_str)
{
    CLEAR();
    system(exec_str);

    puts(print_str);

    if (x == 1 || x == 9) {
      getchar();  /* hold on (press enter) was printed */
    }

    return;
}

/* setting timezone and time */
void ask_n_run_cmd(const char *str1, const char *str2)
{
    char typed[100], exec_str[100];

    printf("%s ", str2);

    if (EOF == (scanf("%s", typed))) {
      puts(BAD_HAPPENS);
      exit(EXIT_FAILURE);
    }
    snprintf(exec_str, 99, str1, typed);

    CLEAR();
    system(exec_str);

    puts(DONE);
    return;
}

/* 
   ask the question passed to the formal parameter str2
   and restrict the user answer to 0 and 1
*/
void ask_zero_or_one(const char *str1, const char *str2)
{
    char exec_str[40];
    short int enter_status, entered_val;

    puts(str2);

    while ((enter_status = (scanf("%hd", &entered_val))) != 1
        || (entered_val < 0 || entered_val > 1))
    {
        if (enter_status != 1) {
          if (EOF == (scanf("%*s"))) {  /* skip bad input (chars) */
            puts(BAD_HAPPENS);
            exit(EXIT_FAILURE);
          }
        }
        puts(str2);
    }
    snprintf(exec_str, 39, str1, entered_val);

    CLEAR();
    system(exec_str);

    puts(DONE);
    return;
}
