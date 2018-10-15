//  GLUTFenetres.c
//  Created by HASSANEIN Alzahra
//

#include <GLUT/glut.h>


void affichage(void){
    
    glClearColor(0,0,0,0);
    //on efface le buffer d'ecran
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //on affiche
    glutSwapBuffers();
}


void redim(int width, int height){
    //Affichage dans toute la fenetre
    glViewport(0,0,width, height);
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
    glutCreateWindow("GLUTFenetre1");
    
    //Association des callback
    glutDisplayFunc(affichage);
    glutReshapeFunc(redim);
    
    //Creation de la seconde fenetre
    glutInitWindowPosition(650,100);
    glutCreateWindow("GLUTFenetreBis");
    
    //Association des callback
    glutDisplayFunc(affichage);
    glutReshapeFunc(redim);
    
    glutMainLoop();
    
    return 0;
    
}


