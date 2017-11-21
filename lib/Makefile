LIBRARY          = ./libfplll_enumlib.so
LIBOJBJECTS      =
HEADERS          = *.hpp

OBJECTS          = enumlib.o 
OBJECTS         += enumlib_dim.160.o enumlib_dim.150.o enumlib_dim.140.o enumlib_dim.130.o 
OBJECTS         += enumlib_dim.120.o enumlib_dim.110.o enumlib_dim.100.o enumlib_dim.90.o 
OBJECTS         += enumlib_dim.80.o enumlib_dim.70.o enumlib_dim.60.o enumlib_dim.50.o 
OBJECTS         += enumlib_dim.40.o enumlib_dim.30.o enumlib_dim.20.o

CXX ?= g++

CXXFLAGS = -shared -fpic -fPIC -pthread -std=c++11 -march=native -O3 -pipe $(CXXSPECIALOPTS) $(EXTRA_CXXFLAGS) 
LDFLAGS  =

ifneq ($(VIRTUAL_ENV),)
CXXFLAGS += -I $(VIRTUAL_ENV)/include
LDFLAGS  += -L $(VIRTUAL_ENV)/lib
else
$(info Warning: environment variable VIRTUAL_ENV is not set!)
endif

LDFLAGS  += -lpthread -lfplll

all: build

build: $(LIBRARY)

%.o:%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(ALL_CCFLAGS) $(GENCODE_FLAGS) -o $@ -c $<

enumlib_dim.%.o: enumlib_dim.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(ALL_CCFLAGS) $(GENCODE_FLAGS) -o $@ -c $< -DENUMDIMENSION=`echo $@ | cut -d. -f2`

$(LIBRARY): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $+ $(LIBRARIES) $(LDFLAGS) 

clean:
	rm -f $(LIBRARY) $(OBJECTS) *~

ifneq ($(VIRTUAL_ENV),)
install: $(LIBRARY) enumlib.hpp
	-mkdir -p $(VIRTUAL_ENV)/include/fplll
	cp enumlib.hpp $(VIRTUAL_ENV)/include/fplll/
	cp $(LIBRARY) $(VIRTUAL_ENV)/lib/
else
install:
	@echo "Environment variable VIRTUAL_ENV is not set!"
endif
