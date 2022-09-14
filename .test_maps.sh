#!/bin/bash
#this script is not to be called on its own. It should only be called using
#the Makefile
chmod 000 maps/forbidden.cub;
echo "TESTING MAP FORBIDDEN"
./cub3D maps/forbidden.cub
echo "Tester returned $?"
echo "TESTING MAP WITH NO .CUB EXTENSION"
./cub3D maps/nocub
echo "Tester returned $?"
echo "TESTING EMPTY MAP"
./cub3D maps/empty.cub
echo "Tester returned $?"
echo "TESTING INCORRECT MAP 1"
./cub3D maps/broken.cub
echo "Tester returned $?"
echo "TESTING CORRECT MAP"
./cub3D maps/default.cub
echo "Tester returned $?"
chmod 400 maps/forbidden.cub;
