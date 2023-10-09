#!/bin/sh

selected_option=$(printf "Shutdown\nReboot\nSuspend\nLogout\nLock screen" | dmenu -p "Power Menu")
if [ "$selected_option" != "Lock screen" ]; then
    confirm_option=$(printf "Yes\nNo" | dmenu -p "Confirm Action")
    if [ "$confirm_option" = "Yes" ]; then
        if [ "$selected_option" = "Shutdown" ]; then
            systemctl poweroff
        elif [ "$selected_option" = "Reboot" ]; then
            systemctl reboot
        elif [ "$selected_option" = "Suspend" ]; then
            systemctl suspend
        elif [ "$selected_option" = "Logout" ]; then
            killall dwm
        fi
    fi
elif [ "$selected_option" = "Lock screen" ]; then
    slock
fi
