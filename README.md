# **Bounding_Box** 
**Dearest Readers,** (if you know, you know 😂) 

This project is about creating a **dynamic minimap** 😎 for a 2D game. If you’ve ever played a game with a huge map, you know how annoying it can be when the minimap is just as massive, cluttered, and hard to read. That’s where this comes in! The dynamic minimap focuses on the player’s immediate area, making it way more useful and less overwhelming. 
## **Why Bother with a Dynamic Minimap?** 
Let’s be real - nobody wants to stare at a giant minimap that shows the entire world. It’s messy, distracting, and honestly, not that helpful. A dynamic minimap fixes this by: 

1. **Staying Focused on the Player**: It only shows what’s around the player, so you’re not bombarded with unnecessary info. 
1. **Keeping Things Clean**: By rendering just a small area, the minimap stays compact and easy to read. 
1. **Boosting Performance**: Rendering less stuff means better performance, which is always a win, especially for bigger games. 
1. **Making Life Easier for Players**: A smaller, smarter minimap helps players navigate without feeling lost or overwhelmed. 
## **Preliminaries** 😭 
Before diving into the main algorithm, I had to make sure the map file passed as an argument was valid and followed these rules: 

1. The map file needs to have a .obx extension. 
1. The map must be composed of only 4 possible characters: 
- **0** for an empty space, 
- **1** for a wall, 
- **‘ ’** (space) which I interpreted as… something 󰣽, 
- **S** for the player’s starting position. 
3. The map must be closed/surrounded by walls. 
3. There cannot be empty lines on the file. 

This whole process is handled in the checks and family functions. Since it’s not the focus of this repo, I won’t go into depth here. However, feel free to check out the source code yourself—I’m sure you’ll understand it because the function and variable names are self-explanatory, and the algorithm is straightforward. 

After ensuring the map was valid, I converted it into a tile map, where each tile represents one character from the original map. This is done in two main functions: 

- **link\_tiles**: Responsible for linking the tile pointers to create a connected map. 
- **set\_tiles**: Assigns each tile an identification (character ID, color, and coordinates) based on the character it represents from the original map. 

It’s also worth mentioning that I check the size of the map to decide whether to apply the dynamic minimap algorithm or not. If the map size is at least 11x11, I apply the algorithm; otherwise, I just render the entire minimap. This is because my minimap is made up of exactly 121 tiles (11x11). 
## **How It Works** 
So, how does this magic happen? Here’s the breakdown: 

1. **Player’s Position is Key**: 

I based my algorithm on an idea from [Circle fill on a grid](https://www.redblobgames.com/grids/circle-drawing/) called **Bounding Box,** which involves finding the corners of the minimap based on the player’s current position. 

<figcaption>Bounding Box image from <a href="https://www.redblobgames.com/grids/circle-drawing/">Circle fill on a grid</a></figcaption>


This is done in the update\_obx function, where I set a square radius of 5 tiles in the cardinal directions starting from the player’s position to get the corner tiles. After finding them, I use the top-left corner as a reference to help with the logic of the algorithm and to paint the minimap later. 

2. **Fixing Inconsistencies:** 

At this point, the algorithm was working, but it showed some inconsistencies when one of the other three minimap corner tiles pointed to a surrounding tile of the “big map.” To solve this, I had to adjust the reference tile in these three cases by adding these 3 specific conditions: 

![](Aspose.Words.5f7bfca7-11a3-414a-bcda-19a46bd12548.002.png)

Image from the code source: Dynamic\_Minimap/src/OBX/update\_obx.c 

Without these conditions, I was either getting a segmentation fault or a bounding box smaller than the minimap size, which led to some tiles of the minimap being static. Shoutout to [@gecarval](https://github.com/gecarval) 󰹹 for suggesting I clear the image (by painting it all black) each time the player moved. While this helped, it wasn’t the full solution because even though the static tiles weren’t being rendered, the minimap still wasn’t being completely painted. 

3. **Real-Time Updates:** 

Finally, after squashing a bunch of bugs, the algorithm became fully functional. Now, as the player moves, the minimap updates instantly, keeping everything accurate.

## **Wanna Help Out?** 
If you’ve got ideas for making this even better, feel free to open an issue or submit a pull request. Let’s make this minimap the best it can be! 🚀 

**Thanks for reading!** 󰝺❤ 

**Yours Truly,** (again, if you know, you know 🤣)

Efinda 🫠
