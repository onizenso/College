//cs335 - Spring 2013
//program: Rain drops
//author:  Gordon Griesel
//purpose: Class exercise
//
//goal: Make it rain
//
//Recommend using a linked list to store raindrops
//
//	1. define the linked-list node structure
//	2. create nodes
//	3. add node to end of linked-list
//	4. examine all list nodes
//	5. remove node when needed
//	6. at end, empty the list
//
//
//
//The following components can be turned on/off
//note: in lab-2, only fonts are used.
//
//#define USE_SOUND
#define USE_FONTS
//#define USE_UMBRELLA
//#define USE_TEXTURES
//#define USE_LOG
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "defs.h"
#include <GL/glfw.h>

#ifdef USE_FONTS
#include "fonts.h"
#endif //USE_FONTS

//macros
#define rnd() (((double)rand())/(double)RAND_MAX)
#define random(a) (rand()%a)

//constants
const float timeslice = 1.0f/60.0f;
const float gravity = -0.2f;

//prototypes
void init(void);
int InitGL(GLvoid);
void checkkey(int k1, int k2);
void physics(void);
void render(void);
void draw_raindrops(void);
void create_raindrop(int one_flag);
void move_raindrops(void);
void check_raindrops(void);
void draw_mountains(void);

//global variables and constants
int time_control=1;
int xres,yres;
unsigned int window_type = GLFW_WINDOW;
typedef struct t_raindrop {
	int type;
	int linewidth;
	int sound;
	Vec pos;
	Vec lastpos;
	Vec vel;
	Vec maxvel;
	Vec force;
	float length;
	float color[4];
	struct t_raindrop *prev;
	struct t_raindrop *next;
} Raindrop;
Raindrop *ihead=NULL;
void delete_raindrop(Raindrop *in);
//
int totrain=0;
int maxrain=0;
int show_mountains = 1;
int show_rain      = 1;
int show_text      = 0;


int main(int argc, char **argv)
{
	int i, ret;
	srand((unsigned int)time(NULL));
	//
	glfwInit();
	srand(time(NULL));
	if (argc > 1) {
		if (strncasecmp(argv[1], "full", 4) == 0)
			window_type = GLFW_FULLSCREEN;
	}
	if (window_type == GLFW_FULLSCREEN) {
		GLFWvidmode glist[500];
		int nmodes = glfwGetVideoModes(glist, 100);
		xres = glist[nmodes-1].Width;
		yres = glist[nmodes-1].Height;
		ret = glfwOpenWindow(xres,yres,8,8,8,0,32,0,GLFW_FULLSCREEN);
		//glfwDisable( GLFW_MOUSE_CURSOR );
	} else {
		xres=320;
		yres=240;
		ret = glfwOpenWindow(xres,yres,0,0,0,0,0,0,GLFW_WINDOW);
		glfwSetWindowTitle("cs335 Lab2 Raindrops in linked list");
		glfwSetWindowPos(0, 0);
	}
	if (!ret) {
		glfwTerminate();
		return 0;
	}
	init();
	InitGL();
	glfwSetKeyCallback((GLFWkeyfun)(checkkey));
	glfwEnable( GLFW_KEY_REPEAT );
	//
	#ifdef USE_FONTS
	//glShadeModel(GL_FLAT);
	glShadeModel(GL_SMOOTH);
	//texture maps must be enabled to draw fonts
	glEnable(GL_TEXTURE_2D);
	initialize_fonts();
	#endif //USE_FONTS
	//
	while(1) {
		for (i=0; i<time_control; i++)
			physics();
		render();
		glfwSwapBuffers();
		if (glfwGetKey(GLFW_KEY_ESC)) break;
		if (!glfwGetWindowParam(GLFW_OPENED)) break;
	}
	glfwSetKeyCallback((GLFWkeyfun)NULL);
	glfwSetMousePosCallback((GLFWmouseposfun)NULL);
	printf("totrain: %i  maxrain: %i\n",totrain,maxrain);
	glfwTerminate();
	#ifdef USE_FONTS
	cleanup_fonts();
	#endif //USE_FONTS

	//--------------------------------------------------
	//We are leaving the program, and doing our cleanup.
	//
	//One part of cleanup is freeing memory that we have
	//allocated during execution.
	//
	//Here, you should check the linked-list of raindrops
	//to see if it still contains nodes.
	//
	//If so, then those nodes should be cleared from memory
	//using the free() command.
	//
	//hint:
	
			//...save next-node pointer...
	//			...free node...
	//			...get saved pointer...
	//			...is it null?...
	//			...yes: done...
	//			...no: continue...
	//		}
	//	}
	if (ihead)
    	{
	    while(ihead)
	    {
		Raindrop* temp;
	       	temp = ihead -> next;
		free(ihead);
		if (temp == NULL) break;
		ihead = temp;
	    }
	}

	return 0;
	}


void checkkey(int k1, int k2)
{
	static int shift=0;
	if (k2 == GLFW_PRESS) {
		//some key is being pressed now
		if (k1 == GLFW_KEY_LSHIFT || k1 == GLFW_KEY_RSHIFT) {
			//it is the shift key
			shift=1;
			return;
		}
	}
	if (k2 == GLFW_RELEASE) {
		if (k1 == GLFW_KEY_LSHIFT || k1 == GLFW_KEY_RSHIFT) {
			//the shift key was released
			shift=0;
		}
		//don't process any other keys on a release
		return;
	}
	if (k1 == 'M') {
		show_mountains ^= 1;
		return;
	}
	if (k1 == 'R') {
		show_rain ^= 1;
		return;
	}
	if (k1 == 'T') {
		show_text ^= 1;
		return;
	}
	if (k1 == '`') {
		if (--time_control < 0)
			time_control = 0;
		return;
	}
	if (k1 == '1') {
		if (++time_control > 32)
			time_control = 32;
		return;
	}
}

void init(void)
{
}

int InitGL(GLvoid)
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_FOG);
	glDisable(GL_CULL_FACE);
	glClearColor(0.1f, 0.2f, 0.3f, 0.0f);
	return 1;
}

void render(GLvoid)
{
	//Log("render()...\n");
	glfwGetWindowSize(&xres, &yres);
	glViewport(0, 0, xres, yres);
	//clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode (GL_PROJECTION); glLoadIdentity();
	glMatrixMode(GL_MODELVIEW); glLoadIdentity();
	glOrtho(0, xres, 0, yres, -1, 1);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	//
	//background sky
	glBegin(GL_QUADS);
		glColor3f(0.2f, 0.0f, 0.2f);
		glVertex2i(xres-1, 0);
		glVertex2i(0,      0);
		glColor3f(0.2f, 0.0f, 0.8f);
		glVertex2i(0,      yres-1);
		glVertex2i(xres-1, yres-1);
	glEnd();
	//mountain ranges
	if (show_mountains)
		draw_mountains();
	if (show_rain)
		draw_raindrops();
	//
	glDisable(GL_BLEND);
	//
	if (show_text) {
		//draw some text
		Rect r;
		r.left = 10;
		r.bot  = 90;
		r.center = 0;
		ggprint12(&r, 16, 0x00cc6622, "Mountains: %s",show_mountains==1?"On":"Off");
		ggprint12(&r, 16, 0x00cc6622, "Rain: %s",show_rain==1?"On":"Off");
		ggprint12(&r, 16, 0x00aaaa00, "total drops: %i",totrain);
		ggprint12(&r, 16, 0x00aaaa00, "max drops: %i\n",maxrain);
	}
}

void draw_raindrops(void)
{
	if (ihead) {
		Raindrop *in = ihead;
		while(in) {
			glPushMatrix();
			glTranslated(in->pos[0],in->pos[1],in->pos[2]);
			glColor4fv(in->color);
			glLineWidth(in->linewidth);
			glBegin(GL_LINES);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(0.0f, in->length, 0.0f);
			glEnd();
			glPopMatrix();
			//
			if (in->next==NULL) break;
			in = in->next;
		}
	}
	glLineWidth(1);
}

void draw_mountains(void)
{
	int i,j;
	float fk;
	static float mountain_range[4][64];
	static float mcol[4][4];
	static float step;
	static int firsttime=1;
	if (firsttime) {
		float h;
		float start[4] = {260.0f, 220.0f, 180.0f, 160.0f};
		for (i=0; i<4; i++) {
			h = start[i];
			for (j=0; j<64; j++) {
				mountain_range[i][j] = h;
				switch(i) {
				case 0: h += (rnd()*40.0f - 20.0f); break;
				case 1: h += (rnd()*34.0f - 17.0f); break;
				case 2: h += (rnd()*28.0f - 14.0f); break;
				case 3: h += (rnd()*18.0f -  9.0f); break;
				}
			}
			//set mountain color
			for (j=0; j<3; j++)
				mcol[i][j]=rnd()*0.2f;
			mcol[0][3]=0.12f;
			mcol[1][3]=0.12f;
			mcol[2][3]=0.12f;
			mcol[3][3]=0.12f;
		}
		step = (float)xres / 63.0f;
		firsttime=0;
	}
	//render mountain ranges...
	for (i=0; i<4; i++) {
		glColor4fv(mcol[i]);
		glBegin(GL_TRIANGLE_STRIP);
		fk = 0.0f;
		for (j=0; j<64; j++) {
			glVertex2f(fk, 0.0f);
			glVertex2f(fk, mountain_range[i][j]);
			fk += step;
		}
		glEnd();
	}
}

void physics(void)
{
	int freq = 50;
	if (window_type == GLFW_WINDOW)
		freq = 100;
	// originally it 1 was passed to create_raindrop
	if (random(100) < freq) {
		//create new rain drop...
		create_raindrop(0);
	}
	if (ihead) {
		move_raindrops();
	}
	if (ihead) {
		check_raindrops();
	}
}

void create_raindrop(int one_flag)
{
	//one_flag: 0 = Make a drop
	//              Many drops can be in the linked-list
	//          1 = Make a drop only if list is empty
	//              Only one drop in linked-list at a time
	//
	//printf("create_raindrop()...\n");
	if (one_flag && ihead) return;
	Raindrop *node = (Raindrop *)malloc(sizeof(Raindrop));
	if (node == NULL) {
		//out-of-memory is a fatal error.
		exit(EXIT_FAILURE);
	}
	node->sound=0;
	node->pos[0] = rnd() * (float)xres;
	if (window_type == GLFW_WINDOW) {
		//start droplet lower on screen
		node->pos[1] = (float)yres - 40.0f;
	} else {
		node->pos[1] = rnd() * 100.0f + (float)yres;
	}
	VecCopy(node->pos, node->lastpos);
	node->vel[0] = 
	node->vel[1] = 0.0f;
	node->color[0] = rnd() * 0.2f + 0.8f;
	node->color[1] = rnd() * 0.2f + 0.8f;
	node->color[2] = rnd() * 0.2f + 0.8f;
	if (window_type != GLFW_WINDOW) {
		node->color[3] = rnd() * 0.4f + 0.05f; //alpha
		node->linewidth = random(8)+1;
	} else {
		node->color[3] = 0.5f; //alpha
		node->linewidth = 8;
	}
	//larger linewidth means faster speed
	node->maxvel[1] = (float)(node->linewidth*16);
	node->length = node->maxvel[1] * 0.2f + rnd();
	//put raindrop into linked list
	node->next = ihead;
	if (ihead) ihead->prev = node;
	ihead = node;
	++totrain;
}

void move_raindrops(void)
{
	Raindrop *node = ihead;
	while(node) {
		//force is toward the ground
		node->vel[1] += gravity;
		if (window_type == GLFW_WINDOW)
			node->vel[1] += (gravity * 100.0f);
		VecCopy(node->pos, node->lastpos);
		node->pos[0] += node->vel[0] * timeslice;
		node->pos[1] += node->vel[1] * timeslice;
		//if (fabs(node->vel[1]) > node->maxvel[1])
		//	node->vel[1] *= .96f;
		//
		if (node->next == NULL) break;
		node = node->next;
	}
}

void check_raindrops(void)
{
	int r,n=0;
	Raindrop *savenode;
	Raindrop *node = ihead;
	while(node) {
		n++;
		if (node->pos[1] < -20.0f) {
			//rain drop is below the visible area
			savenode = node->next;
			delete_raindrop(node);
			node = savenode;
			if (node == NULL) break;
		}
		if (node->next == NULL) break;
		node = node->next;
	}
	if (maxrain < n)
		maxrain = n;
}

void delete_raindrop(Raindrop *node)
{

	//This code is not good!

	/*free(node);
	ihead = NULL;
	return;*/

	//---------------------------------------------------------------
	//Replace the code above.
	//Linked list may have several or many items in it, not just one.
	//You should remove only the node: *node
	//
	//for instance, 
	//	if (node->next == NULL)...
	//  you know that *node is the last node in the list.
	//  and you might remove it like so...
	//
	//		node->prev->next = NULL;
	//		free(node);
	//
	//also, you should always check for null before a free()
	//maybe like this...
	//
	//		if (node)
	//			free(node);
	//
	//
	//hint:
	//		check more than just the end node.
	//		node at the start of list?
	//		node in the middle of list?
	//


	//you can put new code below here
	
	if (node -> next == NULL)
	{
	    node -> prev -> next = NULL;
	    if (node)
	    free(node);
	}

	if (node -> prev == NULL)
	{
	    node -> next -> prev = NULL;
	    if (node)
	    free(node);
	}
	
	if (node -> prev && node -> next)
	{
	    node -> prev -> next = node -> next;
	    node -> next -> prev = node -> prev;
	    if (node)
	    free(node);
	}

	return;
}

