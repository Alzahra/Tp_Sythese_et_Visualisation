UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	FLAGS = -lGL -lGLU -lglut
endif

ifeq ($(UNAME_S),Darwin)
	FLAGS = -framework OpenGL -framework glut
endif

all: GlutFenetre GlutFenetres GlutFenetresCouleurs GlutPrimitives

GlutFenetre: GLUTFenetre.o 
	$(CXX) -o $@ GLUTFenetre.o $(FLAGS) 

GLUTFenetre.o: GLUTFenetre.c 
	$(CXX) -c GLUTFenetre.c $(FLAGS) 


GlutFenetres: GLUTFenetres.o
	$(CXX) -o $@ GLUTFenetres.o $(FLAGS) 

GLUTFenetres.o: GLUTFenetres.c
	$(CXX) -c GLUTFenetres.c $(FLAGS) 


GlutFenetresCouleurs: GLUTFenetresCouleurs.o
	$(CXX) -o $@ GLUTFenetresCouleurs.o $(FLAGS)  

GLUTFenetresCouleurs.o : GLUTFenetresCouleurs.c
	$(CXX) -c GLUTFenetresCouleurs.c $(FLAGS)


GlutPrimitives: GLUTPrimitives.o
	$(CXX) -o $@ GLUTPrimitives.o $(FLAGS)

GLUTPrimitives.o : GLUTPrimitives.c
	$(CXX) -c GLUTPrimitives.c $(FLAGS)

clean:
	rm *.o GlutFenetre GlutFenetres GlutFenetresCouleurs GlutPrimitives
