#pragma once
/// @defgroup os os
/// @ingroup cross

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <iostream>
#include <sstream>

using namespace std;

#ifdef LINUX
#include "linux.hpp"
#endif
