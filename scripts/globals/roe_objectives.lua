require("scripts/globals/log_ids")
require("scripts/globals/zone")

dsp = dsp or {}
dsp.roe = dsp.roe or {}

-----------------------------------
--
--  QUESTS ID
--
-----------------------------------

INCOMPLETE_OBJECTIVE    = 0;
CURRENT_OBJECTIVE       = 1;
COMPLETED_OBJECTIVE     = 2;

-- Log IDs defined as "enums" here to tie into quest_rewrite
-- branch that will be merged in at a later date. Used
-- as keys for the quest ID tables below.

dsp.roe.id =
{
    FIRST_STEP_FORWARD                = 1,
}
