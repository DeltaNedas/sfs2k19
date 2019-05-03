CXX = g++-8
CXXFLAGS = -O3 -Wall -std=c++17 -I. -c
LDFLAGS = -Wl,-rpath,'$$ORIGIN'

BUILDDIR = build

EXEC_FILE = sfs2k19
OBJ = main.cpp.o
OBJECTS = $(patsubst %, $(BUILDDIR)/%, $(OBJ))

COMPILE = $(CXX) $(CXXFLAGS) -o $@ $^

all: $(EXEC_FILE)

$(BUILDDIR)/%.cpp.o: %.cpp 
	$(COMPILE)

$(EXEC_FILE): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm $(BUILDDIR)/*.cpp.o
