CLASS := $(wildcard src/class/*.cpp)
CLASS2 := $(wildcard src/class/*/*.cpp)
CLASS3 := $(wildcard src/class/*/*/*.cpp)
CLASS4 := $(wildcard src/utils/*.cpp)
OUTPUT_FOLDER := bin
# OBJECTS :=  $(patsubst %.cpp, %.o, $(CLASS) $(CLASS2) $(CLASS3) $(CLASS4))

%.o : %.cpp
	  g++ -c $< -o $@

main_windows: 
	g++ $(CLASS) $(CLASS2) $(CLASS3) src/utils/sort.cpp src/main.cpp -o $(OUTPUT_FOLDER)/$@.exe

main_linux: 
	g++ $(CLASS) $(CLASS2) $(CLASS3) src/utils/sort.cpp src/main.cpp -o $(OUTPUT_FOLDER)/$@

clean_main: 
	rm $(OUTPUT_FOLDER)/*.exe $(OUTPUT_FOLDER)/main_linux

CLASS_UNO := $(wildcard uno/class/*.cpp)
CLASS_UNO2 := $(wildcard uno/class/*/*.cpp)
CLASS_UNO3 := $(wildcard uno/class/*/*/*.cpp)
CLASS_UNO4 := $(wildcard uno/utils/*.cpp)

uno_windows: 
	g++ $(CLASS_UNO) $(CLASS_UNO2) $(CLASS_UNO3) uno/main.cpp -o $(OUTPUT_FOLDER)/$@.exe

uno_linux: 
	g++ $(CLASS_UNO) $(CLASS_UNO2) $(CLASS_UNO3) uno/main.cpp -o $(OUTPUT_FOLDER)/$@

clean_uno: 
	rm $(OUTPUT_FOLDER)*.exe $(OUTPUT_FOLDER)/uno_linux