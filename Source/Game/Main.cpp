#include <windows.h>
#include "glew.h"
#include "glut.h"

#include "InGameKeyboard.h"
#include "Utility.h"
#include "Game.h"

void initialize();
void initializeLighting();

int main( int argc, char *argv[] )
{
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE | GLUT_ALPHA |
						GLUT_ACCUM | GLUT_STENCIL| GLUT_MULTISAMPLE);

	// set up an XML config file with screen resolution
	// get refresh rate from win api
	// create string with settings
	// set gameMode with this new string

	//std::string width = itoa(GetSystemMetrics(SM_CXFULLSCREEN));

	glutGameModeString("1920x1080:32@60"); // @TODO (above)
	if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE))
		glutEnterGameMode();
	else {
		glutInitWindowSize(GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN));
		int windowID = glutCreateWindow("OpenGL App");
		Game::window().setID(windowID);
		glutFullScreen();
	}

	glutReshapeFunc(Game::resize);
	glutDisplayFunc(Game::render);
	glutKeyboardFunc(Game::keyDown);
	glutKeyboardUpFunc(Game::keyUp);
	glutSetCursor(GLUT_CURSOR_NONE);
	glutIgnoreKeyRepeat(1);
	glutEntryFunc(Game::windowFocus);

	initialize();
	Game::renderer().start();
	Game::gameLogic().start();
	glutMainLoop();

	Game::quit(EXIT_SUCCESS);
}

static void initialize()
{
    if (glewInit() != GLEW_OK)
		Game::quit(EXIT_FAILURE);
	glClearColor(0.4f, 0.5f, 0.1f, 1.0f);
	glShadeModel(GL_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glFrontFace(GL_CCW);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_FOG_HINT, GL_NICEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glHint(GL_GENERATE_MIPMAP_HINT, GL_NICEST);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_LIGHTING);

	// set projection
	Game::projection().setFovy(60.0);
	Game::projection().setZNear(0.01);
	Game::projection().setZFar(1000.0);

	Game::gameWorld().setGravity(0.2);
	Game::player().setSpeed(1.5, 1.5, 1.5);
	Game::setKeyboard(InGameKeyboard());

	initializeLighting();
}

static void initializeLighting()
{
	GLfloat lightModelAmbient[4] = {0.2f, 0.2f, 0.2f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightModelAmbient);
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

	GLfloat ambiant[4] = {0.0f, 0.0f, 0.0f, 0.0f};
	GLfloat diffuse[4] = {0.9f, 0.9f, 0.8f, 1.0f};
	GLfloat specular[4] = {0.6f, 0.6f, 0.6f, 1.0f};
	GLfloat position[4] = {0.0f, 0.0f, 1.0f, 0.0f};
	GLfloat spotDirection[3] = {0.0f, 0.0f, -1.0f};
	GLfloat exponent = 2.0;
	GLfloat cutoff = 180;
	GLfloat constantAttenuation = 1.0;
	GLfloat	linearAttenuation = 0.0;
	GLfloat	quadraticAttenuation = 0.0;
	Light light0(GL_LIGHT0, ambiant, diffuse, specular, 
		position, spotDirection, exponent, cutoff,
		constantAttenuation, linearAttenuation, quadraticAttenuation);
	Game::lighting().addLight(light0);
}

/*
glutSpecialFunc(keyboardSpecial);
glutPassiveMotionFunc(mouseMove);
glutMouseFunc(mouseClick);
void mouseMove(int x, int y);
void mouseClick(int button, int state, int x, int y)
{
	//if ( state == GLUT_DOWN ){}
}
void keyboardSpecial(int key, int x, int y)
{
	switch ( key )
	{
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
	case GLUT_KEY_UP:
		break;
	case GLUT_KEY_DOWN:
		break;
	}
}
*/