Programmer: Dawson Theroux
Purpose: Final examination and simulation of a game where Heros try and collect an emerald.

Compilation and launch instructions:
	-Navigate to the directory where all file are located.
	-run the make file in the terminal with the command "make".
	-run the executable "DragonsHallow" that was created.
-------------------------------------------------------------------------------------------------------
General Description of simulator:
The quest involves 2 heros, Timmy and Herold. Timmy(T) and Harold(H) both start at the left side of the map and try and make their way to the right side of the
screen to collect the Emerald(*). The heros randomly choose whether to move to the right and up, directly to the right, or right and down on each turn. On each
turn there is also a 60% chance that some sort of Ork spawns. There are three kinds of Orks: Borks, Porks, and Dorks. Each ork variant has different strengths and 
health. Orks will randomly choose whether to move left and up, directly left, or left and down. If an Ork comes in contact with a hero, the hero and the Ork will
lost health based on each others strength and armor. Lastly there is the Dragon(D). The Dragon(D) moves up and down the right edge of the map to protect the
emerald. If the heros come in contact with the dragon, they instantly die.

Description of innovative feature:
For my innovative feature I decided to add 4 rings and Gollem to the game

Gollem:
-Gollem is another questplayer that starts on the same side as the Heros.
-Everytime Gollem moves there is a 50% chance that Gollem is in control and 50% chance that Smegal is in control. If Gollem is in control he will move towards the closest of our two heros and do 2 damage to them if they occupy the same spot. If Smegal is in control he will move the same way all the other QuestPlayers do(with randomly choosing to move up down or straight) and will not deal damage to our Heros.
-Gollem cannot collect the emerald because he is too scared of the dragon and the repercussions from the kindom, but there is a certain ring that can help him not get caught.
-The game stats will show the correct name to make it easy to understand what state he is in.

4 Rings:
-There is a new object contained in the Control class that is a ring. When the ring is created there are 4 possible states. It can be a ring of invisibility, invincibility, visibility or strength. It is then places at a random location depending on who is able to pick it up.
-Ring of invisibility: 
	-Only Gollem can pick up this ring. 
	-Gollem will take the ring and since he can no longer be seen he will sprint to the emerald and take it since no one will know he is the one who took it.
-Ring of invincibility:
	-Only the Heros can pick up this ring.
	-When the Heros have the ring they will no longer take damage from all the variations of Orcs BUT the dragon is stronger than the ring and will still kill them.
-Ring of visibility:
	-Only the dragon can pick up this ring.	
	-When the dragon has this ring, he can now see the heros and will target the closest one to him.
-Ring of strength:
	-Only the Orc variations can pick up this ring.
	-When the Orcs pick up thing they will now have double the strength they originally had.
	
