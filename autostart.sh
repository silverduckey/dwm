#!/bin/sh
killall picom
killall lxsession
killall ibus-daemon
killall volumeicon
killall nm-applet
killall slstatus
. $HOME/.screenlayout/screenlayout.sh
feh --bg-fill --randomize $HOME/.wallpapers &
picom -b &
lxsession &
ibus-daemon -d &
volumeicon &
nm-applet &
slstatus &
