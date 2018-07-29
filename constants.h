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
#define EQSIGNS "============================================================="

/* runtime strings */
#define OPT8 "Please enter a value between 0 and 1:\n0 means Hardware clock to UTC\nand 1 means set it to Local time"
#define OPT5 "Please enter a value between 0 and 1:\n0 means disable NTP and 1 means enable NTP"
#define OPT3 "Enter the timezone. It should be like \nContinent/City - Europe/Berlin"
#define OPT12 "Enter the time. The time may be specified\nin the format  2018-08-01 09:12:45"
#define PRESS_ENTER "\nPress \"Enter\" to continue"
#define DONE "Done."
#define BAD_HAPPENS "Something went wrong, exiting !!!"

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
#define CMD4 "ntpdate -u 0.pool.ntp.org"
#define CMD5 "timedatectl set-ntp"
#define CMD6 "systemctl disable ntpd"
#define CMD7 "systemctl enable ntpd"
#define CMD8 "timedatectl set-local-rtc"
#define CMD9 "hwclock --verbose"
#define CMD10 "hwclock -w"
#define CMD11 "hwclock -s"
#define CMD12 "timedatectl set-time"

/* prototype the functions */
int run_menu(void);
void non_interactive(const int , const char *, const char *);
void non_interactive2(const char *);
void ask_n_run_cmd(const char *, const char *);
void ask_zero_or_one(const char *, const char *);

#endif /* CONSTANTS_H */
