default:
	@make -s build
	@make -s run
build: 
	@rm main
	@echo "Compiling...."
	@ gcc main.c encryption/encryption.c -lm -o main
run:
	@echo "Running...."
	@./main