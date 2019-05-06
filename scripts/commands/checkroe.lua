---------------------------------------------------------------------------------------------------
-- func: !checkroe <objectiveID> {player}
-- desc: Prints status of the ROE objective to the in game chatlog
---------------------------------------------------------------------------------------------------

require("scripts/globals/roe_objectives");

cmdprops =
{
    permission = 1,
    parameters = "sss"
};

function error(player, msg)
    player:PrintToPlayer(msg);
    player:PrintToPlayer("!checkroe <objectiveID> {player}");
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
        targ = player:getCursorTarget();
        if (targ == nil or not targ:isPC()) then
            targ = player;
        end
    else
        targ = GetPlayerByName(target);
        if (targ == nil) then
            error(player, string.format("Player named '%s' not found!", target));
            return;
        end
    end

    -- get objective status
    local status = targ:getROEStatus(objectiveId);
    switch (status): caseof
    {
        [0] = function (x) status = "NOTCOMPLETED"; end,
        [1] = function (x) status = "ACTIVE"; end,
        [2] = function (x) status = "COMPLETED"; end,
    }

    -- show objective status
    player:PrintToPlayer(string.format("%s's status for ROE objective ID %i is: %s", targ:getName(), objectiveId, status));

end;
