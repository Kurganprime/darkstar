---------------------------------------------------------------------------------------------------
-- func: delroe <questID> <player>
-- desc: Deletes the given ROE objective from the GM or target player.
---------------------------------------------------------------------------------------------------

require("scripts/globals/roe_objectives");

cmdprops =
{
    permission = 1,
    parameters = "sss"
};

function error(player, msg)
    player:PrintToPlayer(msg);
    player:PrintToPlayer("!delroe <objectiveID> {player}");
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

    -- add objective
    targ:delROE(objectiveId);
    player:PrintToPlayer(string.format("Deleted ROE objective %i from %s.", objectiveId, targ:getName()));
end;