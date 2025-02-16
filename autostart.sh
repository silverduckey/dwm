#!/bin/sh
killall picom
killall lxsession
killall nm-applet
killall volctl
killall ibus-daemon
killall slstatus
. $HOME/.screenlayout/screenlayout.sh
feh --bg-fill --randomize $HOME/.wallpapers &
picom -b &
lxsession &
nm-applet &
volctl &
ibus-daemon -d &
slstatus &
