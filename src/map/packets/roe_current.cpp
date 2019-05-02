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

    bool endoflist = false;

    ShowDebug(CL_CYAN"CROECurrentPacket: Assembling ROE Current objective list for packet\n" CL_RESET);

    uint8 slot = 0;
    while (slot < MAX_ROE_ACTIVE && !endoflist) {
        if (PChar->m_roe_current[slot].objectiveID == 0) { // if questID is zero, then we've reached the end of the active quest list
            ShowDebug(CL_CYAN"CROECurrentPacket: While: Reached end of list at slot number %i\n" CL_RESET, slot);
            endoflist = true;
        }
        else {                                         // otherwise, populate the quest data found into the packet
            ShowDebug(CL_CYAN"CROECurrentPacket: While: Slot %i: Writing objective ID %i with progress %i\n" CL_RESET, slot, PChar->m_roe_current[slot].objectiveID, PChar->m_roe_current[slot].progress);
            data[(slot * 4) + 4] = PChar->m_roe_current[slot].objectiveID | (PChar->m_roe_current[slot].progress << 12); // quest ID uses lowest 12 bits; progress in upper 20 bits
        }
        ++slot;
    }

    ref<uint32>(0x100) = 0; // limited time quest ID and progress, setting statically to zero for now
}