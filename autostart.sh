#!/bin/bash
killall screenkey
killall volumeicon
killall ibus-daemon
xrandr -s 1360x768 &
feh --bg-fill --randomize ~/.wallpapers &
picom &
lxsession &
dwmblocks &
volumeicon &
ibus start &
screenkey --start-disabled
