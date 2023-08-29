#!/usr/bin/env bash

declare -a options=(
    "Log out"
    "Lock screen"
    "Reboot"
    "Poweroff"
)

choice=$(printf "%s\n" "${options[@]}" | dmenu -p "Shutdown menu:")
confirmation="Are you sure ? [y/N]"

case $choice in
"Log out")
    if [[ "$(echo -e "No\nYes" | dmenu -p "$confirmation" "${@}")" == "Yes" ]]; then
        killall dwm
    fi
    ;;
"Lock screen")
    slock
    ;;
"Reboot")
    if [[ "$(echo -e "No\nYes" | dmenu -p "$confirmation" "${@}")" == "Yes" ]]; then
        loginctl reboot
    fi
    ;;
"Poweroff")
    if [[ "$(echo -e "No\nYes" | dmenu -p "$confirmation" "${@}")" == "Yes" ]]; then
        loginctl poweroff
    fi
    ;;

esac
