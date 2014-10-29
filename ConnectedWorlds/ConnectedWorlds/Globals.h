#pragma once

enum levelNames{ NORMAL = 0, ICE, FIRE, WATER, SPACE, STORM, DESERT, FLIPPED };

const Vec2 GRAVITY(0.0f, 0.4f);

#define ZERO 0.000001f

const int levelColours[7][3] = {
//RRR, GGG, BBB
{ 255, 255, 255 },
{ 000, 128, 255 },
{ 255, 128, 000 },
{ 064, 128, 128 },
{ 200, 200, 200 },
{ 128, 255, 128 },
{ 128, 064, 000 }, };