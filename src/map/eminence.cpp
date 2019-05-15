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

#include "map.h";
#include "eminence.h";

void LoadObjectiveList()
{
    const char* Query =
        "SELECT "
            "objectiveid,"          // 0
            "repeatable,"           // 1
            "onetime_sparks,"       // 2
            "onetime_exp,"          // 3
            "onetime_accolades,"    // 4
            "onetime_keyitemid,"    // 5
            "onetime_itemid,"       // 6
            "onetime_itemcount,"    // 7
            "onetime_cpbonus,"      // 8
            "repeat_sparks,"        // 9
            "repeat_exp,"           // 10
            "repeat_accolades "     // 11
        "FROM roe_objectives "
        "WHERE objectiveid < %u;";

    int32 ret = Sql_Query(SqlHandle, Query, MAX_ROE_OBJECTIVES);

    if (ret != SQL_ERROR && Sql_NumRows(SqlHandle) != 0)
    {
        while (Sql_NextRow(SqlHandle) == SQL_SUCCESS)
        {

        }
    }
}