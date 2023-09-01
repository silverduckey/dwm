#!/usr/bin/env bash

selected_option=$(echo -e "Shutdown\nReboot\nSuspend\nLogout\nLock screen" | dmenu -p "Power Menu")
if [[ $selected_option != "Lock screen" ]]; then
    confirm_option=$(echo -e "Yes\nNo" | dmenu -p "Confirm Action")
    if [[ $confirm_option == "Yes" ]]; then
        if [[ $selected_option == "Shutdown" ]]; then
            loginctl poweroff
        elif [[ $selected_option == "Reboot" ]]; then
            loginctl reboot
        elif [[ $selected_option == "Suspend" ]]; then
            loginctl suspend
        elif [[ $selected_option == "Logout" ]]; then
            killall dwm
        fi
    fi
elif [[ $selected_option == "Lock screen" ]]; then
    slock
fi
