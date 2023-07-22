#!/bin/bash
killall volumeicon
dwmblocks &
xrandr -s 1360x768 &
feh --bg-fill --randomize ~/.wallpapers &
picom &
lxsession &
volumeicon &
ibus start
