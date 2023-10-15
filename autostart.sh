#!/bin/sh
killall picom
killall lxsession
killall ibus-daemon
source $HOME/.screenlayout/screenlayout.sh
slstatus &
feh --bg-fill --randomize ~/.wallpapers &
picom &
lxsession &
ibus start
