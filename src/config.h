// Primary config file. Everything here can be tweaked and the program shouldn't outright *crash*. Actual performance may vary.

#ifndef CONFIG_GUARD

#define CONFIG_GUARD

#define STAR	'*'	// Character for representing each star

#define X_MIN	-10	// Boundaries of rectangular prism in which the stars can generate
#define Y_MIN	-10
#define Z_MIN	-5
#define X_MAX	10
#define Y_MAX	10
#define Z_MAX	5


#define INIT_X	0	// Starting position of the camera
#define INIT_Y	0
#define INIT_Z	0

#define C_FWD	'w'	// Keybinds
#define C_BCK	's'
#define C_LFT	'a'
#define C_RIG	'd'
#define C_UP	'z'
#define C_DWN	'x'
#define C_QUIT	'q'

#define SPD_X	0.1	// Speed in the 3 axes
#define SPD_Y	0.05
#define SPD_Z	0.05

// Uncomment the line below to enable debug mode
//#define DEBUG

// Uncomment the line below to show coordinates in the top-left corner
//#define SHOW_INFO

#endif
