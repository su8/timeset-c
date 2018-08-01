/*
   07/29/2018

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

/* 
   print/draw the menu and return 
   the user option choice back to main.c
*/
int draw_menu(void)
{
  int input = -1;
  static const char draw_menu[] =
  {
    GREEN"==="PINK"  "PROGRAM_TITLE"  "GREEN"===\n"
    MENU_ROW("1",  MENU_OPT1)
    MENU_ROW("2",  MENU_OPT2)
    MENU_ROW("3",  MENU_OPT3)
    MENU_ROW("4",  MENU_OPT4)
    MENU_ROW("5",  MENU_OPT5)
    MENU_ROW("6",  MENU_OPT6)
    MENU_ROW("7",  MENU_OPT7)
    MENU_ROW("8",  MENU_OPT8)
    MENU_ROW("9",  MENU_OPT9)
    MENU_ROW("10", MENU_OPT10)
    MENU_ROW("11", MENU_OPT11)
    MENU_ROW("12", MENU_OPT12)
    MENU_ROW("0",  MENU_OPT0)
    GREEN""EQSIGNS"\n\n"NORM""
    "Enter your choice:"" "
  };

  printf("%s", draw_menu);
  
  if (EOF == (scanf("%d", &input)))
  {
    EXIT_BAD();
  }
  getchar();  /* dispose the newline char */

  return input;
}

/*
   all commands passed to this function
   doesn't require user interaction, nor
   change anything to the system date and/or time
*/
void non_interactive(const int x, const char *exec_str, const char *print_str)
{
  system(exec_str);

  if (!puts(print_str))
  {
    EXIT_BAD();
  }

  if (1 == x || 9 == x)
  {
    getchar();  /* hold on (press enter) was printed */
  }
  return;
}

/* The user used the command line options */
void non_interactive2(const char *exec_str) {
  system(exec_str);

  return;
}

/* setting timezone and time */
void ask_n_run_cmd(const char *str1, const char *str2)
{
  char typed[100], exec_str[200];

  if (!puts(str2))
  {
    EXIT_BAD();
  }

  if (EOF == (scanf("%s", typed)))
  {
    EXIT_BAD();
  }
  snprintf(exec_str, 199, "%s \"%s\"", str1, typed);
  system(exec_str);

  if (!puts(DONE))
  {
    EXIT_BAD();
  }
  return;
}

/* 
   ask the question passed to the formal parameter str2
   and restrict the user answer to 0 and 1
*/
void ask_zero_or_one(const char *str1, const char *str2)
{
  char exec_str[40];
  int enter_status = -1, entered_val = -1;

  SYSTEM_TDCTL();
  if (!puts(str2))
  {
    EXIT_BAD();
  }

  while (1 != (enter_status = (scanf("%d", &entered_val))) ||
    (entered_val < 0 || entered_val > 1))
  {
    if (1 != enter_status)
    {
      if (EOF == (scanf("%*s"))) /* skip bad input (chars) */
      {
        EXIT_BAD();
      }
    }
    SYSTEM_TDCTL();
    if (!puts(str2))
    {
      EXIT_BAD();
    }
  }
  snprintf(exec_str, 39, "%s %d", str1, entered_val);
  system(exec_str);

  if (!puts(DONE))
  {
    EXIT_BAD();
  }
  return;
}
