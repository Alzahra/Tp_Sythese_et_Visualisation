UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	FLAGS = -lGL -lGLU -lglut
endif

ifeq ($(UNAME_S),Darwin)
	FLAGS = -framework OpenGL -framework glut
endif

all: glutTextureCube

glutTextureCube: glutTextureCube.o 
	$(CXX) -o $@ glutTextureCube.o $(FLAGS) 

glutTextureCube.o: glutTextureCube.c 
	$(CXX) -c glutTextureCube.c $(FLAGS) 

clean:
	rm *.o glutTextureCube