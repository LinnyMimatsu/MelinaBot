#include "Include/gif_randomizer.h"
#include <iostream>
#include <string>
#include <cstdlib>

std::string handle_HFgif() {
	
	/*creating the gif link and random number variables*/
	std::string link;
	int random;

	/*creating a random number*/
	std::srand(time(NULL));
	random = std::rand() % 3 + 1;

	/*assigns a gif to whichever number gets pulled from the random number variable*/
	if (random == 1) {

		link = "https://gifdb.com/images/high/teamwork-high-five-eohre9qd7p1xn3b8.gif";

	}
	else if(random == 2) {

		link = "https://i.pinimg.com/originals/0b/ef/a7/0befa7d49d82d865188ebbafee028842.gif";
			
	}
	else if (random == 3) {

		link = "https://64.media.tumblr.com/670b47fe8f7da2a49e8089ccfa233c9d/tumblr_pc1t0wl1xR1wn2b96o1_1280.gif";

	}


	return link;

}

std::string handle_Kgif() {

	/*creating the gif link and random number variables*/
	std::string link;
	int random;

	/*creating a random number*/
	//std::srand(std::time(NULL));
	random = std::rand() % 3 + 1;

	/*assigns a gif to whichever number gets pulled from the random number variable*/
	if (random == 1) {

		link = "https://i.pinimg.com/originals/10/5a/7a/105a7ad7edbe74e5ca834348025cc650.gif";

	}
	else if (random == 2) {

		link = "https://i.pinimg.com/originals/13/06/73/1306732d3351afe642c9a7f6d46f548e.gif";

	}
	else if (random == 3) {

		link = "https://i.pinimg.com/originals/6b/5e/44/6b5e44911c0b3dda5b18a0c142119c20.gif";

	}


	return link;

}

std::string handle_Sgif() {

	/*creating the gif link and random number variables*/
	std::string link;
	int random;

	/*creating a random number*/
	std::srand(time(NULL));
	random = std::rand() % 3 + 1;

	/*assigns a gif to whichever number gets pulled from the random number variable*/
	if (random == 1) {

		link = "https://i.pinimg.com/originals/71/a5/1c/71a51cd5b7a3e372522b5011bdf40102.gif";

	}
	else if (random == 2) {

		link = "https://64.media.tumblr.com/b05c60b90649f9f9f173ac288d41ac53/7ea633a1e0f4c2c6-4a/s1280x1920/f46660d8f914b28076e7bd44bf2247b6ee38afb9.gif";

	}
	else if (random == 3) {

		link = "https://i.makeagif.com/media/10-13-2015/0wjjxD.gif";

	}


	return link;

}
