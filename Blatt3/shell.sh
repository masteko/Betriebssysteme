#! /bin/bash

filecount=$(cd $HOME && ls -l | grep "total.*" | cut -d " " -f 2)
echo "Der User $LOGNAME hat $filecount Dateien in seinem Homeverzeichnis $HOME"
