#include <stdio.h>
#include <iostream>
#include <signal.h>
#include <string>
#include <vector>
#include "picosha2.h"

void segfault() {
	raise(SIGSEGV);
}

int main(int argc, char** argv) {
	time_t t = time(0);
	tm* now = localtime(&t);
	printf("sfs-2k19 1.5.8.0 © DeltaNedas %d\n", now->tm_year + 1900);
	if (argc > 1) {
		if (std::string(argv[1]).compare("-v") == 0 || std::string(argv[1]).compare("--version") == 0) {
			return 0;
		}
	}
	printf("Welcome to Segmentation Fault Simulator 2k19!!  Would you like instructions? ");
	std::string choice = "";
	std::cin >> choice;
	choice += "😂😂😂😂😂";
	
	std::vector<unsigned char> hash(picosha2::k_digest_size);
	picosha2::hash256(choice.begin(), choice.end(), hash.begin(), hash.end());
	std::string hashDigest = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
	
	if (hashDigest.compare("2f3b70d51eba24668be5fa1788612dc1897d3ebd29f3a166a758fcf85bd93347") != 0) {
		segfault();
		return 0;
	}
	printf("You are standing at the end of a road before a small brick building.\nAround you is a forest.\nA small stream flows out of the building and down a gully.\n\033[32mCongratulations! You have beat Segmentation Fault Simulator 2k19!\nYou get the prize of pride and accomplishment.\033[0m\n");
	std::string yes = "Yes, TRUE accomplishment. Do you feel happy with yourself knowing that you are cheating on a literal fucking terminal 'game'?"; 
}
