#include <X11/X.h>

static const unsigned int borderpx = 1;
static const unsigned int snap = 32;

static const unsigned int gappih = 2;
static const unsigned int gappiv = 2;
static const unsigned int gappoh = 2;
static const unsigned int gappov = 2;
static int smartgaps = 1;

static const unsigned int systraypinning = 0;
static const unsigned int systrayonleft = 0;
static const unsigned int systrayspacing = 2;
static const int systraypinningfailfirst = 1;
static const int showsystray = 1;

static const int showbar = 1;
static const int topbar = 1;
static const char *fonts[] = {"Ubuntu Nerd Font:pixelsize=14"};
static const char col_gray1[] = "#3b4252";
static const char col_gray2[] = "#3b4252";
static const char col_gray3[] = "#d8dee9";
static const char col_gray4[] = "#88c0d0";
static const char col_gray5[] = "#4c566a";
static const char *colors[][3] = {
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray4, col_gray5, col_gray5},
};

static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

static Rule rules[] = {
    /* class      instance    title       tags mask     isfloating   monitor */
    {NULL, NULL, NULL, 0, False, -1},
};

static const float mfact = 0.50;
static const int nmaster = 1;
static const int resizehints = 1;
static const int attachdirection = 2;
static const int lockfullscreen = 1;
#define FORCE_VSPLIT 1
#include "vanitygaps.c"

static const Layout layouts[] = {
    {"[]=", tile},
    {"[M]", monocle},
    {"HHH", grid},
    {"><>", NULL},
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

#define TERMINAL "st"
#define EDITOR "nvim"

static char dmenumon[2] = "0";
static const char *termcmd[] = {TERMINAL, NULL};
static const char *dmenucmd[] = {"dmenu_run", NULL};
static const char *editorcmd[] = {TERMINAL, "-e", EDITOR, NULL};
static const char *browsercmd[] = {"brave", NULL};
static const Key keys[] = {
    {MODKEY | ShiftMask, XK_Return, spawn, {.v = dmenucmd}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_b, spawn, {.v = browsercmd}},
    {MODKEY, XK_v, spawn, {.v = editorcmd}},
    {MODKEY, XK_q, spawn, SHCMD("$HOME/.dwm/scripts/powermenu")},
    {MODKEY | ShiftMask, XK_b, togglebar, {0}},
    {MODKEY | ShiftMask, XK_j, rotatestack, {.i = +1}},
    {MODKEY | ShiftMask, XK_k, rotatestack, {.i = -1}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_h, setcfact, {.f = +0.25}},
    {MODKEY | ShiftMask, XK_l, setcfact, {.f = -0.25}},
    {MODKEY | ShiftMask, XK_o, setcfact, {.f = 0.00}},
    {MODKEY | ControlMask, XK_Return, zoom, {0}},
    {MODKEY | Mod1Mask, XK_u, incrgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_u, incrgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_i, incrigaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_i, incrigaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_o, incrogaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_o, incrogaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_6, incrihgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_6, incrihgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_7, incrivgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_7, incrivgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_8, incrohgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_8, incrohgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_9, incrovgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_9, incrovgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_0, togglegaps, {0}},
    {MODKEY | Mod1Mask | ShiftMask, XK_0, defaultgaps, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY | ShiftMask, XK_c, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_g, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[3]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_q, quit, {0}},
    {MODKEY | ControlMask, XK_r, quit, {1}},
};

static const Button buttons[] = {
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
