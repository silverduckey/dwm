#!/bin/bash
killall volumeicon
slstatus &
$HOME/.screenlayout/screenlayout.sh
feh --bg-fill --randomize ~/.wallpapers &
picom &
lxsession &
volumeicon &
ibus start
