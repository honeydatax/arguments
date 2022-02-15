printf "\ec\e[46;34m\ainstalling...\n"
gcc -o arguments arguments.cpp  `pkg-config gtk+-2.0 --cflags --libs`
gcc -o arglists arglist.c
sudo cp arguments /usr/bin
sudo cp arguments.desktop /usr/share/applications

