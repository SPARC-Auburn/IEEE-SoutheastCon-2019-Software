#pragma once

const bool VISION_DEBUG_IMAGE = true;
const int VISION_DEBUG_COLOR_IMAGE = -1; // -1 to disable (0 red, 1 green, 2 blue, 3 yellow)
const bool VISION_DEBUG_TEXT = false;
const bool VISION_DEBUG_3D = true;
const int resolutionX = 640;
const int resolutionY = 480;

enum Colors {
	Red,
	Green,
	Blue,
	Yellow
};