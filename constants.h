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

/* constants and function declarations */
#ifndef CONSTANTS_H
#define CONSTANTS_H

/* the colours */
#define PINK "\x1B[1;95m"
#define BLUE "\x1B[1;94m"
#define GREEN "\x1B[1;92m"
#define YELLOW "\x1B[1;93m"
#define RED "\x1B[1;91m"
#define NORM "\x1B[0;0m"

/* misc */
#define STREQ(STR1, STR2) (0 == (strcmp(STR1, STR2)))
#define MENU_ROW(NUM, OPT) BLUE "[" YELLOW NUM BLUE "]" NORM "  " OPT "\n"
#define SYSTEM_TDCTL() if (STREQ(CMD8, str1)) system("timedatectl | grep local");
#define EXIT_BAD() \
  puts("Something went wrong, exiting !!!"); \
  exit(EXIT_FAILURE);

#define EQSIGNS "============================================================="

/* runtime strings */
#define PLEASE_ENTER "Please enter a value between 0 and 1:\n0 means"
#define OPT8 PLEASE_ENTER " Hardware clock to UTC\nand 1 means set it to Local time"
#define OPT5 PLEASE_ENTER " disable NTP and 1 means enable NTP"
#define OPT3 "Enter the timezone. It should be like \nContinent/City - Europe/Berlin"
#define OPT12 "Enter the time. The time may be specified\nin the format  2018-08-01 09:12:45"
#define PRESS_ENTER "\nPress \"Enter\" to continue"
#define DONE "Done."

/* draw_menu strings */
#define PROGRAM_TITLE "TimeSet(tings) - Configure the System Date and Time"
#define MENU_OPT1 "Show Current Date and Time Configurations"
#define MENU_OPT2 "Show Known Timezones"
#define MENU_OPT3 "Set System Timezone"
#define MENU_OPT4 "Synchronize Time from the Network (NTP)"
#define MENU_OPT5 "Control whether NTP is used for system time or not"
#define MENU_OPT6 "Enable NTP at Startup"
#define MENU_OPT7 "Disable NTP at Startup"
#define MENU_OPT8 "Control whether Hardware Clock is in Local Time or not"
#define MENU_OPT9 "Read the time from the Hardware Clock"
#define MENU_OPT10 "Synchronize Hardware Clock from the System Time"
#define MENU_OPT11 "Synchronize System Time from the Hardware Clock"
#define MENU_OPT12 "Set System Time manually"
#define MENU_OPT0 "Exit/Quit"

/* commands to execute */
#define CMD1 "timedatectl status"
#define CMD2 "timedatectl list-timezones"
#define CMD3 "timedatectl set-timezone"
#define CMD4 "ntpd"
#define CMD5 "timedatectl set-ntp"
#define CMD6 "systemctl enable ntpd"
#define CMD7 "systemctl disable ntpd"
#define CMD8 "timedatectl set-local-rtc"
#define CMD9 "hwclock --verbose"
#define CMD10 "hwclock -w"
#define CMD11 "hwclock -s"
#define CMD12 "timedatectl set-time"

/* prototype the functions */
int draw_menu(void);
void non_interactive(const int , const char *, const char *);
void non_interactive2(const char *);
void ask_n_run_cmd(const char *, const char *);
void ask_zero_or_one(const char *, const char *);

#endif /* CONSTANTS_H */
