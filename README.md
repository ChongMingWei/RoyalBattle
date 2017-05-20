# Project2
Implement a game - PD2-ROYALE
* Mainly use for Qt tutorial , without commercial purpose.
* created by Chong Ming Wei (E1406664)
* Original game : CLASH-ROYALE , owned by Supercell(https://play.google.com/store/apps/details?id=com.supercell.clashroyale)

## About all settings
1.[Game] The control class which displays all items on the view works as the control center.
		   Loads the background picture and background music.

2.[BuildArcherIcon]&[BuildKnightIcon][BuildRogueIcon]&[BuildSniperIcon] Build icon for user to click and summon the champions.

3.[Archer]&[Com_Archer] A champion sets with 6 HP ,1 attack range and deal with 1 damage per .2 seconds to other champions and castle.
							 Moving range is 10 per .2 seconds.
							 Use QTimer to forced moving and so as the other champions

4.[Knight]&[Com_Knight]A champion sets with 10 HP ,1 attack range and deal with 2 damage per .2 seconds to other champions but 1 damage per .2 seconds to castle.
							Moving range is 15 per .2 seconds.

5.[Rogue]&[Com_Rogue]A champion sets with 5 HP ,1 attack range and deal with 1 damage per .2 seconds to other champions but 2 damage per .2 seconds to castle.
						 Moving range is 15 per .2 seconds.

6.[Sniper]&[Com_Sniper]A champion sets with 8 HP ,1 attack range and deal with 2 damage per .2 seconds to other champions but 1 damage per .2 seconds to castle.
						 Moving range is 10 per .2 seconds.

7.[arrow] A very fast-moving object moves 50 per .05 seconds.It's equipped by castle and can deal with 1 damage to the champions.
          Use QTimer to forced moving and so as the other champions

8.[Castle] &[Com_Castle]A static building deals with 1 damage per .2 seconds and initialized with 20 HP.
                        It can acquire the object getting in its attack range and shoot arrow dealing with 1 damage per second.

9.[gameover & btn] To load the image which displays game result(win or loss)


###### Qt creator environment : Qt 4.0.2 (gcc version 4.8.4 ,64 bit) , on Ubuntu 14.04 .
