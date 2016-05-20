CXXFLAGS=-std=c++11 -g
LDFLAGS=-lglui -lglut -lGL -lGLU
oDir=oFiles/
oFiles=Camera.o CubeCell.o GridCube.o main.o
all: $(oDir)
	make --no-print-directory unclear
	make --no-print-directory comp
	make --no-print-directory clear
$(oDir):
	mkdir $(oDir)
comp: $(oFiles)
	g++ -o Prog $(oFiles) $(LDFLAGS)
Camera.o: Camera.cpp Camera.h Algebra.h
CubeCell.o: CubeCell.cpp CubeCell.h Algebra.h prototyes.h
GridCube.o: GridCube.cpp GridCube.h CubeCell.h Algebra.h prototyes.h
main.o: main.cpp Camera.h Algebra.h GridCube.h CubeCell.h prototyes.h
unclear:
	@if ! mv $(oDir)*.o .; then printf "";fi
clear:
	@if ! mv *.o $(oDir); then printf "";fi
clean:
	rm *.o ;rm $(oDir)*.o
