//
// Created by SamuelSukovský on 17/04/2024.
//

#include "Hopper.h"

Hopper::Hopper(int id, int size, pair<int, int> position, DIRECTION dir, int hopLength) : hopLength{hopLength}, Bug("Hopper", id, size, position, dir)
{

}