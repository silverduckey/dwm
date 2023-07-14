#!/bin/bash
killall volumeicon
xrandr -s 1360x768 &
feh --bg-fill --randomize ~/.wallpapers &
picom &
lxsession &
dwmblocks &
volumeicon &
ibus start &
