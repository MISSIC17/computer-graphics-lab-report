CC = gcc
CFLAGS = -lgraph -lGL -lGLU -lglut 
about:
	@echo "DSA Lab Report"

run:
	@$(CC) title.c -o ./output/title.out && output/title.out
	@$(CC) $(f) -o output/${basename}.out $(CFLAGS)
	@./output/${f}.out


dir := $(dir $(f))
filename := $(notdir $(f))
basename := $(subst /,-,$(dir))$(basename $(filename))
