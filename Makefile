CC=gcc
CFLAGS=-Wall -g -Iinclude
LDFLAGS=-lncurses
SRCDIR=src
OBJDIR=obj
BINDIR=bin
SRCS=$(addprefix $(SRCDIR)/,%.c)
OBJS=$(addprefix $(OBJDIR)/,main.o snake.o unit.o food.o event.o board.o)
PROGNAME=snake

$(OBJDIR)/%.o: $(SRCS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS) | $(BINDIR)
	$(CC) -o $(BINDIR)/$(PROGNAME) $^ $(LDFLAGS)

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

.PHONY: clean
clean:
	rm -rf $(BINDIR) $(OBJDIR)
