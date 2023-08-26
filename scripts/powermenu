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
    else
        output "User chose not to logout." && exit 1
    fi
    ;;
"Lock screen")
    slock
    ;;
"Reboot")
    if [[ "$(echo -e "No\nYes" | dmenu -p "$confirmation" "${@}")" == "Yes" ]]; then
        loginctl reboot
    else
        output "User chose not to reboot." && exit 0
    fi
    ;;
"Poweroff")
    if [[ "$(echo -e "No\nYes" | dmenu -p "$confirmation" "${@}")" == "Yes" ]]; then
        loginctl poweroff
    else
        output "User chose not to poweroff." && exit 0
    fi
    ;;

esac
