CC      = g++
CFLAGS  = -std=c++17 -Wall -Wextra -Werror -Wuninitialized
CLIBS   = -lgtest -lgtest_main
FILES   = controller/* facade/* model/* view/* tests/*.h tests/*.cc
ifeq ($(shell uname -s), Darwin)
TARGET = maze.app
else
TARGET = maze
endif

all: uninstall install
ifeq ($(shell uname -s), Darwin)
	open bin/$(TARGET)
else
	./bin/$(TARGET)
endif

install: clean
	mkdir -p build
	mkdir -p bin
	cd build && cp ../maze.pro ./maze.pro && \
	qmake && make && mv $(TARGET) ../bin/ && \
	cd .. && rm -rf build

uninstall: clean
	rm -rf bin

clean:
	rm -rf build
	rm -rf report
	rm -rf docs

dvi: clean
	doxygen ./dvi/Doxyfile
	cp dvi/maze.jpg docs/html
	cp dvi/maze.jpg docs/latex
ifeq ($(shell uname -s), Darwin)
	open docs/html/index.html
else
	xdg-open ./docs/html/index.html
endif

dist: uninstall install
	tar  -cvzf ./bin/dist.tar ./bin/$(TARGET)
	rm -rf ./bin/$(TARGET)

tests: clean
	mkdir -p build
	cd build && \
	$(CC) $(CFLAGS) \
	../facade/file_reader* ../model/* ../tests/*.cc -o tests $(CLIBS) && \
	./tests && \
	cd .. && rm -rf build

gcov-report: clean
	mkdir -p build
	cd build && \
	$(CC) $(CFLAGS) --coverage \
	../facade/file_reader* ../model/* ../tests/*.cc -o tests $(CLIBS) && \
	lcov -c -i -d . -o base.info && \
	./tests && \
	lcov -c -d . -o test.info && \
	lcov -a base.info -a test.info -o total.info && \
	lcov -r total.info "/usr/*" "*/A1_Maze-1/src/tests/tests.cc" -o filtered.info && \
	genhtml --ignore-errors source filtered.info -o ../report && \
	cd .. && rm -rf build
ifeq ($(shell uname -s), Darwin)
	open report/index.html
else
	xdg-open ./report/index.html
endif

googlestyle:
	cp ../materials/linters/.clang-format ./
	clang-format -i $(FILES)
	rm -f ./.clang-format

clang-format:
	cp ../materials/linters/.clang-format ./
	clang-format -n $(FILES)
	rm -f ./.clang-format

valgrind: clean
	mkdir -p build
	cd build && \
	$(CC) $(CFLAGS) -g \
	../facade/file_reader* ../model/* ../tests/*.cc -o tests $(CLIBS) && \
	valgrind --tool=memcheck --leak-check=yes -s -q ./tests && \
	cd .. && rm -rf build

leaks: clean
	mkdir -p build
	cd build && \
	$(CC) $(CFLAGS) \
	../facade/file_reader* ../model/* ../tests/*.cc -o tests $(CLIBS) && \
	CK_FORK=no leaks -atExit -- ./tests && \
	cd .. && rm -rf build
