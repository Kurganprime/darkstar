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

#include "roe_current.h"
#include "../entities/charentity.h"

CROECurrentPacket::CROECurrentPacket(CCharEntity* PChar)
{
    this->type = 0x11;
    this->size = 0x83;

    uint8 slot = 0;
    while (slot < MAX_ROE_ACTIVE && PChar->m_roe_current[slot].objectiveID != 0) {
        ref<std::bitset<32>>(0x04+(slot*4)) = ((std::bitset<32>)PChar->m_roe_current[slot].objectiveID) | ((std::bitset<32>)(PChar->m_roe_current[slot].progress) << 12);
        ++slot;
    }

    ref<uint32>(0x100) = 0; // limited time quest ID and progress, setting statically to zero for now
}