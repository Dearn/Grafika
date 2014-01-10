####====---- Implemented by dr inż. Krzysztof Rojek ----====####

PROJECT = test

INC   =   ./include
SRC   =   ./src
BIN   =   ./bin
OBJ   =   ./obj
MKFILES    =   ./mk

CXXFLAGS += -I$(INC)

include ./$(MKFILES)/config.mk

CXXFLAGS += -I/usr/include/qt4 -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4/Qt -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui
LIBS += -L/usr/lib64/qt4 -lQtGui -lQtCore -lGLU -lGL -lglut -lQtOpenGL

OBJS =	$(OBJ)/test.o $(OBJ)/scena.o $(OBJ)/scena_moc.o

all: $(PROJECT)

depend:
	$(CXX) -MM $(CXXFLAGS) -iprefix obj -iwithprefix obj $(SRC)/*.cpp > \
	$(MKFILES)/depend.tmp
	sed 's/^[a-z_-]*\.o:/$$(OBJ)\/&/'  $(MKFILES)/depend.tmp > \
	$(MKFILES)/depend.mk
	rm  $(MKFILES)/depend.tmp

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(SRC)/scena_moc.cpp: $(INC)/scena.h
	moc $< -o $@

$(PROJECT): $(SRC)/scena_moc.cpp $(OBJS) 
	$(CXX) $(LDFLAGS) -o $(BIN)/$(PROJECT) $(OBJS) $(LIBS)

run:
	$(BIN)/$(PROJECT)

clean:
	-rm -rf $(OBJ)/*.o $(SRC)/scena_moc.cpp

realclean: clean
	-rm -rf $(BIN)/$(PROJECT)

include ./$(MKFILES)/depend.mk
