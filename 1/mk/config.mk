ifdef TAU
TAUROOTDIR	= /usr/local/tau
include $(TAUROOTDIR)/include/Makefile
CXX		= $(TAU_CXX)
CXXFLAGS        = $(TAU_INCLUDE) $(TAU_DEFS)
LIBS 	      	= $(TAU_LIBS)
LDFLAGS	      	= $(USER_OPT) -lpthread
else
CXX		= $(CXXPATH)g++
endif

CXXFLAGS += -ftemplate-depth-30

ifdef PTHREADS
CXXFLAGS += -DSMP_WITH_THREADS -DNUMBER_OF_PROCESSORS=2
LIBS += -lpthread
else
WITH_PTHREADS =
endif

OPTFLAGS = -O3 -Wall
OPTFLAGS += -g

CXXFLAGS += $(OPTFLAGS)
LDFLAGS += $(OPTFLAGS)

CXXFLAGS += 
