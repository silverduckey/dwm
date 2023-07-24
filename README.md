## Installation
```
git clone https://gitlab.com/vudangxyz/dwm ~/.dwm
cd ~/.dwm
sudo make clean install
```
If you want to start dwm using a display manager such as LightDM or SDDM then you will have to create a dwm.desktop file and put it in /usr/share/xsessions. There is an example dwm.desktop file below.
```
[Desktop Entry]
Encoding=UTF-8
Name=Dwm
Comment=Dynamic window manager
Exec=dwm
Icon=dwm
Type=XSession
```
