CC := gcc
CFLAGS := -Wall -Wextra -std=c11

# Targets
all: football.exe temperature.exe

football.exe: football_main.c football.c football.h
	$(CC) $(CFLAGS) -o football.exe football_main.c football.c

temperature.exe: temperature_main.c temperature.c temperature.h
	$(CC) $(CFLAGS) -o temperature.exe temperature_main.c temperature.c

clean:
	rm -f *.exe
