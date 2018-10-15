//  GLUTFenetre.c
//  Created by HASSANEIN Alzahra
//

#include <GLUT/glut.h>
#include <stdlib.h>

void affichage(void){

    //on efface le buffer d'ecran
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //on affiche
    glutSwapBuffers();
}

void redim(int width, int height){
    //Affichage dans toute la fenetre
    glViewport(0,0,width, height);
}


void clavier(unsigned char key, int x, int y){
    
    switch (key){
        case 32 :
            glClearColor(rand()%2,rand()%2,rand()%2,0);
            break;
        case 'q':
        case'Q' :
            exit (0);
            break;
    }glutPostRedisplay();
}

int main (int argc, char **argv){
    
    //Initialisation de GLUT
    glutInit(&argc, argv);
    
    //Taille et emplacemet de la fenetre
    glutInitWindowSize(400,400);
    glutInitWindowPosition(200,100);
    
    //Type d'affichage, Tampon de profondeur, Double buffer
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    
    //Creation de la premiere fenetre
    glutCreateWindow("GLUTFenetre");
   
    //Association des callback
    glutDisplayFunc(affichage);
    glutReshapeFunc(redim);
    
    //Action Clavier
    glutKeyboardFunc(clavier);
    
 
    glutMainLoop();
    
    return 0;
    
}
