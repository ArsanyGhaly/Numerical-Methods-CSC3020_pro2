AutomatedMakefile = am
CC = g++

FILES =  Example.o

PROJECT_PATH = $(CURRENT_DIR)

INC_DIRS = -I$(PROJECT_PATH)/include/

LIBS = -lCSC2110

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o

all: Example


Example: 		$(FILES)
			$(LINK) Example.exe $(FILES) $(LIBS)

Secant.o:		Secant.h Secant.cpp
			$(COMPILE) Secant.cpp

Example.o:		Example.h Example.cpp
			$(COMPILE) Example.cpp





