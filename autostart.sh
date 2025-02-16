#!/bin/sh
killall picom
killall lxsession
killall ibus-daemon
killall nm-applet
killall volumeicon
killall slstatus
. $HOME/.screenlayout/screenlayout.sh
feh --bg-fill --randomize $HOME/.wallpapers &
picom -b &
lxsession &
ibus-daemon -d &
nm-applet &
volumeicon &
slstatus &
