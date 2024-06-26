#pragma once
#include <string>
#include <vector>

#include "Item.h"
#include "NPC.h"

struct Room
{
public:
	std::string Name;

	Room();
	Room(std::string name, std::string desc, std::vector<std::string> exits);
	Room(std::string name, std::string desc, std::vector<std::string> exits, std::vector<Item*> items);
	~Room();

	/* Gets an item inside this room, from its index. Returns a nullptr if out of bounds */
	Item* GetItem(int index);
	/* Adds an item for this room*/
	void AddItem(Item* item);
	/* Removes an item from this room */
	Item* RemoveItem(std::string itmName);
	/* Does the Items in this room contain this item */
	bool ItemsContains(std::string name);
	/* Returns the amount of items inside this room */
	int GetItemsSize();

	/* Gets an exit from it's index. Returns empty std::string if index is out of bounds */
	std::string GetExit(int index);
	/* Gets the amount of exits set for the room */
	int GetExitsSize();
	/* Adds an exit to the room */
	void AddExit(std::string exitName);

	/* Sets the NPC for this room, limited to only one*/
	void AddNPC(NPC* npc);
	/* Gets an NPC by their index. Returns a nullptr if out of bounds */
	NPC* GetNPC(int index);
	/* Gets an NPC from it's name. Returns a nullptr if not found */
	NPC* GetNPC(std::string npcName);
	/* Gets the amount of NPCs inside this room */
	int GetNPCSize();

	/*Gets the print out room description for the room*/
	std::string GetDescription();
	/* Sets the description of the room */
	void SetDescription(std::string desc);

private:
	/* Standard description of this room */
	std::string m_description;
	/* All exits available in this room */
	std::vector<std::string> m_exits;
	/* Items inside the room */
	std::vector<Item*> m_items;
	/* All NPCs inside this room */
	std::vector<NPC*> m_npcs;
};