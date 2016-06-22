
CPP = g++

SRCDIR =  ../../../src
TSTDIR = ..
INCLUDEDIR = ../../../include
RAPIDJSONDIR = ../../../../rapidjson/include 

CPPFLAGS = -MD -I$(INCLUDEDIR) -I$(RAPIDJSONDIR)

VPATH = $(TSTDIR):$(SRCDIR)

LIBS = -lcurl

SRC = string_utils.cpp series.cpp \
	quandl.cpp yahoo.cpp mt.cpp web.cpp test.cpp

OBJ = $(SRC:.cpp=.o)

all:: test;

.SUFFIXES : .o .cpp .c 

.cpp.o :
	$(CPP) $(CPPFLAGS) -c $<

test: $(OBJ)
	$(CPP) $(OBJ) $(LIBS) -o test; 

#	$(CPP) -o $@ $^ $(CPPFLAGS) $(LIBS)

clean:
	rm $(SRCDIR)/*.o $(TSTDIR)/*.o 
