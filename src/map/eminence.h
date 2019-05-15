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

#ifndef _EMINENCE_H
#define _EMINENCE_H

#define MAX_ROE_OBJECTIVES 4096

#include "../common/cbasetypes.h"

struct Objective_t
{
    uint16  m_objectiveid;
    bool    m_repeatable;
    uint16  m_onetime_sparks;
    uint16  m_onetime_exp;
    uint16  m_onetime_accolades;
    uint16  m_onetime_keyitemid;
    uint16  m_onetime_itemid;
    uint8   m_onetime_itemcount;
    uint8   m_onetime_cpbonus;
    uint16  m_repeat_sparks;
    uint16  m_repeat_exp;
    uint16  m_repeat_accolades;
};

#endif