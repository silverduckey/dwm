#!/bin/bash
killall picom
killall lxsession
killall volumeicon
killall ibus-daemon
source $HOME/.screenlayout/screenlayout.sh
slstatus &
feh --bg-fill --randomize ~/.wallpapers &
picom &
lxsession &
volumeicon &
ibus start
