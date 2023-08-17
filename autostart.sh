#!/bin/bash
killall volumeicon
slstatus &
xrandr -s 1360x768 &
feh --bg-fill --randomize ~/.wallpapers &
picom &
lxsession &
volumeicon &
ibus start
