---------------------------------------------------------------------------------------------------
-- func: completeroe <objectiveID> <player>
-- desc: Completes the given ROE objective for the GM or target player.
---------------------------------------------------------------------------------------------------

require("scripts/globals/roe_objectives")

cmdprops =
{
    permission = 1,
    parameters = "sss"
};

function error(player, msg)
    player:PrintToPlayer(msg);
    player:PrintToPlayer("!completeroe <objectiveID> {player}");
end;

function onTrigger(player, objectiveId, target)

    -- validate objectiveId
    local objectiveIds = dsp.roe.id;
    if (objectiveId ~= nil) then
        objectiveId = tonumber(objectiveId) or objectiveIds[string.upper(objectiveId)];
    end
    if (objectiveId == nil or objectiveId < 0) then
        error(player, "Invalid objectiveID.");
        return;
    end

    -- validate target
    local targ;
    if (target == nil) then
        targ = player;
    else
        targ = GetPlayerByName(target);
        if (targ == nil) then
            error(player, string.format("Player named '%s' not found!", target));
            return;
        end
    end

    -- complete objective
    targ:completeROE(objectiveId);
    player:PrintToPlayer(string.format("Completed ROE objective with ID %u for %s", objectiveId, targ:getName()));
end;
