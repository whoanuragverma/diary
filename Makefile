SRC = $(wildcard *.c) $(wildcard */*.c)
LIBS = -lm 
default: 
	@make -s build
	@make -s run
build: $(SRC)
	@echo Compiling these files 
	@echo $(SRC)
	@echo Compiling all of these into ./main
	@gcc $(SRC) $(LIBS) -o main || exit 1
run:
	@echo Running...
ifeq ($(OS),Windows_NT)
	@echo Launching new CMD on Windows
	@CMD /C start cmd.exe /K main || echo Failed to Start CMD
else
	@./main
	@echo 
endif
	