#!/bin/sh
killall picom
killall lxsession
killall ibus-daemon
killall slstatus
. $HOME/.screenlayout/screenlayout.sh
slstatus &
feh --bg-fill --randomize $HOME/.wallpapers &
picom &
lxsession &
ibus start
