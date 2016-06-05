CXX=g++
OBJ=statusbar.o
LFLAGS=-lstatusbar
CFLAGS=-O3 -Ilib/

#main
montecarlobirthday.out: main.cpp lib/libstatusbar.a
	$(CXX) $(LFLAGS) -O3 -Ilib/ -Llib/ $< -o $@

lib/libstatusbar.a: statusbar.o
	ar rcs $@ $^

.cpp.o:
	$(CXX) $(CFLAGS) -c $<

%.o: lib/%.cpp
	$(CXX) $(CFLAGS) -c $<

clean:
	rm -rf *.o *~
cleanall: clean
	rm *.out
