#!/bin/bash

#echo "Ligne à modifier (ID=12345)"
total=$1
count=$2
cppFile=$3
compiledFile=$4

if [ $count == 1 ]; then
	echo ""
fi

# echo -ne "\033[2K" # Effacer la ligne
clear

cols=$(tput cols)

# ASCII Art
ascii_art=$(cat <<'EOF'
 _____ ______   ________  ___  __    _______   ________ ___  ___       _______      
|\   _ \  _   \|\   __  \|\  \|\  \ |\  ___ \ |\  _____\\  \|\  \     |\  ___ \     
\ \  \\\__\ \  \ \  \|\  \ \  \/  /|\ \   __/|\ \  \__/\ \  \ \  \    \ \   __/|    
 \ \  \\|__| \  \ \   __  \ \   ___  \ \  \_|/_\ \   __\\ \  \ \  \    \ \  \_|/__  
  \ \  \    \ \  \ \  \ \  \ \  \\ \  \ \  \_|\ \ \  \_| \ \  \ \  \____\ \  \_|\ \ 
   \ \__\    \ \__\ \__\ \__\ \__\\ \__\ \_______\ \__\   \ \__\ \_______\ \_______\
    \|__|     \|__|\|__|\|__|\|__| \|__|\|_______|\|__|    \|__|\|_______|\|_______|
EOF
)

# Activer le fond coloré une fois
echo -ne "\033[1;41m" # Activer le fond rouge

# Appliquer le style à chaque ligne
while IFS= read -r line; do
    # Calculer l'espace pour centrer la ligne
    padding=$(( (cols - ${#line}) / 2 ))
    # Afficher la ligne remplie avec le fond coloré
    printf "%-${cols}s\n" "$(printf "%*s%s%*s" $padding "" "$line" $((cols - ${#line} - padding)) "")"
done <<< "$ascii_art"

./compiler $total $count $cppFile $compiledFile

printf "%-${cols}s" "Styling"
printf "%-${cols}s" "Styling"
printf "%-${cols}s" "Styling"
printf "%-${cols}s" "Styling"

echo -ne "\033[0m"