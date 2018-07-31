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

#include <argp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constants.h"

static const char doc[] = "TimeSet - Manage System Date and Time.\vMandatory arguments to long options are mandatory for short options too.\n";
const char *argp_program_version = "timeset 1.0.5";
static struct argp_option options[] =
{
  { .doc = "" },
  { .name = "show-date-time",   .key = 's', .doc = MENU_OPT1  },
  { .name = "show-timezone",    .key = 't', .doc = MENU_OPT2  },
  { .name = "read-hw-time",     .key = 'r', .doc = MENU_OPT9  },
  { .doc = NULL }
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
  (void)arg;
  (void)state;

  switch(key)
  {
    case 's': non_interactive2(CMD1);   break;
    case 't': non_interactive2(CMD2);   break;
    case 'r': non_interactive2(CMD9);   break;
    default: return ARGP_ERR_UNKNOWN;
  }
  return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
  int return_val = -1;
  struct argp arg_parser = {
    .doc = doc,
    .options = options, 
    .parser = parse_opt
  };
  argp_parse(&arg_parser, argc, argv, 0, NULL, NULL);

  /* 
     Do not continue if the user has
     used the command line options
  */
  if (argc > 1)
  {
    return EXIT_SUCCESS;
  }

  /*
     Do not permit non-root users.
     This doesn't affect the command
     line options/arguments.
  */
  if (0 != (geteuid()))
  {
    puts("You are not a root user, exiting.");
    return EXIT_FAILURE;
  }

  while (0 != (return_val = draw_menu()))
  {
    system("clear");
    switch(return_val)
    {
      case 1: non_interactive(1, CMD1, PRESS_ENTER); break;
      case 2: non_interactive(2, CMD2, DONE);        break;
      case 3: ask_n_run_cmd(CMD3, OPT3);             break;
      case 4: non_interactive(4, CMD4, DONE);        break;
      case 5: ask_zero_or_one(CMD5, OPT5);           break;
      case 6: non_interactive(6, CMD6, DONE);        break;
      case 7: non_interactive(7, CMD7, DONE);        break;
      case 8: ask_zero_or_one(CMD8, OPT8);           break;
      case 9: non_interactive(9, CMD9, PRESS_ENTER); break;
      case 10: non_interactive(10, CMD10, DONE);     break;
      case 11: non_interactive(11, CMD11, DONE);     break;
      case 12: ask_n_run_cmd(CMD12, OPT12);
        if (EOF == (scanf("%*s")))
        {
          EXIT_BAD();
        }
        break;
      default:
        printf("%s\n%s%s\n\n", RED, "Please choose a option between 0-12.", NORM);
        break;
    }
  }

  return EXIT_SUCCESS;
}
