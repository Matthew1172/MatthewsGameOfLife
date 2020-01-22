#include "Personality.h"

Personality::Personality()
{
	int strength = 0, charisma = 0, intelligence = 1;
	traits.push_back(std::make_unique<Strength>("Strength", strength, 's'));
	traits.push_back(std::make_unique<Intelligence>("Intelligence", intelligence, 'i'));
	traits.push_back(std::make_unique<Charisma>("Charisma", charisma, 'c'));
}

void Personality::chooseTraits()
{
	int strength = 0, charisma = 0, intelligence = 0;
	std::cout << "Welcome to my game! You have 10 points to spend across 3 personality traits. Use them wisely!" << std::endl;
	std::cout << "How many points in strength? (0-10)" << std::endl;
	std::cin >> strength;
	std::cout << "How many points in intelligence? (0-10)" << std::endl;
	std::cin >> intelligence;
	std::cout << "How many points in charisma? (0-10)" << std::endl;
	std::cin >> charisma;
	traits.push_back(std::make_unique<Strength>("Strength", strength, 's'));
	traits.push_back(std::make_unique<Intelligence>("Intelligence", intelligence, 'i'));
	traits.push_back(std::make_unique<Charisma>("Charisma", charisma, 'c'));
}

char Personality::printLargestTrait()
{	
	Trait* largest = traits[0].get();
	for (int i = 0; i < traits.size(); i++) {
		if (largest->getValue() < traits[i].get()->getValue()) {
			largest = traits[i].get();
		}
	}
	return largest->getRep();
}

std::vector<std::unique_ptr<Trait>>* Personality::getTraits()
{
	return &traits;
}

Personality* Personality::scramble(Personality* thePersonality)
{
	int r;
	srand(time(0));
	Personality* newPersonality = new Personality();
	std::vector<std::unique_ptr<Trait>>* parentalTraits = thePersonality->getTraits();
	for (auto& t : *parentalTraits) {
		r = rand();
		t->setValue(r);
	}
	return newPersonality;
}
