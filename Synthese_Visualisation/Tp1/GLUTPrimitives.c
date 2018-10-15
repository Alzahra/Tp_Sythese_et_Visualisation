//
//  GLUTPrimitives.c
//  
//
//  Created by HASSANEIN Alzahra on 13/04/2018.
//

#include <stdio.h>
#include <GLUT/glut.h>
#include <stdlib.h>

GLenum mode = GL_POLYGON ;

void trace_objet(void){
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glBegin(mode);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.2, 0.5);
    glVertex2f(0.4, 0.2);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.4, 0.3);
    glVertex2f(0.6, 0.2);
    glEnd();
    glutSwapBuffers();
}

void redim(int width, int height){
    //Affichage dans toute la fenetre
    glViewport(0,0,width, height);
}

/* fonction de gestion du menuPrincipal
 value contient l'identificateur associe à l'article du menu selectionne*/
void ChoixMenuPrincipal(int value) {
     switch (value) {
         case 10 :
             exit(0); /* on quitte */
             break;
     }
}

/* fonction de gestion du sousMenu */
void ChoixSousMenu(int value) {
 
    switch (value) {
        case 1 : mode = GL_POLYGON;  break;
        case 2 : mode = GL_LINES; break;
        case 3 : mode = GL_TRIANGLES; break;
        case 4 : mode = GL_POINTS; break;
    }
    glutPostRedisplay();
    
}


void CreerMenu(void) {
    int sousMenu;
    
    /* creation d'un menu, l'identicateur de ce menu est stocké dans l'entier sousMenu */
    sousMenu = glutCreateMenu(ChoixSousMenu);
    /* ajout d'une entree dans ce menu*/
    glutAddMenuEntry("Lines",2);
    glutAddMenuEntry("Triangles",3);
    glutAddMenuEntry("Points",4);
    glutAddMenuEntry("Polygon (Defaut)",1);
    /* creation d'un menu dont la fonction de "gestion" est ChoixMenuPrincipal */
    glutCreateMenu(ChoixMenuPrincipal);
    /* ajout d'un sous menu a ce menu*/
    glutAddSubMenu("Modes d'affichages",sousMenu);
    glutAddMenuEntry("Quitter",10);
    /* on associe l'apparition de ce menu au bouton droit de la souris */
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


//dessiner un carre de 3x3
void souris(int button, int state, int x, int y) {
    
    switch(button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN){
                glClear(GL_COLOR_BUFFER_BIT);
                glPointSize(2.0);
                glBegin(GL_POINTS);
                glColor3f(1.0,1.0,1.0);
                glVertex2i(x,y); 
                
                glEnd();
                glFlush();
                
                break;
            }
    }
    glutPostRedisplay(); //indique que le contenu de la fenetre doit etre affiche
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
    glutCreateWindow("GLUTPrimitives");
    
    //Association des callback
    glutDisplayFunc(trace_objet);
    glutReshapeFunc(redim);
    
    glutMouseFunc(souris);
    CreerMenu();
    
    glutMainLoop();
    return 0;
}
