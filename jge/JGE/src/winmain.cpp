//========================================================================
//    NeHe OpenGL Wizard : NeHeSimple.cpp
//    Wizard Created by: Vic Hollis
//========================================================================
/*
 *		This Code Was Created By Jeff Molofee 2000
 *		A HUGE Thanks To Fredric Echols For Cleaning Up
 *		And Optimizing This Code, Making It More Flexible!
 *		If You've Found This Code Useful, Please Let Me Know.
 *		Visit My Site At nehe.gamedev.net
 */

//#include <stdio.h>
//#include <fcntl.h>
//#include <io.h>
//
//#include <iostream>
//#include <fstream>
//#include <map>

#include <chrono>
#include <stdio.h>
#include <time.h>
#include <map>
#include <functional>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include <windows.h>		// Header File For Windows
#include <gl\glew.h> 

#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <gl\glaux.h>		// Header File For The Glaux Library

#include "..\..\JGE\include\JGE.h"
#include "..\..\JGE\include\JTypes.h"
#include "..\..\JGE\include\JApp.h"
#include "..\..\JGE\include\JFileSystem.h"
#include "..\..\JGE\include\JRenderer.h"

#include "..\..\JGE\include\JGameLauncher.h"

#include <SDL.h>
#include <SDL_mouse.h>
#include <SDL_syswm.h>

using namespace std;
using namespace chrono;

SDL_Window* window = NULL;
SDL_GLContext glContext;
SDL_Event event;
SDL_GameController* gameController = nullptr;



//#include "..\src\GameApp.h"

#pragma comment( lib, "opengl32.lib" )	// Search For OpenGL32.lib While Linking
#pragma comment( lib, "glu32.lib" )		// Search For GLu32.lib While Linking
#pragma comment( lib, "glaux.lib" )		// Search For GLaux.lib While Linking
#pragma comment( lib, "User32.lib" )
#pragma comment( lib, "Gdi32.lib" )
#pragma comment( lib, "Comdlg32.lib" )

HDC			hDC=NULL;		// Private GDI Device Context
HGLRC		hRC=NULL;		// Permanent Rendering Context
HWND		hWnd=NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	active=TRUE;			// Window Active Flag Set To TRUE By Default
bool	fullscreen=FALSE;		// Windowed Mode By Default

bool g_isUsingKeyboard = false;

BOOL	done = FALSE;


DWORD	lastTickCount;

BOOL	g_keys[256];

//------------------------------------------------------------------------

JGE* g_engine = NULL;
JApp* g_app = NULL;
JGameLauncher* g_launcher = NULL;

//------------------------------------------------------------------------


static u32 gButtons = 0;
static u32 gOldButtons = 0;

double analogX = 0;
double analogY = 0;
std::string textInput = "";
//std::vector<bool> keyPressed(256, false);
//int ScreenW = 2560;
//int ScreenH = 1440;
int ScreenW = SCREEN_WIDTH;
int ScreenH = SCREEN_HEIGHT;

map<int, int> gKeyboardMap = {
	{SDL_SCANCODE_G, PSP_CTRL_TRIANGLE},
	{SDL_SCANCODE_BACKSPACE, PSP_CTRL_CIRCLE},
	{SDL_SCANCODE_SPACE, PSP_CTRL_CROSS},
	{SDL_SCANCODE_Y, PSP_CTRL_UP},
	{SDL_SCANCODE_B, PSP_CTRL_DOWN},
	{SDL_SCANCODE_H, PSP_CTRL_LEFT},
	{SDL_SCANCODE_U, PSP_CTRL_RIGHT},
	{SDL_SCANCODE_LEFT, PSP_CTRL_LTRIGGER},
	{SDL_SCANCODE_RIGHT, PSP_CTRL_RTRIGGER},
	{SDL_SCANCODE_RETURN, PSP_CTRL_START},
	{SDL_SCANCODE_TAB, PSP_CTRL_SELECT},
	{SDL_SCANCODE_LALT, PSP_CTRL_NOTE},
	{SDL_SCANCODE_R, PSP_CTRL_SQUARE}
};

map<int, int> gMouseMap = {
	{SDL_BUTTON_LEFT, PSP_CTRL_CROSS},
	{SDL_BUTTON_RIGHT, PSP_CTRL_CIRCLE},
	{SDL_BUTTON_MIDDLE, PSP_CTRL_TRIANGLE}
};

map<int, int> gGamepadMap = {
	{SDL_CONTROLLER_BUTTON_A, PSP_CTRL_CROSS},
	{SDL_CONTROLLER_BUTTON_B, PSP_CTRL_CIRCLE},
	{SDL_CONTROLLER_BUTTON_X, PSP_CTRL_SQUARE},
	{SDL_CONTROLLER_BUTTON_Y, PSP_CTRL_TRIANGLE},
	{SDL_CONTROLLER_BUTTON_LEFTSHOULDER, PSP_CTRL_LTRIGGER},
	{SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, PSP_CTRL_RTRIGGER},
	{SDL_CONTROLLER_BUTTON_BACK, PSP_CTRL_SELECT},
	{SDL_CONTROLLER_BUTTON_START, PSP_CTRL_START},
	{SDL_CONTROLLER_BUTTON_DPAD_UP, PSP_CTRL_UP},
	{SDL_CONTROLLER_BUTTON_DPAD_DOWN, PSP_CTRL_DOWN},
	{SDL_CONTROLLER_BUTTON_DPAD_LEFT, PSP_CTRL_LEFT},
	{SDL_CONTROLLER_BUTTON_DPAD_RIGHT, PSP_CTRL_RIGHT}
};

//static u32 gPSPKeyMasks[17] =
//{
//	PSP_CTRL_SELECT,
//		PSP_CTRL_START,
//		PSP_CTRL_UP,
//		PSP_CTRL_RIGHT,
//		PSP_CTRL_DOWN,
//		PSP_CTRL_LEFT,
//		PSP_CTRL_LTRIGGER,
//		PSP_CTRL_RTRIGGER,
//		PSP_CTRL_TRIANGLE,
//		PSP_CTRL_CIRCLE,
//		PSP_CTRL_CROSS,
//		PSP_CTRL_SQUARE,
//		PSP_CTRL_HOME,
//		PSP_CTRL_HOLD,
//		PSP_CTRL_SQUARE,
//		PSP_CTRL_CIRCLE,
//		PSP_CTRL_TRIANGLE,
//};


//static u32 gWinKeyCodes[17] =
//{
//
//	VK_CONTROL,
//		VK_RETURN,
//		'Y',
//		'U',
//		'B',
//		VK_LEFT,
//		'Q',
//		'E',
//		'G',
//		VK_NUMPAD2,
//		VK_NUMPAD1,
//		'R',
//		VK_F1,
//		VK_F2,
//		VK_NUMPAD4,
//		VK_BACK,
//		VK_NUMPAD5
//		
//};

void SetEnglishKeyboardLayout() {
	// 將鍵盤佈局設置為美式英語
	HKL hklEnglish = LoadKeyboardLayout("00000409", KLF_SETFORPROCESS);
	if (hklEnglish == NULL) {
		// 如果加載失敗，輸出錯誤訊息
		MessageBox(NULL, "Failed to load English keyboard layout.", "Error", MB_OK | MB_ICONERROR);
		return;
	}

	// 啟用鍵盤佈局
	ActivateKeyboardLayout(hklEnglish, KLF_SETFORPROCESS);
}

void RedirectIOToConsole();
void UpdateProjectionMatrix(int width, int height);

string JGEGetTextInput()
{
	return textInput;
}


void JGEControl()
{
	gOldButtons = gButtons;

	textInput = "";
	
	gButtons = 0;
	
}

void process_input()
{
	gOldButtons = gButtons;
	gButtons = 0;
	textInput = "";

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_TEXTINPUT:
			textInput = event.text.text;
			break;
		case SDL_TEXTEDITING:
			// 忽略输入法文本编辑事件
			break;
		case SDL_QUIT:
			done = TRUE; // 设置标志以退出主循环
			break;
		case	SDL_CONTROLLERBUTTONDOWN:
				//isUsingKeyboard = false;
			break;
		case SDL_KEYDOWN:
				g_isUsingKeyboard = true;
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				// 退出相对模式，使鼠标可见并可移出窗口
				SDL_SetRelativeMouseMode(SDL_FALSE);
				SDL_ShowCursor(SDL_ENABLE);
				fullscreen = !fullscreen;
				SDL_SetWindowFullscreen(window, 0);
				ScreenW = SCREEN_WIDTH;
				ScreenH = SCREEN_HEIGHT;
				SDL_SetWindowSize(window, ScreenW, ScreenH);
				SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
				UpdateProjectionMatrix(ScreenW, ScreenH);  // 恢復投影矩陣
			}

			if (event.key.keysym.sym == SDLK_F11) {
				// 切换全屏和窗口模式
				fullscreen = !fullscreen;
				if (fullscreen) {
					SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
					SDL_GetWindowSize(window, &ScreenW, &ScreenH);
					UpdateProjectionMatrix(ScreenW, ScreenH);  // 更新投影矩陣
				}
				else {
					SDL_SetWindowFullscreen(window, 0);
					ScreenW = SCREEN_WIDTH;
					ScreenH = SCREEN_HEIGHT;
					SDL_SetWindowSize(window, ScreenW, ScreenH);
					SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
					UpdateProjectionMatrix(ScreenW, ScreenH);  // 恢復投影矩陣
				}
			}
			break;
		case SDL_WINDOWEVENT:
			if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
				// 更新投影矩陣，根據新的窗口尺寸
				int width, height;
				SDL_GetWindowSize(window, &width, &height);
				UpdateProjectionMatrix(width, height);
			}
			
			break;
		case SDL_MOUSEBUTTONDOWN:
			// 当点击鼠标时，重新进入相对模式
			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_SetRelativeMouseMode(SDL_TRUE);
				SDL_ShowCursor(SDL_ENABLE);
			}
			break;
		case SDL_JOYDEVICEADDED:
			// 检测到新手柄连接
			if (gameController == nullptr && SDL_NumJoysticks() > 0 && SDL_IsGameController(event.jdevice.which)) {
				gameController = SDL_GameControllerOpen(event.jdevice.which);
				if (gameController) {
					std::cout << "GameController connected!" << std::endl;
				}
			}
			break;
		case SDL_JOYBUTTONDOWN:
			g_isUsingKeyboard = false;
			break;

		case SDL_JOYDEVICEREMOVED:
			// 手柄被移除
			if (gameController) {
				SDL_GameControllerClose(gameController);
				gameController = nullptr;
				std::cout << "GameController disconnected!" << std::endl;
			}
			break;
		default:
			break;
		}
	}

	// keyboard
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	
	for (const auto& entry : gKeyboardMap) {
		if (currentKeyStates[entry.first]) {
			gButtons |= entry.second; // 按下时设置按钮状态
		}
		else {
			gButtons &= ~entry.second; // 释放时清除按钮状态
		}
	}

	//mouse buttons
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
		gButtons |= gMouseMap[SDL_BUTTON_LEFT];
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		gButtons |= gMouseMap[SDL_BUTTON_RIGHT];
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE))
		gButtons |= gMouseMap[SDL_BUTTON_MIDDLE];

	// gamepad
	
	if (gameController != nullptr) {
		for (const auto& entry : gGamepadMap) {
			int buttonIndex = entry.first;
			int buttonState = SDL_GameControllerGetButton(gameController, static_cast<SDL_GameControllerButton>(buttonIndex));

			if (buttonState == SDL_PRESSED) {
				gButtons |= entry.second; // 按下时设置按钮状态
			}
		}
		// 获取摇杆的输入值
		analogX = SDL_GameControllerGetAxis(gameController, SDL_CONTROLLER_AXIS_LEFTX) / 32767.0f;
		analogY = SDL_GameControllerGetAxis(gameController, SDL_CONTROLLER_AXIS_LEFTY) / 32767.0f;
	}
}


BOOL JGEGetKeyState(int key)
{
	return (g_keys[key]);
}

BOOL isUsingKeyboard()
{
	return g_isUsingKeyboard ? TRUE : FALSE;
}


bool JGEGetButtonState(u32 button)
{
	return (gButtons&button)==button;
}


bool JGEGetButtonClick(u32 button)
{
	return (gButtons&button)==button && (gOldButtons&button)!=button;
}

u8 JGEGetAnalogX()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_D]) return 0xff;
	if (currentKeyStates[SDL_SCANCODE_A]) return 0;
	if (analogX > -0.01 && analogX < 0.01) return 0x80;
	return (analogX + 1) * 127.0; // convert from [-1,1] range to [0,255] range
}

u8 JGEGetAnalogY()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_W]) return 0;
	if (currentKeyStates[SDL_SCANCODE_S]) return 0xff;
	if (analogY > -0.01 && analogY < 0.01) return 0x80;
	return (analogY + 1) * 127.0; // convert from [-1,1] range to [0,255] range
}

void JGEGetMouseMovement(int* x, int* y)
{
	SDL_GetRelativeMouseState(x, y);
}

void UpdateProjectionMatrix(int width, int height) {

	float screenAspectRatio = static_cast<float>(SCREEN_WIDTH) / SCREEN_HEIGHT;
	float currentAspectRatio = static_cast<float>(width) / height;

	int adjustedWidth = width;
	int adjustedHeight = height;

	int xOffset = 0;
	int yOffset = 0;

	if (currentAspectRatio == screenAspectRatio) {
		// 屏幕比例与理想比例相同，直接使用传入的宽高
		adjustedWidth = width;
		adjustedHeight = height;
	}
	else {
		// 屏幕比例不同，调整到最接近的符合比例的尺寸，并计算偏移
		if (currentAspectRatio > screenAspectRatio) {
			// 屏幕较宽，基于高度调整宽度，并水平居中
			adjustedWidth = static_cast<int>(height * screenAspectRatio);
			xOffset = (width - adjustedWidth) / 2;
		}
		else {
			// 屏幕较窄，基于宽度调整高度，并垂直居中
			adjustedHeight = static_cast<int>(width / screenAspectRatio);
			yOffset = (height - adjustedHeight) / 2;
		}
	}

	//glViewport(0, 0, (GLsizei)width, (GLsizei)height);	// Reset The Current Viewport
	glViewport(xOffset, yOffset, adjustedWidth, adjustedHeight);
	glMatrixMode(GL_PROJECTION);										// Select The Projection Matrix
	glLoadIdentity();													// Reset The Projection Matrix

	gluOrtho2D(0.0f, SCREEN_WIDTH_F - 1.0f, 0.0f, SCREEN_HEIGHT_F - 1.0f);
	//glOrtho(0.0f, (GLfloat)SCREEN_WIDTH_F, (GLfloat)SCREEN_HEIGHT_F, 0.0f, -1.0f, 1.0f);

	glMatrixMode(GL_MODELVIEW);										// Select The Modelview Matrix
	glLoadIdentity();													// Reset The Modelview Matrix

	glDisable(GL_DEPTH_TEST);
}

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(75.0f,(GLfloat)width/(GLfloat)height,0.5f,1000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix

}

int InitGL(GLvoid)												// All Setup For OpenGL Goes Here
{
	//glUseProgram(shaderProgram);
	glClearColor (0.0f, 0.0f, 0.0f, 0.0f);						// Black Background
	glClearDepth (1.0f);										// Depth Buffer Setup
	glDepthFunc (GL_LEQUAL);									// The Type Of Depth Testing (Less Or Equal)
	glEnable (GL_DEPTH_TEST);									// Enable Depth Testing
	glShadeModel (GL_SMOOTH);									// Select Smooth Shading
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);			// Set Perspective Calculations To Most Accurate
	
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);						// Set Line Antialiasing
	//glEnable(GL_LINE_SMOOTH);									// Enable it!
	
	glEnable(GL_CULL_FACE);										// do not calculate inside of poly's
	glFrontFace(GL_CCW);										// counter clock-wise polygons are out
	
	glEnable(GL_TEXTURE_2D);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_SCISSOR_TEST);									// Enable Clipping
	//glScissor(20, 20, 320, 240);
	//glGenerateMipmap(GL_TEXTURE_2D);



	return TRUE;												// Initialization Went OK
}


int InitGame(GLvoid)
{
	g_engine = JGE::GetInstance();

	//SetEnglishKeyboardLayout();

	SDL_StartTextInput();
	if (SDL_NumJoysticks() > 0 && SDL_IsGameController(0)) {
		gameController = SDL_GameControllerOpen(0);
		if (gameController) {
			std::cout << "GameController initialized!" << std::endl;
		}
	}
	SDL_SetRelativeMouseMode(SDL_TRUE);

	
	//JGameLauncher *launcher = new JGameLauncher();
	g_app = g_launcher->GetGameApp();
	g_app->Create();
	g_engine->SetApp(g_app);
	
	//JRenderer::GetInstance()->Enable2D();

	UpdateProjectionMatrix(ScreenW, ScreenH);
	
	lastTickCount = GetTickCount();

	ZeroMemory (g_keys, 256);

	//delete launcher;

	return TRUE;
}


void DestroyGame(GLvoid)
{
//	JParticleSystem::Destroy();
//	JMotionSystem::Destroy();
	
	g_engine->SetApp(NULL);
	if (g_app)
	{
		g_app->Destroy();
		delete g_app;
		g_app = NULL;
 	}

	JGE::Destroy();

 	g_engine = NULL;

}


int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{

// 	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear Screen And Depth Buffer
// 	glLoadIdentity ();											// Reset The Modelview Matrix
	
	//if (g_app)
	//	g_app->Render();
	g_engine->Render();
	
//	glFlush ();

	return TRUE;										// Everything Went OK
}

void Update(int dt)
{
	//JGEControl();
	process_input();
	
	g_engine->SetDelta(dt);
	
	//if (g_app)
	//	g_app->Update();

	g_engine->Update();

	g_engine->mClicked = false;
	
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	DestroyGame();

	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL",hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/
 


BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	/*Uint32 windowFlags = SDL_WINDOW_OPENGL;
	if (fullscreenflag) {
		windowFlags |= SDL_WINDOW_FULLSCREEN;
	}*/

	// 初始化 SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0) {
		MessageBox(NULL, "Unable to initialize SDL.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;
	}

	// 创建 SDL 窗口

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenW, ScreenH, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (!window) {
		SDL_Quit();
		MessageBox(NULL, "Window creation failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;
	}

	// 创建 OpenGL 上下文
	glContext = SDL_GL_CreateContext(window);
	if (!glContext) {
		SDL_DestroyWindow(window);
		SDL_Quit();
		MessageBox(NULL, "Failed to create OpenGL context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;
	}

	// 启用双缓冲
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Disable Cursor
	//SDL_ShowCursor(SDL_DISABLE);

	// 设置 OpenGL 视口
	//glViewport(0, 0, width, height);

	// 设置投影矩阵
	//UpdateProjectionMatrix(width, height);  // 确保使用新的函数更新投影矩阵

	// 初始化 OpenGL 设置
	if (!InitGL()) {
		SDL_GL_DeleteContext(glContext);
		SDL_DestroyWindow(window);
		SDL_Quit();
		MessageBox(NULL, "OpenGL Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;
	}

	if (!InitGame()) {
		SDL_GL_DeleteContext(glContext);
		SDL_DestroyWindow(window);
		SDL_Quit();
		MessageBox(NULL, "Game Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;
	}

	return TRUE;  // 成功
}


LRESULT CALLBACK WndProc(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
		case WM_ACTIVATE:							// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))					// Check Minimization State
			{
				active=TRUE;						// Program Is Active
				if (g_engine != NULL)
					g_engine->Resume();
			}
			else
			{
				active=FALSE;						// Program Is No Longer Active
				if (g_engine != NULL)
					g_engine->Pause();
			}

			return 0;								// Return To The Message Loop
		}

		case WM_SYSCOMMAND:							// Intercept System Commands
		{
			switch (wParam)							// Check System Calls
			{
				case SC_SCREENSAVE:					// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
				return 0;							// Prevent From Happening
			}
			break;									// Exit
		}

		case WM_CLOSE:								// Did We Receive A Close Message?
		{
			PostQuitMessage(0);						// Send A Quit Message
			return 0;								// Jump Back
		}

		case WM_KEYDOWN:												// Update Keyboard Buffers For Keys Pressed
			if ((wParam >= 0) && (wParam <= 255))						// Is Key (wParam) In A Valid Range?
			{
				g_keys[wParam] = TRUE;					// Set The Selected Key (wParam) To True
				return 0;												// Return
			}
			break;															// Break
			
		case WM_KEYUP:													// Update Keyboard Buffers For Keys Released
			if ((wParam >= 0) && (wParam <= 255))						// Is Key (wParam) In A Valid Range?
			{
				g_keys[wParam] = FALSE;					// Set The Selected Key (wParam) To False
				return 0;												// Return
			}
		break;	

		case WM_LBUTTONDOWN:
		{
			return 0;
		}
		
		case WM_LBUTTONUP:
		{
			return 0;
		}
		
		case WM_RBUTTONDOWN:
		{
			return 0;
		}

		case WM_RBUTTONUP:
		{
			return 0;
		}

		case WM_MOUSEMOVE:
		{
//			Mint2D::SetMousePosition(LOWORD(lParam), HIWORD(lParam)); 
			return 0;
		}

		case WM_SIZE:								// Resize The OpenGL Window
		{
			//ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			//return 0;								// Jump Back
		}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

int WINAPI WinMain(	HINSTANCE	hInstance,			// Instance
					HINSTANCE	hPrevInstance,		// Previous Instance
					LPSTR		lpCmdLine,			// Command Line Parameters
					int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	//BOOL	done=FALSE;								// Bool Variable To Exit Loop
	
	DWORD	tickCount;
	int		dt;

	// Ask The User Which Screen Mode They Prefer
//	if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
//	{
//		fullscreen=FALSE;							// Windowed Mode
//	}

	//RedirectIOToConsole();
	

	g_launcher = new JGameLauncher();

	u32 flags = g_launcher->GetInitFlags();

	if ((flags&JINIT_FLAG_ENABLE3D)!=0)
		JRenderer::Set3DFlag(true);

	SDL_StartTextInput();

	// Create Our OpenGL Window


	if (!CreateGLWindow(g_launcher->GetName(),ScreenW, ScreenH,32,!fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}
	
	
	//if (shaderProgram == 0) {
	//	return -1;  // 如果着色器初始化失败，退出程序
	//}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (g_engine->IsDone())
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					tickCount = SDL_GetTicks();					// Get The Tick Count
					dt = (tickCount - lastTickCount);
					lastTickCount = tickCount;
					Update(dt);									// Update frame

					//Mint2D::BackupKeys();

					DrawGLScene();					// Draw The Scene
					//SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
					SDL_GL_SwapWindow(window);
				}
			}
		}

	}

//			if (keys[VK_F1])						// Is F1 Being Pressed?
//			{
//				keys[VK_F1]=FALSE;					// If So Make Key FALSE
//				KillGLWindow();						// Kill Our Current Window
//				fullscreen=!fullscreen;				// Toggle Fullscreen / Windowed Mode
//				// Recreate Our OpenGL Window
//				if (!CreateGLWindow("NeHe's OpenGL Framework",640,480,16,fullscreen))
//				{
//					return 0;						// Quit If Window Was Not Created
//				}
//			}
	//	}
	//}
	
	
	if (g_launcher)
		delete g_launcher;

	if (gameController) {
		SDL_GameControllerClose(gameController);
	}
	// Shutdown
	//KillGLWindow();									// Kill The Window
	// 清理资源
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (msg.wParam);							// Exit The Program
}




void RedirectIOToConsole(){
	static const WORD MAX_CONSOLE_LINES = 500;
 int hConHandle;

long lStdHandle;
    CONSOLE_SCREEN_BUFFER_INFO coninfo;
    FILE                       *fp;

    // allocate a console for this app
    AllocConsole();

    // set the screen buffer to be big enough to let us scroll text
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), 
                               &coninfo);
    coninfo.dwSize.Y = MAX_CONSOLE_LINES;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), 
                               coninfo.dwSize);

    //// redirect unbuffered STDOUT to the console
    //lStdHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);
    //hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
    //fp = _fdopen( hConHandle, "w" );
    //*stdout = *fp;
    //setvbuf( stdout, NULL, _IONBF, 0 );

    //// redirect unbuffered STDIN to the console
    //lStdHandle = (long)GetStdHandle(STD_INPUT_HANDLE);
    //hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
    //fp = _fdopen( hConHandle, "r" );
    //*stdin = *fp;
    //setvbuf( stdin, NULL, _IONBF, 0 );

    //// redirect unbuffered STDERR to the console
    //lStdHandle = (long)GetStdHandle(STD_ERROR_HANDLE);
    //hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
    //fp = _fdopen( hConHandle, "w" );
    //*stderr = *fp;
    //setvbuf( stderr, NULL, _IONBF, 0 );
    //
    //// make cout, wcout, cin, wcin, wcerr, cerr, wclog and clog 
    //// point to console as well
    //ios::sync_with_stdio();
}


