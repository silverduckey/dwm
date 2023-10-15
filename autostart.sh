#!/bin/sh
killall picom
killall lxsession
killall ibus-daemon
. $HOME/.screenlayout/screenlayout.sh
slstatus &
feh --bg-fill --randomize ~/.wallpapers &
picom &
lxsession &
ibus start
