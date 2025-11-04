#!/bin/bash
file="/home/abdo/.bashrc"
if [ -f "$file" ]; then
	echo "export HELLO=HOSTNAME" >> "$file"
	echo "LOCAL=$(whoami)" >>  "$file"
	source "$file"
	gnome-terminal
else
	echo "File does not exist"

fi


