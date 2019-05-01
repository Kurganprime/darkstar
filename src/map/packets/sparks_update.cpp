/*
===========================================================================

  Copyright (c) 2010-2015 Darkstar Dev Teams

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see http://www.gnu.org/licenses/

  This file is part of DarkStar-server source code.

===========================================================================
*/

#include "../../common/socket.h"

#include <string.h>

#include "sparks_update.h"
#include "../entities/charentity.h"

#include "../utils/charutils.h"

CSparksUpdatePacket::CSparksUpdatePacket(CCharEntity* PChar)
{
    this->type = 0x10;
    this->size = 0x09;

    ref<uint16>(0x04) = charutils::GetPoints(PChar, "spark_of_eminence");
    //ref<uint16>(0x06) = charutils::GetPoints(PChar, "unity_accolades");
    ref<uint16>(0x06) = 0;      // Unity Accolades
    ref<uint8>(0x08)  = 1;      // unity (shared)
    ref<uint8>(0x09)  = 0;      // unity (person)
    ref<uint16>(0x0A) = 0xFFFF;
    ref<uint16>(0x0C) = 0xFFFF;
    ref<uint16>(0x0E) = 0xFFFF;
}