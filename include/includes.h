#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <termios.h>
#include <map>
#include <functional>

#include "utils.h"
#include "terminal.h"
#include "game.h"
#include "control.h"
#include "draw.h"

using namespace std::chrono_literals;

#define Key_Q 'q'
#define Key_W 'w'
#define Key_A 'a'
#define Key_S 's'
#define Key_D 'd'
#define Key_SPACE ' '