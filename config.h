// vim: set foldmethod=marker:

#include <X11/XF86keysym.h>

// appearance {{{

static const unsigned int borderpx  = 1;  // border pixel of windows
static const unsigned int snap      = 32; // snap pixel
static const int showbar            = 1;  // 0 means no bar
static const int topbar             = 1;  // 0 means bottom bar

static const char *fonts[]          = { "FiraMono Nerd Font:style=Regular:size=10" };

static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const float mfact     = 0.5; // factor of master area size [0.05..0.95]
static const int nmaster     = 1;    // number of clients in master area
static const int resizehints = 0;    // 1 means respect size hints in tiled resizals

static const Layout layouts[] = {
	// symbol, arrange function
	{ "[]="  , tile    }, // first entry is default
	{ "[M]"  , monocle },
	{ "><>"  , NULL    }, // no layout function means floating behavior
};

// }}}

// colors {{{

static const char col_foreground[]   = "#ebdbb2";
static const char col_background[]   = "#1d2021";
static const char col_background2[]  = "#504945";
static const char col_cursorColor[]  = "#ebdbb2";
static const char col_color0[]       = "#282828";
static const char col_color8[]       = "#928374";
static const char col_color1[]       = "#cc241d";
static const char col_color9[]       = "#fb4934";
static const char col_color2[]       = "#98971a";
static const char col_color10[]      = "#b8bb26";
static const char col_color3[]       = "#d79921";
static const char col_color11[]      = "#fabd2f";
static const char col_color4[]       = "#458588";
static const char col_color12[]      = "#83a598";
static const char col_color5[]       = "#b16286";
static const char col_color13[]      = "#d3869b";
static const char col_color6[]       = "#689d6a";
static const char col_color14[]      = "#8ec07c";
static const char col_color7[]       = "#a89984";
static const char col_color15[]      = "#ebdbb2";

static const char *colors[][3] = {
	// [name]    = { fg            , bg            , border          }
	[SchemeNorm] = { col_foreground, col_background, col_background2 },
	[SchemeSel]  = { col_background, col_color7    , col_color7      },
};

// }}}

// rules {{{

static const Rule rules[] = {

	// { class              , instance              , title                 , tags mask, iscentered, isfloating, monitor }
	{ "st-256color"         , "fzfmenu"             , NULL                  , 0        , 1         , 1         , -1      },
	{ "st-256color"         , "scratchpad"          , NULL                  , 0        , 1         , 1         , -1      },
	{ "st-256color"         , "calculator"          , NULL                  , 0        , 1         , 1         , -1      },
	{ "Pavucontrol"         , "pavucontrol"         , "Volume Control"      , 0        , 1         , 1         , -1      },
	{ "SimpleScreenRecorder", "SimpleScreenRecorder", "simplescreenrecorder", 0        , 1         , 1         , -1      },
	{ "Wicd-client.py"      , "wicd-client.py"      , "Wicd Network Manager", 0        , 1         , 1         , -1      },

};

// }}}

// bindings {{{

#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY, view,       {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY, tag,        {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY, toggleview, {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY, toggletag,  {.ui = 1 << TAG} },

static Key keys[] = {

	// alt+number goes to tag
	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3)
	TAGKEYS(XK_5, 4)
	TAGKEYS(XK_6, 5)
	TAGKEYS(XK_7, 6)
	TAGKEYS(XK_8, 7)
	TAGKEYS(XK_9, 8)

	// {modifier       , key      , function     , {argument}}
	{ MODKEY          , XK_j     , focusstack   , { .i = +1 }     },
	{ MODKEY          , XK_k     , focusstack   , { .i = -1 }     },
	{ MODKEY          , XK_w     , killclient   , { 0 }           },
	{ MODKEY          , XK_h     , setmfact     , { .f = -0.005 } },
	{ MODKEY          , XK_l     , setmfact     , { .f = +0.005 } },
	// { MODKEY          , XK_f     , togglefullscr, { 0 }           },
	{ MODKEY          , XK_Return, zoom         , { 0 }           },
	{ MODKEY          , XK_comma , focusmon     , { .i = -1 }     },
	{ MODKEY          , XK_period, focusmon     , { .i = +1 }     },
	{ MODKEY|ShiftMask, XK_comma , tagmon       , { .i = -1 }     },
	{ MODKEY|ShiftMask, XK_period, tagmon       , { .i = +1 }     },

	// { MODKEY, XK_minus, setgaps, { .i = +5 } },
	// { MODKEY, XK_equal, setgaps, { .i = -5 } },

	{ MODKEY, XK_t, setlayout, {.v = &layouts[0]} },  /* tile */
	{ MODKEY, XK_m, setlayout, {.v = &layouts[1]} },  /* monocle */
};

static Button buttons[] = {

	// { clickevent, mask  , button , function      , {argument} }
	{ ClkClientWin , MODKEY, Button1, movemouse     , {0       } },
	{ ClkClientWin , MODKEY, Button2, togglefloating, {0       } },
	{ ClkClientWin , MODKEY, Button3, resizemouse   , {0       } },

};

// }}}

