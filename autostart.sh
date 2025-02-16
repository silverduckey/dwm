#!/bin/sh
killall picom
killall lxsession
killall volumeicon
killall ibus-daemon
killall nm-applet
killall slstatus
. $HOME/.screenlayout/screenlayout.sh
feh --bg-fill --randomize $HOME/.wallpapers &
picom -b &
lxsession &
volumeicon &
ibus-daemon -d &
nm-applet &
slstatus &
