//  GLUTFenetresCouleurs.c
//  Created by HASSANEIN Alzahra
//

#include <GLUT/glut.h>


void affichage1(void){
    
    glClearColor(0,0,0,0);
    //on efface le buffer d'ecran
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //on affiche
    glutSwapBuffers();
}


void affichage2(void){
    
    glClearColor(1,0,0,0);
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
    glutCreateWindow("GLUTFenetresCouleurs");
    
    //Association des callback
    glutDisplayFunc(affichage1);
    glutReshapeFunc(redim);
    
    //Creation de la seconde fenetre
    glutInitWindowPosition(650,100);
    glutCreateWindow("GLUTFenetresCouleursBis");
    
    //Association des callback
    glutDisplayFunc(affichage2);
    glutReshapeFunc(redim);
    
    glutMainLoop();
    
    return 0;
    
}

