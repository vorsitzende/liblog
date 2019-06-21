# Generic Multi-purpose Makefile
# Claudia Jughashvili, 2019

AS      := nasm
CC      := gcc
CPP     := g++
LD      := ld
INC     := include
OBJDIR  := obj
SRCDIR  := src
OUTDIR  := lib
OUT     := $(OUTDIR)/liblog.so
CFLAGS  := -c -Wall -I$(INC) -fPIC
LFLAGS  := -shared
CPPSRC  := $(notdir $(shell find $(SRCDIR) -maxdepth 1 -name '*.cpp'))
CPPOBJ  := $(addprefix $(OBJDIR)/,$(CPPSRC:%.cpp=%.o))
CSRC  := $(notdir $(shell find $(SRCDIR) -maxdepth 1 -name '*.c'))
COBJ  := $(addprefix $(OBJDIR)/,$(CSRC:%.c=%.o))

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CPP) $(CFLAGS) $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

all : $(CPPOBJ) $(COBJ)
	$(CPP) $(LFLAGS) $(CPPOBJ) $(COBJ) -o $(OUT)
	strip -s $(OUT)

.PHONY : clean
clean :
	rm -f $(CPPOBJ) $(COBJ) $(OUT)
