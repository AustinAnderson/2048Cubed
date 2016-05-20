CXXFLAGS=-std=c++11 -g
LDFLAGS=-lglui -lglut -lGL -lGLU
oDir=oFiles/
oFiles=driver.o InternalCell.o InternalGrid.o
all: $(oDir)
	make --no-print-directory unclear
	make --no-print-directory comp
	make --no-print-directory clear
$(oDir):
	mkdir $(oDir)
comp: $(oFiles)
	g++ -o Prog $(oFiles) $(LDFLAGS)
driver.o: driver.cpp InternalGrid.h InternalCell.h Algebra.h
InternalCell.o: InternalCell.cpp InternalCell.h Algebra.h
InternalGrid.o: InternalGrid.cpp InternalGrid.h InternalCell.h Algebra.h
unclear:
	@if ! mv $(oDir)*.o .; then printf "";fi
clear:
	@if ! mv *.o $(oDir); then printf "";fi
clean:
	rm *.o ;rm $(oDir)*.o
