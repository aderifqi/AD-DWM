/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const Gap default_gap        = {.isgap = 1, .realgap = 10, .gappx = 10};
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:style=Reguler:size=9.5" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:style=Medium:size=10";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };

// japang numirals
// "〇" = 0
static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class													instance							title       tags mask   iscentered     isfloating   monitor */
	{ "Gimp",														NULL,								NULL,              0,				0,							1,            -1 },
	{ "PacketTracer7",			 "PacketTracer7",  	            NULL,         1 << 3,				1,							1,            -1 },
	{ "firefox",												NULL,								NULL,         1 << 1,				0,							0,            -1 },
	{ "Firefox Developer Edition",	 		NULL,								NULL,         1 << 1,				0,							0,            -1 },
	{ "xdman",													NULL,								NULL,					1	<< 1,				0,							1,		 		  	-1 },	
	{ "Eog",														NULL,								NULL,							 0,				0,							1,            -1 },
	{ "File-roller",										NULL,								NULL,							 0,				0,							1,						-1 },
	{ "Evince",													NULL,								NULL,							 0,				0,							1,						-1 },
	{ "Nm-connection-editor",						NULL,								NULL,							 0,				0,							1,						-1 },
	{ NULL,										 "libreoffice",	        			NULL,					1	<< 2,				0,							0,						-1 },
	{ NULL,										          NULL,	            "WPS ",					1	<< 2,				0,							0,						-1 },
	{ "TelegramDesktop",								NULL,								NULL,					1	<< 3,				0,							1,						-1 },
	{ "Soffice",									 "soffice",								NULL,				       0,				0,							1,						 0 },
	{ "Soffice",									 "soffice", 	  "Presenting: ",				       0,				0,							1,						 1 },
	{ NULL,						 							    NULL,		  		 "ncmpcpp",				       0,				1,							1,					  -1 },
	{ NULL,                  					  NULL,	      		"BpyTOP",		      1 << 7,				1,							1,					  -1 },
	{ "Lxappearance",					"lxappearance",		  		      NULL,				       0,				1,							1,					  -1 },
	{ NULL,			   											NULL,		    	"calcurse",							 0,				1,							1,					  -1 },
	{ "Kamus",										   "kamus",		       		  NULL,							 0,				1,							1,					  -1 },
	{ "Colorgrab",						   "colorgrab",   		 "ColorGrab",							 0,				1,							1,					  -1 },

	{ "St",															"st", 						 "st~",							 0,				1,							1,					  -1 },

	{ "Colorgrab",						   "colorgrab",   		 "ColorGrab",							 0,				1,							1,					  -1 },
	{ "Lxappearance",					"lxappearance",		  		      NULL,				       0,				1,							1,					  -1 },
	{ "TelegramDesktop",								NULL,								NULL,					1	<< 3,				0,							1,						-1 },
	{ "FreeMind",									"FreeMind",   					 	NULL,							 0,				0,							1,					  -1 },
	{ "Thunar",											"Thunar",   					 	NULL,							 0,				0,							1,					  -1 },
	{ "Mail",									 "Thunderbird",     				 	NULL,					1 << 7,				0,							1,					  -1 },
	{ "Keepnote",							  	"keepnote",   					 	NULL,							 0,				0,							1,					  -1 },
	{ "KeePass2",							  	"keepass2",   					 	NULL,					1 << 7,				0,							1,					  -1 },
	{ "Connman-gtk",					 "connman-gtk",   					 	NULL,							 0,				1,							1,					  -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, NULL };
static const char *termcmd[]  = { "st", NULL };
#include "movestack.c"
#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = GAP_TOGGLE} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },

		// Costum
	{ MODKEY,                       XK_F7,       xrdb,           {.v = NULL } },
	{ MODKEY,                        XK_e,      spawn,          SHCMD("/usr/bin/clipmenu")},
	{ MODKEY|ShiftMask,              XK_e,      spawn,          SHCMD("clipdel -d '.' ")},
	
	{ MODKEY,                    XK_Print,      spawn,          SHCMD("/usr/bin/flameshot gui") },
	{ MODKEY|ShiftMask,          XK_Print,      spawn,          SHCMD("/home/ad/.local/bin/capture") },

	{ MODKEY|ShiftMask,              XK_w,      spawn,          SHCMD("/usr/bin/networkmanager_dmenu") },
	{ 0,                         XK_Print,      spawn,          SHCMD("scrot %Y.%m.%d.%T-$wx$h.png --quality 100 -e 'mv $f /home/ad/Pictures/shots/' && dunstify  -r 90105 'Print screen'")},

	{ MODKEY,                       XK_F8,      spawn,          SHCMD("/usr/bin/systemctl suspend") },
	{ MODKEY,                        XK_a,      spawn,        	SHCMD("j4-dmenu-desktop --dmenu='rofi  -dmenu -i -p \"Run\" -lines 10 -width 600'" )},


	{ MODKEY|ShiftMask,              XK_s,      spawn,          SHCMD("st -t 'st~' -g 75x20") },

	{ MODKEY|ShiftMask,              XK_r,      spawn,          SHCMD("/home/ad/.local/bin/screencast" )},
	{ MODKEY|ControlMask,            XK_q,      spawn,          SHCMD("/home/ad/.local/bin/powermenu" )},
	{ MODKEY|ShiftMask,              XK_t,    	spawn,          SHCMD("/home/ad/.local/bin/tunnel_rofi" )},

	// ---------  xf86 key  ------------

	// custom key for general keyboard 
	{ MODKEY|ShiftMask,            XK_F6,      		spawn,          SHCMD("brightnessctl s +10 ; pkill -RTMIN+18 ${STATUSBAR:-dwmblocks}" )},
	{ MODKEY|ShiftMask,            XK_F5,       	spawn,          SHCMD("brightnessctl s 10- ; pkill -RTMIN+18 ${STATUSBAR:-dwmblocks}" )},
	{ MODKEY|ShiftMask, 					 XK_F10,   			spawn,					SHCMD("pamixer -t; pkill -RTMIN+21 ${STATUSBAR:-dwmblocks}") },
	{ MODKEY|ShiftMask,            XK_F12,      	spawn,          SHCMD("/home/ad/.local/bin/volKey +" )},
	{ MODKEY|ShiftMask,            XK_F11,      	spawn,          SHCMD("/home/ad/.local/bin/volKey -" )},



	// xf86 
	{ 0,            XF86XK_MonBrightnessUp,      		spawn,          SHCMD("brightnessctl s +10 ; pkill -RTMIN+18 ${STATUSBAR:-dwmblocks}" )},
	{ 0,            XF86XK_MonBrightnessDown,      	spawn,          SHCMD("brightnessctl s 10- ; pkill -RTMIN+18 ${STATUSBAR:-dwmblocks}" )},
	{ 0, 						XF86XK_AudioMute, 			  			spawn,					SHCMD("pamixer -t; pkill -RTMIN+21 ${STATUSBAR:-dwmblocks}") },
	{ 0,            XF86XK_AudioRaiseVolume,       	spawn,          SHCMD("/home/ad/.local/bin/volKey +" )},
	{ 0,            XF86XK_AudioLowerVolume,       	spawn,          SHCMD("/home/ad/.local/bin/volKey -" )},

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

