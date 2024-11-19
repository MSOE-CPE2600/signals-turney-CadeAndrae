CC = gcc
CFLAGS = -Wall
LDFLAGS =
SOURCES = recv_signal.c send_signal.c signal_alarm.c signal_handler.c signal_segfault.c signal_sigaction.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLES = recv_signal send_signal signal_alarm signal_handler signal_segfault signal_sigaction

all: $(EXECUTABLES)

-include $(OBJECTS:.o=.d)

recv_signal: recv_signal.o
	$(CC) recv_signal.o $(LDFLAGS) -o recv_signal

send_signal: send_signal.o
	$(CC) send_signal.o $(LDFLAGS) -o send_signal

signal_alarm: signal_alarm.o
	$(CC) signal_alarm.o $(LDFLAGS) -o signal_alarm

signal_handler: signal_handler.o
	$(CC) signal_handler.o $(LDFLAGS) -o signal_handler

signal_segfault: signal_segfault.o
	$(CC) signal_segfault.o $(LDFLAGS) -o signal_segfault

signal_sigaction: signal_sigaction.o
	$(CC) signal_sigaction.o $(LDFLAGS) -o signal_sigaction

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	$(CC) -MM $(CFLAGS) $< > $*.d

clean:
	rm -rf $(OBJECTS) $(EXECUTABLES) *.d
