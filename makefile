CC = gcc
CFLAGS =  -lSDL_image -framework OpenGL -framework GLUT
SDL_INC= `sdl-config --cflags`
SDL_LIB= `sdl-config --libs`

all: my_world clear

input.o: input.c
	$(CC) -c $^

printing_functions.o: printing_functions.c
	$(CC) -c $^ $(SDL_INC) $(SDL_LIB)

my_world.o: my_world.c
	$(CC) -c $^ $(SDL_INC) $(SDL_LIB)

my_world: my_world.o printing_functions.o input.o
	$(CC) -o my_world $^ $(CFLAGS) $(SDL_INC) $(SDL_LIB)

clear:
	rm *.o

