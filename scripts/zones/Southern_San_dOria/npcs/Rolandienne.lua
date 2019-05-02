-----------------------------------
-- Area: Southern San d`Oria
--   NPC: Alaune
-- Type: Tutorial NPC
-- !pos -90 1 -56 230
-----------------------------------
local ID = require("scripts/zones/Southern_San_dOria/IDs");
require("scripts/globals/settings");
require("scripts/globals/quests");
require("scripts/globals/roe_objectives");
require("scripts/globals/keyitems")
-----------------------------------

function onTrade(player,npc,trade)
end;

function onTrigger(player,npc)
    local FirstStepForward = player:getROEStatus(dsp.roe.id.FIRST_STEP_FORWARD);

    if (FirstStepForward == CURRENT_OBJECTIVE and player:hasKeyItem(dsp.ki.MEMORANDOLL) == false) then
        player:startEvent(993);
    elseif (FirstStepForward == COMPLETED_OBJECTIVE and player:hasKeyItem(dsp.ki.MEMORANDOLL) == true) then
        player:startEvent(995); -- opens sparks shop
    else
        player:startEvent(994);
    end;
end;

function onEventUpdate(player,csid,option)
end;

function onEventFinish(player,csid,option)
    if (csid == 993 and option == 1) then
        player:addKeyItem(dsp.ki.MEMORANDOLL);
        player:messageSpecial(ID.text.KEYITEM_OBTAINED,dsp.ki.MEMORANDOLL);
        player:completeROE(dsp.roe.id.FIRST_STEP_FORWARD);
        player:delROE(dsp.roe.id.FIRST_STEP_FORWARD); -- quest is not repeatable and must be cleared from the list
    end;
end;
