build_osx:
COMPILER = g++
SOURCE_LIBS = -ILib/
OSX_OPT = -LLib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL Lib/libraylib.a
OSX_OUT = -o "Bin/build_osx"
CFILES = Src/*.cpp

build_osx: 
	$(COMPILER) $(CFILES) $(SOURCE_LIBS) $(OSX_OUT) $(OSX_OPT)