CLASS := $(wildcard class/*.cpp)
CLASS2 := $(wildcard class/*/*.cpp)
CLASS3 := $(wildcard class/*/*/*.cpp)
CLASS4 := $(wildcard utils/*.cpp)
# OBJECTS :=  $(patsubst %.cpp, %.o, $(CLASS) $(CLASS2) $(CLASS3) $(CLASS4))

%.o : %.cpp
	  g++ -c $< -o $@

main: 
	g++ $(CLASS) $(CLASS2) $(CLASS3) main.cpp -o $@.exe

clean: 
	rm *.exe