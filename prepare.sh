#!/bin/bash

if [[ $(id -u) > 0 ]]; then
    echo "You must run this script as root."
    exit 1
fi

function install_pkg {
    NEW_PKGS=()
    INSTALLED_PKGS=()
    for PKG in $@ ; do
        if [[ 0 -eq $(dpkg-query -W -f='${Status}' $PKG 2>/dev/null | grep -c "ok installed") ]]; then
            NEW_PKGS+=($PKG)
        else
            INSTALLED_PKGS+=($PKG)
        fi
    done
    if [[ ${#NEW_PKGS[@]} -gt 0 ]]; then
        apt install --assume-yes ${NEW_PKGS[@]}
    fi
    if [[ ${#INSTALLED_PKGS[@]} -gt 0 ]]; then
        echo "<${INSTALLED_PKGS[@]}> already installed"
    fi
}

# Install dependencies for Ubuntu 22.04 / Mint 21
install_pkg \
    build-essential \
    cmake \
    libsdl2-dev
