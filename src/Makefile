############################################
#             PATH DEFINITIONS             #
############################################

MAIN_PATH = ../

BIN_PATH = ../bin

SOURCE_PATH = ./

TEST_PATH = ../tests


#########################################################
#             COMPILER AND FLAG DEFINITIONS             #
#########################################################

CC = gcc
LD = gcc

CFLAGS = -Wall
LFLAGS = -Wall 


##############################################
#             OBJECT DEFINITIONS             #
##############################################


CVMMAINOBJS = cvmMain.o cvmStack.o cvmErrors.o


CVMTESTSOBJS = cvmTests.o cvmStack.o cvmErrors.o

##############################################
#             TARGET DEFINITIONS             #
##############################################

EXECS = 	cvmMain\

TESTS =		cvmTests

#######################################
#             BUILD RULES             #
#######################################

#Implicit rule
.c.o: 
	$(CC) $(CFLAGS) -c $<

cvmMain:  $(CVMMAINOBJS)
	$(LD) $(LFLAGS) -o $@ $(CVMMAINOBJS) 

cvmTests:  $(CVMTESTSOBJS)
	$(LD) $(LFLAGS) -o $@ $(CVMTESTSOBJS)

all: $(EXECS)


########################################
#             TEST SCRIPT              #
########################################



################################################
#             INSTALLATION SCRIPT              #
################################################


install: $(EXECS)
	mkdir -p $(BIN_PATH)
	cp $(EXECS) $(BIN_PATH)
	rm -rf *.o $(EXECS)

test: $(TESTS)
	mkdir -p $(TEST_PATH)
	cp $(TESTS) $(TEST_PATH)
	rm -rf *.o $(TESTS)
	$(TEST_PATH)/cvmTests	

	
clean:
	rm -rf *.o $(EXECS)
	rm -f $(BIN_PATH)/*
	rm -f $(TEST_PATH)/*