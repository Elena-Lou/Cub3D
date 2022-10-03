#!/bin/bash
#this script is not to be called on its own. It should only be called using
#the Makefile
chmod 000 ./maps/forbidden.cub;
echo "======= THE FOLLOWING SHOULD FAIL ======="
echo -e "\n\nTESTING MAP FORBIDDEN"
$@ ./cub3D ./maps/forbidden.cub
echo "Tester returned $?"
echo -e "\n\nTESTING MAP WITH NO .CUB EXTENSION"
$@ ./cub3D ./maps/nocub
echo "Tester returned $?"
echo -e "\n\nTESTING MAP WITH NO NAME WITH .CUB EXTENSION"
$@ ./cub3D ./maps/.cub
echo "Tester returned $?"
echo -e "\n\nTESTING EMPTY MAP"
$@ ./cub3D ./maps/empty.cub
echo "Tester returned $?"
echo -e "\n\nTESTING INCORRECT MAP 1"
$@ ./cub3D ./maps/broken.cub
echo "Tester returned $?"
echo -e "\n\nTESTING INCORRECT PLAYER POSITION"
$@ ./cub3D ./maps/wrong_player.cub
echo "Tester returned $?"
echo "======= THE FOLLOWING SHOULD SUCCEED ======="
echo -e "\n\nTESTING CORRECT MAP"
$@ ./cub3D ./maps/default.cub
echo "Tester returned $?"
chmod 400 ./maps/forbidden.cub;
