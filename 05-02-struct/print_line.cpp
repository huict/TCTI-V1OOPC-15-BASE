// This file implements the print_line function in an ugly way.
// don't use it as an example for your own code.

#include "windows.h"

HINSTANCE hInstance;
WNDCLASSEX wc; /* A properties struct of our window */
HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
MSG Msg; /* A temporary location for all messages */
HDC hdc;

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		/* trap the WM_CLOSE (clicking X) message, and actually tell the window to close */
		case WM_CLOSE: {
			DestroyWindow(hwnd);
			break;
		}
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

#define SCALE 2

// derived by trial-and-error :(
#define X_MARGIN 20
#define Y_MARGIN 42
	
void create_screen( int xsize, int ysize ){

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		  = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WndProc; /* This is where we will send messages to */
	wc.hInstance	  = hInstance;
	wc.hCursor		  = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		for(;;);
	}

	hwnd = CreateWindowEx(
	    WS_EX_CLIENTEDGE,
		"WindowClass",
		"LCD Window",
		WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		xsize + X_MARGIN, /* width */
		ysize + Y_MARGIN, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		for(;;);
	}
	
   hdc = GetDC(hwnd);

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produre unreasonably CPU usage
	*/
	if(0)while(GetMessage(&Msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&Msg); /* Translate keycodes to chars if present */
		DispatchMessage(&Msg); /* Send it to WndProc */
	}
	// return Msg.wParam;
}

void winloop(){
   for(;;){ 
   MSG Msg; 
	   BOOL r = PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE );
      if( r == -1 ){
         // exit( 0 );
      } else if( r > 0) {
		   TranslateMessage(&Msg); /* Translate key codes to chars if present */
		   DispatchMessage(&Msg); /* Send it to WndProc */
	   }   
   }   
}

void print_pixel( int x, int y ){
   static bool init_done = false;
   if( ! init_done ){
      init_done = true;
      create_screen( SCALE * 128, SCALE * 64 );\
      atexit ( winloop );
   }
   
   for( int dx = 0; dx < SCALE; dx++ ){
         for( int dy = 0; dy < SCALE; dy++ ){
            SetPixel( hdc, SCALE * x + dx, SCALE * y + dy, RGB( 0x00, 0x00, 0x00 ));
         }
   }   
}


// avoid these because <algorithm> imports iostream stuff
template <class T> void swap( T& a, T& b ){
  T c(a); a=b; b=c;
}

struct line {
   int start_x;
   int start_y; 
   int end_x;
   int end_y;
};

void print_line( line arg_line ){
    
   const int width = 1; 
              
   // http://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
   // http://homepages.enterprise.net/murphy/thickline/index.html
   
   // int i0 = 0; int i1 = 1;
   int i0 = - ( width / 2 ); 
   // int i1 = 1;
   int i1 = width + i0;
   // i1 = width;
   
   int x0 = arg_line.start_x;
   int y0 = arg_line.start_y;
   int x1 = arg_line.end_x;
   int y1 = arg_line.end_y;
   int Dx = x1 - x0; 
   int Dy = y1 - y0;
   int steep = (abs(Dy) >= abs(Dx));
   int ox = 0, oy = 1;
   if( steep ){
      swap(x0, y0);
      swap(x1, y1);
      // recompute Dx, Dy after swap
      Dx = x1 - x0;
      Dy = y1 - y0;
      swap( ox, oy );
   }
   int xstep = 1;
   if( Dx < 0 ){
      xstep = -1;
      Dx = -Dx;
   }
   int ystep = 1;
   if( Dy < 0 ){
      ystep = -1;    
      Dy = -Dy; 
   }
   int TwoDy = 2*Dy; 
   int TwoDyTwoDx = TwoDy - 2*Dx; // 2*Dy - 2*Dx
   int E = TwoDy - Dx; //2*Dy - Dx
   int y = y0;
   int xDraw, yDraw;  
   for( int x = x0; x != x1; x += xstep ){    
      if (steep) {     
         xDraw = y;
         yDraw = x;
      } else {     
         xDraw = x;
         yDraw = y;
      }
      for( int i = i0; i < i1; i++ ){
         print_pixel( xDraw + ox * i, yDraw + oy * i );
      }   
      // trace << xDraw << " " << yDraw;
      if( E > 0 ){
         E += TwoDyTwoDx; //E += 2*Dy - 2*Dx;
         y = y + ystep;
      } else {
         E += TwoDy; //E += 2*Dy;
      }
   }
}

void wait( long long int d );

long long int now(){
   return GetTickCount() * 1000ULL;
}

void wait( long long int d ){
   long long int end = now() + d;
   while( now() < end ){
	   MSG Msg; 
	   BOOL r = PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE );
      if( r == -1 ){
         // exit( 0 );
      } else if( r > 0) {
		   TranslateMessage(&Msg); /* Translate key codes to chars if present */
		   DispatchMessage(&Msg); /* Send it to WndProc */
	   }   
   }
}