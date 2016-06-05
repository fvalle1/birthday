CXX=g++
OBJ=statusbar.o main.o
LFLAGS=-lstatusbar
CFLAGS=-O3 -Ilib/

TARGET=montecarlobirthday.out 

all: $(TARGET)

%.out: $(OBJ)
	$(CXX) -O3 -Ilib/  $^ -o $@

lib/libstatusbar.a: statusbar.o
	ar rcs $@ $^

.cpp.o:
	$(CXX) $(CFLAGS) -c $<

%.o: lib/%.cpp
	$(CXX) $(CFLAGS) -c $<

wl: main.cpp lib/libstatusbar.a
	$(CXX) $(LFLAGS) -Llib/ -Ilib/ $< -o $(TARGET)

clean:
	rm -rf *.o *~
cleanall: clean
	rm -f *.out
