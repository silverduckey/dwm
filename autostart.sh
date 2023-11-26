#!/bin/sh
killall compfy
killall lxsession
killall ibus-daemon
killall slstatus
. $HOME/.screenlayout/screenlayout.sh
slstatus &
feh --bg-fill --randomize $HOME/.wallpapers &
compfy &
lxsession &
ibus start
