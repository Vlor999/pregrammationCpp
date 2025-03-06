++ = g++ -std=c++11 -Wall -Wextra
OUT = out
FILE = helloWorld.c++
OUTFILE = helloWorld

all: run

compile:
	mkdir -p $(OUT)
	$(++) $(FILE) -o $(OUT)/$(OUTFILE)

run: compile
	./$(OUT)/$(OUTFILE)

clean:
	rm -rf $(OUT)/*