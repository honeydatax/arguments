printf "\ec\e[46;34m\ainstalling...\n"
gcc -o arguments arguments.c -lX11
gcc -o arglists arglist.c
sudo cp arguments /usr/bin
sudo cp arguments.desktop /usr/share/applications

