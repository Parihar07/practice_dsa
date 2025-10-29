#this simple make file
CXX = g++
CXXFLAGS = 
EXCECUTABLE = main.out


#Get list of all cpp files
CXX_SRC_FILES = $(wildcard ./*.cpp)
#Rename all the files from above list to extension .o
#command syntax patsubst: $(text:pattern=replacement)
CXX_OBG_FILES = $(patsubst ./%.cpp, ./%.o, $(CXX_SRC_FILES))

CALL_CXX_COMPILER = $(CXX) $(CXXFLAGS)

## TARGETS ##
build: $(CXX_OBG_FILES)
	echo "$(CXX_OBG_FILES)"
	${CALL_CXX_COMPILER} $(CXX_OBG_FILES) -o $(EXCECUTABLE)

execute:
	./$(EXCECUTABLE)

clean:
	rm -f *.out 
	rm -f *.o
	rm -f $(EXCECUTABLE).out

%.o: %.cpp
	$(CXX) -c $< -o $@ 