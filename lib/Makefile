LIBRARY          = ./enumlib.so
LIBOJBJECTS      =
HEADERS          = *.hpp

OBJECTS          = enumlib.o 
OBJECTS         += enumlib_dim.160.o enumlib_dim.150.o enumlib_dim.140.o enumlib_dim.130.o 
OBJECTS         += enumlib_dim.120.o enumlib_dim.110.o enumlib_dim.100.o enumlib_dim.90.o 
OBJECTS         += enumlib_dim.80.o enumlib_dim.70.o enumlib_dim.60.o enumlib_dim.50.o 
OBJECTS         += enumlib_dim.40.o enumlib_dim.30.o enumlib_dim.20.o


CXX ?= g++
GCCLOCAL ?= boost
EXEC=/usr/bin/time
FPLLL ?= ~/git/fplll-dev-me

CXXFLAGS = -shared -fpic -fPIC -pthread -std=c++11 -march=native -Ofast -pipe $(CXXSPECIALOPTS) $(EXTRA_CXXFLAGS) 
CXXFLAGS += -I $(FPLLL)

LDFLAGS   += -L $(GCCLOCAL)/lib -lboost_thread -lboost_system -lpthread

all: build

build: $(LIBRARY)

%.o:%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(ALL_CCFLAGS) $(GENCODE_FLAGS) -o $@ -c $<

enumlib_dim.%.o: enumlib_dim.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(ALL_CCFLAGS) $(GENCODE_FLAGS) -o $@ -c $< -DENUMDIMENSION=`echo $@ | cut -d. -f2`

$(LIBRARY): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $+ $(LIBRARIES) $(LDFLAGS) 

run: build
	$(EXEC) $(PROGRAM) instances/BKZ-5/d60.base

clean:
	rm -f $(PROGRAM) $(OBJECTS) *~

