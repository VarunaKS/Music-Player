# Music-Player
Software to play music

We have made a music player using the SDL library in C and linked lists(plays only .ogg files)

TO EXECUTE THIS PROGRAM , YOU HAVE TO INCLUDE SPECIFIC LIBRARIES(type in the following command in the command prompt):
gcc UI.c -lmingw32 -lSDL2main -lSDL2_mixer -lSDL2

UI.c has the User Interface related code
new.c has all the code related to the SDL player. It has the play and getll function to play the song based on user selection and get the linked list containing that song respectively.
file.c has all the code related to saving and retrieving the data in csv files. A new playlist is stored in music.csv using savetxt function, a song can be serched using the search function,
shuffle function can be used to shuffle all songs and create a random linked list, play all plays all the songs stored.

Four .bmp images have been included, these are selected and shown on the player window randomly.
Four sample .ogg music files are also included in this folder
