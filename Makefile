all: temperature.exe

temperature.exe: temperature_main.c temperature.c
	gcc -Wall -Wextra -std=c11 -o temperature.exe temperature_main.c temperature.c

clean:
	rm -f temperature.exe
